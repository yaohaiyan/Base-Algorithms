#include "stdafx.h"
#include "QuickSort.h"


QuickSort::QuickSort()
{
	this->algorithmName = "QuickSort";
}


QuickSort::~QuickSort()
{
}


void QuickSort::sort(std::vector<int> &sortVector)
{
	this->quickSort(sortVector, 0, sortVector.size() - 1);
}

void QuickSort::quickSort(std::vector<int> & sortVector, int leftIndex, int rightIndex)
{
	int middleIndex = (leftIndex + rightIndex) / 2;
	int pivot = sortVector[middleIndex];

	for (int i = leftIndex, j = rightIndex; i < j;)
	{
		while (i < middleIndex && sortVector[i] <= pivot)
		{
			i++;
		}
		if (i < middleIndex)
		{
			sortVector[middleIndex] = sortVector[i];
			middleIndex = i;
		}

		while (j > middleIndex && sortVector[j] >= pivot)
		{
			j--;
		}
		if (j > middleIndex)
		{
			sortVector[middleIndex] = sortVector[j];
			middleIndex = j;
		}
	}
	sortVector[middleIndex] = pivot;

	if (middleIndex - leftIndex > 1)
	{
		this->quickSort(sortVector, leftIndex, middleIndex - 1);
	}
	if (rightIndex - middleIndex > 1)
	{
		this->quickSort(sortVector, middleIndex + 1, rightIndex);
	}
}
