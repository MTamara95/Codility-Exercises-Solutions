# task: https://app.codility.com/programmers/lessons/8-leader/dominator/

def solution (A):
    if(len(A) == 0):
        return -1
    stack = [A[0]]
    N = len(A)
    for i in range (1, N):
        stack.append(A[i])
        if(len(stack) > 1 and stack[len(stack)-1] != stack[len(stack)-2]):
            stack.pop() # A[i]
            stack.pop() # A[i-1]
    # when the stack is empty, we don't have a leader:
    if(len(stack) == 0):
        return -1
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
        return -1
    # else, we have a leader - we will return the position of its first appearance:
    i = 0
    while(True):
        if(A[i] == leader):
            return i
        i += 1
            
    
    
print(solution([2,4,3,2,3,-1,3,3])) # [2,4,3,2,3,-1,3,3]