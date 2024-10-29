#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <stdint.h>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <time.h>

class PmergeMe {
private:
	PmergeMe();
	int *nbr_array;
	int size;
	std::vector<int> vector;
	std::deque<int> deque;
public:
	PmergeMe(int *nbr_array, int size);
	PmergeMe(const PmergeMe &pmergeme);
	PmergeMe &operator=(const PmergeMe &pmergeme);
	~PmergeMe();
	void setVector(void);
	void setDeque(void);
	void vectorFordJohnson(std::vector<int> &base);
	void dequeFordJohnson(std::deque<int> &base);
	void vectorMerge(std::vector<int> &left, std::vector<int> &right);
	void dequeMerge(std::deque<int> &base, std::deque<int> &left, std::deque<int> &right);
};

#endif