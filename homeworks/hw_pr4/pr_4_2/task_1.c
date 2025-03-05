#include <stdio.h>
#include <string.h>

typedef struct{
    char name[8];
    void (*fun)(char*);
} Command;

void upper(char *str){
    for (int i = 0; i < strlen(str); i++){
        if (str[i] >= 97 && str[i] <= 122){
            str[i] = str[i] - 32;
        }
    }
}

void lower(char *str){
    for (int i = 0; i < strlen(str); i++){
        if (str[i] >= 65 && str[i] <= 90){
            str[i] = str[i] + 32;
        }
    }
}

void reverse(char *str){
    char x;
    for (int i = 0; i < strlen(str) / 2; i++){
        x = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = x;
    }
}

void task1(){
    Command commands[3] = {
        {"upper", upper},
        {"lower", lower},
        {"reverse", reverse},
    };
    char str[200];
    char command[10];
    while (1){
        printf("Введите команду (upper, lower, reverse, exit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcasecmp(command, "exit") == 0){
            printf("Завершение программы.");
            break;
        }

        printf("Введите строку: ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = 0;


        for (int i = 0; i < 3; i++){
            if (strcasecmp(command, commands[i].name) == 0){
                commands[i].fun(str);
            }
        }
        printf("%s\n", str);
    }

}

int main(){
    task1();
    return 0;
}