// task: https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_profit/

#include<stdio.h>

int solution(int A[], int N){
    if(N == 0 || N == 1)
        return 0;
        
    int i = 0, res = A[1] - A[0], min = A[0];
    
    for(i = 0; i < N; i++){
        if(A[i] < min)
            min = A[i];
        else
            res = (A[i] - min > res)? (A[i]-min) : res;
    }
    
    return (res > 0) ? res : 0;
}

//int main() {
//   int A[] = {23171, 21011, 21123, 21366, 21013, 21367};// {5, 4, 3, 2, 1};
//   int N = 6, res = 0;
//   
//   res = solution(A, N);
//   printf("%i", res);
//}