// task: https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/peaks/

#include <stdio.h>
#include <stdlib.h>


int solution(int A[], int N) {
    
    if(N == 1 || N == 2)
        return 0;
        
    int i = 0, j = 0, peaksN = 0, max = 0, indI = 0;
    int *peaks = malloc(N*sizeof(int));
    int *ind = malloc(N*sizeof(int));
    
    // identifying peaks:
    ind[0] = ind[N-1] = 0;
    for(i = 1; i < N-1; i++){
        if(A[i] > A[i-1] && A[i] > A[i+1]){
            peaks[peaksN++] = i;
            ind[i] = 1;
            i++;
        }
        else
            ind[i] = 0;
    }
    
    if(peaksN == 0 || peaksN == 1)
        return peaksN;
    if(peaksN == 2 && (peaks[0] > N/2 || peaks[1] < N/2))
        return 1;
    if(peaksN == 2)
        return 2;
    
    max = (peaks[0]+1 > N-peaks[peaksN-1])? (peaks[0]+1) : (N-peaks[peaksN-1]); // max is >= than that value
    while(N%max != 0 && max < N)
        max++;
    
    for(i = 0; i <= N/max-1; i++){
        if(max == N)
            break;
        indI = 0;
        for(j = 0; j < max; j++){
            if(ind[i*max+j] == 1){
                indI = 1;
                break;
            }
        }
        if(indI == 1)
            continue;
        // indI = 0 - u tom intervalu nema peaks
        max++;
        while(N%max != 0 && max < N)
            max++;
        i = 0; // resetujemo proveru
    }
    
    free(ind);
    free(peaks);
    
    return N/max;
    
}

//int main() {
//    
//    int A[] = {0, 1, 0, 0, 1, 0, 0, 1, 0};
//    int N = 9, res = 0;
//    
//    res = solution(A, N);
//    printf("%d\n", res);
//    
//    return 0;
//}