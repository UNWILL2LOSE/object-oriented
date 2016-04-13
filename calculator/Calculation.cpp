////ʵ�ּ�����ַ������ֵ�ת��
#include <iostream> 
#include <string>
#include <queue>
#include<stack> 
#include<sstream>
#include "Calculation.h"
using namespace std;

//		���������з���ɷ��������� 
		void Calculation::sortStack(queue<string> temp){

			string last=temp.front();
			int n=0;
//				����ͷΪ-ʱ

			if (last=="-"){
				temp.pop();
				last=temp.front();
				digital.push(-convertString2Double(last));
				temp.pop();
			}
			
			while (!temp.empty()){
				
				if (n<1){
					n++;
	//				��Ϊ����+ -��ֱ�Ӽ���
					if(temp.front()=="+"||temp.front()=="-"){
						symbol.push(temp.front());
	//					��Ϊ���� * /��
					}else if(temp.front()=="*"||temp.front()=="/"){
						symbol.push(temp.front());
	//					 ��Ϊ�������ŵ�ʱ�� 
					}else if(temp.front()=="("||temp.front()==")"){
						symbol.push(temp.front());
	//					��Ϊ��������ʱ�����ת������push����ջ��
					}else{
						digital.push(convertString2Double(temp.front()));
						
					}
					last=temp.front();
					temp.pop();
				}else{
					
	//				��Ϊ����+��ֱ�Ӽ���
					if(temp.front()=="+"){
						symbol.push(temp.front());
					}
					
	//				������Ϊ-ʱ�����ǰ���Ƿ�Ϊ���ã����ǵĻ�����-�ź�����ֱ�Ϊ���� 
					else if(temp.front()=="-"){
						if(last=="+"||last=="-"||last==")"||last=="("||last=="*"||last=="/"){
							temp.pop();
							digital.push(-convertString2Double(temp.front()));
						}else{
							symbol.push(temp.front());
						}
					}
					
	//				��Ϊ���� * /��
					else if(temp.front()=="*"||temp.front()=="/"){
						symbol.push(temp.front());

					}
					
	//				��Ϊ�������ŵ�ʱ�� 
					else if(temp.front()=="("||temp.front()==")"){
						symbol.push(temp.front());
					}
					
	//				��Ϊ��������ʱ�����ת������push����ջ��
					else{
						digital.push(convertString2Double(temp.front()));
					}
					
					last=temp.front();
					temp.pop();
				}
			}
		}
		
		//	�����ַ���int��ת�� 
		double Calculation::convertString2Double(string temp){
//			������ 
			stringstream stream;
//			�����д�ֵ
			stream<<temp;
//			����洢ת�����
			double result;
//			��result��д��ֵ
			stream>>result;
//			����ֵ 
			return result;
		}	 
		
		
//		ͨ��ѹջ���� 
		double Calculation::solve(){
			
			while (!symbol.empty()){
				
				double temp=digital.top();
				digital.pop();
				
				if (symbol.top()=="+"){
					symbol.pop();
					if (!symbol.empty()){
						double flag=checkMulti()+temp;
//						cout<<"+:flag:"<<flag<<endl;
						digital.push(flag);
					}else{
						double flag=temp+digital.top();
						digital.pop();
						digital.push(flag);
					}
				}
				
				else if (symbol.top()=="-"){
					symbol.pop();
					if (!symbol.empty()){
						double flag=checkMulti()-temp;
//						cout<<"-:flag:"<<flag<<endl;
						digital.push(flag);
					}else{
						double flag=digital.top()-temp;
						digital.pop();
						digital.push(flag);
					}
				}
				
				else if (symbol.top()=="*"){
					symbol.pop();
					if (!symbol.empty()){
						double flag=checkMulti()*temp;
						digital.push(flag);
//						cout<<"*"<<flag<<endl;
					}else{
						double flag=digital.top()*temp;
						digital.pop();
						digital.push(flag);
					}
				}
				
				else if (symbol.top()=="/"){
					symbol.pop();
					if (!symbol.empty()){
						double flag=checkMulti()/temp;
						digital.push(flag);
					}else{
						double flag=digital.top()/temp;
						digital.pop();
						digital.push(flag);
					}
				}
				
				else if (symbol.top()==")"){
					symbol.pop();
					digital.push(temp);
					double flag=solve();
					digital.push(flag);
//					cout<<"over"<<endl;
				}
				
				else if (symbol.top()=="("){
					symbol.pop();
					double flag=temp;
//					cout<<"("<<flag<<endl;
					return flag;
				}
			}
			
			return digital.top();
		}
			
			
//		ʵ�ּ����һ����
		double Calculation::checkMulti(){
//			cout<<"test"<<endl;
			double sum;
			if (digital.size()>1){
//				���λ+��-���򷵻ص�ǰֵ 
				if (symbol.top()=="+"||symbol.top()=="-"){
//					��¼��һ��ֵ����pop���ź���ֵ
					sum=digital.top(); 
					digital.pop();
//					cout<<"sum:"<<sum<<endl;
					return sum;
				}else if (symbol.top()=="*"||symbol.top()=="/"){
					if (symbol.top()=="*"){
						symbol.pop();
						sum=digital.top();
//						cout<<"sum:"<<sum<<endl;
						digital.pop();
						sum=sum*checkMulti();
					}else
					if (symbol.top()=="/"){
						symbol.pop();
						sum=digital.top();
						digital.pop();
						sum=(1/sum)*checkMulti();
					}
//					cout<<"sum:"<<sum<<endl;
					return sum;
				}else if (symbol.top()==")"){
					symbol.pop();
					double flag=solve();
//					cout<<"over"<<endl;
//					cout<<flag<<endl;
					return flag;
				}else if (symbol.top()=="("){
					double flag=digital.top();
					digital.pop();
					return flag;
				}
			}else{
				sum=digital.top();
				digital.pop();
//				cout<<"sum:"<<sum<<endl;
				return sum;
			}
		}

