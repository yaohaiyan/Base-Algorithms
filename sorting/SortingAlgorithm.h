#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
class SortingAlgorithm
{
public:
	SortingAlgorithm();
	~SortingAlgorithm();
	virtual void sort(std::vector<int> &) = 0;
	void testRunTime(std::vector<int> & sortVector);
protected:
	std::string algorithmName;
};

