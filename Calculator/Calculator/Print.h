#ifndef __CALC_H_
#define __CALC_H 
#include <iostream> 
#include<sstream>
#include<fstream>
#include <string>
#include<stdlib.h>
#include <queue>
using namespace std;
class Print
{
	public 	:
		void printString(queue<string> input);
		//ʵ��ʹ��io�����ָ���ļ��ĵĴ� 
		void printAnswer(char *input,char *output);
};
#endif
