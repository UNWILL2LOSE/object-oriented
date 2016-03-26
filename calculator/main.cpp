#include <iostream> 
#include <string>
#include<stdlib.h>
#include <queue>
#include "Scan.h"
#include "Print.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*修改版*/ 

int main(int argc, char** argv) {
	
	cout<<"请输入一个四则运算表达式："<<endl; 
	
//	输入字符串 
	string demo; 
	cin>>demo;
	
//	实例化Ｓｃａｎ和Ｐｒｉｎｔ 
	Scan s;
	Print p;
	queue<string> temp=s.ToStringQueue(demo);
	if (temp.empty()){
		cout<<"输入数字超过10位（包括小数位"<<endl; 
	}else{
		p.printString(temp);
	}
	
	system("pause");
	return 0;
}
