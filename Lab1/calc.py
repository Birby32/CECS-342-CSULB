import re
import string

def lex_string(s):
    s = re.sub(r"\s", r"", s)
    ret = []
    i = 0
    paren_depth = 0
    while i < len(s):
        if s[i] in string.digits:
            rnum = re.search(r"\d*", s[i:]).group(0)
            ret.append(("digit", int(rnum), paren_depth))
            i += len(rnum)
        elif s[i] in "+-":
            ret.append(("add", s[i], paren_depth))
            i += 1
        elif s[i] in "*/":
            ret.append(("mult", s[i], paren_depth))
            i += 1
        elif s[i] == "(":
            ret.append(("lparen", s[i], paren_depth))
            i += 1
            paren_depth += 1
        elif s[i] == ")":
            paren_depth -= 1
            ret.append(("rparen", s[i], paren_depth))
            i+= 1
        elif s[i] == "^":
            ret.append(("exp", s[i], paren_depth))
            i += 1
        else:
            raise ValueError("I'm panicking over invalid input!")
    return ret

def E(tokens):
    return S(tokens)

def S(tokens):
    ret = T(tokens)
    if ret:
        return ret
    else:
        add_index = [i for (i, e) in enumerate(tokens) if e[0] == "add"][-1]
        e = E(tokens[:add_index])
        t = T(tokens[add_index+1:])
        # print(e, t)
        return [e, tokens[add_index], t]
            
    
def T(token):
    if len(token) > 1:
        return None
    if token[0][0] == "digit" and len :
        return token[0][1]
    
ptree = E(lex_string("2+3+4+15+2"))
print(ptree)

def process_tree(ptree):
    total = 0
    neg = False
    for e in ptree:
        if type(e) is list:
            # print(add_tree(e))
            total = total + process_tree(e)
        elif type(e) is tuple and e[0] == 'add':
            if e[1] == '-': 
                neg = True
            else:
                neg = False
        else:
            if neg:
                e *= -1
            total += e
    return total

print(process_tree(ptree))

print(process_tree(E(lex_string("3-5+10"))))