/*
** EPITECH PROJECT, 2017
** int to char
** File description:
** transform int to char*
*/

#include <stdlib.h>
#include "my.h"

int find_size(int nb)
{
	int module = 0;
	int result = 1;
	int number = nb;
	int i = 0;

	number = number / 10;
	while (number >= 1) {
		number = number / 10;
		result = result * 10;
	}
	while (result >= 1) {
		number = nb / result;
		module = number % 10;
		result = result / 10;
		number = module + 48;
		i++;
	}
	return (i);
}

char *int_to_string(int nb)
{
	int module = 0;
	int result = 1;
	int number = nb;
	int i = find_size(nb);
	char *string = malloc(sizeof(char) * (i + 1));

	number = number / 10;
	while (number >= 1) {
		number = number / 10;
		result = result * 10;
	}
	string[0] = '$';
	for (i = 1; result >= 1; i++) {
		number = nb / result;
		module = number % 10;
		result = result / 10;
		number = module + 48;
		string[i] = number;
	}
	string[i] = '\0';
	return (string);
}
