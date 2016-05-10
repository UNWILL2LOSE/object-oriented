#include <iostream> 
#include<sstream>
#include<fstream>
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
		if(demo=="-a"){
			//		实例化Ｓｃａｎ和Ｐｒｉｎｔ
			Scan s;
			Print p;
			Calculation c;
			demo=*(argv+2);
			cout<<demo<<" = ";
			queue<string> temp=s.ToStringQueue(demo);
			
			c.sortStack(temp);
			cout<<c.solve()<<endl;
		}else if(demo=="-f"){
			Print p;
			p.printAnswer(*(argv+2),*(argv+3));
		}else{
			Scan s;
			Print p;
			Calculation c;
			queue<string> temp=s.ToStringQueue(demo);
			c.sortStack(temp);
			cout<<c.solve()<<endl;
		}
	}else{
		cout<<"无参数"<<endl;
	}
	system("pause");
	return 0;
}
