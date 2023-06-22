#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_ENTRIES 100

struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
};

int updateLogEntry(const char* filename, int entryNo, const struct LogEntry* updatedEntry) {
    FILE* file = fopen(filename, "r+");
    if (file == NULL) {
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "EntryNo") != NULL) {
            continue;
        }

        int currentEntryNo;
        sscanf(line, "%d", &currentEntryNo);

        if (currentEntryNo == entryNo) {
            fseek(file, -strlen(line), SEEK_CUR);
            fprintf(file, "%d,%s,%.2f,%d,%d,%s\n",
                    updatedEntry->entryNo,
                    updatedEntry->sensorNo,
                    updatedEntry->temperature,
                    updatedEntry->humidity,
                    updatedEntry->light,
                    updatedEntry->time);
            found = 1;
            break;
        }
    }

    fclose(file);

    return found;
}

int main() {
    const char* filename = "data.csv";
    int entryNo = 2;

    struct LogEntry updatedEntry;
    updatedEntry.entryNo = 2;
    strcpy(updatedEntry.sensorNo, "S3");
    updatedEntry.temperature = 35.5;
    updatedEntry.humidity = 95;
    updatedEntry.light = 60;
    strcpy(updatedEntry.time, "10:32:00");

    if (updateLogEntry(filename, entryNo, &updatedEntry)) {
        printf("Log entry with EntryNo %d updated successfully.\n", entryNo);
    } else {
        printf("Log entry with EntryNo %d not found.\n", entryNo);
    }

    return 0;
}
