/*
** EPITECH PROJECT, 2023
** settings uo
** File description:
** find largest square on board
*/
#include "include/setting_up.h"

static void free_array(char **world)
{
    for (int i = 0; world[i]; i++) {
        free(world[i]);
    }
    free(world);
}

int len_line(char *str , int len)
{
    int compt = 0;
    int i = (my_intlen(len) + 1);

    for (i; str[i] != '\n'; i++) {
        if ( str[i] == '.' || str[i] == 'o')
            compt++;
    }
    return compt;
}

char **get_map(char *buffer, int len)
{
    char **world;
    int i;
    int line = len_line(buffer, len);
    int j = my_intlen(len) + 1;

    world = malloc(sizeof(char *) * (len + 1));
    for (i = 0; buffer[j] != '\0'; i++) {
        world[i] = malloc(sizeof(char) * (line + 1));
        for ( int k = 0; buffer[j] != '\n'; j++) {
            world[i][k] = buffer[j];
            k++;
        }
        world[i][line] = '\0';
        j++;
    }
    world[i] = 0;
    return world;
}

static int min(int a, int b, int c)
{
    if ( a <= b && a <= c)
        return a;
    if ( b <= c && b <= a)
        return b;
    if ( c <= a && c <= b)
        return c;
}

static void draw_square(char **world, int max, int max_i, int max_j)
{
    for (int i = max_i; i > max_i - max; i--) {
        for (int k = max_j; k > max_j - max; k--) {
            world[i][k] = 'x';
        }
    }
    for (int i = 0; world[i]; i++) {
        write(1, world[i], my_strlen(world[i]));
        write(1, "\n", 1);
    }
    free_array(world);
}

static int **set_matrix(int **matrix, int len, int line)
{
    matrix = malloc(sizeof(int *) * (len + 2));
    for (int i = 0; i < len + 1; i++)
        matrix[i] = malloc(sizeof(int) * (line + 2));
    for (int i = 0; i < line + 1; i++)
        matrix[0][i] = 0;
    for ( int j = 0; j < len + 1; j++)
        matrix[j][0] = 0;
    return matrix;
}

void setting_up(char **world, int len, int line)
{
    int **matrix;
    int max_i = 0;
    int max_j = 0;
    char temp;
    int max = 0;

    matrix = set_matrix(matrix, len, line);
    for (int i = 1; i < len + 1; i++) {
        for ( int j = 1; j < line + 1; j++) {
            matrix[i][j] = world[i - 1][j - 1] == '.' ? 1 +
            min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) : 0;
            max_j = matrix[i][j] > max ? j : max_j;
            max_i = matrix[i][j] > max ? i : max_i;
            max = matrix[i][j] > max ? matrix[i][j] : max;
        }
    }
    draw_square(world, max, max_i - 1, max_j - 1);
    free(matrix);
}

char **get_map_pattern(char **av)
{
    int len = my_getnbr(av[1]);
    char *pattern = av[2];
    char **world;
    int i;
    int j = 0;

    world = malloc(sizeof(char *) * (len + 1));
    for (i = 0; i < len; i++) {
        world[i] = malloc(sizeof(char) * (len + 1));
        for ( int k = 0; k < len; k++) {
            world[i][k] = pattern[j];
            j = pattern[j + 1] == '\0' ? 0 : j + 1;
        }
        world[i][len] = '\0';
    }
    world[i] = 0;
    return world;
}

static int error_handling(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return 84;
    if ( my_getnbr(av[1]) < 0)
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    char *buffer;
    int fd;
    char **world;

    if (error_handling(ac, av) == 84)
        return 84;
    buffer = malloc(sizeof(char) * (get_size(av) + 1));
    if (ac == 2) {
        fd = open(av[1], O_RDONLY);
        read(fd, buffer, get_size(av) + 1);
        if (my_getnbr(buffer) == 0)
            return 84;
        world = get_map(buffer, my_getnbr(buffer));
        setting_up(world, my_getnbr(buffer), len_line(buffer, my_getnbr
        (buffer)));
        close(fd);
    } else {
        if ( pattern(av) == 84)
            return 84;
    }
}
