#include "stdafx.h"
#include "Heapsort.h"


Heapsort::Heapsort()
{
	this->algorithmName = "HeapSort";
}


Heapsort::~Heapsort()
{
}

void Heapsort::sort(std::vector<int> & sortVector)
{
	buildMaxHeap(sortVector);

	auto size = sortVector.size();
	auto length = size;
	for (int i = size - 1; i >= 1; i--)
	{
		int root = sortVector[0];
		sortVector[0] = sortVector[i];
		sortVector[i] = root;

		length -= 1;
		maxHeapify(sortVector, 0, length);
	}
}

void Heapsort::buildMaxHeap(std::vector<int> & sortVector)
{
	auto size = sortVector.size();
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		maxHeapify(sortVector, i, size);
	}
}

void Heapsort::maxHeapify(std::vector<int> & sortVector, int index, int length)
{
	int node = index;
	int left = 0;
	int right = 0;


	while (true)
	{		
		left = (node + 1) * 2 - 1;
		right = (node + 1) * 2;

		int largest = node;
		if (left < length && sortVector[left] > sortVector[node])
		{
			largest = left;
		}

		if (right < length && sortVector[right] > sortVector[largest])
		{
			largest = right;
		}

		if (node != largest)
		{
			auto largestContent = sortVector[largest];
			sortVector[largest] = sortVector[node];
			sortVector[node] = largestContent;
			node = largest;
		}
		else
		{
			break;
		}
	}
}
