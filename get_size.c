/*
** EPITECH PROJECT, 2023
** get_size
** File description:
** get_size of files
*/

#include "include/setting_up.h"

int get_size(char **av)
{
    struct stat file;
    int size;

    if (stat(av[1], &file) == -1)
        return 84;
    size = file.st_size;
    return size;
}

int verify(char **av)
{
    char **world = get_map_pattern(av);

    for (int i = 0; av[2][i]; i++) {
        if ( av[2][i] != '.' && av[2][i] != 'o')
            return 84;
    }
    return 0;
}

int pattern(char **av)
{
    if (verify(av) == 84)
        return 84;
    setting_up(get_map_pattern(av), my_getnbr(av[1]), my_getnbr(av[1]));
}
