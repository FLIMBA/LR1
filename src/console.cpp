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
    printf("|       BAZA DANNUH AVTOMOBILEY       |\n");
    printf("|-------------------------------------|\n");
    printf("|  1. Dobavit mashinu                 |\n");
    printf("|  2. Pechat machin v tabl. vide      |\n");
    printf("|  3. Nayti po marke                  |\n");
    printf("|  4. Nayti po probegu ( > zadan.)    |\n");
    printf("|  5. Vuhod iz programmu              |\n");
    printf("=-------------------------------------=\n");
    printf("Vaberite punct: ");
}

void wait_for_key() {
    printf("\nNazhmite Enter dlya prodolzheniya...");
    while (getchar() != '\n');  // очищаем буфер
    getchar();  // ждём Enter
}