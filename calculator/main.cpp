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
//		ʵ�����ӣ���ͣУ����
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
//			cout<<"�������ֳ���10λ������С��λ��"<<endl;
//		}else{
//			p.printString(temp);
//		}
	}else{
		cout<<"�޲���"<<endl;
	}
 

	
	system("pause");
	return 0;
}
