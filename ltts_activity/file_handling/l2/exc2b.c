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

void writeLogEntries(const char* filename, const struct LogEntry logEntries[], int numEntries) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        return;
    }

    fprintf(file, "EntryNo,sensorNo,Temperature,Humidity,Light,Time\n");

    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%d,%s,%.2f,%d,%d,%s\n",
                logEntries[i].entryNo,
                logEntries[i].sensorNo,
                logEntries[i].temperature,
                logEntries[i].humidity,
                logEntries[i].light,
                logEntries[i].time);
    }

    fclose(file);
}

int updateLogEntry(struct LogEntry logEntries[], int numEntries, int entryNo, const struct LogEntry* updatedEntry) {
    for (int i = 0; i < numEntries; i++) {
        if (logEntries[i].entryNo == entryNo) {
            logEntries[i].entryNo = updatedEntry->entryNo;
            strcpy(logEntries[i].sensorNo, updatedEntry->sensorNo);
            logEntries[i].temperature = updatedEntry->temperature;
            logEntries[i].humidity = updatedEntry->humidity;
            logEntries[i].light = updatedEntry->light;
            strcpy(logEntries[i].time, updatedEntry->time);
            return 1;
        }
    }
    return 0;
}


int main() {
    const char* filename = "data.csv";
    int entryNo = 2;

    struct LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), file); // Skip header line

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,]",
               &logEntries[numEntries].entryNo,
               logEntries[numEntries].sensorNo,
               &logEntries[numEntries].temperature,
               &logEntries[numEntries].humidity,
               &logEntries[numEntries].light,
               logEntries[numEntries].time);

        numEntries++;

        if (numEntries >= MAX_ENTRIES) {
            break;
        }
    }

    fclose(file);

    struct LogEntry updatedEntry;
    updatedEntry.entryNo = 2;
    strcpy(updatedEntry.sensorNo, "S3");
    updatedEntry.temperature = 35.5;
    updatedEntry.humidity = 95;
    updatedEntry.light = 60;
    strcpy(updatedEntry.time, "10:32:00");

    if (updateLogEntry(logEntries, numEntries, entryNo, &updatedEntry)) {
        printf("Log entry with EntryNo %d updated successfully.\n", entryNo);
        writeLogEntries(filename, logEntries, numEntries);
    } else {
        printf("Log entry with EntryNo %d not found.\n", entryNo);
    }

    return 0;
}
