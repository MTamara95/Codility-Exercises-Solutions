// task: https://app.codility.com/programmers/lessons/4-counting_elements/missing_integer/

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}   
    
int solution(int A[], int N) {
    
    int i = 0, num = 1;
    
    qsort(A, N, sizeof(int), cmpfunc);
    
    for(i = 0; i < N; i++){
        if(A[i] == num)
            num++;
        else if(A[i] > num)
            return num;
    }
    
    return num;
    
}