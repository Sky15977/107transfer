/*
** EPITECH PROJECT, 2022
** transfer.h
** File description:
** dico func
*/

#include <stdio.h>

#ifndef TRANSFER_H
    #define TRANSFER_H

    #include "my.h"
    #include <unistd.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stddef.h>

    #define TRUE (0)
    #define FALSE (1)
    #define ERROR (84)
    #define SUCCES (0)

    typedef struct transfer_s {
        int ac;
        char **tab;
    } transfer_t;

//error.c
    int manage_error(void);
    int manage_usage(void);

//getnbr_n.c
    bool operation(char const *str, int i, bool statutC);
    int getnbr_n(char const *str, int i);

//process.c
    int my_strlen_star(char const *str, int i);
    char *my_str_dup_star(char *s1, int i);
    double polynome(char **tab, double x);
    int process_transfer(int ac, char **av);

//str_dup.c
    char *my_str_dup_s(char *s1);
    char **my_tab_str_copy(char **buff, char **tab);
    char **tab_copy_plus(char **tab, char *str);

#endif
