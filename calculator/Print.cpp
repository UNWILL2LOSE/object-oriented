#include <iostream> 
#include <string>
#include <queue>
#include "print.h"
using namespace std;

void Print::printString(queue<string> temp){
//	当队列不为空时循环 
	while(!temp.empty())
	{
//		输出并删除队列 首位 
		cout << temp.front()<<endl;
		temp.pop();
	}
}

