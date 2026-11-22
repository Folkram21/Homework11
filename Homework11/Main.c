#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

// структура
struct Car {
    char marka[50];
    char maker[50];
    char type[30];
    int year;
    char reg_date[20];
};

int main() {
    setlocale(LC_CTYPE, "RUS");
}
