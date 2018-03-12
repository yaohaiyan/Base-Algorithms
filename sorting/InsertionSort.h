#pragma once
#include "SortingAlgorithm.h"
class InsertionSort :
	public SortingAlgorithm
{
public:
	InsertionSort();
	~InsertionSort();
	virtual void sort(std::vector<int> &) override;
private:
	void dichotomyRecursion(std::vector<int> & sortVector);
	void generalInsert(std::vector<int> & sortVector);
	int findSmallerIndex(std::vector<int>, int );
};

