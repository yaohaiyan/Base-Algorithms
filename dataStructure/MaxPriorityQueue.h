#pragma once
#include "PriorityQueue.h"
class MaxPriorityQueue :
	public PriorityQueue
{
public:
	MaxPriorityQueue();
	~MaxPriorityQueue();

	Element maximun();
	Element extractMax();
	void increaseKey(int targetIndex, int handle);
	void insert(Element element);
};

