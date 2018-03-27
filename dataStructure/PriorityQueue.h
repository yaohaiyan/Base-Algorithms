#pragma once

#include <vector>
#include <ostream>

struct Element
{
	int handle;
	int data;

public:
	friend std::ostream & operator << (std::ostream &out, const Element &obj);
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

	void heapify(int index);

	void printAllElement();

protected:
	Element extractM();
	int getParentIndex(int index);

protected:
	HeapType type; // Ŀǰֻ������
	std::vector<Element> queue;
};