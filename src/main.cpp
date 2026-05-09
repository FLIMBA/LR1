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
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    car** database = NULL;  // указатель на массив указателей на Car
    int size = 0;           // сколько сейчас машин
    add_car(&database, &size);
    system("pause");
    return 0;
}
