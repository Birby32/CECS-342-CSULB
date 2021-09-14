
// let expression = sys.argv[1]
// let expression = '2*2-1*3*3/3-5*2-4/2*1'
let expression = process.argv[2]

const operators = ["+","-","*","/"]
const plusmin = ["+","-"]
const muldiv = ["*","/"]
 
function proc_exp(exp){
    const expList = []
    let number = ""
    let numberStored = false

    for(pos=0;pos < exp.length; pos++){
        let char = exp.charAt(pos)
        if(isOperator(char) && numberStored){
            expList.push(number) 
            expList.push(char) 
            numberStored = false
            number = ""
        }else if(isOperator(char) && !numberStored){
            expList.push(char)
            pos += 1
        }else{
            numberStored = true
            number += char //do nothing 
        }
    }

    if(numberStored){
        expList.push(number)
    }
    return expList
}

function isOperator(char){
    if(operators.indexOf(char) > -1){
        return true
    }
    return false
}

function compute(expList){
    let pos = 0
    let char = ''

    for(pos = 0;pos < expList.length;pos++){
        char = expList[pos]
        if(char == '+'){
            return compute(expList.slice(0,pos)) + compute(expList.slice(pos+1,expList.length+1))
        }else if(char == '-'){
            return compute(expList.slice(pos+1,expList.length+1)) - compute(expList.slice(0,pos)) // Reverse because I reverse the entire expression due to recurive call trace
        }else{
            //do nothing
        }
    }

    for(pos = 0;pos < expList.length;pos++){
        char = expList[pos]
        if(char == '*'){
            return compute(expList.slice(0,pos)) * compute(expList.slice(pos+1,expList.length+1))
        }else if(char == '/'){
            return compute(expList.slice(pos+1,expList.length+1)) / compute(expList.slice(0,pos)) // Reverse because I reverse the entire expression due to recurive call trace
        }
    }

    return parseInt(expList[0])
}

// console.log('Expression:          ',proc_exp(expression))
expressionList = proc_exp(expression)
expressionList.reverse()
// console.log("Reversed Expression: ",expressionList)
console.log (expression," = ",compute(expressionList))