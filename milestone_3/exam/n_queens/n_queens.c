#include <stdio.h>
#include <stdlib.h>

void print_solution(int *positions, int n)
{
    int i = 0;
    while (i < n)
    {
        printf("%d", positions[i]);
        if (i < n - 1)
            printf(" ");
        i++;
    }
    printf("\n");
}

int is_valid(int *positions, int row, int pos)
{
    int i = row - 1;
    while (i >= 0)
    {
        int t = positions[i];

        if (pos == t || pos == t + (row - i) || pos == t - (row - i))
            return (0);
        i--;
    }
    return (1);
}

void place_queens(int n, int *positions, int row)
{
    int pos = 0;

    if (row == n)
    {
        print_solution(positions, n);
        return;
    }
    while (pos < n)
    {
        if (is_valid(positions, row, pos))
        {
            positions[row] = pos;
            place_queens(n, positions, row + 1);
        }
        pos++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    int n = atoi(argv[1]);
    int positions[n];

    place_queens(n, positions, 0);
    return 0;
}
