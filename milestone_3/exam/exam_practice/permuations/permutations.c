#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

void permutation(char *original, char *solution, int *used, int solution_index, int len)
{
    int i = 0;

    if (solution_index == len)
    {
        puts(solution);
        return ;
    }
    while (i < len)
    {
        if (!used[i])
        {
            used[i] = 1;
            solution[solution_index] = original[i];
            permutation(original, solution, used, solution_index + 1, len);
            used[i] = 0;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    int len = ft_strlen(av[1]);
    char solution[len + 1];
    int used[len];
    int i = 0;

    while (i < len)
    {
        used[i] = 0;
        i++;
    }
    solution[len] = '\0';
    permutation(av[1], solution, used, 0, len);
    return (0);
}
