// file to implement the work in Assignment 
# include <fstream>
# include <iostream>
# include <string>
# include <sstream>
# include <tuple>
# define debug true
using namespace std;

struct wordItem {
    string word;
    int count ;
};

void getStopWords(const char *ignoreWordsFileName, string ignoreWords[]){
    //  A function to read a words in ignoreWords file and store them in the @ignoreWords array.
    // There will be exactly 50 words in this array. 

    ifstream stop_words_handle (ignoreWordsFileName);
    
    // throw warning if error in opening file
    if(stop_words_handle.fail()){
        cout << "Faile to open " << ignoreWordsFileName << endl;
    }   

    // variable to store the word written on each line
    string line;
    int id = 0; 
    while(!stop_words_handle.eof()){
        getline(stop_words_handle, line);
        ignoreWords[id] = line;
        id++;
    }

    // throw warning if you encounter more than the pre defined number of words in the file
    if (id > 50){
        cout << "The" << ignoreWordsFileName << "contains more that 50 words \n";
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
            if (uniqueWords[i].count < uniqueWords[j].count){
                wordItem curr_word = uniqueWords[i];
                uniqueWords[i] = uniqueWords[j];

                // insert the curr element at i + 1  and shift everything else to the right

                for (int k = i+1; k < length; k++){
                    wordItem next_word = uniqueWords[k+1];
                    uniqueWords[k] = curr_word;
                    curr_word = next_word;
                }
            }
        }
    }
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords){
    // a function to print the NEXT 10 words starting from the index @N from the sorted array @uniqueWords
    cout << "Probability of next 10 words from rank " << N << endl;
    cout << "---------------------------------------------" << endl;
    for (int ind = N; ind < N +10; ind++){
        float prob_of_occ = (float) uniqueWords[ind].count/totalNumWords;
        cout << prob_of_occ << " - " << uniqueWords[ind].word << endl;
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

void addWordToWordArray(wordItem wordArray[], string word, int length){
    // a helper function to add words to @wordArray. If the word already exists then increment the count
    // @ length : the number of elements in the array
    // check if the word exists or not
    bool flag = false;
    int ind; 
    tuple<bool, int > check = checkIfWordInWordArray(wordArray, word, length);

    if (get<0>(check)){
        // word already exist in the array so we only increment the count
        wordArray[get<1>(check)].count++;
    }
    else{
        length++;
        wordArray[length].word = word;
        wordArray[length].count = 1; 
    }
}


int main(int argc,char const* argv[]){

    // N tells us the how many of the most frequent words to print
    // ip_file_name - name of the input file
    // ignore_file_name - name of the file containing words to be ignored 
    if (argc != 4){
        cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl; 
        return 0;
    }

    string N = argv[1];
    string ip_file_name = argv[2];
    const char *ignore_file_name = argv[3];
    // throw warning if correct number of arguments are not passed
    if (debug){
        cout << N << " " << ip_file_name << " " << ignore_file_name << endl;
    }
    
    string ignoreWords[50];
    getStopWords(ignore_file_name, ignoreWords);

    // array to hold the words fom the @ip_file_name file
    int array_size = 100;
    struct wordItem word_arr[array_size];

    // read words from @ip_file_name file
    ifstream ifile (ip_file_name);
    string line;
    string word;
    int * wordCount = 0;

    int count_array_doubling = 1;
    // array doubling : when an array is full we increase its size, then we make the size of
    // thew new size of the array equal to twice its original size - every it doubles it size - exponential increase
    
    while(!ifile.eof()){
        getline(ifile, line);
        stringstream ss(line);
        while(ss >> word){
            // wordCount++;
            // check if array is full 
            if (*wordCount == array_size){
                count_array_doubling++;
                // tmp array to hold the old value 
                struct wordItem tmp_word_arr[array_size];

                // copy all old values
                for (int k = 0; k < array_size; k++){
                    tmp_word_arr[k] = word_arr[k];
                }

                // create an array of size = 2 * array_size
                array_size = 2* array_size;
                struct wordItem word_arr[array_size];

                // iterate over all the previous elements and store it in the new variable
                for (int k = 0; k < array_size/2; k++){
                    word_arr[k] = tmp_word_arr[k];
                }
            }
            // if the word was not encounter before then increment count 
            // tuple <bool, int> c = checkIfWordInWordArray(word_arr, word, wordCount); 
            
            // if (!get<0>(c)){
            //     wordCount++;
            // }
            // add words to the array
            addWordToWordArray(word_arr, word, *wordCount);
        }

        // print the # of times array is doubled
        cout << "Array doubled : " << count_array_doubling << endl;

        // print the # of unique words
        cout << "Unique non-common words: " << endl;

        // print the total non-common words
        cout << "Total non-common words: " << endl;

        // print the probability of the words
        printNext10(NULL, NULL, NULL);

        
    
    }

    return 0;
}