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
#include <console.h>
#include <bd.hpp>

using namespace std;
// Ctrl + .

int main(int argc, char* argv[]){

    //setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    car** database = NULL;  // указатель на массив указателей на Car
    int size = 0;           // сколько сейчас машин
    int choice;             // выбор пользователя
    int probeg = 0;
    char buffer[256];
    //add_car(&database, &size);
    //print_table(database, size);
     do {
        print_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                clear_console();
                printf("=== DOBAVLENIE NOVOY MASHINU ===\n");
                add_car(&database, &size);
                printf("\n+! Mashuna dobavlena!\n");
                wait_for_key();
                break;
                
            case 2:
                clear_console();
                printf("=== SPISOK VSEH MASHIN ===\n");
                print_table(database, size);
                wait_for_key();
                break;

            case 3:
                clear_console();
                printf("=== NAYTI PO MARKE ===\n");
                printf("Vvedite marku avtomobilya: ");
                scanf("%255s", buffer);
                find_by_brand(database, size, buffer);
                wait_for_key();
                break;
            case 4:
                clear_console();
                printf("=== Nayti po probegu ( > zadan.) ===\n");
                printf("Vvedite probeg avtomobilya: ");
                scanf("%d", &probeg);
                find_by_mileage(database, size, probeg);
                wait_for_key();
                break;                 
            case 5:
                printf("\nVuhod iz programmu...\n");
                free_all_cars(database, size);
                database = NULL;
                size = 0;
                break;
                
            default:
                printf("Nevernuy vubor!\n");
                wait_for_key();
        }
    } while (choice != 5);
    system("pause");
    return 0;
}
