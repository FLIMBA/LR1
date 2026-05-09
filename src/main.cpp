#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <clocale>
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <cstdlib>
#include <math.h>
#include <clocale>
#include <string.h>
#include <iomanip>
#include <ctype.h>
#include <conio.h>
#include <cstring>
#include <array>
#include <cstdio>
//#include "../.h/stroki.h"
#include <stroki.h>

using namespace std;
// Ctrl + .

typedef struct{
    char* brand;       // марка
    char* owner_last;  // фамилия владельца
    char* owner_first; // имя владельца
    int power;         // мощность
    int mileage;       // пробег
} car;

void add_car(car*** db, int* count){

    *db = (car**)realloc(*db, (*count + 1) * sizeof(car*)); // *db ~ car**
    (*db)[*count] = (car*)malloc(sizeof(car));

    char buffer[256];
    
    printf("Марка: ");
    scanf("%255s", buffer);
    (*db)[*count]->brand = (char*)malloc(strlen(buffer) + 1);
    strcpy((*db)[*count]->brand, buffer);

    printf("Имя: ");
    scanf("%255s", buffer);
    (*db)[*count]->owner_first = (char*)malloc(strlen(buffer) + 1);
    strcpy((*db)[*count]->owner_first, buffer);

    printf("Фамилия: ");
    scanf("%255s", buffer);
    (*db)[*count]->owner_last = (char*)malloc(strlen(buffer) + 1);
    strcpy((*db)[*count]->owner_last, buffer);

    printf("Мощность: ");
    scanf_s("%d", &((*db)[*count]->power));

    printf("Пробег: ");
    scanf_s("%d", &((*db)[*count]->mileage));

    (*count)++;
}

int main(int argc, char* argv[]){
    setlocale(LC_ALL, "Russian");
    //system("chcp 1251");
    car** database = NULL;  // указатель на массив указателей на Car
    int size = 0;           // сколько сейчас машин
    add_car(&database, &size);
    system("pause");
    return 0;
}
