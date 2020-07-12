# include "MovieTree.cpp"
# include <iostream>
# include <fstream> 
# define debug true

using namespace std;

void menu();

void addData(MovieTree tree, string file_name);

int main(int argc, char* argv[]){
    // get user input
    string ip_file_name;
    if (debug){
        ip_file_name = "Documentaries.csv";
    }
    else{
        ip_file_name = argv[1];
    }
    MovieTree tree;

    // addData(tree, ip_file_name);
    //open the file
    ifstream iFile("/home/karan-m/Documents/learning_hub/learn c++/summer_20_CSCI_2270/Assignments/Assignment 6/" + ip_file_name);

    if (iFile.fail()){
        cout << "Error opening the file. Please make sure you enter the right name" << endl;
        return 0;
    }

    string ranking;
    string rating;
    string year;
    string title;
    int iranking;
    float frating;
    int iyear;
    // the ip format is <ranking>,<title>,<year>,<rating>
    while (getline(iFile, ranking, ',')){
        getline(iFile, title, ',');
        getline(iFile, year, ',');
        getline(iFile, rating);

        // convert to approproate formats
        iyear = stoi(year);
        frating = stof(rating);
        iranking = stoi(ranking);

        tree.addMovieNode(iranking, title, iyear, frating);
    }

    int choice;
    while (1){
        menu();
        cin >> choice;

        switch (choice){

            case 1:{
                string movie;
                cout << "Enter title:" << endl;
                cin.ignore();
                getline(cin, movie);
                tree.findMovie(movie);
                break;
            }

            case 2:{
                float r;
                int y;
                cout << "Enter minimum rating:" << endl;
                cin >> r;
                cout << "Enter minimum year:" << endl;
                cin >> y;
                tree.queryMovies(r, y);
                break;
            }

            case 3:{
                tree.printMovieInventory();
                break;
            }

            case 4:{
                tree.averageRating();
                break;
            }

            case 5:{
                cout << "Goodbye!" << endl;
                return 0;
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

void addData(MovieTree tree, string file_name){
    //open the file
    ifstream iFile("/home/karan-m/Documents/learning_hub/learn c++/summer_20_CSCI_2270/Assignments/Assignment 6/" + file_name);

    if (iFile.fail()){
        cout << "Error opening the file. Please make sure you enter the right name" << endl;
        return;
    }

    string ranking;
    string rating;
    string year;
    string title;
    int iranking;
    float frating;
    int iyear;
    // the ip format is <ranking>,<title>,<year>,<rating>
    while (getline(iFile, ranking, ',')){
        getline(iFile, title, ',');
        getline(iFile, year, ',');
        getline(iFile, rating);

        // convert to approproate formats
        iyear = stoi(year);
        frating = stof(rating);
        iranking = stoi(ranking);

        tree.addMovieNode(iranking, title, iyear, frating);
    }
}