# include "ProducerConsumer.hpp"

using namespace std;

ProducerConsumer::ProducerConsumer(){
    // set queueFront and queueEnd to o
}

bool ProducerConsumer::isEmpty(){
    // A function that returns true if the queue is empty else false
}

bool ProducerConsumer::isFull(){
    // A function that return true is queue is full else false
}

void ProducerConsumer::enqueue(string item){
    // A function to add an item to the end of the queue and throw an error is the queue is full
}

void ProducerConsumer::dequeue(){
    // A function to remove the first item from the queue if its not empty else throw an error
}

int ProducerConsumer::queueSize(){
    // A function that returns the number of items in the queue
}

string ProducerConsumer::peek(){
    // A function to return the first element of the queue
}