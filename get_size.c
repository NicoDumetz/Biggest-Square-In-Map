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

    if (my_getnbr(av[1]) <= 0)
        return 84;
    if (my_strlen(av[2]) == 0)
        return 84;
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

int verify_size(char *buffer)
{
    int compt = 0;

    for (int i = my_intlen(my_getnbr(buffer)) + 1; buffer[i]; i++) {
        if (buffer[i] == '\n')
            compt++;
    }
    if ( compt != my_getnbr(buffer))
        return 84;
}

static int verify_file(char *buffer)
{
    for (int i = my_getnbr(buffer) + 1; buffer[i]; i++)
        if (buffer[i] != 'o' && buffer[i] != '.' && buffer[i] != '\n')
            return 84;
}

int open_file(char *buffer, char **world, int fd, char **av)
{
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return 84;
    read(fd, buffer, get_size(av) + 1);
    if (my_getnbr(buffer) <= 0 || verify_size(buffer) == 84)
        return 84;
    if (verify_file(buffer) == 84)
        return 84;
    world = get_map(buffer, my_getnbr(buffer));
    setting_up(world, my_getnbr(buffer), len_line(buffer, my_getnbr
    (buffer)));
    close(fd);
}
