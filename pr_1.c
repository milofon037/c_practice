void min_weight() {
    //Космический челнок "Буран" принимает на борт только космонавтов с массой тела от 60 до 90 кг.
    //Напишите программу, которая запрашивает у пользователя его массу и сообщает, может ли он пройти отбор.
    //Используйте int для хранения массы.

    int weight;
    printf("Введите свой вес: ");
    scanf("%d", &weight);
    if (weight >= 60 && weight <= 90){
        printf("Вы можете пройти отбор!!!");
    }else{
        printf("К сожалению, вы не можете пройти отбор(((");
    }

}

int main(){
    min_weight();
}
