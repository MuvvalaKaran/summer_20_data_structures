# include "ProducerConsumer.cpp"
# include <iostream>

using namespace std;

void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char * argv[]){
    
    ProducerConsumer obj;
    string opt;
    menu();
    std::cin >>  opt;
    while (1){
        if (stof(opt) == 1){
            int no_of_items;
            cout << "ENter the number of items to be produced:" << endl;
            std::cin >> no_of_items;
 
            for (int k = 0; k < no_of_items; k++){
                string item;
                cout << "Item" << k+1 << ":" << endl;
                std::cin >> item;
                obj.enqueue(item);
            }
        }
        else if (stof(opt) == 2){
            int no_of_items;
            cout << "Enter the number of items to be consumed:" << endl;
            std::cin >> no_of_items;
            for (int k = 0; k < no_of_items; k++){
                if (!obj.isEmpty()){
                    cout << "Consumed: " << obj.peek() << endl;
                    obj.dequeue();
                }
                else
                {
                    cout << "No more items to consume from queue" << endl;
                    break;
                }
               
            }
        }
        else if (stof(opt) == 3)
        {
            cout << "Number of items in the queue :" << obj.queueSize() << endl;
            return -1;
        }
    menu();
    std::cin >> opt;
    }
}