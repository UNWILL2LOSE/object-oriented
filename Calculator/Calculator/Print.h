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
		//实现使用io输出到指定文件的的答案 
		void printAnswer(char *input,char *output);
};
#endif
