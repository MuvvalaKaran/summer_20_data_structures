# include <iostream>
# include <fstream>
# include <typeinfo>
# include <sstream>
# include <string>

using namespace std;
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

// argc is the total # of arguments
// argv is an array storing all the arguments passed
int main(int argc, char const *argv[]){

    // a hardcoded value of # of ints to expect
    int num_of_ints = 100; 
    // tmp variable to store a variable
    string s_num;
    int i_num;
    int array[num_of_ints] = {0};
    int num_of_arr_ele = 0;
    // create a handle to read the file
    ifstream iFile("/home/karan-m/Documents/learning_hub/learn c++/summer_20_CSCI_2270/Assignments/Assignment\ 1/numbers.txt");

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
}