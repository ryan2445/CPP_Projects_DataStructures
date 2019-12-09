//RYAN HOFFMAN - CS302 - PROJECT 1 - DELIMITERS
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
#include "StackLinked.cpp"

bool delimetersOk(const string & expression);

int main(){
//	string input = "";
//	cout << "Input: ";
//	cin >> input;
//	cout << input << " ok? -> " << (delimetersOk(input) ? "Ok" : "Not Ok") << endl;
	cout << "(()()) ok? -> " << (delimetersOk("(()())") ? "Ok" : "Not Ok") << endl;
	cout << "(()() ok? -> " << (delimetersOk("(()()") ? "Ok" : "Not Ok") << endl;
	cout << "{()(} ok? -> " << (delimetersOk("{()(}") ? "Ok" : "Not Ok") << endl;
	cout << "<>[(] ok? -> " << (delimetersOk("<>[(]") ? "Ok" : "Not Ok") << endl;
	cout << "[{()}] ok? -> " << (delimetersOk("[{()}]") ? "Ok" : "Not Ok") << endl;
	return 0;
}

bool delimetersOk(const string & expression){
	StackLinked<char> stack;
	for(int i=0;i<expression.length();i++){ //IF CHAR FROM STRING IS OPENING, PUSH TO STACK. IF CHAR IS CLOSING, POP.
		if(expression[i]=='[' || expression[i]=='(' || expression[i]=='<' || expression[i]== '{'){
			stack.push(expression[i]);
		}
		else{
			stack.pop();
		}
	}
	if(stack.isEmpty()){ //IF OK, STACK WILL BE EMPTY IN THE END
		return 1;
	}
	return 0;
}
