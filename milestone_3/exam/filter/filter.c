#define _GNU_SOURCE
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    static char buffer[1000000];
    char *filter;
    int i = 0;
    int bytes_read = 1;

    if (ac != 2 || av[1][0] == '\0')
        return (1);
    while (bytes_read > 0)
    {
        bytes_read = read(0, &buffer[i], 1);
        if (bytes_read == -1)
            return (perror("Error :"), 1);
        i++;
    }
    buffer[i] = '\0';
    i = 0;
    while (memmem(buffer, strlen(buffer), av[1], strlen(av[1])))
    {
        filter = memmem(buffer, strlen(buffer), av[1], strlen(av[1]));
        while (i < (int)strlen(av[1]))
        {
            filter[i] = '*';
            i++;
        }
        i = 0;
    }
    printf("%s", buffer);
    return (0);
}
