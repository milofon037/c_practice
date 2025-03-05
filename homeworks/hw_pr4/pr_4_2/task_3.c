#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
    char name[15];
    int (*fun)(int, int);
} Command;

int add(int a, int b){
    return a + b;
}

int minus(int a, int b){
    return a - b;
}

int times(int a, int b){
    return a * b;
}

int parts(int a, int b){
    return a / b;
}

void task3(){
    Command commands[4] = {
        {"+", add},
        {"-", minus},
        {"*", times},
        {"/", parts}
    };

    char str[200];
    char *command;
    int a, b;
    int res = 0;
    while (1){
        printf("Введите строку (exit для выхода): ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = 0;

        if (strcasecmp(str, "exit") == 0){
            printf("Завершение программы.");
            break;
        }

    
        sscanf(strtok(str, " "), "%d", &a);
        command = strtok(NULL, " ");
        sscanf(strtok(NULL, " "), "%d", &b);

        for (int i = 0; i < 4; i++){
            if (strcasecmp(command, commands[i].name) == 0){
                res = commands[i].fun(a, b);
                break;
            }
        }
        printf("%d\n", res);
    }
}


int main(){
    task3();
    return 0;
}
