// sorting.cpp: 定义控制台应用程序的入口点。
//
//
#include "stdafx.h"
#include <vector>
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "ChooseSort.h"
#include "QuickSort.h"
#include "Heapsort.h"

using namespace std;
const int NUM = 10000;
//当NUM = 10000时，各排序算法用时如下：
//				最好情况					最坏情况					随机情况（一次）
//		插入排序：0.005s					21.270s					10.199s
//		冒泡排序：0.002s					42.355s					27.716s
//		选择排序：14.164s					14.177s					14.137
//		快速排序：0.019s					0.025s					0.170s
//		分治排序：0.256s					0.236s					0.271s

void addSortObject(SortingAlgorithm & sort, const vector<int> & sortVector)
{
	vector<int> insertVector(sortVector);
	sort.testRunTime(insertVector);
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> sortVector(NUM);
	srand(time(0));
	for (int i = 0; i < NUM; i++)
	{
		sortVector[i] = rand() % 25 + 1;
		//sortVector[i] = NUM - i;
		//sortVector[i] = i;
	}
	//for (int i : sortVector)
	//{
	//	cout << i << " ";
	//}
	//cout << endl;

	InsertionSort insertObject;
	addSortObject(insertObject, sortVector);

	//BubbleSort bubbleObject;
	//addSortObject(bubbleObject, sortVector);

	//ChooseSort choooseObject;
	//addSortObject(choooseObject, sortVector);

	//QuickSort quickObject;
	//addSortObject(quickObject, sortVector);

	//MergeSort mergeObject;
	//addSortObject(mergeObject, sortVector);

	Heapsort heapsort;
	addSortObject(heapsort, sortVector);

	system("pause");
	return 0;
}