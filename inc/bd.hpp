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

#endif