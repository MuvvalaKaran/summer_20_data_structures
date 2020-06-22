// file to implement the work in Assignment 
# include <fstream>
# include <iostream>
# include <string>

using namespace std;

struct wordItem {
    string word;
    int count ;
};

void getStopWords(const char *ignoreWordsFileName, string ignoreWords[]){
    //  A function to read a words in ignoreWords file and store them in the @ignoreWords array.
    // There will be exactly 50 words in this array. 

    ifstream stop_words_handle ("ignoreWordsFileName");
    
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


int main(int argc,char const* argv[]){

    // N tell us the how many of the most frequent words to print
    // ip_file_name - name of the input file
    // ignore_file_name - name of the file containing words to be ignored 

    // throw warning if correct number of arguments are not passed
    if (argc != 4){
        cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> \ 
        <ignoreWordsfilename.txt>" << endl; 
    }

    return 0;
}