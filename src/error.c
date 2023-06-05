/*
** EPITECH PROJECT, 2023
** error.c
** File description:
** error
*/

#include "transfer.h"

int manage_error(void)
{
    my_putstr("./107transfer: bad arguments\n");
    my_putstr("retry with -h\n");
    exit(ERROR);
}

int manage_usage(void)
{
    my_putstr("USAGE\n   ./107transfer [num den]+\n\nDESCRIPTIONS\n   num\t");
    my_putstr("    polynomial numerator defined by its coefficients\n   den");
    my_putstr("\t    polynomial denominator defined by its coefficients\n\n");
    exit(SUCCES);
}
