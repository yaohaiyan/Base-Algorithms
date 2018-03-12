#include "stdafx.h"
#include "MergeSort.h"


MergeSort::MergeSort()
{
	this->algorithmName = "MergeSort";
}


MergeSort::~MergeSort()
{
}


void MergeSort::sort(std::vector<int> & sortVector)
{
	this->mergeSort(sortVector, 0, sortVector.size() - 1);
}


void MergeSort::mergeSort(std::vector<int> & sortVector, int headIndex, int tailIndex)
{
	if (headIndex == tailIndex)
	{
		return;
	}

	int middleIndex = (headIndex + tailIndex) / 2;
	int headVectorSize = middleIndex - headIndex + 1;
	int tailVectorSize = tailIndex - middleIndex;

	this->mergeSort(sortVector, headIndex, middleIndex);
	this->mergeSort(sortVector, middleIndex + 1, tailIndex);

	std::vector<int> hailVector(sortVector.begin() + headIndex, sortVector.begin() + headIndex + headVectorSize);
	std::vector<int> tailVector(sortVector.begin() + middleIndex + 1, sortVector.begin() + middleIndex + 1 + tailVectorSize);

	int hailVectorIndex = 0;
	int tailVectorIndex = 0;
	for (int i = headIndex; i <= tailIndex;)
	{		
		if (hailVectorIndex == headVectorSize)
		{
			sortVector[i] = tailVector[tailVectorIndex];
			tailVectorIndex++;
			i++;
			continue;
		}
		else if (tailVectorIndex == tailVectorSize )
		{
			sortVector[i] = hailVector[hailVectorIndex];
			hailVectorIndex++;
			i++;
			continue;
		}
		
		if (hailVector[hailVectorIndex] >= tailVector[tailVectorIndex])
		{
			sortVector[i] = tailVector[tailVectorIndex];
			tailVectorIndex++;
			i++;
		}
		else if (hailVector[hailVectorIndex] <tailVector[tailVectorIndex])
		{
			sortVector[i] = hailVector[hailVectorIndex];
			hailVectorIndex++;
			i++;
		}
	}
}
