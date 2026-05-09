#ifndef BD_H
#define BD_H

typedef struct{
    char* brand;       // марка
    char* owner_last;  // фамилия владельца
    char* owner_first; // имя владельца
    int power;         // мощность
    int mileage;       // пробег
} car;

void add_car(car*** db, int* count);
void print_table(car** db, int count);
void free_all_cars(car** db, int count);
void find_by_brand(car** db, int count, const char* target_brand);
int compare_owners(const void* a, const void* b);
void find_by_mileage(car** db, int count, int min_mileage);

#endif