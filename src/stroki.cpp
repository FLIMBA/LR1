//#include "../.h/stroki.h"
#include <stroki.h>
#include <stdio.h>

int clwp(const char* str, int n, int len) {
	int count = 0;
	int word_len = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') {
			if (word_len > n) {
				count++;
			}
			word_len = 0;
		}
		else {
			word_len++;
		}
	}

	if (word_len > n) {
		count++;
	}
	return count;
}

void print_by_pages(const char* text, int str_len, int kol_str, int comlen){
	int g = 0;                  // текущая позиция в строке (от 0 до str_len-1)
	int current_line = 0;       // текущая строка на странице (от 0 до kol_str-1)
	int page = 1;               // текущая страница

	printf("=== page %d ===\n", page);

	for (int i = 0; i < comlen; i++) { //&& text[i] != '\0'
    	// Выводим символ
    	printf("%c", text[i]);
   		g++;
    
    	// Если достигли конца строки
    	if (g >= str_len || text[i] == '\n') {
        	printf("\n");       // переходим на новую строку
        	g = 0;              // сбрасываем позицию в строке
        	current_line++;     // увеличиваем счетчик строк на странице
        
        	// Если достигли конца страницы
        	if (current_line >= kol_str) {
            	page++;
            	printf("\n=== page %d ===\n", page);
            	current_line = 0;   // сбрасываем счетчик строк для новой страницы
        	}
    	}
	}	
	printf("\n");  // последний перевод строки
}