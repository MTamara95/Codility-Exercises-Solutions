# task: https://app.codility.com/programmers/lessons/7-stacks_and_queues/nesting/

def solution(S):
    stack = []
    for i in range(0, len(S)):
        if(S[i] == '('):
            stack.append('(')
        else: # S[i] = ')'
            if(len(stack) == 0):
                return 0
            stack.pop()
        i = i+1
    if(len(stack) == 0):
        return 1
    return 0