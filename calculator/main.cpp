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
			cout<<"进入算式显示选项"<<endl;
			demo=*(argv+2);
			cout<<"算式为："<<demo<<endl;
			queue<string> temp=s.ToStringQueue(demo);
		}else{
			cout<<"进入非算式宣示选项"<<endl;
			cout<<"算式为："<<demo<<endl;
			queue<string> temp=s.ToStringQueue(demo);
			c.sortStack(temp);
			cout<<"运算结果:"<<c.solve()<<endl;
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
