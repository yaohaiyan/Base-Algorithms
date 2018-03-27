// dataStructure.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MinPriorityQueue.h"
#include "MaxPriorityQueue.h"
#include <iostream>
#include<time.h>

using namespace std;

int main()
{
	MinPriorityQueue minQueue;
	MaxPriorityQueue maxQueue;
	vector<Element> task;

	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		Element element;
		element.handle = rand() % 50 + 1;
		element.data = i;

		minQueue.insert(element);
		maxQueue.insert(element);
		task.push_back(element);
	}

	for (auto i : task)
	{
		cout << i;
	}
	cout << endl;

	minQueue.printAllElement();
	maxQueue.printAllElement();

	Element min = minQueue.extractMin();
	cout << "min:" << min << endl;
	Element max = maxQueue.extractMax();
	cout << "max:" << max << endl;

	minQueue.printAllElement();
	maxQueue.printAllElement();

	getchar();
    return 0;
}

