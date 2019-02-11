# task: https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/

def solution(S):
    stack = []
    tmp = ''
    for i in range(0, len(S)):
        if(S[i] == '(' or S[i] == '{' or S[i] == '['):
            stack.append(S[i])
        else: # S[i] = ')' or '}' or ']'
            if(len(stack) == 0):
                return 0
            tmp = stack.pop()
            if((tmp == '(' and S[i] == ')') or (tmp == '{' and S[i] == '}') or (tmp == '[' and S[i] == ']')):
                continue
            return 0
        i = i+1
    if(len(stack) == 0):
        return 1
    return 0