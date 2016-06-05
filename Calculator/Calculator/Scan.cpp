#include "Scan.h"

queue<string> Scan::ToStringQueue(string input){

//定义长度 
	int length=0;
//	初始化字符串和列表 
	string temp1="";
	string temp2="";
	queue<string> ans;
	queue<string> enmpty;
//	遍历input 
	for(int i=0;i<input.length();i++)
	{
		if(input[i]>='0'&&input[i]<='9'||input[i]=='.')
		{
//			符合条件 
			length++;
//			超过10位报错 
			if(length>10) 
			{
				return enmpty;
			}
//			储存非单个或单个的数字 
			temp1=temp1+input[i];
//			判断除除了最后一位的ｉｎｐｕｔ的 下一位 
			if(i!=(input.length()-1))
			{
//				断后一位是否符合条件 ，符合交给下一位去做 
				if(input[i+1]>='0'&&input[i+1]<='9'||input[i+1]=='.')
				{
				}
//				不符合就将储存的ｔｅｍｐ１加入队列中 
				else
				{
					ans.push(temp1);
					temp1="";
					length=0;
				}
			}
//			把单个数字的ｉｎｐｕｔ加入 
			else
			{
				ans.push(temp1);
				temp1="";
				length=0;
			}
		}
//		将出了数字的加队列 
		else
		{
			temp2=input[i];
			ans.push(temp2);
		}
	}
	
	return ans;
}
#include "stdafx.h"