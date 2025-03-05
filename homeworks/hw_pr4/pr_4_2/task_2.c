#include <stdio.h>
#include <string.h>


typedef struct{
    char name[15];
    void (*fun)(char*);
} Command;


void remove_spaces(char* str){
    char new_str[200];
    int j = 0;
    for (int i = 0; i < strlen(str); i++){
        if (str[i] != ' '){
            new_str[j] = str[i];
            j++;
        }
    }
    strcpy(str, new_str);
}

void vowel_to_star(char* str){
    for (int i = 0; i < strlen(str); i++){
        if (strchr("aeoiuyAEOIUYеыаоэяиюЕЫАОЭЯИЮ", str[i]) != NULL){
            str[i] = '*';
        }
    }
}

void invert_str(char* str){
    for (int i = 0; i < strlen(str); i++){
        if (str[i] >= 97 && str[i] <= 122){
            str[i] = str[i] - 32;
        }else if (str[i] >= 65 && str[i] <= 90){
            str[i] = str[i] + 32;
        }
    }
}

void task2(){
    Command commands[3] = {
        {"rmspaces", remove_spaces},
        {"vowelstar", vowel_to_star},
        {"invreg", invert_str},
    };
    char str[200];
    char command[20];
    while (1){
    printf("Введите команду (rmspaces, vowelstar, invreg, exit): ");
    fgets(command, sizeof(command), stdin);
    command[strlen(command) - 1] = 0;

    if (strcasecmp(command, "exit") == 0){
        printf("Завершение программы.");
        break;
    }

    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = 0;


    for (int i = 0; i < 3; i++){
        if (strcasecmp(command, commands[i].name) == 0){
            commands[i].fun(str);
        }
    }
    printf("%s\n", str);
    }
}


int main(){
    task2();
    return 0;
}
