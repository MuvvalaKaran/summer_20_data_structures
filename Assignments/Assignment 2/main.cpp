// file to implement the work in Assignment 
# include <fstream>
# include <iostream>
# include <string>
# include <sstream>
# include <tuple>
// flag to enter the debug when we do not ask the user inputs!
# define debug false

using namespace std;

struct wordItem {
    string word;
    int count ;
};

string get_current_dir(){
    return "/home/karan-m/Documents/learning_hub/learn c++/summer_20_CSCI_2270/Assignments/Assignment 2/";
}

void getStopWords(const char *ignoreWordsFileName, string ignoreWords[]){
    //  A function to read a words in ignoreWords file and store them in the @ignoreWords array.
    // There will be exactly 50 words in this array. 

    ifstream stop_words_handle (get_current_dir() + ignoreWordsFileName);
    
    // throw warning if error in opening file
    if(stop_words_handle.fail()){
        cout << "Failed to open " << ignoreWordsFileName << endl;
    }   

    // variable to store the word written on each line
    string line;
    int id = 0; 
    while(id < 50){
        getline(stop_words_handle, line);
        ignoreWords[id] = line;
        id++;
    }

    // throw warning if you encounter more than the pre defined number of words in the file
    if (id > 50){
        cout << "The file " << ignoreWordsFileName << " contains more that 50 words in it\n";
    } 
}

bool isStopWord(string word, string ignoreWords[]){
    // A function to return True if @word exists in the array of strings @ignoreWords[]
    
    //iterate over the whole array and check each element manually
    for(int j = 0; j < 50; j++){
        if (word == ignoreWords[j]){
            return true;
        }
    }  
    return false;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length){
    // A function to compute the total number of words in the entire document by summing up
    // all the counts of the individual unique words.
    // @length : the length of the uniqueWords array
    int sum = 0;

    for (int k = 0; k < length; k++){
        sum += uniqueWords[k].count;
    }

    return sum;
}

void arraySort(wordItem uniqueWords[], int length){
    /*A function to sort the @uniqueWords array by word count in descending order - big first; small later! 
    @uniqueWords contains @length initialized elements.*/

    for (int i= 0; i < length; i++){
        // for the current element, compare with all the elements after it
        for (int j = i + 1; j < length; j++){
            // if the next element is bigger than the current element
            if (uniqueWords[i].count > uniqueWords[j].count){
                wordItem tmp_word = uniqueWords[j];
                uniqueWords[j] = uniqueWords[i];
                uniqueWords[i] = tmp_word;
            }
        }
    }
}

