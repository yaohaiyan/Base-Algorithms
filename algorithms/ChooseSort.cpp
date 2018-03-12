#include "stdafx.h"
#include "ChooseSort.h"


ChooseSort::ChooseSort()
{
	this->algorithmName = "ChooseSort";
}


ChooseSort::~ChooseSort()
{
}


void ChooseSort::sort(std::vector<int> & sortVector)
{
	int vectorSize = sortVector.size();
	for (int i = 0; i < vectorSize - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < vectorSize; j++)
		{
			if (sortVector[j] < sortVector[minIndex])
			{
				minIndex = j;
			}
		}

		if (i != minIndex)
		{
			int minInCycle = sortVector[i];
			sortVector[i] = sortVector[minIndex];
			sortVector[minIndex] = minInCycle;
		}
	}
}
