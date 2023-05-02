#include <iostream>

int main()
{
    std::cout << "Love you so much!\nPress 'Enter' to exit";
	char input;
	
	if((input = getchar()) == '\n')
	{std::cout << "Exit success";}
	else
	{std::cout << "Exit failure";}
	return -1;
}