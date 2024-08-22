#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

void simulateReplace(std::string filename, std::string s1, std::string s2)
{
    std::ifstream firstFile(filename.c_str());
    if (!firstFile.is_open())
    {
        std::cout << "File not found" << std::endl;
        return;
    }

    std::ofstream secondFile((filename + ".replace").c_str());
	if (!secondFile)
	{
		std::cout << "Error on the replace file" << std::endl;
		return ;
	}
	
    std::string line;
    while (std::getline(firstFile, line))
    {
        std::string result;
        size_t pos = 0;
        size_t found_pos;
        while ((line.find(s1, pos)) != std::string::npos)
        {
			found_pos = line.find(s1, pos);
            result.append(line, pos, found_pos - pos);
            result.append(s2);
            pos = found_pos + s1.length();
        }
        result.append(line, pos, std::string::npos);
        secondFile << result << std::endl;
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
