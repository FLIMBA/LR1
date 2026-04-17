#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <clocale>
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

using namespace std;

#define SIZE 20 
#define COL 5

using namespace std;

int main()
{
	//setlocale(LC_ALL, "")
	//setlocale(0, "Russian");
	char s1[80], s2[80];
	int k = 0, k1 = 0, k2 = 0, i;
	// ввод строк с клавиатуры
	cout << "\nstr1->"; fgets(s1, 80, stdin);
	cout << "\nstr2->";	fgets(s2, 80, stdin);
	// определение длины строк
	cout << "Длина строки 1: " << strlen(s1) << endl;
	cout << "Длина строки 2: " << strlen(s2) << endl;
	// сравнение строк	
	if (!strcmp(s1, s2)) cout << "Строки равны" << endl;
	else {
		cout << "Строки не равны: ";
		if (strcmp(s1, s2) > 0) cout << "cтрока1 больше строки2" << endl;
		else cout << "cтрока2 больше строки1" << endl;
	}
	// объединение строк
	strcat(s1, s2);
	printf("%s\n", strcat(s1, s2));
	// поиск эталона-символа в строке
	if (strchr(s1, '!')) cout << "! есть в " << s1 << endl;
	cout << "символ р  строит на " << (strchr(s1, 'р') - s1 + 1) << " месте" << endl;
	// поиск эталона-строки в строке
	if (strstr(s1, "ро")) cout << "ро есть в " << s1 << endl;
	// копирование
	strncpy(s1, s2, 3);	// копируем 3 символа из s2 в s1	
	strcpy(s2, "Копирование!");
	cout << "s1:  " << s1 << endl;
	cout << "s2:  " << s2 << endl;
	return 0;
}

/*
int main() {
	const int k = 1500;	// максимальная сумма массива
	const int col = 5;	// число колонок при выводе массива
	int dig[1000], * p, s = 0, i;
	//массив заполняется, пока его сумма не превышает k
	for (p = dig; s < k; p++)
	{
		*p = rand() % 1000;	// запись элемента массива
		s = s + *p;		// подсчет суммы массива
	}
	*p = 1111;	// запись граничного значения
	// Массив печатается до тех пор, пока элемент не равен 1111.
	for (i = 0, p = dig; *p != 1111; p++, i++)
	{
		printf("%d", *p);
		if ((i + 1) % col) printf("\t");
		else		  printf("\n");
	}
	return 0;
}
*/