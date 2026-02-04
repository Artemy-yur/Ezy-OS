//
// Created by Artemy on 04.02.2026.
//
#include  "../libraru/initlibery.h"
#include  <windows.h>
#include <psapi.h>
#include <../clearwin.h>

int starts(void);

static void print_memory_info() {
    PROCESS_MEMORY_COUNTERS pmc;

    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        printf("PageFaultCount: %lu\n", pmc.PageFaultCount);
        printf("PeakWorkingSetSize: %llu bytes\n", (unsigned long long)pmc.PeakWorkingSetSize);
        printf("WorkingSetSize: %llu bytes\n", (unsigned long long)pmc.WorkingSetSize);
        printf("PagefileUsage: %llu bytes\n", (unsigned long long)pmc.PagefileUsage);
    }
}
typedef struct {
    char last_update[11];
    char version[15];
} date;

void info_system(void) {
    date now = {"04.02.2026", "Version 0.2"};
    printf("Last update: %s\nVersion: %s\n", now.last_update, now.version);
    print_memory_info();
    SLEEP(1);  // 10 секунд в миллисекундах
    CLEAR;
    starts();
}