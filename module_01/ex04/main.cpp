#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

void	simulateReplace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream firstFile(filename.c_str());
	if (!firstFile.is_open())
	{
		std::cout << "File not found" << std::endl;
		return ;
	}
	
	std::string	buffer;
	std::ofstream secondFile((filename + ".replace").c_str());
	while (std::getline(firstFile, buffer))
	{
		int	pos = buffer.find(s1);
		if (pos != -1)
		{
			buffer.erase(pos, (int)s1.length());
			buffer.insert(pos, s2);
		}
		secondFile << buffer << std::endl;
	}
	firstFile.close();
	secondFile.close();
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "Wrong nbr of parameters" << std::endl;
	else
		simulateReplace(argv[1], argv[2], argv[3]);
	return (0);
}
