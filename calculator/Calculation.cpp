////实现计算和字符到数字的转换
#include <iostream> 
#include <string>
#include <queue>
#include<stack> 
#include<sstream>
#include "Calculation.h"
using namespace std;

//		将参数队列分类成符号与数字 
		void Calculation::sortStack(queue<string> temp){

			string last=temp.front();
			int n=0;
//				当开头为-时

			if (last=="-"){
				temp.pop();
				last=temp.front();
				digital.push(-convertString2Double(last));
				temp.pop();
			}
			
			while (!temp.empty()){
				
				if (n<1){
					n++;
	//				当为符号+ -是直接加入
					if(temp.front()=="+"||temp.front()=="-"){
						symbol.push(temp.front());
	//					当为符号 * /是
					}else if(temp.front()=="*"||temp.front()=="/"){
						symbol.push(temp.front());
	//					 当为其他符号的时候 
					}else if(temp.front()=="("||temp.front()==")"){
						symbol.push(temp.front());
	//					当为任意数的时候进行转换，并push进入栈中
					}else{
						digital.push(convertString2Double(temp.front()));
						
					}
					last=temp.front();
					temp.pop();
				}else{
					
	//				当为符号+是直接加入
					if(temp.front()=="+"){
						symbol.push(temp.front());
					}
					
	//				当符号为-时，检查前面是否为符好，若是的话，将-号后的数字变为负数 
					else if(temp.front()=="-"){
						if(last=="+"||last=="-"||last==")"||last=="("||last=="*"||last=="/"){
							temp.pop();
							digital.push(-convertString2Double(temp.front()));
						}else{
							symbol.push(temp.front());
						}
					}
					
	//				当为符号 * /是
					else if(temp.front()=="*"||temp.front()=="/"){
						symbol.push(temp.front());

					}
					
	//				当为其他符号的时候 
					else if(temp.front()=="("||temp.front()==")"){
						symbol.push(temp.front());
					}
					
	//				当为任意数的时候进行转换，并push进入栈中
					else{
						digital.push(convertString2Double(temp.front()));
					}
					
					last=temp.front();
					temp.pop();
				}
			}
		}
		
		//	进行字符到int的转换 
		double Calculation::convertString2Double(string temp){
//			定义流 
			stringstream stream;
//			向流中传值
			stream<<temp;
//			这里存储转换结果
			double result;
//			向result中写入值
			stream>>result;
//			返回值 
			return result;
		}	 
		
		
//		通过压栈降级 
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
			
			
//		实现检查下一符号
		double Calculation::checkMulti(){
//			cout<<"test"<<endl;
			double sum;
			if (digital.size()>1){
//				如果位+和-，则返回当前值 
				if (symbol.top()=="+"||symbol.top()=="-"){
//					记录下一个值，并pop符号和数值
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

