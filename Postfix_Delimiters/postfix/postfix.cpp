//RYAN HOFFMAN - CS302 - PROJECT 1 - POSTFIX
#include <iostream>
#include <stdexcept>
#include <string>
#include <ctype.h>
using namespace std;
#include "StackLinked.cpp"

float result(string postfix, StackLinked<float> & stack);
	int main(){
	StackLinked<float> stack;
//	string input= "";
//	cout << "Input: ";
//	cin >> input;
//	cout << input << " = " << result(input, stack) << endl;
	cout << "34+52/* = (3+4)/(5*2) = " << result("34+52/*", stack) << endl;
	cout << "76*2-1/ = (7*6)-(2/1) = " << result("76*2-1/", stack) << endl;
	cout << "58-27*3*+ = 5-8+2*7*3 = " << result("58-27*3*+", stack) << endl;
	cout << "59/2/36-* = 5/9/2*(3-6) = " << result("59/2/36-*", stack) << endl;
	cout << "62*46*/ = (6*2)/(4*6) = " << result("62*46*/", stack) << endl;
	return 0;
}

float result(const string postfix, StackLinked<float> & stack){
	float result=0.0;
	int len=postfix.length();
	for(int i=0; i<len; i++){
		if(isdigit(postfix[i])){ //IF A NUMBER 0-9, PUSH TO STACK
			stack.push(postfix[i]-'0');
		}
		else{ //ELSE POP 2 NUMBERS AND APPLY OPERATOR
			float operand1 = stack.pop();
			float operand2 = stack.pop();
			if(postfix[i]=='+'){
				result=operand2+operand1;
			}
			else if(postfix[i]=='-'){
				result=operand2-operand1;
			}
			else if(postfix[i]=='*'){
				result=operand2*operand1;
			}
			else if(postfix[i]=='/'){
				result=operand2/operand1;
			}
			else if(postfix[i]=='^'){
				result=1;
				for(int i=0;i<operand1;i++){
					result*=operand2;
				}
			}
			stack.push(result); //PUSH RESULT AFTER OPERATOR IS APPLIED
		}
	}
	return stack.pop(); //LASTLY POP THE NUMBER OFF THE STACK
}
