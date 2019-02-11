// task: https://app.codility.com/programmers/lessons/4-counting_elements/perm_check/

int solution(int A[], int N) {
    
    int i = 0, ind = 1;
    int *B = malloc(N*sizeof(int));
    
    for(i = 0; i < N; i++){ /* B = 1, ..., N */
        if(A[i] < 1 || A[i] > N)
            return 0;
        B[i] = i+1;
    }
    printf("\n");
    
    for(i = 0; i < N; i++){
        B[A[i]-1] = 0; /* all elements A[i] are in range [1,N] */
    }
        
    for(i = 0; i < N; i++){
        if(B[i] != 0){
            ind = 0;
            break;
        }
    }
    
    free(B);
        
    return ind;
    
}