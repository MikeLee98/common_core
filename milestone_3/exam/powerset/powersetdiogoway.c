#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	print_set (int *set, int size)
{
	int i = 0;

	while (i < size)
	{
		printf("%d", set[i]);
		if (i < size - 1)
            printf(" ");
		i++;
	}
	printf("\n");
}

void	find_sets(int size, int *nums, int soma, int *set, int set_index, int index, int target)
{
	int i = index;

    while (i < size)
    {
        int next_soma = soma + nums[i];
        set[set_index] = nums[i];
        if (next_soma == target)
            print_set(set, set_index + 1);
        find_sets(size, nums, next_soma, set, set_index + 1, i + 1, target);
        i++;
    }
}

int main (int ac, char **av)
{
	int n = ac - 2;
	int soma = 0;
	int *nums = malloc (sizeof(int) * n);
	int *set = malloc (sizeof(int) * n);
	int i = 0;
	int target = atoi(av[1]);

	if (ac < 3)
		return 1;
	while (i < n)
	{
		nums[i] = atoi(av[i + 2]);
		i++;
	}
	if (target == 0)
		printf("\n");
	find_sets(n, nums, soma, set, 0, 0, target);
	free (set);
	free (nums);
	return 0;
}