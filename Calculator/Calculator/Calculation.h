//ʵ�ּ�����ַ������ֵ�ת��
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
//		����ջ 
		stack<string> symbol;
//		����ջ 
		stack<double> digital;
//		���������з���ɷ��������� 
		void sortStack(queue<string> temp);
//		�����ַ���int��ת�� 
		double convertString2Double(string temp);
//		ͨ��ѹջ���� 
		double solve();
//		ʵ�ּ����һ����
		double Calculation::checkMulti();
};
#endif
