#include <bd.hpp>
#include <cstdio>
#include <console.h>
#include <cstdlib>
#include <cstring>

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
    wait_for_key();
    clear_console();
}