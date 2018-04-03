/*
** EPITECH PROJECT, 2018
** my cook
** File description:
** int to string for the time
*/

#include "proto.h"

void change_string_and_i(int *i, char *string)
{
	if (*i == 2) {
		string[0] = '0';
		*i = 1;
	} else if (*i == 1) {
		string[0] = '0';
		string[1] = ':';
		string[2] = '0';
		*i = 3;
	} else
		*i = 0;
}

void manage_number(int *number, int *result)
{
	*number = *number / 10;
	while (*number >= 1) {
		*number = *number / 10;
		*result = *result * 10;
	}
}

char *change_time(int nb)
{
	int module = 0;
	int result = 1;
	int number = nb;
	int i = find_size(nb);
	char *string = malloc(sizeof(char) * 5);

	manage_number(&number, &result);
	change_string_and_i(&i, string);
	for (; result >= 1; i++) {
		if (i == 1)
			string[i] = ':';
		else {
			number = nb / result;
			module = number % 10;
			result = result / 10;
			number = module + 48;
			string[i] = number;
		}
	}
	string[i] = '\0';
	return (string);
}
