#include <iostream> 
#include <string>
#include<stdlib.h>
#include <queue>
#include "Scan.h"
#include "Print.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*�޸İ�*/ 

int main(int argc, char** argv) {
	
	cout<<"������һ������������ʽ��"<<endl; 
	
//	�����ַ��� 
	string demo; 
	cin>>demo;
	
//	ʵ�����ӣ���ͣУ���� 
	Scan s;
	Print p;
	queue<string> temp=s.ToStringQueue(demo);
	if (temp.empty()){
		cout<<"�������ֳ���10λ������С��λ"<<endl; 
	}else{
		p.printString(temp);
	}
	
	system("pause");
	return 0;
}
