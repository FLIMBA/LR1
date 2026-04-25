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
//#include "../.h/stroki.h"
#include <stroki.h>

using namespace std;
// Ctrl + .

#define SIZE 20 
#define COL 5
#define LENGTH 1024
const int PAGE_L = 10;
const int STR_L = 10;



const int DLINA = 1000;
char s[DLINA];
int Klow = 0;
int word_l = 0;
int str_len = 8; 
int kol_str = 3;


int main(int argc, char* argv[])
{
	setlocale(0, "Russian");
	printf("Введите максимальную длинну слова: \t");
	scanf_s("%d", &word_l);
	printf("\nМаксимальна длинна слова: %d \n", word_l);
	char text[1000], q[100], * p;
	int i, len = 0, comlen = 0, k;
	// ВВОД ТЕКСТА В МАССИВ  text С КЛАВИАТУРЫ :
	// устанавливаем указатель p на начало массива text
	// цикл ввода заканчиваем, когда введена пустая строка
	// после записи очередной строки перемещаем указатель (+ длина строки)
	getchar();
	
	for (p = text, k = 0; ; p = p + len + 1, k++)
	{
		//fgets(q, sizeof(q), stdin);		// ввод строки с клавиатуры 
		cin.getline(q, sizeof(q));
		if(q[0] == '#'){
			break;
		}
		q[strcspn(q, "\0")] = ' ';
		strcpy(p, q); 	// копирование в text
		len = strlen(q);	// определение длины строки
		comlen += len;	// общая длина текста
	}

	// for (p = text, k = 0; q[0] != '#' && q[1] != '\n'; p = p + len + 1, k++)
	// {
	// 	//fgets(q, sizeof(q), stdin);		// ввод строки с клавиатуры 
	// 	cin.getline(q, sizeof(q));
	// 	//printf("%s", q); 
	// 	strcpy(p, q); 	// копирование в text
	// 	q[strcspn(q, "\n")] = '\0';
	// 	len = strlen(q);	// определение длины строки
	// 	comlen += len;	// общая длина текста
	// }
	
	for (i = 0; i < comlen; i++){
		if (islower(text[i])) {
			Klow++;
		}
		//cout << text[i];
	}
	printf("Кол-во строчных букв: %d", Klow);
	cout << endl;
	printf("Кол-во слов > %d: %d", word_l, clwp(text, word_l, comlen));
	cout << endl;

	//testing a%b
	//cout << 0%3 << 1%3 << 2%3 << 3%3 << '\n'; // 0 1 2 0
	// int j = 7;
	// printf("j = %d", (j+1)%str_len); cout << '\n';
	// j = 15;
	// printf("j = %d", (j+1)%str_len); cout << '\n';
	// cout << '\n';

	//vuvod stroki
	print_by_pages(text, str_len, kol_str, comlen);	
	return 0;
}


//int main(int argc, char* argv[]) {
//	size_t len = 0;
//	setlocale(0, "Russian");
//	while (fgets(s, sizeof(s), stdin)) {
//		len = strlen(s); // or size_t strlen() возвращает длину строки
//		if (len > 0 && s[len - 1] == '\n') {
//			s[len - 1] = '\n';
//		}
//		if (strcmp(s, "#") == 0) break;
//		printf("Введённая строка: %s\n", s);
//	}
//	for (int i = 0; i < len; i++) {
//		printf("%s", s);
//	}
//	return 0;
//}

//void initmas(double *p, int n, int i);
//void printmas(double *p, int n, int k);
//double summas(double *p, int n);
//void spec(double p[], int n, int K, double *l);
//double sumP(double* p, double* tn, double* tk);
//double sumP1(double* p, int tn, int tv);
//
//int main() {
//	int K = 0;
//	int* k = &K;
//	printf("%d", *k);
//	setlocale(0, "Russian");
//	//printf("Введите длину массива Y: \t"); //ввести 10
//	//scanf_s("%d", &R);
//	K = 10;
//	double X[SIZE];
//	double Y[SIZE];
//	initmas(X, SIZE, 1);	// заполнение массива X
//	initmas(Y, SIZE, 0);	// заполнение массива Y нулями
//	printmas(X, SIZE, COL);
//
//
//	spec(Y, SIZE, K, X);
//	printmas(Y, SIZE, COL);
//	//double summpred = sumP(X, &X[0], &X[2]);
//	//printf("\n%lf", summpred);
//	return 0;
//}
//
//void spec(double p[], int n, int K, double *l) {
//	double *vrY;
//	double *vrX;
//	vrX = l;
//	for (int i = 0; i < SIZE-K; i++) { //SIZE-K or n-K
//		p[i] = (sumP1(vrX, i, K + i)/10);
//		//p[i] = 7.9;
//	}
//	/*for (vrY = p; vrY < (p + n); vrY++) {
//		if (K + g + vrX == SIZE) {
//			*vrY = (1 / K) * sumP(vrX, g + vrX, K + vrX + g);
//			g++;
//		}
//	}*/
//}
//
//double sumP(double* p, double* tn, double* tk) {
//	double sm;
//	double* vr;	// рабочий указатель(локальная переменная)
//	for (sm = 0, vr = tn; vr <= tk; vr++)
//		sm = sm + *vr;
//	return sm;
//}
//
//double sumP1(double* p, int tn, int tv) {
//	double sm;	
//	double* vr;	// рабочий указатель(локальная переменная)
//	for (sm = 0, vr = &p[tn]; vr <= &p[tv] ; vr++)
//		sm = sm + *vr;	
//	return sm;	
//}
//
//void initmas(double* p, int n, int i)
//{
//	if (i == 1)
//	{
//		double* vr;
//		time_t k;
//		srand(time(&k));
//		for (vr = p; vr < (p + n); vr++)
//			*vr = rand() % 100 / 3.5;
//	}
//	if (i == 0) {
//		double* vr;
//		for (vr = p; vr < (p + n); vr++)
//			*vr = 0;
//	}
//}
//
//void printmas(double* p, int n, int k){
//	int i;
//	for (i = 0; i < n; i++, p++)
//	{
//		printf("%8.2f", *p);
//		if ((i + 1) % k) printf("\t");
//		else		  printf("\n");
//	}
//	printf("\n");
//}
//
//double summas(double* p, int n)
//{
//	double sm;	//сумма (локальная переменная)
//	double* vr;	// рабочий указатель(локальная переменная)
//	for (sm = 0, vr = p; vr < (p + n); vr++)
//		sm = sm + *vr;	// суммирование массива
//	return sm;	// возврат суммы в вызывающую программу
//}