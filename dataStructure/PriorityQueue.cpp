#include "stdafx.h"
#include "PriorityQueue.h"
#include <iostream>

std::ostream & operator<<(std::ostream & out, const Element & obj)
{
	out << '[' << obj.handle << ',' << obj.data << ']';
	return out;
}

PriorityQueue::PriorityQueue()
{
	type = MAX_HEAP; // 默认最大优先队列
}

PriorityQueue::~PriorityQueue()
{
	std::vector<Element>().swap(this->queue);
}

void PriorityQueue::heapify(int index)
{
	int queueLength = queue.size();

	int node = index;
	int left = 0;
	int right = 0;

	while (true)
	{
		int left = 2 * node + 1;
		int right = 2 * node + 2;

		int targetIndex = node;
		if (left <  queueLength && (queue.at(left).handle - queue.at(targetIndex).handle) * type > 0)
		{
			targetIndex = left;
		}

		if (right <  queueLength && (queue.at(right).handle - queue.at(targetIndex).handle) * type > 0)
		{
			targetIndex = right;
		}

		if (targetIndex != node)
		{
			Element larger = queue.at(targetIndex);
			queue.at(targetIndex) = queue.at(node);
			queue.at(node) = larger;
			node = targetIndex;
		}
		else
		{
			break;
		}
	}
}

Element PriorityQueue::extractM()
{
	int length = this->queue.size();
	if (length < 1)
	{
		std::cout << "队列中没有元素" << std::endl;
		return Element();
	}

	Element m = this->queue[0];
	this->queue[0] = this->queue[length - 1];
	this->queue.pop_back();

	heapify(0);

	return m;
}

void PriorityQueue::printAllElement()
{
	int length = this->queue.size();
	for (int i = 0; i < length; i++)
	{
		std::cout << this->queue[i];
	}
	std::cout << std::endl;
}

int PriorityQueue::getParentIndex(int index)
{
	return index % 2 == 0 ? index / 2 - 1 : index / 2;
}