# include <iostream>
# include <fstream>
# include <typeinfo>
# include <sstream>
# include <string>

using namespace std;
// problem 2
struct Park {
                string parkname;
                string state;
                int area;
            };

// problem 1 

int insertIntoSortedArray(int *myArray, int numEntries, int newValue){
    // do something

    // variable to hold the # of elements in an array
    int len ;
    int bigger_value;
    // int tmp_value;
    // loop over the entire array and as soon as you find the element larger myValue insert at i and shift others by 1.
    for (int i=0; i < numEntries; i++){
        // if(myArray[i] == 0){ myArray[i] = newValue;}
        if (newValue < myArray[i])
        {
            // insert newValue @ i and shift others by one
            //1. store value at 1 in a tmp variable
            int curr_value = myArray[i];
            myArray[i] = newValue;
            for (int j = i+1; j < numEntries; j++)
            {
                // shift all the elements by 1
                int next_value = myArray[j];
                myArray[j] = curr_value;
                curr_value = next_value;
            }
            break;
        }

        if (i == numEntries - 1){
            myArray[i] = newValue;
            } 
    }

    // len = sizeof(myArray)/ sizeof(int);
    // count elements in an array
    int iterVar = 0;
    while(myArray[iterVar] != 0){
        iterVar++;
    } 

    return iterVar;

}

void addPark(Park parks[], string parkname, string state, int area, int length){
    // no. of items currently stored in the array
    Park p;
    p.parkname = parkname;
    p.state = state;
    p.area = area;
    parks[length] = p;
}


void printList(const Park parks[], int length){
    // length is the numbers of elements in the array 
    for (int i=0; i< length; i++)
    {
        cout << parks[i].parkname << " [" << 
        parks[i].state << "] area: "<< parks[i].area << endl;
    }
}

// argc is the total # of arguments
// argv is an array storing all the arguments passed
int main(int argc, char const *argv[]){
    // get user inputs
    string ip_file_name = argv[1];
    string op_file_name = argv[2];

    string min_area = argv[3];
    long int il_min_area = stol(min_area);

    // create parks array
    Park p_array[100];
    
    int case_num;
    cout << "Enter problem no: \n";
    cin >> case_num;
    // a hardcoded value of # of ints to expect
    int num_of_ints = 100; 
    // tmp variable to store a variable
    string s_num;
    int i_num;
    int array[num_of_ints] = {0};
    int num_of_arr_ele = 0;
    // create a handle to read the file
    ifstream iFile("/home/karan-m/Documents/learning_hub/learn c++/summer_20_CSCI_2270/Assignments/Assignment 1/numbers.txt");

    switch (case_num){
        case 1:
            // do operations related to problem 1

            if (iFile.fail()){
                cout << "Failed to open the file. \n";
                return 0;
            }
            while (getline(iFile, s_num)){
                i_num = stoi(s_num);
                num_of_arr_ele++;
                num_of_arr_ele = insertIntoSortedArray(array,num_of_arr_ele , i_num);
            }

            // print the array
            for (int k = 0; k<num_of_arr_ele; k++){
                cout << array[k] << endl;
            }

            if(num_of_arr_ele == num_of_ints)
            {
                // once done looping over all the elements dump the output to a txt file
                ofstream oFile ("sorted_array_output.txt");
                for (int k = 0; k < num_of_ints; k++){
                    oFile << array[k] << endl;
                } 
            }

            return 0;
        case 2:
            ip_file_name = "/home/karan-m/Documents/learning_hub/learn c++/summer_20_CSCI_2270/Assignments/Assignment 1/park.csv";
            ifstream file_handle(ip_file_name);
            string tmp_S;
            string p_name = "";
            string p_state ="";
            string p_area = "";
            
            
            // stringstream ss;
            // variable to keep track of the number of lines
            int iternum = 0;
            int idx = 0;
            // parse through each line
            // while (!file_handle.eof()){
            //     int i;
            //     iternum++;
            //     getline(file_handle, tmp_S);
            //     for (i=0; i<tmp_S.length(); i++){
            //         if (tmp_S[i] == ','){
            //             for (int j = 0; j < i; j++){
            //                 p_name = p_name + tmp_S[j];
            //             }
            //         }
            //         cout << p_name;
            //         i++;
            //         for (int j = i; j < i+2; j++){
            //             p_state = p_state + tmp_S[j];
            //         }
            //         cout << p_state;
            //         i++;
            //         for (int j = i+2; j < tmp_S.length(); j++){
            //             p_area = p_area + tmp_S[j];
            //         }
            //         i = tmp_S.length();
            //         cout << p_area;
            //     }

            //     if (p_area != ""){
            //         // addPark(p_array, p_name, p_state, stoi(p_area), iternum);
            //     }
            //     p_name = "";
            //     p_state = "";
            //     p_area = "";
            // }
            int i = 0;
            while(getline(file_handle, tmp_S, '\n')){
                while (i < 3){
                    getline(file_handle, tmp_S, ',');
                    cout << "curent string : "<< tmp_S << endl;
                    i++;
                }   
                i = 0;
                
                // use stringstream to break words
                // stringstream s(tmp_S);
                // string word;
                // int count = 0;
                // while (s >> word){
                //     count++;
                //     cout << count << word << " ";
                // }
                // cout << endl;
                
                // first we get a p_name then p_state and then p_area
                // if (idx == 0){
                //     // save p_name
                //     p_name = tmp_S;
                //     idx++;
                //     cout << p_name << " " ;
                //     continue;
                // }
                // if (idx == 1)
                // {
                //     getline(file_handle, tmp_S, ',');
                //     p_state = tmp_S;
                //     idx++;
                //     cout << p_state << " ";
                //     continue;
                // }
                // if (idx == 2)
                // {
                //     // p_area = stoi(tmp_S);
                //     // getline(file_handle, tmp_S, '\n');
                //     // p_area = stoi(tmp_S);
                //     idx = 0;
                //     cout << tmp_S <<endl;
                //     continue;
                // }
                
                
            }


            // printList(p_array, iternum);


            return 0;
            
    }
        

   
}