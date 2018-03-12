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
	// 每次将最大值与放到i处，将长度减一，然后进行一次maxHeapify维护，堆减小到1时，数组完成排序
	for (int i = size - 1; i >= 1; i--)
	{
		int root = sortVector[0];
		sortVector[0] = sortVector[i];
		sortVector[i] = root;

		length -= 1;
		maxHeapify(sortVector, 0, length);
	}
}

// 建最大堆
void Heapsort::buildMaxHeap(std::vector<int> & sortVector)
{
	auto size = sortVector.size();
	// 子数组A[(n/2)+1 .. n]中的元素都是树的叶节点，因此只需对之前的元素进行一次维护即可建成最大堆
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		maxHeapify(sortVector, i, size);
	}
}

//维护最大堆的性质
void Heapsort::maxHeapify(std::vector<int> & sortVector, int index, int length)
{
	int node = index;
	int left = 0;
	int right = 0;

	// 将最大数放到根节点对应的位置
	while (true)
	{		
		left = (node + 1) * 2 - 1;
		right = (node + 1) * 2;

		int largest = node;
		if ((left < length) && (sortVector[left] > sortVector[node]))
		{
			largest = left;
		}

		if ((right < length) && (sortVector[right] > sortVector[largest]))
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
