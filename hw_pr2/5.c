#include <stdio.h>

union Data {
    int N;
    float fl_d;
    char str[50];
};

void main(){
    int n, i;
    scanf("%d", &n);
    union Data d;
    if (n == 1){
        scanf("%d", &d.N);
    }else if (n == 2){
        scanf("%f", &d.fl_d);
    }else if (n == 3){
        scanf("%s", &d.str);
    }

    if (n == 1){
        printf("Integer: %d", d.N);
    }else if (n == 2){
        printf("Float: %f", d.fl_d);
    }else if (n == 3){
        printf("String: %s", d.str);
    }
}
