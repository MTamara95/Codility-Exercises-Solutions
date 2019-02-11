// task: https://app.codility.com/programmers/lessons/6-sorting/max_product_of_three/

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}   

int solution(int A[], int N) {
    
    int max = 1;
    
    qsort(A, N, sizeof(int), cmpfunc);
        
    if(A[0]*A[1]*A[N-1] > A[N-3]*A[N-2]*A[N-1])
        max = A[0]*A[1]*A[N-1];
    else
        max = A[N-3]*A[N-2]*A[N-1];
        
    return max;
    
}