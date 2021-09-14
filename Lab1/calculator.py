import sys
expression = sys.argv[1]
# expression = '2*2-1*3*3/3-5*2-4/2*1'

operators = ["+","-","*","/"]
plusmin = ["+","-"]
muldiv = ["*","/"]

def proc_exp(exp):
    expList = []
    pos = 0
    number = ""
    numberStored = False

    for char in exp:
        if(isOperator(char) and numberStored):
            expList.append(number) 
            pos += 1
            expList.append(char) 
            pos += 1
            numberStored = False
            number = ""
        elif(isOperator(char) and not numberStored):
            expList.append(char)
            pos += 1
        else:
            numberStored = True
            number += char #do nothing 

    if(numberStored):
        expList.append(number)

    return expList

def isOperator(char):
    if(char in operators):
        return True
    return False

def compute(expList):
    pos = 0
    for char in expList:
        if(char == '+'):
            return compute(expList[0:pos]) + compute(expList[pos+1:len(expList)+1])
        elif(char == '-'):
            return compute(expList[pos+1:len(expList)+1]) - compute(expList[0:pos]) # Reverse because I reverse the entire expression due to recurive call trace
        pos += 1

    pos = 0
    for char in expList:
        if(char == '*'):
            return compute(expList[0:pos]) * compute(expList[pos+1:len(expList)+1])
        elif(char == '/'):
            return compute(expList[pos+1:len(expList)+1]) / compute(expList[0:pos]) # Reverse because I reverse the entire expression due to recurive call trace
        pos += 1

    return int(expList[0])

print('Expression:          ',proc_exp(expression))
expressionList = proc_exp(expression)
expressionList.reverse()
print("Reversed Expression: ",expressionList)
print (expression," = ",compute(expressionList))