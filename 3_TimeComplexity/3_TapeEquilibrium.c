// task: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

int solution(int A[], int N) {
    int i = 0, min_i = 0, sum = 0, currentSum = 0, sum1 = 0, sum2 = 0;
    float absDiff = 0, min = 0;
    
    for(i = 0; i < N; i++)
        sum += A[i];
    
    for(i = 0; i < N-1; i++){
        currentSum += A[i];
        /* absDiff = |sum/2 - sum(i from 0 to min_i) A[i]| */
        if(sum/2.0 - currentSum > 0)
            absDiff = sum/2.0 - currentSum;
        else
            absDiff = currentSum - sum/2.0;
        if(i == 0){
            min = absDiff;
            min_i = 0;
        }
        if(absDiff < min){
            min = absDiff;
            min_i = i;
        }
    }    
    
    for(i = 0; i <= min_i; i++)
        sum1 += A[i];
    for(i = min_i+1; i < N; i++)
        sum2 += A[i];
        
    return (sum1 > sum2)? (sum1-sum2) : (sum2-sum1);
}