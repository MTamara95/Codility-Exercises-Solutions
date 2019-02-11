// task: https://app.codility.com/programmers/lessons/6-sorting/triangle/

#include<limits.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}   

int solution(int A[], int N) {
    int i = 0;
    
    qsort(A, N, sizeof(int), cmpfunc); /* when the array is sorted, it's enough to check if A[i] + A[i+1] > A[i+2];
       with this condition, for sorted array this is true: A[i+2] + A[i+1] > A[i] and A[i+2] + A[i] > A[i+1] */
    
    /* zero, one or two elements cannot form a triplet: */
    if(N < 3)
        return 0;
        
    for(i = 0; i < N-2; i++){
        /* first special case - ..., INT_MAX, INT_MAX: */
        if(A[i+1] == INT_MAX){
            if(A[i] <= 0)
                return 0;
            else // A[i] > 0 /* sum of A[i] and A[i+1] will be some negative value, because of overflow */
                return 1;
        }
            
        /* second special case - INT_MIN, INT_MIN, ...: */
        if(A[i+1] == INT_MIN)
            return 0;
        
        /* end with checking special cases; continue with normal checking: */
        if(A[i] + A[i+1] > A[i+2])
            return 1;
    }
        
    return 0;
    
}