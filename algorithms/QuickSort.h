#pragma once
#include "SortingAlgorithm.h"
class QuickSort :
	public SortingAlgorithm
{
public:
	QuickSort();
	~QuickSort();
	virtual void sort(std::vector<int> &sortVector) override;
private:
	void quickSort(std::vector<int> & sortVector, int leftIndex, int rightIndex);
};

