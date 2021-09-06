class calculator{
    public static void main() {
        
    }
}

vector<string> proc_exp(string expression);
int compute(vector<string>* expression);
bool isOperator(char value);

int main(int argc, char const *argv[])
{
    string expression = "1+1-2";
    vector<string>* expList = proc_exp(expression);
    int value = compute(expList);
    cout << value <<endl;
    
    return 0;
}

vector<string>* proc_exp(string expression){
    vector<string>* expressionList;
    int pos = 0;
    string number = "";
    bool numberStored = false;

    for(int pos = 0;pos < expression.size();pos++){
        if(isOperator(expression.at(pos)) && numberStored){
            expressionList->push_back(number);
            string op(1,expression.at(pos));
            expressionList->push_back(op);
            pos++;
            
            numberStored = false;
            number = "";
        }
        else if(isOperator(expression.at(pos)) && !numberStored){
            string op(1,expression.at(pos));            
            expressionList->push_back(op);
            pos++;
        }
        else{
            numberStored = true;
            number += expression.at(pos);
        } 
    }

    if(numberStored)
        expressionList->push_back(number);

    return expressionList;
}

bool isOperator(char value){
    bool op = false;
    if(value == '+' ||value == '*' || value == '/' || value == '-')
        op = true;
    return op;
}

int compute(string* expression){
    return 0;
}