#include "../inc/header.h"

void mx_printinteger(int n) {
	char buffer[12];
	int i = 0;
	if (n == 0) {
		mx_printchar('0');
	} else if (n < 0) {
		if (n == -2147483648) {
			mx_printinteger(-214748364);
			mx_printinteger(8);
		} else {
			mx_printchar('-');
			mx_printinteger(-n);
		}
	} else {
		while (n != 0) {
			buffer[i++] = '0' + n % 10;
			n /= 10;
		}
		for (int j = i - 1; j >= 0; j--) {
			mx_printchar(buffer[j]);
		}
	}
}
