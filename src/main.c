/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "transfer.h"

void get_struct(transfer_t *tr, int ac, char **av)
{
    int i = 1;

    tr->ac = ac - 1;
    tr->tab = malloc(sizeof(char *) * ac);
    for (; av[i]; i++) {
        tr->tab[i - 1] = my_strdup(av[i]);
    }
}

void init_struct(transfer_t *tr)
{
    tr->ac = 0;
    tr->tab = NULL;
}

int main(int ac, char **av)
{
    transfer_t *tr = malloc(sizeof(transfer_t));

    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0))
        manage_usage();
    if (ac < 3 || (ac - 1) % 2 != 0)
        manage_error();
    init_struct(tr);
    get_struct(tr, ac, av);
    return process_transfer(ac, av);
}
