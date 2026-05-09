#include <bd.hpp>
#include <cstdio>
#include <console.h>
#include <cstdlib>
#include <cstring>

void add_car(car*** db, int* count){

    *db = (car**)realloc(*db, (*count + 1) * sizeof(car*)); // *db ~ car**
    (*db)[*count] = (car*)malloc(sizeof(car));

    char buffer[256];
    
    printf("Marka: ");
    scanf("%255s", buffer);
    (*db)[*count]->brand = (char*)malloc(strlen(buffer) + 1);
    strcpy((*db)[*count]->brand, buffer);

    printf("Imya: ");
    scanf("%255s", buffer);
    (*db)[*count]->owner_first = (char*)malloc(strlen(buffer) + 1);
    strcpy((*db)[*count]->owner_first, buffer);

    printf("Familiya: ");
    scanf("%255s", buffer);
    (*db)[*count]->owner_last = (char*)malloc(strlen(buffer) + 1);
    strcpy((*db)[*count]->owner_last, buffer);

    printf("Mochnost: ");
    scanf_s("%d", &((*db)[*count]->power));

    printf("Probeg: ");
    scanf_s("%d", &((*db)[*count]->mileage));

    (*count)++;
}

void print_table(car** db, int count) {
    printf("\n");
    printf("+-------------------+-------------------+-------------------+----------+----------+\n");
    printf("| Marka             | Familiya          | Imya              | Mochnost | Probeg   |\n");
    printf("+-------------------+-------------------+-------------------+----------+----------+\n");
    
    for (int i = 0; i < count; i++) {
        printf("| %-17s | %-17s | %-17s | %8d | %8d |\n",
               db[i]->brand,
               db[i]->owner_last,
               db[i]->owner_first,
               db[i]->power,
               db[i]->mileage);
    }
    printf("+-------------------+-------------------+-------------------+----------+----------+\n");
    printf("Vsego mashin: %d\n\n", count);
}

void free_all_cars(car** db, int count) {
    if (!db) return;
    
    for (int i = 0; i < count; i++) {
        if (db[i]) {
            // Освобождаем строки
            free(db[i]->brand);
            free(db[i]->owner_last);
            free(db[i]->owner_first);
            
            // Зануляем указатели (защита от висячих указателей)
            db[i]->brand = NULL;
            db[i]->owner_last = NULL;
            db[i]->owner_first = NULL;
            
            // Освобождаем структуру
            free(db[i]);
            db[i] = NULL;
        }
    }
    free(db);
}