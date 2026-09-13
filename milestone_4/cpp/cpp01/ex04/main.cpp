/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mario <Mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 12:43:22 by marioro2          #+#    #+#             */
/*   Updated: 2026/09/14 00:04:21 by Mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	size_t pos;

	pos = 0;
	if (argc != 4)
		return (1);
	std::ifstream inputFile(argv[1]);
	if (!inputFile)
		return (1);
	std::istreambuf_iterator<char> begin(inputFile);
	std::istreambuf_iterator<char> end;
	std::string content(begin, end);
	std::ofstream outputFile(std::string(argv[1]) + ".replace");
	if (!outputFile)
		return (1);
	pos = content.find(argv[2]);
	while (pos != std::string::npos)
	{
		
	}
}
