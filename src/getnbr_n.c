/*
** EPITECH PROJECT, 2022
** getnbr_n.c
** File description:
** my_getnbr
*/

#include "transfer.h"

bool operation(char const *str, int i, bool statutC)
{
    if (str[i] < 48 || 57 < str[i]) {
        if (str[i] == '+' || str[i] == '-') {
            statutC = false;
        } else {
            statutC = true;
        }
    }
    return (statutC);
}

int getnbr_n(char const *str, int i)
{
    int nb = 0;
    bool statutC = false;
    int statutN = 0;

    while (str[i] != '\0' && str[i] != '*') {
        statutC = operation(str, i, statutC);
        if (str[i] == '-')
            statutN ++;
        if (str[i] > 47 && str[i] < 58 && statutC == false) {
            nb += str[i] - 48;
            nb = nb * 10;
        }
        i ++;
    }
    nb = nb / 10;
    if (statutN % 2 != 0)
        nb = nb * -1;
    return (nb);
}