void reverseArray(wordItem array[], int length){
    // A helper method to rever the given array of wordItem
    wordItem temp;
    int j = length - 1;
    int i = 0;
    while (i < j){
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords){
    // a function to print the NEXT 10 words starting from the index @N from the sorted array @uniqueWords
    cout << "Probability of next 10 words from rank " << N << endl;
    cout << "---------------------------------------------" << endl;
    cout.precision(4);
    for (int ind = N; ind < N +10; ind++){
        float prob_of_occ = (float) uniqueWords[ind].count/totalNumWords;
        cout << fixed << prob_of_occ << " - " << uniqueWords[ind].word << endl;
    }
}

tuple<bool, signed int> checkIfWordInWordArray(wordItem wordArray[], string word, int length){
    // a helper method to check if @word is present in @wordArray
    // NOTE: All algo you are writing are super ineffecient with linear implementation. Maybe improve the implementation in future commits. 
    for (int ind = 0; ind < length; ind++){
        if (wordArray[ind].word == word){
            return {true, ind};
        }
    }
    return {false,-1};
}

bool checkWordInIgnoreArray(string ignoreWords[], string word){

    for(int j = 0; j < 50; j++){
        if (ignoreWords[j] == word){
            return true;
        }
    }
    return false;
}

int getTotalNonCommonWords(wordItem array[], int length){

    int sum = 0;
    for (int k = 0; k < length; k++){
        sum += array[k].count;
    }

    return sum;

}

void addWordToWordArray(wordItem wordArray[],string ignoreWords[], string word, int *length){
    // a helper function to add words to @wordArray. If the word already exists then increment the count
    // @ length : the number of elements in the array
    // check if the word exists or not
    // bool flag = false;
    // int ind; 

    if (!checkWordInIgnoreArray(ignoreWords, word)){
        tuple<bool, int > check = checkIfWordInWordArray(wordArray, word, *length);

        if (get<0>(check)){
            // word already exist in the array so we only increment the count
            wordArray[get<1>(check)].count++;
        }
        else{
            wordArray[*length].word = word;
            wordArray[*length].count = 1;
            *length = *length + 1; 
        }
    }
}

void arrayDoubling(wordItem *&orgArray, int &size, int scale=2){
    size = size * scale;
    wordItem * tmpArray = new wordItem[size];

    for (int i = 0; i< size/2 ; i++){
        tmpArray[i] = orgArray[i]; 
    }

    delete [] orgArray;
    orgArray = tmpArray;
}


int main(int argc,char const* argv[]){

    // N tells us the how many of the most frequent words to print
    // ip_file_name - name of the input file
    // ignore_file_name - name of the file containing words to be ignored 

    string N;
    string ip_file_name;
    const char * ignore_file_name;

    if (debug){
        N = "10";
        ip_file_name = "Tom_Sawyer.txt";
        ignore_file_name = "ignoreWords.txt";
    }
    else{
        if (argc != 4){
            cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl; 
            return 0;
        }
        N = argv[1];
        ip_file_name = argv[2];
        ignore_file_name = argv[3];
        
        // throw warning if correct number of arguments are not passed
        if (debug){
            cout << N << " " << ip_file_name << " " << ignore_file_name << endl;
        }
    }
    
    string ignoreWords[50];
    getStopWords(ignore_file_name, ignoreWords);

    // array to hold the words fom the @ip_file_name file
    int array_size = 100;
    wordItem * unique_arr = new wordItem[array_size];

    // read words from @ip_file_name file
    ifstream ifile (get_current_dir() + ip_file_name);
    string line;
    string word;
    int totalWordCount = 0;
    int wordCount = 0;
    int *ptr_wordCount = &wordCount;

    int count_array_doubling = 1;
    // array doubling : when an array is full we increase its size, then we make the size of
    // thew new size of the array equal to twice its original size - every it doubles it size - exponential increase
    
    while(!ifile.eof()){
        getline(ifile, line);
        stringstream ss(line);
        while(ss >> word){
            totalWordCount++;
            // check if array is full 
            if (wordCount == array_size){
                count_array_doubling++;
                arrayDoubling(unique_arr, array_size);
            }
            // add word to the array
            addWordToWordArray(unique_arr, ignoreWords , word, &wordCount);
        }
    }

    // print the # of times array is doubled
    cout << "Array doubled : " << count_array_doubling << endl;

    // print the # of unique words
    cout << "Unique non-common words: "<< wordCount << endl;

    // print the total number of words
    cout << "Total number of words: " << totalWordCount << endl;

    // print the total non-common words
    int nonCommonWordsCount = getTotalNonCommonWords(unique_arr, wordCount);
    cout << "Total non-common words" << nonCommonWordsCount << endl;
    // unsorted output
    ofstream  write_un_handle ("unsorted_output.txt");
    for (int j = 0 ; j < wordCount; j++){
        write_un_handle << unique_arr[j].word << " , " << unique_arr[j].count << endl;
    }

    // sort them according to the highest frequency 
    arraySort(unique_arr, wordCount);
    reverseArray(unique_arr, wordCount);

    // dump unique array to check the sort function
    ofstream  write_handle ("sort_output.txt");
    for (int j = 0 ; j < wordCount; j++){
        write_handle << unique_arr[j].word << " , " << unique_arr[j].count << endl;
    }

    // print the probability of the words
    printNext10(unique_arr, stoi(N), nonCommonWordsCount);

    return 0;
}