#pragma once
#include "PriorityQueue.h"
class MinPriorityQueue :
	public PriorityQueue
{
public:
	MinPriorityQueue();
	~MinPriorityQueue();

	Element minimum();
	Element extractMin();
	void decreaseKey(int targetIndex, int handle);
	void insert(Element element);
};

