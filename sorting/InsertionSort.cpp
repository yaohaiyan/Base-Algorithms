#include "stdafx.h"
#include "InsertionSort.h"


InsertionSort::InsertionSort()
{
	this->algorithmName = "InsertionSort";
}


InsertionSort::~InsertionSort()
{
}
//从小到大排序
void InsertionSort::sort(std::vector<int> &sortVector)
{
	//generalInsert(sortVector);
	dichotomyRecursion(sortVector);
}



void InsertionSort::dichotomyRecursion(std::vector<int> & sortVector)
{
	int vectorSize = sortVector.size();
	for (int currentSortTotalNum = 1; currentSortTotalNum < vectorSize; currentSortTotalNum++)
	{
		
		if (sortVector.at(currentSortTotalNum) >= sortVector.at(currentSortTotalNum - 1)) 
			continue;
	
		int smallerIndex = findSmallerIndex(sortVector, currentSortTotalNum);

		int key = sortVector.at(currentSortTotalNum);
		sortVector.erase(sortVector.begin() + currentSortTotalNum);
		sortVector.emplace(sortVector.begin() + smallerIndex, key);
	}
}

void InsertionSort::generalInsert(std::vector<int> & sortVector)
{
	int vectorSize = sortVector.size();
	for (int currentSortTotalNum = 1; currentSortTotalNum < vectorSize; currentSortTotalNum++)
	{
		int key = sortVector.at(currentSortTotalNum);
		int endedOperationIndex = 0;

		for (int operationIndex = currentSortTotalNum; operationIndex > 0 && sortVector.at(operationIndex - 1) > key; operationIndex--) 
		{
			sortVector.at(operationIndex) = sortVector.at(operationIndex - 1);

			endedOperationIndex = operationIndex - 1;
		}
		if (endedOperationIndex != currentSortTotalNum)
		{
			sortVector.at(endedOperationIndex) = key;
		}
	}
}

int InsertionSort::findSmallerIndex(std::vector<int> sortVector, int tailIndex)
{
	int targetValue = sortVector.at(tailIndex);
	int low = 0;
	int high = tailIndex;
	int middle = 0;
	while (true)
	{
		middle = (high - low) / 2 + low; // 直接使用(high + low) / 2 可能导致溢出
		if (sortVector.at(middle) >= targetValue)
		{
			high = middle;
		}
		else if (sortVector.at(middle + 1) < targetValue)
		{
			low = middle + 1;
		}
		else
		{
			return middle + 1;
		}

		if (0 == middle)
			return middle;
	}
}

