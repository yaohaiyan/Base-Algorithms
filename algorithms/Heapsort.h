#pragma once
#include "SortingAlgorithm.h"
class Heapsort :
	public SortingAlgorithm
{
public:
	Heapsort();
	~Heapsort();

	virtual void sort(std::vector<int> & sortVector) override;

private:
	void buildMaxHeap(std::vector<int> & sortVector);
	void maxHeapify(std::vector<int> & sortVector, int index, int length);
};

