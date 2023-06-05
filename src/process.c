/*
** EPITECH PROJECT, 2023
** process.c
** File description:
** process
*/

#include "transfer.h"

int my_strlen_star(char const *str, int i)
{
    int count = 0;

    for (;str[i] != '\0' && str[i] != '*'; i ++)
        count++;
    return (count);
}

char *my_str_dup_star(char *s1, int i)
{
    int size = my_strlen_star(s1, i);
    char *s2 = malloc(sizeof(char) * (size + 1));
    int j = 0;

    for (; s1[i] != '\0' && s1[i] != '*'; i++) {
            s2[j] = s1[i];
            j ++;
    }
    s2[size] = '\0';
    return s2;
}

double polynome(char **tab, double x)
{
    int count = 0;
    double result = 0;

    for (; tab[count]; count++);
    count --;
    result = atoi(tab[count]);
    count --;
    for(; count != 0; count --)
        result = result * x + atoi(tab[count]);
    return result;
}

int verif_numb(char *str)
{
    for (int i = 0; str[i] != '\0';i ++)
        if (str[i] != '-' && str[i] != '*' && (str[i] < '0' || str[i] > '9'))
            return 84;
    return 0;
}

int process_transfer(int ac, char **av)
{
    char *str;
    char ***tab = malloc(sizeof(char **) * ac);
    double F;
    double res;

    for (int j = 0; av[j + 1]; j ++) {
        tab[j] = malloc(sizeof(char *));
        tab[j][0] = my_str_dup_star("test", 0);
        if (av[j + 1][((my_strlen(av[j + 1])) - 1)] == '*' || verif_numb(av[j + 1]) == 84)
            return 84;
        for (int i = 0; av[j + 1][i] != '\0';) {
            str = my_str_dup_star(av[j + 1], i);
            tab[j] = tab_copy_plus(tab[j], str);
            free(str);
            while (av[j + 1][i] != '\0' && av[j + 1][i] != '*')
                i ++;
            if (av[j + 1][i] == '*')
                i ++;
        }
    }
    tab[ac - 1] = NULL;
    int i;
    for (double x = 0; x <= 1.001; x += 0.001) {
        F = 1;
        i = 0;
        for (; i + 1 <= ac - 1; i += 2) {
             res = polynome(tab[i], x);
             F = F * res;
             res = polynome(tab[i + 1], x);
             F = F / res;
        }
        if (res == 0)
            return 84;
        printf("%.3f -> %.5f\n", x, F);
    }
    return 0;
}
