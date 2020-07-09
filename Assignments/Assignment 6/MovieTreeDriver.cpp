# include "MovieTree.cpp"
# include <iostream>

using namespace std;

void menu();

int main(int argc, char* argv[]){

    int choice;
    while (1){
        menu();
        cin >> choice;

        switch (choice){

            case 1:{
                break;
            }

            case 2:{
                break;
            }

            case 3:{
                break;
            }

            case 4:{
                break;
            }

            case 5:{
                cout << "Goodbye!" << endl;
                break;
            }
        }
    }
}

void menu(){
    cout << "=======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Query movies" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "4. Average Rating of movies" << endl;
    cout << "5. Quit" << endl;
}
