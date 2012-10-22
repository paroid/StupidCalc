#pragma once

#include<string>
#include<math.h>
using namespace std;
#define MAX 200
#define FUNC 128
// By Paroid  ÈíÐÅ0801 ³Â¿Æ 20083563 

template<class type> class Stack{    // stack 
public:
	Stack(int len=25);
	void pop(type &e);
	void push(type e);
	bool emp();
	type getop();
private:
	type *data;
	int len;
	int top;
};	

class calc
{
public:
	calc(char *s);
	calc();
	~calc(void);
	double cal(double x=0,double y=0);
	void change(char *s);
	char esp[MAX];
};

typedef struct{
	calc exp;
	string name;
}calcF;
