//实现计算和字符到数字的转换
#ifndef __CALC_H_
#define __CALC_H 
#include <iostream> 
#include <string>
#include <queue>
#include<stack> 
#include<sstream>
using namespace std; 
class Calculation{
	
	public:
//		符号栈 
		stack<string> symbol;
//		数字栈 
		stack<double> digital;
//		将参数队列分类成符号与数字 
		void sortStack(queue<string> temp);
//		进行字符到int的转换 
		double convertString2Double(string temp);
//		通过压栈降级 
		double solve();
//		实现检查下一符号
		double Calculation::checkMulti();
};
#endif
