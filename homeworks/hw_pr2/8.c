#include <stdio.h>

union Grade {
    int N;
    char str;
};

void main(){
    int n, i;
    scanf("%d", &n);
    union Grade* grades = malloc(sizeof(union Grade) * n);
    for (i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        if (t == 1){
            scanf("%d", &grades[i].N);
            printf("Grades: %d\n", grades[i].N);
        }
        else if (t == 2) {
            scanf("%c", &grades[i].str);
            printf("Grades: %c\n", grades[i].str);
        }
    }
}
