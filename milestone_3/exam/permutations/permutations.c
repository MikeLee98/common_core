#include <stdio.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

void backtrack(char *in, char *out, int *used, int depth, int len)
{
	int i;

	if (depth == len)
	{
		puts(out);
		return;
	}
	i = 0;
	while (i < len)
	{
		if (!used[i])
		{
			used[i] = 1;
			out[depth] = in[i];
			backtrack(in, out, used, depth + 1, len);
			used[i] = 0;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	int len = ft_strlen(av[1]);
	char out[len + 1];
	int used[len];
	int i = 0;

	while (i < len)
		used[i++] = 0;
	out[len] = '\0';
	backtrack(av[1], out, used, 0, len);
	return (0);
}
