#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *ft_strjoin(char *s1, char *s2)
{
    int size1;
    int size2;
    char *s3;

    if (!s1)
        size1 = 0;
    else
        size1 = strlen(s1);
    size2 = strlen(s2);
    s3 = calloc(size1 + size2 + 1, 1);
    if (!s3)
        return (NULL);
    if (s1)
        memmove(s3, s1, size1);
    memmove(s3 + size1, s2, size2);
    free(s1);
    return (s3);
}

int main(int ac, char **av)
{
    char *line = NULL;
    static char buffer[1000];
    int counter = 0;
    int i = 0;
    char *tmp = NULL;

    if (ac != 2 || av[1][0] == '\0')
        return (1);
    if (ac == 2)
    {
        while ((counter = read(0, buffer, 999)))
    }
}
