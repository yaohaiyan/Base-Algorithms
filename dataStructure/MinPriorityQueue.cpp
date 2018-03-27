#include "stdafx.h"
#include "MinPriorityQueue.h"
#include <iostream>


MinPriorityQueue::MinPriorityQueue()
{
	this->type = MIN_HEAP;
}


MinPriorityQueue::~MinPriorityQueue()
{

}

Element MinPriorityQueue::minimum()
{
	return this->queue.at(0); // 可能会越界
}

Element MinPriorityQueue::extractMin()
{
	return extractM();
}

void MinPriorityQueue::decreaseKey(int targetIndex, int handle)
{
	if (this->queue.at(targetIndex).handle < handle)
	{
		std::cout << "句柄大于要增加权重的元素的句柄" << std::endl;
		return;
	}

	this->queue.at(targetIndex).handle = handle;

	int node = targetIndex;
	while (node > 0)
	{
		int parentIndex = getParentIndex(node);
		if (this->queue.at(node).handle > this->queue.at(parentIndex).handle)
		{
			break;
		}

		Element larger = this->queue.at(node);
		this->queue.at(node) = this->queue.at(parentIndex);
		this->queue.at(parentIndex) = larger;
		node = parentIndex;
	}
}

void MinPriorityQueue::insert(Element element)
{
	Element larger;
	larger.handle = INT_MAX;
	larger.data = element.data;
	this->queue.push_back(larger);
	decreaseKey(this->queue.size() - 1, element.handle);
}
