#pragma once
#include "SortingAlgorithm.h"
class BubbleSort :
	public SortingAlgorithm
{
public:
	BubbleSort();
	~BubbleSort();
	virtual void sort(std::vector<int> &) override;
};

