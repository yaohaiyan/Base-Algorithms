#pragma once

#include <vector>

struct Data
{
	int key;
	
};

class PriorityQueue
{
public:
    PriorityQueue();
    ~PriorityQueue();
    
	void insert(Data);
	Data maximun();
	Data extractMax();
	void increaseKey(Data data, int key);

private:

private:
    std::vector<Data> queue;
};