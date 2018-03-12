#pragma once
#include "SortingAlgorithm.h"
class ChooseSort :
	public SortingAlgorithm
{
public:
	ChooseSort();
	~ChooseSort();
	virtual void sort(std::vector<int> & sortVector) override;
};

