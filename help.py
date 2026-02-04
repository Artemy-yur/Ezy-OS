import sys

commands = ['gh', 'file', 'additions', 'wearth', 'timenow', 'exit', 'help', 'clear']

def print_help():
    print("Доступные команды / Available commands:")
    print("  gh        - Домой / Go home")
    print("  file      - Файлы / File operations")
    print("  additions - Меню / Additions menu")
    print("  wearth    - Погода / Weather")
    print("  timenow   - Время / Current time")
    print("  exit      - Выход / Exit")
    print("  help      - Справка / Help")
    print("  clear     - Очистка / Clear screen")
    print(" list       - Все файлы / File")

def main():
    print_help()
    while True:
        try:
            command = input("\nВведите команду (help/exit): ").strip().lower()
            if command == 'exit':
                print("Выход из справки...")
                break
            elif command == 'help':
                print_help()
            elif command in commands:
                print(f"Команда '{command}' не реализована в help.py пока что.")
            else:
                print(f"Неизвестная команда: '{command}'")
        except EOFError:
            break
        except KeyboardInterrupt:
            break


if __name__ == "__main__":
    main()

