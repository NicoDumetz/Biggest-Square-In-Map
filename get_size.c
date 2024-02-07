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
