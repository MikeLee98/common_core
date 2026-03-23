#include <stdlib.h>
#include <stdio.h>

void print_solutions(int *positions, int n)
{
    int i = 0;

    while (i < n)
    {
        printf("%d", positions[i++]);
        if (i < n)
            printf(" ");
    }
    printf("\n");
}

int is_valid(int *positions, int row, int col)
{
    int i = 0;

    while (i < row)
    {
        if (col == positions[i] || col == positions[i] - (row - i) || col == positions[i] + (row - i))
            return (0);
        i++;
    }
    return (1);
}

void place_queens(int n, int *positions, int row)
{
    int col = 0;

    if (row == n)
    {
        print_solutions(positions, n);
        return ;
    }
    while (col < n)
    {
        if (is_valid(positions, row, col))
        {
            positions[row] = col;
            place_queens(n, positions, row + 1);
        }
        col++;
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    int n = atoi(av[1]);
    int positions[n];

    place_queens(n, positions, 0);
    return (0);
}
