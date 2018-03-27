#include "stdafx.h"
#include "MaxPriorityQueue.h"
#include <iostream>


MaxPriorityQueue::MaxPriorityQueue()
{
	this->type = MAX_HEAP;
}


MaxPriorityQueue::~MaxPriorityQueue()
{
}

Element MaxPriorityQueue::maximun()
{
	return this->queue.at(0); // 可能会越界
}

Element MaxPriorityQueue::extractMax()
{
	return extractM();
}

void MaxPriorityQueue::increaseKey(int targetIndex, int handle)
{
	if (this->queue.at(targetIndex).handle > handle)
	{
		std::cout << "句柄小于要增加权重的元素的句柄" << std::endl;
		return;
	}

	this->queue.at(targetIndex).handle = handle;

	int node = targetIndex;
	while (node > 0)
	{
		int parentIndex = getParentIndex(node);
		if (this->queue.at(node).handle < this->queue.at(parentIndex).handle)
		{
			break;
		}

		Element larger = this->queue.at(node);
		this->queue.at(node) = this->queue.at(parentIndex);
		this->queue.at(parentIndex) = larger;
		node = parentIndex;
	}
}

void MaxPriorityQueue::insert(Element element)
{
	Element smaller;
	smaller.handle = INT_MIN;
	smaller.data = element.data;
	this->queue.push_back(smaller);
	increaseKey(this->queue.size() - 1, element.handle);
}

