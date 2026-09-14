/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 12:43:22 by marioro2          #+#    #+#             */
/*   Updated: 2026/09/14 17:35:21 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	size_t pos;

	pos = 0;
	if (argc != 4)
		return (1);
	if (std::string(argv[2]).empty())
		return (1);
	std::ifstream inputFile(argv[1]);
	if (!inputFile)
		return (1);
	std::istreambuf_iterator<char> begin(inputFile);
	std::istreambuf_iterator<char> end;
	std::string content(begin, end);
	std::string outputName = std::string(argv[1]) + ".replace";
	std::ofstream outputFile(outputName.c_str());
	if (!outputFile)
		return (1);
	pos = content.find(argv[2]);
	while (pos != std::string::npos)
	{
		std::string before = content.substr(0, pos);
		before += argv[3];
		before += content.substr(pos + std::string(argv[2]).size());
		content = before;
		pos = content.find(argv[2], pos + std::string(argv[3]).size());
	}
	outputFile << content;
	return (0);
}
