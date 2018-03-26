#pragma once

#include <vector>

struct Element
{
	int handle;
	char data;
};

enum HeapType
{
	MIN_HEAP = -1,
	MAX_HEAP = 1
};

class PriorityQueue
{
public:
    PriorityQueue();
    ~PriorityQueue();
    
private:
	void heapify(int type);
	virtual void buildHeap() = 0;

private:
    std::vector<Element> queue;
	HeapType type; // 目前只有两种
};