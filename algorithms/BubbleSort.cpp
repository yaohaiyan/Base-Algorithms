#include "stdafx.h"
#include "BubbleSort.h"


BubbleSort::BubbleSort()
{
	this->algorithmName = "BubbleSort";
}


BubbleSort::~BubbleSort()
{
}


void BubbleSort::sort(std::vector<int> &sortVector)
{
	//外层循环，设置外层循环次数
	for (int cycleNumbers = sortVector.size(); cycleNumbers > 0; cycleNumbers--)
	{
		bool flag = true;
		//内层循环，依次将较大的数后移
		for (int currOperationIndex = 0; currOperationIndex < cycleNumbers - 1; currOperationIndex++)
		{
			if (sortVector[currOperationIndex + 1] < sortVector[currOperationIndex])
			{
				int smallerNum = sortVector[currOperationIndex + 1];
				sortVector[currOperationIndex + 1] = sortVector[currOperationIndex];
				sortVector[currOperationIndex] = smallerNum;
				flag = false;
			}
		}
		if (flag)
		{
			break;
		}
	}
}
