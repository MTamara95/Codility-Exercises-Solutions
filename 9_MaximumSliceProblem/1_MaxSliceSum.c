// task: https://app.codility.com/programmers/lessons/9-maximum_slice_problem/max_slice_sum/

int solution(int A[], int N) {
    int i = 0, max = A[0], currMax = A[0];
    
    for(i = 1; i < N; i++){
/*
        if(currMax + A[i] < currMax)
            currMax = A[i];
        else 
*/
	   if(currMax + A[i] < A[i])
            currMax = A[i];
        else
            currMax += A[i];
        if(currMax > max)
            max = currMax;
    }
    
    return max;
    
}


