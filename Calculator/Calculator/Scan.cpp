#include "Scan.h"

queue<string> Scan::ToStringQueue(string input){

//���峤�� 
	int length=0;
//	��ʼ���ַ������б� 
	string temp1="";
	string temp2="";
	queue<string> ans;
	queue<string> enmpty;
//	����input 
	for(int i=0;i<input.length();i++)
	{
		if(input[i]>='0'&&input[i]<='9'||input[i]=='.')
		{
//			�������� 
			length++;
//			����10λ���� 
			if(length>10) 
			{
				return enmpty;
			}
//			����ǵ����򵥸������� 
			temp1=temp1+input[i];
//			�жϳ��������һλ�ģ�������� ��һλ 
			if(i!=(input.length()-1))
			{
//				�Ϻ�һλ�Ƿ�������� �����Ͻ�����һλȥ�� 
				if(input[i+1]>='0'&&input[i+1]<='9'||input[i+1]=='.')
				{
				}
//				�����Ͼͽ�����ģ����𣱼�������� 
				else
				{
					ans.push(temp1);
					temp1="";
					length=0;
				}
			}
//			�ѵ������ֵģ���������� 
			else
			{
				ans.push(temp1);
				temp1="";
				length=0;
			}
		}
//		���������ֵļӶ��� 
		else
		{
			temp2=input[i];
			ans.push(temp2);
		}
	}
	
	return ans;
}
#include "stdafx.h"