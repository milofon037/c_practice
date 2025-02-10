#include <stdio.h>
#include <math.h>

int main(int argc, char**argv){
    if (argc < 3){
        printf("Слишком мало аргументов");
        return 1;
    }
    if (argc > 3){
        printf("Слишком много аргументов");
        return 2;
    }

    printf("%lf", pow((double)atof(argv[1]), (double)atof(argv[2])));
    return 0;
}
