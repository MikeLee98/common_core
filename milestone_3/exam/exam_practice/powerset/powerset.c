#include <stdlib.h>
#include <stdio.h>

void print_sets(int *subset, int subset_size)
{
    int i = 0;

    while (i < subset_size)
    {
        printf("%d", subset[i++]);
        if (i < subset_size)
            printf(" ");
    }
    printf("\n");
}

void find_sets(int target, int set_size, int *set, int *subset, int set_index, int subset_index, int sum)
{
    if (sum == target)
        print_sets(subset, subset_index);
    while (set_index < set_size)
    {
        subset[subset_index] = set[set_index];
        set_index++;
        find_sets(target, set_size, set, subset, set_index, subset_index + 1, sum + subset[subset_index]);
    }
}

int main(int ac, char **av)
{
    if (ac < 3)
        return (1);
    int set_size = ac - 2;
    int set[set_size];
    int subset[set_size];
    int i = 0;

    while (i < set_size)
    {
        set[i] = atoi(av[i + 2]);
        i++;
    }
    find_sets(atoi(av[1]), set_size, set, subset, 0, 0, 0);
    return (0);
}
