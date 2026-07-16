#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int sum(char *s, int *i);

// Function to evaluate a product of numbers in the expression
int nbr(char *s, int *i)
{
// Initialize the result to 0
	int a = 0;
// If the current character is a digit, convert it to an integer and return it
	if (isdigit(s[*i]))
	{
// Convert the character to an integer
		a = s[*i] - '0';
// Move to the next character
		(*i)++;
// Return the integer value
		return (a);
	}
// If the current character is an opening parenthesis, evaluate the expression inside the parentheses
	while (s[*i] == '(')
	{
// Move past the opening parenthesis
		(*i)++;
// Evaluate the sum of products inside the parentheses
		a = sum(s, i);
// Move past the closing parenthesis
		(*i)++;
	}
// Return the evaluated value of the expression inside the parentheses
	return a;
}

// Function to evaluate a product of numbers in the expression
int product(char *s, int *i)
{
// Evaluate the first number or expression
	int a = nbr(s, i);
// Continue evaluating numbers or expressions while there are '*' operators
	while (s[*i] == '*')
	{
// Move past the '*' operator
		(*i)++;
// Evaluate the next number or expression and multiply it with the current product
		a *= nbr(s, i);
	}
// Return the final product
	return (a);
}

// Function to evaluate the sum of products in the expression
int sum(char *s, int *i)
{
// Evaluate the first product
	int a = product(s, i);
// Continue evaluating products while there are '+' operators
	while (s[*i] == '+')
	{
// Move past the '+' operator
		(*i)++;
// Evaluate the next product and add it to the sum
		a += product(s, i);
	}
// Return the final sum
	return (a);
}

// Function to parse the input expression and check for syntax errors
int parse(char *s)
{
// Check for unexpected tokens at the beginning of the expression
	if (*s == '+' || *s == '*' || *s == ')')
		return (printf("Unexpected token '%c'\n", *s), 0);
// Initialize a counter for opened parentheses
	int opened = 0;
// Iterate through the characters in the expression to check for syntax errors
	for (int i = 0; s[i]; i++)
	{
// Check for unexpected tokens based on the current character and the next character
		if (isdigit(s[i]) && (isdigit(s[i + 1]) || s[i + 1] == '('))
			return (printf("Unexpected token '%c'\n", s[i + 1]), 0);
// Check for unexpected tokens based on the current character and the next character
		if (s[i] == '+' || s[i] == '*')
		{
// Check for unexpected end of input or invalid tokens after '+' or '*'
			if (!s[i + 1])
				return (printf("Unexpected end of input\n"), 0);
// Check for unexpected tokens after '+' or '*'
			if (s[i + 1] == '+' || s[i + 1] == '*' || s[i + 1] == ')')
				return (printf("Unexpected token '%c'\n", s[i + 1]), 0);
		}
// Check for unexpected tokens based on the current character and the next character
		if (s[i] == '(')
		{
// Increment the counter for opened parentheses
			opened++;
// Check for unexpected end of input or invalid tokens after '('
			if (!s[i + 1])
				return (printf("Unexpected end of input\n"), 0);
// Check for unexpected tokens after '('
			if (s[i + 1] == '+' || s[i + 1] == '*' || s[i + 1] == ')')
				return (printf("Unexpected token '%c'\n", s[i + 1]), 0);
		}
// Check for unexpected tokens based on the current character and the next character
		if (s[i] == ')')
		{
// Decrement the counter for opened parentheses
			opened--;
// Check for unexpected end of input or invalid tokens after ')'
			if (opened < 0)
				return (printf("Unexpected token ')'\n"), 0);
// Check for unexpected tokens after ')'
			if (isdigit(s[i + 1]) || s[i + 1] == '(')
				return (printf("Unexpected token '%c'\n", s[i + 1]), 0);
		}
	}
// Check for any unclosed parentheses at the end of the expression
	if (opened > 0)
		return (printf("Unexpected end of input\n"), 0);
// If no syntax errors were found, return success
	return (1);
}
// Main
int main(int argc, char **argv)
{
// Check for the correct number of command-line arguments and validate the input expression
	if (argc != 2 || !parse(argv[1]))
		return (1);
// Initialize the index for parsing the expression
	int i = 0;
// Evaluate the expression and print the result
	printf("%d\n", sum(argv[1], &i));
}
