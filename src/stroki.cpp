//#include "../.h/stroki.h"
#include <stroki.h>

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