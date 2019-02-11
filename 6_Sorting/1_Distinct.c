// task: https://app.codility.com/programmers/lessons/6-sorting/distinct/

#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}   

int solution(int A[], int N) {
    int i = 0, res = 0;
    
    qsort(A, N, sizeof(int), cmpfunc);
    
    if(N == 0)
        return 0;
    if(N == 1)
        return 1;
    for(i = 0; i < N-1; i++){
        if(A[i] != A[i+1])
            res++;
    }
        
    return res+1;
    
}

//int main() {
//   
//   int A[] = {1,2,3,3,3,4,4,5,5};
//   int res = 0, N = 9;
//   
//   res = solution(A, N);
//   printf("%d\n", res);
//   
//   return 0;
//   
//}