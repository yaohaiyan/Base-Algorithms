#pragma once
#include "PriorityQueue.h"
class MaxPriorityQueue :
	public PriorityQueue
{
public:
	MaxPriorityQueue();
	~MaxPriorityQueue();

	virtual void buildHeap() override;
	Element maximun();
	Element extractMax();
	void increaseKey(Element data, int handle);
};

