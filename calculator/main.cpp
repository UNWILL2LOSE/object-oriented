#include <iostream> 
#include <string>
#include<stdlib.h>
#include <queue>
#include "Scan.h"
#include "Print.h"
#include "Calculation.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	if(argc>1){
		string demo=*(argv+1); 
//		cin>>demo;
//		实例化Ｓｃａｎ和Ｐｒｉｎｔ
		Scan s;
		Print p;
		Calculation c;
		if(demo=="-a"){
			demo=*(argv+2);
			cout<<demo<<" = ";
			queue<string> temp=s.ToStringQueue(demo);
			
			c.sortStack(temp);
			cout<<c.solve()<<endl;
		}else{
			queue<string> temp=s.ToStringQueue(demo);
			
			c.sortStack(temp);
			cout<<c.solve()<<endl;
		}
			
//		if(temp.empty()){
//			cout<<"输入数字超过10位（包括小数位）"<<endl;
//		}else{
//			p.printString(temp);
//		}
	}else{
		cout<<"无参数"<<endl;
	}
 

	
	system("pause");
	return 0;
}
