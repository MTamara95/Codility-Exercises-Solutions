// task: https://app.codility.com/programmers/lessons/5-prefix_sums/passing_cars/

int solution(int A[], int N){
    
    int i = 0, count = 0, tmp = 0;
    
    for(i = 0; i < N; i++){
        if(A[i] == 0)
            tmp++; /* 0 is detected in the array - every 1 is worth for one more */
        else if(A[i] == 1){
            count += tmp; /* 1 is detected in the array - counting existing pairs, with earlier zeros */
            if(count > 1000000000) /* overflow */
                return -1;
        }
    }
    
    return count;
    
}