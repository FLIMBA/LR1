#include <bd.hpp>
#include <cstdio>
#include <console.h>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>

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

void find_by_brand(car** db, int count, const char* target_brand) {
    // 1. Временный массив указателей (максимум count элементов)
    car** results = (car**)malloc(count * sizeof(car*));
    int found_count = 0;
    
    // 2. Поиск подходящих машин
    for (int i = 0; i < count; i++) {
        if (strcmp(db[i]->brand, target_brand) == 0) {
            results[found_count] = db[i];  // сохраняем УКАЗАТЕЛЬ, не копируем!
            found_count++;
        }
    }
    
    // 3. Вывод результата
    if (found_count == 0) {
        printf("Машины марки '%s' не найдены.\n", target_brand);
    } else {
        printf("Найдено машин: %d\n", found_count);
        print_table(results, found_count);  // переиспользуем функцию!
    }
    
    // 4. Освобождаем временный массив
    free(results);
}

int compare_owners(const void* a, const void* b) {
    //printf("Vhod Comp: %d, %d \n", a, b);
    // a и b — указатели на элементы массива (Car**)
    car* car_a = *(car**)a;  // получаем Car* из Car**
    car* car_b = *(car**)b;
    
    // Сравниваем фамилии
    int last_cmp = strcmp(car_a->owner_last, car_b->owner_last);
    if (last_cmp != 0) return last_cmp;
    
    // Если фамилии равны — сравниваем имена
    return strcmp(car_a->owner_first, car_b->owner_first);
}

void find_by_mileage(car** db, int count, int min_mileage) {
    //printf("Vhod : %d, %d, %d \n", db, count, min_mileage);
    // 1. Временный массив подходящих машин
    car** results = (car**)malloc(count * sizeof(car*));
    int found = 0;
    
    // 2. Отбираем машины с пробегом > min_mileage
    //printf("results: \n");
    for (int i = 0; i < count; i++) {
        if (db[i]->mileage > min_mileage) {
            //printf("%d", db[0]);
            results[found++] = db[i];
            //printf("%d", results[found-1]);
        }
    }
    if (found == 0) {
        printf("Нет машин с пробегом больше %d\n", min_mileage);
        free(results);
        return;
    }
    
    // 3. СОРТИРУЕМ по фамилии и имени
    qsort(results, found, sizeof(car*), compare_owners);
    
    //4. Выводим результат
    printf("\n=== VLADELCU S PROBEGOM > %d (%d chel.) ===\n", min_mileage, found);
    for (int i = 0; i < found; i++) {
        printf("%d. %s %s (%s, probeg: %d)\n",
               i + 1,
               results[i]->owner_last,
               results[i]->owner_first,
               results[i]->brand,
               results[i]->mileage);
    }
    printf("\n=== VLADELCU S PROBEGOM > %d (%d chel.) ===\n", min_mileage, found);
    print_table(results, found);
    free(results);
}