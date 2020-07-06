# include "RPNCalculator.cpp"

using namespace std;

bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main(int argc, char* argv[]){
    
    // instantiate a stack of type RPNCalculator
    RPNCalculator stk;
    string s;

    cout << "Enter the operators and operands ('+', '*') in a postfinc format" << endl;
    // cin.ignore();
    getline(cin, s);
    while (true){
        // push the operator/operand to the stack and keep doing so until the user enters "="
        if (isNumber(s)){
            stk.push(stof(s));
            // getline(cin, s);
        }
        else if (s != "="){
            stk.compute(s);
        }
        else
        {
            if (stk.isEmpty()){
                cout<< "No operands: Nothign to evaluate";
                return -1;
            }

            // check if the expression is invalid
            else if (stk.getStackHead()->next != NULL){
                cout << "Invalid Expression" << endl;
                return -1;
            }

            else{
                cout <<  stk.peek()->number << endl;
                return 0;
            }
        }
        getline(cin, s);
    }
}

