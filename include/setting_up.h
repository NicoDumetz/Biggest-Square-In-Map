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

#endif
