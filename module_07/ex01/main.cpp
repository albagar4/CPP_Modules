#include "iter.hpp"

int main(void) {
	{
		int nbrArray[10];
		for (int i = 0; i < 10; i++)
			nbrArray[i] = i + 3;
		ft_iter(nbrArray, 10, show_value);
	}
	{
		std::string strArray[10];
		for (int i = 0; i < 10; i++)
		{
			if (i % 2)
				strArray[i] = "even";
			else
				strArray[i] = "odd";
		}
		ft_iter(strArray, 10, show_value);
	}
	{
		char charArray[10];
		for (int i = 0; i < 10; i++)
			charArray[i] = 33 + i;
		ft_iter(charArray, 10, show_value);
	}
	return (0);
}
