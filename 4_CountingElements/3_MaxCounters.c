// task: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

struct Results solution(int N, int A[], int M){
    
    struct Results res;
    int *numOfReps = malloc(N*sizeof(int));
    int i = 0, j = 0, maxCurr = 0, max = 0, previous = 0;
    
    res.L = N;
    
    /* initialization of the array numOfReps - all zeros: */
    for(i = 0; i < N; i++)
        numOfReps[i] = 0;
    
    for(i = 0; i < M; i++){
        if((maxCurr != 0) && (A[i] == N+1)){
            max += maxCurr;
            maxCurr = 0;
            for(j = previous; j < i; j++)
                numOfReps[A[j]-1] = 0;
            previous = i+1;
        }
        else if(A[i] < N+1){ 
            (numOfReps[A[i]-1])++;
            if(numOfReps[A[i]-1] > maxCurr)
                maxCurr = numOfReps[A[i]-1];
        }
    }
    
    for(i = 0; i < N; i++)
        numOfReps[i] += max;
    
    res.C = numOfReps;
    return res;
    
}