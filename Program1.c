#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day {
    char *name;    // Day name
    int date;      // Date
    char *activity;// Activity description
};

// Creates calendar array of 7 days
struct Day *create() {
    // Allocate memory for 7 structs
    struct Day *calendar = (struct Day *)malloc(7 * sizeof(struct Day));
    for (int i = 0; i < 7; i++) {
        calendar[i].name = (char *)malloc(20 * sizeof(char));     // Up to 19 chars + null
        calendar[i].activity = (char *)malloc(100 * sizeof(char));// Up to 99 chars + null
    }
    return calendar;
}

// Reads day's data from keyboard
void read(struct Day *calendar) {
    for (int i = 0; i < 7; i++) {
        printf("Enter day name: ");
        scanf("%s", calendar[i].name);

        printf("Enter date: ");
        scanf("%d", &calendar[i].date);

        printf("Enter activity: ");
        scanf(" %[^\n]", calendar[i].activity); // Reads the whole line including spaces
    }
}

// Displays all days
void display(struct Day *calendar) {
    printf("\nCalendar:\n");
    for (int i = 0; i < 7; i++) {
        printf("%s (Date: %d): %s\n", calendar[i].name, calendar[i].date, calendar[i].activity);
    }
}

int main() {
    struct Day *calendar = create();   // Create calendar
    read(calendar);                    // Fill calendar
    display(calendar);                 // Print calendar

    // Free memory
    for (int i = 0; i < 7; i++) {
        free(calendar[i].name);
        free(calendar[i].activity);
    }
    free(calendar);
    return 0;
}
