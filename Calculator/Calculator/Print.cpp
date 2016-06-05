
#include "Print.h"
#include "Scan.h"
#include "Calculation.h"

void Print::printString(queue<string> temp){
//	当队列不为空时循环 
	while(!temp.empty())
	{
//		输出并删除队列 首位 
		cout << temp.front()<<endl;
		temp.pop();
	}
}


//实现使用io输出到指定文件的的答案 
void Print::printAnswer(char *input,char *output){
		ifstream infile(input);
		ofstream outfile(output);
		string getArgv;
		if(!infile){
			cout<<"文件不存在"<<endl;
		}else{
			while(getline(infile,getArgv)){
				Scan *s=new Scan();
				Calculation *c=new Calculation();
				queue<string> temp=s->ToStringQueue(getArgv);
				c->sortStack(temp);
				double ans=c->solve();
				outfile<<ans;
				outfile<<"\n";
				delete c;c=NULL;
			}
		}
		infile.close();
		outfile.close();
}

#include "stdafx.h"