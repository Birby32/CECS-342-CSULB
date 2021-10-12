package Lab1;

import java.util.Vector;
import java.util.Collections;
import java.util.List;

public class calculator{    

    static Boolean isOperator(char value){
        Boolean op = false;
        if(value == '+' ||value == '*' || value == '/' || value == '-')
            op = true;
        return op;
    }

    static Vector<String> proc_exp(String expression){
        Vector<String> expressionList = new Vector<String>();
        String number = "";
        Boolean numberStored = false;
    
        for(int pos = 0;pos < expression.length();pos++){
            if(isOperator(expression.charAt(pos)) && numberStored){
                expressionList.add(number);
                String op = String.valueOf(expression.charAt(pos));
                expressionList.add(op);
                
                numberStored = false;
                number = "";
            }
            else if(isOperator(expression.charAt(pos)) && !numberStored){
                String op = String.valueOf(expression.charAt(pos));
                expressionList.add(op);
            }
            else{
                numberStored = true;
                number += expression.charAt(pos);
            } 
        }


    
        if(numberStored)
            expressionList.add(number);
    
        return expressionList;
    }

    static int compute(Vector<String> expression){

        for(int pos = 0;pos < expression.size();pos++){
            if(expression.get(pos) == "+"){
                return compute(sub(expression,0,pos-1)) + compute(sub(expression,pos+1,expression.size()-1));
            }else if(expression.get(pos) == "-"){
             return compute(sub(expression,pos+1,expression.size()-1)) - compute(sub(expression,0,pos-1));
            }else{
                //do nothing
            }
        }
    
        for(int pos = 0;pos < expression.size();pos++){
            if(expression.get(pos) == "*"){
                return compute(sub(expression,0,pos-1)) * compute(sub(expression,pos+1,expression.size()-1));
            }else if(expression.get(pos) == "/"){
             return compute(sub(expression,pos+1,expression.size()-1)) / compute(sub(expression,0,pos-1));
            }else{
                //do nothing
            }
        }
    
        return Integer.parseInt(expression.get(0));
    }
    
    /**
     * Inclusion Subvector
     * 
     **/
    static Vector<String> sub(Vector<String> v, int m, int n) {
        Vector<String> newvec = new Vector<String>();
        List<String> temp = v.subList(m, n);
        for(int i = 0;i < temp.size();i++){
            newvec.add(temp.get(i));
        }

        return newvec;
    }
    public static void main(String[] args) {
        String expression = "2+3";
        Vector<String> expList = proc_exp(expression);
        Collections.reverse(expList);

        int value = compute(expList);
        System.out.println(value);    
    }
}