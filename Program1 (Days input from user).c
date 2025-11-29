#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Day
{
    char *name;
    int date;
    char *activity;
};

struct Day *create(int n)
{
    struct Day *calendar;
    calendar = (struct Day *)malloc(n*sizeof(struct Day));

    for (int i=0;i<n;i++)
    {
        calendar[i].name = (char *)malloc(20*sizeof(char));
        calendar[i].activity = (char *)malloc(100*sizeof(char));
    }
    return calendar;
}

void read(struct Day *calendar,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the day: ");
        scanf("%s",calendar[i].name);

        printf("\nEnter the date: ");
        scanf("%d",&calendar[i].date);

        printf("\nEnter the activity: ");
        scanf(" %[^\n]",calendar[i].activity);
    }
}

void display(struct Day *calendar, int n)
{
    printf("\nCalendar:\n");
    for (int i=0;i<n;i++)
    {
        printf("Day: %s [Date: %d] Activity: %s\n",calendar[i].name,calendar[i].date,calendar[i].activity);
    }
}

int main()
{
    int n;
    printf("\nEnter days in a week: ");
    scanf("%d",&n);

    struct Day *calendar = create(n);
    read(calendar,n);
    display(calendar,n);

    for (int i=0;i<n;i++)
    {
        free(calendar[i].name);
        free(calendar[i].activity);
    }
    free(calendar);
    return 0;
}