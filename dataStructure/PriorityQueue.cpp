#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue()
{
	type = MAX_HEAP; // 默认最大优先队列
}

PriorityQueue::~PriorityQueue()
{

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
