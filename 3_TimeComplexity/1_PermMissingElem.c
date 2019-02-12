// task: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

int solution(int A[], int N) {
        
    int res = 0, i = 0, sum1 = 0, sum2 = 0;
    
    /* sum1 - sum of the elements from 1 to N+1;
	 * calculate on this way because (N+1)*(N+2) can make an overflow */
	if ((N + 1) % 2 == 0) {
		sum1 = ((N + 1) / 2)*(N + 2);
	}
	else {
		sum1 = (N + 1)*((N + 2) / 2);
	}
    
    /* sum2 - sum of the elements of the array */
    for(i = 0; i < N; i++){
        sum2 += A[i];
    }
    
    return sum1 - sum2;
}