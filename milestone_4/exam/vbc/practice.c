#include <ctype.h>
#include <stdio.h>

int sum(char *s, int *i);

int nbr(char *s, int *i)
{
	int a = 0;
	if (isdigit(s[*i]))
	{
		a = s[*i] - '0';
		(*i)++;
		return (a);
	}
	while(s[*i] == '(')
	{
		(*i)++;
		a = sum(s, i);
		(*i)++;
	}
	return (a);
}

int product(char *s, int *i)
{
	int a = nbr(s, i);
	while(s[*i] == '*')
	{
		(*i)++;
		a *= nbr(s, i);
	}
	return (a);
}

int sum(char *s, int *i)
{
	int a = product(s, i);
	while(s[*i] == '+')
	{
		(*i)++;
		a += product(s, i);
	}
	return (a);
}

int    err(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
	return (0);
}

int parse(char *s)
{
	int i = 0;
	int opened = 0;

	if (s[i] == '+' || s[i] == '*')
		return (err(s[i]));
	while (s[i])
	{
		if (isdigit(s[i]) && (isdigit(s[i + 1]) || s[i + 1] == '('))
			return (err(s[i + 1]));
		if ((s[i] == '+' || s[i] == '*') && (s[i + 1] == '+' || s[i + 1] == '*' || s[i + 1] == ')' || !s[i + 1]))
			return (err(s[i + 1]));
		if (s[i] == '(')
		{
			opened++;
			if (s[i + 1] == '+' || s[i + 1] == '*' || s[i + 1] == ')')
				return (err(s[i + 1]));
		}
		if (s[i] == ')')
		{
			if (--opened < 0)
				return (err(s[i]));
			if (isdigit(s[i + 1]) || s[i + 1] == '(')
				return (err(s[i + 1]));
		}
		i++;
	}
	if (opened > 0)
		return (err(0));
	return (1);
}

int main(int argc, char** argv)
{
	int i = 0;
	if (argc != 2 || !parse(argv[1]))
		return (1);
	printf("%d\n", sum(argv[1], &i));
}
