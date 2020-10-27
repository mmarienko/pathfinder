#include "../inc/libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	unsigned long store = nbr;
	unsigned long hexSymbol;
	int counter = 0;
	int i;
	char *hex = NULL;

	if (nbr == 0) {
		hex = mx_strnew(1);
		hex[0] = 48;
		return hex;
	}
	while (store) {
		store = store / 16;
		counter++;
	}
	hex = mx_strnew(counter);
	store = nbr;
	i = counter - 1;
	while (store) {
		hexSymbol = store % 16;
		if (hexSymbol >= 0 && hexSymbol <= 9)
			hex[i] = hexSymbol + 48;
		else
			hex[i] = hexSymbol + 87;
		store = store / 16;
		i--; 
	}
	return hex;
}
