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
    struct Event events[n];

    for (i = 0; i < n; i++){
        struct Event event;
        struct Date d;
        scanf("%s %d %d %d %s", &event.name, &d.day, &d.month, &d.year, &event.discr);
        event.date = d;
        events[i] = event;
    }

    for (i = 0; i < n; i++){
        printf("Event: %s\nDate: %d/%d/%d\nDescription: %s\n\n", events[i].name, events[i].date.day, events[i].date.month, events[i].date.year, &events[i].discr);
    }
}
