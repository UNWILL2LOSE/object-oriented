#include <iostream> 
#include <string>
#include <queue>
#include "print.h"
using namespace std;

void Print::printString(queue<string> temp){
//	�����в�Ϊ��ʱѭ�� 
	while(!temp.empty())
	{
//		�����ɾ������ ��λ 
		cout << temp.front()<<endl;
		temp.pop();
	}
}

