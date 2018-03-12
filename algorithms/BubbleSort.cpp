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
	//���ѭ�����������ѭ������
	for (int cycleNumbers = sortVector.size(); cycleNumbers > 0; cycleNumbers--)
	{
		bool flag = true;
		//�ڲ�ѭ�������ν��ϴ��������
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
