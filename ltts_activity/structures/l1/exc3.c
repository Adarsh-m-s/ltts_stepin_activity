// Write a program using structures to calculate the difference between two time periods using a user-defined function.

#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time getTimePeriod() {
    struct Time t;
    scanf("%d", &t.hours);
    scanf("%d", &t.minutes);
    scanf("%d", &t.seconds);
    return t;
}

struct Time calculateDifference(struct Time t1, struct Time t2) {
    struct Time diff;
    int totalSeconds1, totalSeconds2, timeDifference;

    totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    timeDifference = totalSeconds1 - totalSeconds2;

    diff.hours = timeDifference / 3600;
    timeDifference %= 3600;
    diff.minutes = timeDifference / 60;
    diff.seconds = timeDifference % 60;

    return diff;
}

void displayTimePeriod(struct Time t) {
    printf("%02d:%02d:%02d\n", t.hours, t.minutes, t.seconds);
}

int main() {
    struct Time timePeriod1, timePeriod2, difference;

    timePeriod1 = getTimePeriod();
    timePeriod2 = getTimePeriod();

    difference = calculateDifference(timePeriod1, timePeriod2);

    displayTimePeriod(difference);

    return 0;
}

