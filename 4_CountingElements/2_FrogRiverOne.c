// task: https://app.codility.com/programmers/lessons/4-counting_elements/frog_river_one/

int solution(int X, int A[], int N){
    
    int *B = malloc(X*sizeof(int));
    int i = 0, count = 0;
    
    for(i = 0; i < X; i++)
        B[i] = i+1; /* B: 1 2 ... X */
        
    for(i = 0; i < N; i++){
        if(B[A[i]-1] != 0){
            count++;
            B[A[i]-1] = 0;
        }
        if(count == X)
            break;
    }
    
    if(count != X)
        return -1;
    
    return i;
    
}