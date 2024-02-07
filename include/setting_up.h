/*
** EPITECH PROJECT, 2023
** header h
** File description:
** header for my setting up
*/

/*
** EPITECH PROJECT, 2023
** my_printf.h
** File description:
** header to include usefull data or prototypes functions
*/

#ifndef SETTING_UP
    #define SETTING_UP
    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <stdint.h>
    #include <stddef.h>
    #include <wchar.h>
    #include <sys/stat.h>
int my_strlen(char const *str);
int my_intlen(long nb);
int my_getnbr(char const *str);
int get_size(char **av);
char **get_map_pattern(char **av);
int verify(char **av);
int pattern(char **av);
void setting_up(char **world, int len, int line);
int open_file(char *buffer, char **world, int fd, char **av);
char **get_map(char *buffer, int len);
int len_line(char *str , int len);


#endif
