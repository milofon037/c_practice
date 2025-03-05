#include <stdio.h>
#include <string.h>

void task1(){
    char st[][50] = {"SShuttle", "STurtle", "SSSR", "StarSearcher", "SSearcher", "SuperRocket", "SSD", "SSlim", "Soyuz", "SSoyus"};
    int count = 10;
    for (int i = 0; i < 10; i++){
        if (strncmp(st[i], "SS", 2) == 0){
            printf("First ship: %s\n", st[i]);
        }
    }
}

void task2(){
    char st[100];
    int n;
    scanf("%s", st);

    for (int i = 0; i < strlen(st); i++){
        if (st[i] == '*' || st[i] == '#'){
            st[i] = ' ';
            continue;
        }else{
            n = i;
            break;
        }
    }
    int len_p = strlen(st) - n - (strlen(st) - strcspn(st, "*#"));
    char res[100];
    int j = 0;
    for (int i = n; i < strcspn(st, "*#"); i++){
        res[j] = st[i];
        j++;
    }
    printf("Длина полезной части: %d\nПолезная строка: %s", len_p, res);

}

void task3(){
    char st[100];
    fgets(st, sizeof(st), stdin);
    st[strcspn(st, "\n")] = 0;
    char *res = strtok(st, ";");
 
    while (res){
        printf("%s\n", res);
        res = strtok(NULL, ";");
    }
}

void task4(){
    char st[100];
    fgets(st, sizeof(st), stdin);
    st[strcspn(st, "\n")] = 0;
    if (strcasecmp(st, "LAUNCH-2025") == 0){
        printf("Код принят");
    }else{
        printf("Ошибка! Код '%s' неверный!", st);
    }
}

void task5(){
    char st[200];
    fgets(st, sizeof(st), stdin);
    st[strcspn(st, "\n")] = 0;

    char *copy_st = strdup(st);

    printf("Оригинал: %s\nКопия: %s\n", st, copy_st);
}

int main(){
    //task1();
    //task2();
    //task3();
    //task4();
    //task5();
    return 0;
}

