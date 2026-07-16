#include <stdio.h>

int parse (char* s)
{
	int i = 0;
	if (*s == '+' || *s == '*' || *s == ')')
		return (printf("Unexpected token '%c'\n", *s), 0);
	for
}

int main(int argc, char** argv)
{
	if (argc != 2 || !parse(argv[1]))
		return (1);
	int i = 0;
	printf("%d\n", sum(argv[i], &i));
}
