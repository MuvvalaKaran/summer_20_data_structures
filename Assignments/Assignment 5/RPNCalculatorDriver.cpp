# include "RPNCalculator.hpp"

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

bool checkValidity(RPNCalculator stack);

int main(int argc,char* argv[]){
    
    // instantiate a stack of type RPNCalculator
    RPNCalculator stk;

    cout << "Enter the operators and operands ('+', '*') in a postfinc format" << endl;
    cin.ignore();
    string s;
    getline(cin, s);
    while (s != "s"){
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
            else if (checkValidity){
                cout << "Invalid Expression" << endl;
                return -1;
            }

            else{
                cout <<  stk.getStackHead()->number << endl;
                return 0;
            }
        }
    }
}

bool checkVaidity(RPNCalculator stack){
    // pop anc check if stack is empty if yes then push and return true else push return false
    
    Operand * tmp_node = stack.getStackHead();
    stack.pop();

    if (stack.isEmpty()){
        stack.push(tmp_node->number);
        return true;
    }
    else{
        stack.push(tmp_node->number);
        return false;
    }

