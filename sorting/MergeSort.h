#pragma once
#include "SortingAlgorithm.h"
class MergeSort :
	public SortingAlgorithm
{
public:
	MergeSort();
	~MergeSort();
	virtual void sort(std::vector<int> & sortVector) override;
private:
	void mergeSort(std::vector<int> & sortVector, int head, int tail);
};

