
#include "Print.h"
#include "Scan.h"
#include "Calculation.h"

void Print::printString(queue<string> temp){
//	�����в�Ϊ��ʱѭ�� 
	while(!temp.empty())
	{
//		�����ɾ������ ��λ 
		cout << temp.front()<<endl;
		temp.pop();
	}
}


//ʵ��ʹ��io�����ָ���ļ��ĵĴ� 
void Print::printAnswer(char *input,char *output){
		ifstream infile(input);
		ofstream outfile(output);
		string getArgv;
		if(!infile){
			cout<<"�ļ�������"<<endl;
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