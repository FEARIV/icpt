#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool debug = false;

unsigned long providedSeconds;
int totalYears;
int totalMonths;
int totalDays;
int totalHours;
int totalMinutes;

long SecondsPerYear = 31536000;
long SecondsPerMonth = 2592000;
long SecondsPerDay = 86400;
long SecondsPerHour = 3600;
long SecondsPerMinute = 60;

void askInput() {
    printf("Type a number of seconds: \n");
    scanf("%d", &providedSeconds);
}

char* GetAmount(int value, char* singleAmount, char* multiAmount) {
    if (value == 1) {
        return singleAmount;
    }
    return multiAmount;
}

void convertYears() {
    int years = floor(providedSeconds / SecondsPerYear);
    if (years >= 1) {
        providedSeconds = providedSeconds % SecondsPerYear;
        totalYears = years;
    }
    if (debug) {
        printf("Years set to: %d\n", totalYears);
        printf("Remaining seconds: %d\n", providedSeconds);
    }
}

void convertMonths() {
    int months = floor(providedSeconds / SecondsPerMonth);
    if (months >= 1) {
        providedSeconds = providedSeconds % SecondsPerMonth;
        totalMonths = months;
    }
    if (debug) {
        printf("Months set to: %d\n", totalMonths);
        printf("Remaining seconds: %d\n", providedSeconds);
    }
}

void convertDays() {
    int days = providedSeconds / SecondsPerDay;
    if (days >= 1) {
        providedSeconds = providedSeconds % SecondsPerDay;
        totalDays = days;
    }
    if (debug) {
        printf("Days set to: %d\n", totalDays);
        printf("Remaining seconds: %d\n", providedSeconds);
    }
}

void convertHours() {
    int hours = floor(providedSeconds / SecondsPerHour);
    if (hours >= 1) {
        providedSeconds = providedSeconds % SecondsPerHour;
        totalHours = hours;
    }
    if (debug) {
        printf("Hours set to: %d\n", totalHours);
        printf("Remaining seconds: %d\n", providedSeconds);
    }
}

void convertMinutes() {
    int minutes = floor(providedSeconds / SecondsPerMinute);
    if (minutes >= 1) {
        providedSeconds = providedSeconds % SecondsPerMinute;
        totalMinutes = minutes;
    }
    if (debug) {
        printf("Minutes set to: %d\n", totalMinutes);
        printf("Remaining seconds: %d\n", providedSeconds);
    }
}

void printResult() {
    printf("That's a total of %d %s, %d %s, %d %s, ", totalYears, GetAmount(totalYears, "year", "years"), totalMonths, GetAmount(totalMonths, "month", "months"), totalDays, GetAmount(totalDays, "day", "days"));
    printf("%d %s, %d %s & %d %s.", totalHours, GetAmount(totalHours, "hour", "hours"), totalMinutes, GetAmount(totalMinutes, "minute", "minutes"), providedSeconds, GetAmount(providedSeconds, "second", "seconds"));
}

int main() {
    askInput();
    convertYears();
    convertMonths();
    convertDays();
    convertHours();
    convertMinutes();
    printResult();
    return 0;
}
