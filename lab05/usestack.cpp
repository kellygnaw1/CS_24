// usestack.cpp - for CS 24 lab practice using stacks
// KELLY WANG 11/08/18

#include "intstack.h"
#include <iostream>
using namespace std;

int main() {
//evaluate (((6*7) + (3)) / 5)
// evaluating "5 3 6 7 * + /"

// start with an empty stack
Stack numbers;

// first 4 tokens all numbers to push "5 3 6 7":
numbers.push(5);//bottom of the stack
numbers.push(3);//3rd of stack
numbers.push(6);//2nd of stack
numbers.push(7);//top of stack

// 5th token is calculation to do "*":
int right = numbers.top();
numbers.pop();
int left = numbers.top();
numbers.pop();
numbers.push(left * right);

// 6th token is another calculation "+":
right = numbers.top();
numbers.pop();
left = numbers.top();
numbers.pop();
numbers.push(left + right);

//7th token is another calculation "/":
right = numbers.top();
numbers.pop();
left = numbers.top();
numbers.pop();
numbers.push(right/left);



// done - print result:
cout << numbers.top() << endl;
    return 0;
}