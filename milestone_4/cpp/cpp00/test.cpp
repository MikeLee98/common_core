#include <sstream>
#include <iostream>
#include <string>

int main(void)
{
	std::string num_str = "1-a-10"; 
	std::stringstream iss_one(num_str);

	int num1, num2, num3 = 2;
	char c1 = 'z', c2 = 'j';

	iss_one >> num1 >> c1 >> num2 >> c2 >> num3;
	std::cout << num1 << c1 << num2 << c2 << num3 << std::endl;
}
