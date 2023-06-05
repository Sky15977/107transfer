/*
** EPITECH PROJECT, 2023
** str_dup.c
** File description:
** copy char **
*/

#include "transfer.h"

char *my_str_dup_s(char *s1)
{
    char *s2 = malloc(sizeof(char) * (my_strlen(s1) + 1));

    for (int i = 0; s1[i]; i++)
            s2[i] = s1[i];
    s2[my_strlen(s1)] = '\0';
    return s2;
}

char **my_tab_str_copy(char **buff, char **tab)
{
    int count = 0;

    for (; buff[count]; count++);
    tab = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; buff[i]; i ++)
        tab[i] = my_str_dup_s(buff[i]);
    return tab;
}

char **tab_copy_plus(char **tab, char *str)
{
    char **buff = NULL;
    int count = 0;

    buff = my_tab_str_copy(tab, buff);
    free_tab(tab);
    for (; buff[count]; count++);
    tab = malloc(sizeof(char *) * (count + 3));
    for (int i = 0; buff[i]; i ++)
        tab[i] = my_str_dup_s(buff[i]);
    tab[count] = my_str_dup_s(str);
    tab[count + 1] = NULL;
    tab[count + 2] = NULL;
    return tab;
}
