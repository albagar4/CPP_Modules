#include "./PmergeMe.hpp"

PmergeMe::PmergeMe() {
	// std::cout << "PmergeMe: Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(int *nbr_array, int size) {
	// std::cout << "PmergeMe: Parameterized constructor called" << std::endl;
	this->nbr_array = nbr_array;
	this->size = size;
}

PmergeMe::~PmergeMe() {
	// std::cout << "PmergeMe: Destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &pmergeme) {
	// std::cout << "PmergeMe: Copy constructor called" << std::endl;
	int cpy[pmergeme.size];

	this->nbr_array = cpy;
	this->size = pmergeme.size;
	for (int i = 0; i < pmergeme.size; i++) {
		this->nbr_array[i] = pmergeme.nbr_array[i];
		this->vector[i] = pmergeme.vector[i];
		this->deque[i] = pmergeme.deque[i];
	}
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeme) {
	// std::cout << "PmergeMe: Copy assignment operator called" << std::endl;
	if (this != &pmergeme) {
		int cpy[pmergeme.size];

		this->nbr_array = cpy;
		this->size = pmergeme.size;
		for (int i = 0; i < pmergeme.size; i++) {
			this->nbr_array[i] = pmergeme.nbr_array[i];
			this->vector[i] = pmergeme.vector[i];
			this->deque[i] = pmergeme.deque[i];
		}
	}
	return (*this);
}

void PmergeMe::vectorMerge(std::vector<int> &left, std::vector<int> &right) {
	int i = 0;
	int j = 0;

	this->vector.clear();
	while (e)
}

void PmergeMe::vectorFordJohnson(std::vector<int> &base) {
	if (base.size() <= 3) {
		if (base.size() == 2) {
			if (base[1] < base[0])
				std::swap(base[0], base[1]);
		}
		else if (base.size() == 3) {
			if (base[0] > base[1])
				std::swap(base[0], base[1]);
			if (base[1] > base[2])
				std::swap(base[1], base[2]);
			if (base[0] > base[2])
				std::swap(base[0], base[2]);
		}
	}
	else {
		int half = base.size() / 2;
		std::vector<int>left(base.begin(), base.begin() - half);
		std::vector<int>right(base.begin() + half, base.end());

		this->vectorFordJohnson(left);
		this->vectorFordJohnson(right);

		this->vectorMerge(base, left, right); 
	}
}

void PmergeMe::setVector(void) {
	// timer starts here
	std::cout << "Before: std::vector<int> = {";
	for (int i = 0; i < this->size; i++) {
		this->vector.push_back(this->nbr_array[i]);
		if (i == this->size - 1)
			std::cout << this->vector[i] << "}" << std::endl;
		else
			std::cout << this->vector[i] << ", ";
	}
	this->vectorFordJohnson(this->vector);
	// timer ends here
	std::cout << "Time to process a range of " << this->size << " elements with std::vector<int> : " << std::endl;
	return;
}
