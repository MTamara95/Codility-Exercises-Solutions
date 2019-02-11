# task: https://app.codility.com/programmers/lessons/8-leader/equi_leader/

def tmp (A):
    if(len(A) == 0):
        return 1000000001 # indicator couldn't be -1, because the element -1 is maybe a leader
    elif(len(A) == 1):
        return A[0]
    stack = [A[0]]
    N = len(A)
    for i in range (1, N):
        stack.append(A[i])
        if(len(stack) > 1 and stack[len(stack)-1] != stack[len(stack)-2]):
            stack.pop() # A[i]
            stack.pop() # A[i-1]
    # when the stack is empty, we don't have a leader:
    if(len(stack) == 0):
        return 1000000001
    # when the stack isn't empty but number of leaders appearances is
    # less or equal than N/2, we don't have a leader too:
    leader = stack[len(stack)-1]
    i = 0
    count = 0
    while(True):
        if(i == N):
            break
        if(A[i] == leader):
            count += 1
        i += 1
    if(count <= N//2):
        return 1000000001
    # else, we have a leader - we will return the position of its first appearance:
    i = 0
    while(True):
        if(A[i] == leader):
            return leader
        i += 1
           
            
def solution(A):
    res = 0
    N = len(A)
    i = 0
    # the equileader must be equals to a leader
    leader = tmp(A)
    totalNum = 0
    for i in range(0, N):
        if(A[i] == leader):
            totalNum += 1
    leftNum = 0
    rightNum = totalNum
    for i in range(0, N-1):
        if(A[i] == leader):
            leftNum += 1
            rightNum -= 1
        if(leftNum > (i+1)/2 and rightNum > (N-i-1)/2):
            res += 1
    return res
