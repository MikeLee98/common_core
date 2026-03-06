#include <stdio.h>
#include <stdlib.h>

void build(int argc, char **argv, int index, char *buffer, int len)
{
    if (index >= argc)
        return;
    len += sprintf(buffer + len, "%s", argv[index]); // add current number to buffer
    printf("%s\n", buffer); // print current sequence
    build(argc, argv, index + 1, buffer, len); // recursive call (extend sequence)
    build(argc, argv, index + 1, "", 0); // restart sequence from next number
}

int main(int argc, char **argv)
{
    char buffer[1024] = {0};
    build(argc, argv, 1, buffer, 0);
    return 0;
}
