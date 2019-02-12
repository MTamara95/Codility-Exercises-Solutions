// task: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

int solution(int A[], int N) {

    int i = 0, min_i = 0, sum = 0, currentSum = 0, restSum = 0;
    float absDiff = 0, min = 0;
    
    for(i = 0; i < N; i++)
        sum += A[i];
	restSum = sum;

    for(i = 0; i < N-1; i++){
        currentSum += A[i];
		restSum -= A[i];
		absDiff = (currentSum > restSum) ? (currentSum - restSum) : (restSum - currentSum);
        if(i == 0){
            min = absDiff;
            min_i = 0;
        }
        if(absDiff < min){
            min = absDiff;
            min_i = i;
        }
    }
        
    return min;
}