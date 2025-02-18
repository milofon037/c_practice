#include <stdio.h>

struct Date{
    int day;
    int month;
    int year;
};

struct Event {
    char name[50];
    struct Date date;
    char discr[100];
};

void main(){
    int n, i;
    scanf("%d", &n);
    struct Event* events = malloc(sizeof(struct Event) * n);

    for (i = 0; i < n; i++){
        scanf("%s %d %d %d %s", &events[i].name, &events[i].date.day, &events[i].date.month, &events[i].date.year, &events[i].discr);
    }

    for (i = 0; i < n; i++){
        printf("Event: %s\nDate: %d/%d/%d\nDescription: %s\n\n", events[i].name, events[i].date.day, events[i].date.month, events[i].date.year, &events[i].discr);
    }
}
