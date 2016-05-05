#include<iostream>
#include "circle.cpp"
using namespace std;
int main()
{
	cout<<"please input radius:"<<endl;
	double r;cin>>r;
	if(r<0){
		cout<<"input error"<<endl;
	}else{
		cout<<"the area of circle is:"<<getRadius(r)<<endl;
	}
	return 0;
} 
