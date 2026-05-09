#include <console.h>
#include <cstdlib>
#include <cstdio>

void clear_console() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void print_menu() {
    clear_console();
    printf("=-------------------------------------=\n");
    printf("|       БАЗА ДАННЫХ АВТОМОБИЛЕЙ       |\n");
    printf("|-------------------------------------|\n");
    printf("|  1. Добавить машину                 |\n");
    printf("|  2. Печать всех машин в табл. виде  |\n");
    printf("|  3. Найти по марке                  |\n");
    printf("|  4. Найти по пробегу (> задан.)     |\n");
    printf("|  5. Выход из программы              |\n");
    printf("=-------------------------------------=\n");
    printf("Выберите пункт: ");
}

void wait_for_key() {
    printf("\nНажмите Enter для продолжения...");
    while (getchar() != '\n');  // очищаем буфер
    getchar();  // ждём Enter
}