#include <stdio.h>
// какая-то проблема с enum, которой почему-то нет в номере 6
enum States {Sunny, Cloudy, Rainy};

struct Weather {
    float temp;
    float humidity;
    enum States s;
};


void main(){
    struct Weather w;
    scanf("%f %f %d", &w.temp, &w.humidity, &w.s);
    char st[6];
    if (w.s == 0){
        char st[6] = "Sunny";
    }else if (w.s == 1){
        char st[6] = "Cloudy";
    }else{
        char st[6] = "Rainy";
    }
    printf("Temperature: %f°C\nHumidity: %f%\nCondition: %s", w.temp, w.humidity, st);
}
