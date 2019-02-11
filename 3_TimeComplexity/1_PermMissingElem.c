// task: https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

int solution(int A[], int N) {
        
    int res = 0, i = 0, sum1 = 0, sum2 = 0;
    
    /* sum1 - sum of the elements from 1 to N+1 */
    for(i = 1; i < N+2; i++){
        sum1 += i;
    }
    
    /* sum2 - sum of the elements of the array */
    for(i = 0; i < N; i++){
        sum2 += A[i];
    }
    
    return sum1 - sum2;
}