#include "stdafx.h"
#include "SortingAlgorithm.h"


SortingAlgorithm::SortingAlgorithm()
{
	this->algorithmName = "";
}


SortingAlgorithm::~SortingAlgorithm()
{
}


void SortingAlgorithm::testRunTime(std::vector<int> & sortVector)
{
	clock_t start, finish;

	start = clock();
	this->sort(sortVector);
	finish = clock();

	/*for (int i : sortVector)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;*/

	std::cout << this->algorithmName << " : " << finish - start << "/" << CLOCKS_PER_SEC << " (s) " << std::endl;
}
