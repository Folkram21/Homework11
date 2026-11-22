#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

// структура
struct Car {
    char* marka;
    char* maker;
    char* type;
    int year;
    char* reg_date;
};

int get_reg_date(struct Car car) {
    int digit, date = 0;

    int size = 10;

    for (int i = 6; i < size; i++) {
        digit = (int)car.reg_date[i] - 48;

        date += digit * pow(10, size - (i+1));
    }

    return date;
}

int main() {
    setlocale(LC_CTYPE, "RUS");

    struct Car cars[10] = {
        {"Camry", "Toyota", "Седан", 2005, "12.05.2006"},
        {"Corolla", "Toyota", "Седан", 2010, "15.08.2011"},
        {"RAV4", "Toyota", "Внедорожник", 2003, "01.11.2004"},
        {"Land Cruiser", "Toyota", "Внедорожник", 2015, "20.02.2016"},
        {"X5", "BMW", "Внедорожник", 2004, "20.01.2005"},
        {"Focus", "Ford", "Хэтчбек", 2006, "10.10.2006"},
        {"Solaris", "Hyundai","Седан", 2012, "05.03.2013"},
        {"Polo", "Volkswagen","Хэтчбек", 2008, "18.07.2009"},
        {"Yaris", "Toyota", "Хэтчбек", 2001, "25.12.2002"},
        {"Logan", "Renault","Седан", 2007, "14.09.2007"}
    };

    int size = sizeof(cars) / sizeof(cars[0]);

    printf("-----------------------------------------Список всех машин-------------------------------------\n");
    printf("| № |     Марка     |  Производитель  |      Тип      | Год производства |  Дата регистрации  |\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("|%3d|%15s|%17s|%15s|%18d|%20s|\n", i+1, cars[i].marka, cars[i].maker, cars[i].type, cars[i].year, cars[i].reg_date);
    }

    printf("\n\n-----------Список всех машин (марки “Toyota” и зарегистрированных до 2007 - го года)-----------\n");
    printf("| № |     Марка     |  Производитель  |      Тип      | Год производства |  Дата регистрации  |\n");
    printf("-----------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        if (cars[i].maker == "Toyota" && get_reg_date(cars[i]) < 2007)
            printf("|%3d|%15s|%17s|%15s|%18d|%20s|\n", i + 1, cars[i].marka, cars[i].maker, cars[i].type, cars[i].year, cars[i].reg_date);
    }

    return 0;
}
