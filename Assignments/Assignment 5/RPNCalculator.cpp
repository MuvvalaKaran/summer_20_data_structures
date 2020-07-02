# include "RPNCalculator.hpp"
using namespace std;

RPNCalculator::RPNCalculator(){
    stackHead = nullptr;
}

RPNCalculator::~RPNCalculator(){
    // pop everything off the stack and set stack head to NULL
}

bool RPNCalculator::isEmpty(){
    // A function that return true if the stack is empty

    if (stackHead == nullptr){
        return true;
    }

    return false;
}

void RPNCalculator::push(float num){
    // A function to insert a new node with value @num onto the top of the stack
}

void RPNCalculator::pop(){
    // if the stack is empty throw error else delete the top most item from the stack
    if (isEmpty){
        cout << "Stack empty, cannot pop an item" << endl;
        return;
    }


}

Operand* RPNCalculator::peek(){
    // if the stack is empty throw error else return a pointer to the top of the stack
    if (isEmpty){
        cout << "Stack empty, cannot peek" << endl;
        return nullptr;
    }
}

Operand* RPNCalculator::getStackHead(){
    // a getter method to return the pointer to the stack head
}

bool RPNCalculator::compute(string symbol){

}
