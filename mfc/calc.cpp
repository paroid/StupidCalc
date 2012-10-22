#include "StdAfx.h"
#include "calc.h"
//stack
template<class type> Stack<type>::Stack<type>(int length){
	data=new type[length];
	len=length;
	top=0;
}
template<class type> void Stack<type>::pop(type &e){
	if(top)
		e=data[--top];
}
template<class type> void Stack<type>::push(type d){
	data[top++]=d;
}
template<class type> bool Stack<type>::emp(){
	if(top)
		return false;
	else
		return true;
}
template<class type> type Stack<type>::getop(){
	return data[top-1];
}

char con(char op){     // precedence level test
	switch(op){
	case '-': case '+':
		return 1;
	case '*': case'/':
		return 2;
	case '^':
		return 3;
	case 's': case 'c': case 't':
		return 4;
	case '%':
		return 5;
	default:
		return 0;
	}
}


calc::calc(char *s)
{
	strcpy(esp,s);
}
calc::calc(){
}

calc::~calc(void)
{
}

void calc::change(char *s){
	strcpy(esp,s);
}

double calc::cal(double x,double y){   // calculate
	if(esp[0]==' ')
		return 0;
	char tem[2*MAX];
	int l,i,j;
	Stack<char> op;   // operator stack
	l=strlen(esp);
	j=0;
	char suck;
	//  turn into suffixal expression
	for(i=0;i<l;){
		if(' ' == esp[i]){
			i++;
			continue;
		}
		if('('==esp[i]||')'==esp[i]){
			if('('==esp[i]){
				op.push('(');
				i++;
			}
			else{
				while(op.getop()!='(')
					op.pop(tem[j++]);
				op.pop(suck);
				i++;
			}
		}
		else{
			if(esp[i]>47&&esp[i]<58){
				while((esp[i]>47&&esp[i]<58)||esp[i]=='.'){
					tem[j++]=esp[i++];
				}
				tem[j++]='_';  // insert the mark '_'
			}
			else if(esp[i]=='p'||esp[i]=='e'||esp[i]=='x'||esp[i]=='y')
				tem[j++]=esp[i++];
				else{ 
					while(op.getop()!='('&&!op.emp()&&(con(esp[i])<=con(op.getop())))
						op.pop(tem[j++]);
					op.push(esp[i++]);
				}
		}
	}
	while(!op.emp())
		op.pop(tem[j++]);
	tem[j]='\0';
	//  calculate the result
	if(!op.emp())
		return INT_MIN;
	Stack<double> ans;
	double a,b;
	for(i=0;i<j;){
		if(tem[i]>47&&tem[i]<58){
			bool ty=1;
			double num=0;
			double p=1;
			while(tem[i]!='_'){  // convert  value
				if(tem[i]=='.')
					ty=0;
				if(ty){
					num*=10;
					num+=tem[i]-48;
				}
				else if(tem[i]!='.'){ // deal with the double
					num+=(tem[i]-48)/pow(10,p++);
				}
				i++;
			}
			ans.push(num);
		}
		else if(tem[i]=='p'){  // Pi
			ans.push(3.14159);
			i++;
		}
		else if(tem[i]=='e'){  // e
			ans.push(2.71828);
			i++;
		}
		else if(tem[i] =='x'){
			ans.push(x);
			i++;
		}
		else if(tem[i]=='y'){
			ans.push(y);
			i++;
		}

			else{
				if(tem[i]=='_'){  // ignore the mark '_'
					i++;
					continue;
				}
				ans.pop(b);
				if(tem[i]=='s'||tem[i]=='c'||tem[i]=='t'){  //  monadic operator    
					switch(tem[i++]){
						case 's':
							ans.push(sin(b));
							break;
						case 'c':
							ans.push(cos(b));
							break;
						case 't':
							ans.push(tan(b));
							break;
					}
					continue;
				}
				ans.pop(a);
				switch(tem[i++]){		//binary operation   
					case '+':
						ans.push(a+b);
						break;
					case '-':
						ans.push(a-b);
						break;
					case '*':
						ans.push(a*b);
						break;
					case '/':
						ans.push(a/b);
						break;
					case '^':
						ans.push(pow(a,b));
						break;
					case '%':
						ans.push((int)a%(int)b);
						break;
				}
			}
	}
	return ans.getop();  // the result
}
