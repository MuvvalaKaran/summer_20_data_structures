# include <iostream>
# include "ProducerConsumer.hpp"

using namespace std;

ProducerConsumer::ProducerConsumer(){
    // set queueFront and queueEnd to 0
    queueFront = 0;
    queueEnd = 0;
}

bool ProducerConsumer::isEmpty(){
    // A function that returns true if the queue is empty else false
    return (queueFront == queueEnd);
}

bool ProducerConsumer::isFull(){
    // A function that return true is queue is full else false
    int c = 0;
    // the circular queue is full if the # of elements in the array = the capacity
    // make local copies of the HEAD and TAIL indices
    int local_queueFront = queueFront;
    int local_queueEnd = queueEnd;
    
    if (local_queueEnd + 1 == local_queueFront){
        return true;
    }
    
    while ((local_queueFront != queueEnd) && (local_queueFront < 20)){
        local_queueFront++;
        c++;
    }
    if (c == SIZE){
        return true;
    }
    else{
        return false;
    }
}

void ProducerConsumer::enqueue(string item){
    // A function to add an item to the end of the queue and throw an error is the queue is full
    if (isFull()){
        cout << "Queue full, cannot add new item" << endl;
    }
    else{
        queue[queueEnd] = item;
        if (queueEnd == 19){ 
            queueEnd = 0;
        }
        else
        {
            queueEnd++;
        }
        
        counter++; 
    }
}

void ProducerConsumer::dequeue(){
    // A function to remove the first item from the queue if its not empty else throw an error
    if (isEmpty()){
        cout << "Queue empty, cannot dequeue an item" << endl;
    }
    else{
        string val = queue[queueFront];
        
        if (queueFront == 19){
            queueFront = 0;
        }
        else{
            queueFront++;
        }

        counter--;    
    }

}

int ProducerConsumer::queueSize(){
    // A function that returns the number of items in the queue
    return counter;
}

string ProducerConsumer::peek(){
    // A function to return the first element of the queue
    if(isEmpty()){
        cout << "Queue empty, cannot peak" << endl;
    }
    else{
        return queue[queueFront];
    }
}