#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string> proc_exp(string expression);
int compute(vector<string> expression);
bool isOperator(char value);
vector<string> sub(vector<string> const &v, int m, int n);

int main(int argc, char const *argv[])
{
    string expression = argv[1];
    vector<string> expList = proc_exp(expression);
    reverse(expList.begin(),expList.end());
    int value = compute(expList);
    cout << value <<endl;

    return 0;
}

vector<string> proc_exp(string expression){
    vector<string> expressionList;
    int pos = 0;
    string number = "";
    bool numberStored = false;

    for(int pos = 0;pos < expression.size();pos++){
        if(isOperator(expression.at(pos)) && numberStored){
            expressionList.push_back(number);
            string op(1,expression.at(pos));
            expressionList.push_back(op);
            numberStored = false;
            number = "";
        }
        else if(isOperator(expression.at(pos)) && !numberStored){
            string op(1,expression.at(pos));            
            expressionList.push_back(op);
        }
        else{
            numberStored = true;
            number += expression.at(pos);
        } 
    }

    if(numberStored)
        expressionList.push_back(number);

    return expressionList;
}

bool isOperator(char value){
    bool op = false;
    if(value == '+' ||value == '*' || value == '/' || value == '-')
        op = true;
    return op;
}

int compute(vector<string> expression){
    int pos = 0;
    for(pos = 0;pos < expression.size();pos++){
        if(expression[pos] == "+"){
            return compute(sub(expression,0,pos-1)) + compute(sub(expression,pos+1,expression.size()-1));
        }else if(expression[pos] == "-"){
         return compute(sub(expression,pos+1,expression.size()-1)) - compute(sub(expression,0,pos-1));
        }else{
            //do nothing
        }
    }

    for(pos = 0;pos < expression.size();pos++){
        if(expression[pos] == "*"){
            return compute(sub(expression,0,pos-1)) * compute(sub(expression,pos+1,expression.size()-1));
        }else if(expression[pos] == "/"){
         return compute(sub(expression,pos+1,expression.size()-1)) / compute(sub(expression,0,pos-1));
        }else{
            //do nothing
        }
    }

    return stoi(expression[0]);
}

/**
 * Inclusion Subvector
 * 
 **/
vector<string> sub(vector<string> const &v, int m, int n) {
   auto first = v.begin() + m;
   auto last = v.begin() + n + 1;
   vector<string> vector(first, last);
   return vector;
}
// import sys
// expression = sys.argv[1]
// # expression = '2*2-1*3*3/3-5*2-4/2*1'

// operators = ["+","-","*","/"]
// plusmin = ["+","-"]
// muldiv = ["*","/"]

// def proc_exp(exp):
//     expList = []
//     pos = 0
//     number = ""
//     numberStored = False

//     for char in exp:
//         if(isOperator(char) and numberStored):
//             expList.append(number) 
//             pos += 1
//             expList.append(char) 
//             pos += 1
//             numberStored = False
//             number = ""
//         elif(isOperator(char) and not numberStored):
//             expList.append(char)
//             pos += 1
//         else:
//             numberStored = True
//             number += char #do nothing 

//     if(numberStored):
//         expList.append(number)

//     return expList

// def isOperator(char):
//     if(char in operators):
//         return True
//     return False

// def compute(expList):
//     pos = 0
//     for char in expList:
//         if(char == '+'):
//             return compute(expList[0:pos]) + compute(expList[pos+1:len(expList)+1])
//         elif(char == '-'):
//             return compute(expList[pos+1:len(expList)+1]) - compute(expList[0:pos]) # Reverse because I reverse the entire expression due to recurive call trace
//         pos += 1

//     pos = 0
//     for char in expList:
//         if(char == '*'):
//             return compute(expList[0:pos]) * compute(expList[pos+1:len(expList)+1])
//         elif(char == '/'):
//             return compute(expList[pos+1:len(expList)+1]) / compute(expList[0:pos]) # Reverse because I reverse the entire expression due to recurive call trace
//         pos += 1

//     return int(expList[0])

// print('Expression:          ',proc_exp(expression))
// expressionList = proc_exp(expression)
// expressionList.reverse()
// print("Reversed Expression: ",expressionList)
// print (expression," = ",compute(expressionList))