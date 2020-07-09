# include "RPNCalculator.hpp"
using namespace std;

RPNCalculator::RPNCalculator(){
    stackHead = NULL;
}

RPNCalculator::~RPNCalculator(){
    // pop everything off the stack and set stack head to NULL
    while (!isEmpty()){
        pop();
    }

}

bool RPNCalculator::isEmpty(){
    // A function that return true if the stack is empty

    if (stackHead == NULL){
        return true;
    }

    return false;
}

void RPNCalculator::push(float num){
    // A function to insert a new node with value @num onto the top of the stack
    
    if (!isEmpty()){
        Operand* new_node = new Operand;
        new_node->number = num;
        new_node->next = stackHead;
        stackHead = new_node;
    }

    else{
        Operand* new_node = new Operand;
        new_node->number = num;
        new_node->next = nullptr;
        stackHead = new_node;
    }

}

void RPNCalculator::pop(){
    // if the stack is empty throw error else delete the top most item from the stack
    if (isEmpty()){
        cout << "Stack empty, cannot pop an item" << endl;
        return;
    }
    else{

        Operand *tmp = stackHead;
        stackHead = tmp->next;
        delete tmp;
    }
}

Operand* RPNCalculator::peek(){
    // if the stack is empty throw error else return a pointer to the top of the stack
    if (isEmpty()){
        cout << "Stack empty, cannot peek" << endl;
        return NULL;
    }
    else{
        return stackHead;
    }
}

bool RPNCalculator::compute(string symbol){
    // if operation is done succesfully they return true else false
    // symbol should be either " + " or " * " else throw error. 
    if (symbol != "+" and symbol != "*"){
        cout << "err: invalid operation";
        return false;
    }
    else{

        Operand first;
        Operand second;

        if (stackHead == nullptr or stackHead->next == nullptr){
            cout << "err: not enought operands" << endl;
            return false;
        }

        first = *stackHead;
        second = *stackHead->next;

        // call pop twice
        pop();
        pop();

        double val = (symbol == "+") ? (first.number + second.number) : (first.number * second.number); 

        // push this number to the stack
        push(val);
    }
}
