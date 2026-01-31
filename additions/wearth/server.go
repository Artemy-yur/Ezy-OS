package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
	"net/url"
)

func weatherHandler(w http.ResponseWriter, r *http.Request) {
	city := r.URL.Query().Get("city")
	if city == "" {
		http.Error(w, `{"error": "City parameter is required"}`, http.StatusBadRequest)
		return
	}

	// OpenWeather API
	apiKey := "myapi"
	
	// URL для OpenWeather (current weather)
	apiURL := fmt.Sprintf("http://api.openweathermap.org/data/2.5/weather?q=%s&appid=%s&units=metric", 
		url.QueryEscape(city), apiKey)

	// Делаем запрос
	resp, err := http.Get(apiURL)
	if err != nil {
		http.Error(w, fmt.Sprintf(`{"error": "Failed to fetch weather: %v"}`, err), http.StatusInternalServerError)
		return
	}
	defer resp.Body.Close()

	// Читаем ответ
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		http.Error(w, fmt.Sprintf(`{"error": "Failed to read response: %v"}`, err), http.StatusInternalServerError)
		return
	}

	// Если OpenWeather вернул ошибку
	if resp.StatusCode != http.StatusOK {
		http.Error(w, string(body), resp.StatusCode)
		return
	}

	// Парсим JSON для красивого вывода (опционально)
	var data map[string]interface{}
	if err := json.Unmarshal(body, &data); err == nil {
		// Можно преобразовать ответ
		if mainData, ok := data["main"].(map[string]interface{}); ok {
			// Упрощаем ответ
			response := map[string]interface{}{
				"city":        data["name"],
				"temperature": mainData["temp"],
				"feels_like":  mainData["feels_like"],
				"humidity":    mainData["humidity"],
				"pressure":    mainData["pressure"],
			}
			
			if weatherArr, ok := data["weather"].([]interface{}); ok && len(weatherArr) > 0 {
				if weather, ok := weatherArr[0].(map[string]interface{}); ok {
					response["description"] = weather["description"]
				}
			}

			// Преобразуем обратно в JSON
			jsonResponse, _ := json.Marshal(response)
			w.Header().Set("Content-Type", "application/json")
			w.Write(jsonResponse)
			return
		}
	}

	// Или возвращаем как есть
	w.Header().Set("Content-Type", "application/json")
	w.Write(body)
}

func main() {
	http.HandleFunc("/weather", weatherHandler)
	fmt.Println("Server started on localhost:8080")
	if err := http.ListenAndServe(":8080", nil); err != nil {
		fmt.Printf("Server failed: %v\n", err)
	}
}