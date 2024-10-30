/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:11:17 by albagar4          #+#    #+#             */
/*   Updated: 2024/10/30 11:11:18 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void PmergeMe::vectorMerge(std::vector<int> &base, std::vector<int> &left, std::vector<int> &right) {
	unsigned long int i = 0;
	unsigned long int j = 0;

	base.clear();
	while (i < left.size() && j < right.size()) {
		if (left[i] < right[j])
			base.push_back(left[i++]);
		else
			base.push_back(right[j++]);
	}

	while (i < left.size())
		base.push_back(left[i++]);
	
	while (j < right.size())
		base.push_back(right[j++]);
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
			if (base[0] > base[1])
				std::swap(base[0], base[1]);
		}
	}
	else {
		int half = base.size() / 2;
		std::vector<int>left(base.begin(), base.begin() + half);
		std::vector<int>right(base.begin() + half, base.end());

		this->vectorFordJohnson(left);
		this->vectorFordJohnson(right);

		this->vectorMerge(base, left, right); 
	}
}

void PmergeMe::setVector(void) {
	struct timeval chrono;
	long int start;
	long int end;

	gettimeofday(&chrono, NULL);
	start = chrono.tv_usec;

	for (int i = 0; i < this->size; i++)
		this->vector.push_back(this->nbr_array[i]);

	// this->printVector("Before: ");
	this->vectorFordJohnson(this->vector);
	// this->printVector("After: ");

	gettimeofday(&chrono, NULL);
	end = chrono.tv_usec;

	std::cout << "Time to process a range of " << this->size << " elements with std::vector<int> : " << end - start << " us" << std::endl;
}

void PmergeMe::printVector(std::string str) {
	std::cout << str << "std::vector<int> = {";
	for (int i = 0; i < this->size; i++) {
		if (i == this->size - 1)
			std::cout << this->vector[i] << "}" << std::endl;
		else
			std::cout << this->vector[i] << ", ";
	}
}

void PmergeMe::dequeMerge(std::deque<int> &base, std::deque<int> &left, std::deque<int> &right) {
	unsigned long int i = 0;
	unsigned long int j = 0;

	base.clear();
	while (i < left.size() && j < right.size()) {
		if (left[i] < right[j])
			base.push_back(left[i++]);
		else
			base.push_back(right[j++]);
	}

	while (i < left.size())
		base.push_back(left[i++]);
	
	while (j < right.size())
		base.push_back(right[j++]);
}

void PmergeMe::dequeFordJohnson(std::deque<int> &base) {
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
			if (base[0] > base[1])
				std::swap(base[0], base[1]);
		}
	}
	else {
		int half = base.size() / 2;
		std::deque<int>left(base.begin(), base.begin() + half);
		std::deque<int>right(base.begin() + half, base.end());

		this->dequeFordJohnson(left);
		this->dequeFordJohnson(right);

		this->dequeMerge(base, left, right); 
	}
}

void PmergeMe::setDeque(void) {
	struct timeval chrono;
	long int start;
	long int end;

	gettimeofday(&chrono, NULL);
	start = chrono.tv_usec;
	
	for (int i = 0; i < this->size; i++)
		this->deque.push_back(this->nbr_array[i]);

	// this->printDeque("Before: ");
	this->dequeFordJohnson(this->deque);
	// this->printDeque("After: ");

	gettimeofday(&chrono, NULL);
	end = chrono.tv_usec;
	
	std::cout << "Time to process a range of " << this->size << " elements with std::deque<int> : " << end - start << " us" << std::endl;
}

void PmergeMe::printDeque(std::string str) {
	std::cout << str << "std::deque<int> = {";
	for (int i = 0; i < this->size; i++) {
		if (i == this->size - 1)
			std::cout << this->deque[i] << "}" << std::endl;
		else
			std::cout << this->deque[i] << ", ";
	}
}
