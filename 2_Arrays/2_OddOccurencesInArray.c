// task: https://app.codility.com/programmers/lessons/2-arrays/odd_occurrences_in_array

int solution(int A[], int N) {

    int res = 0, i = 0;
    
    for(i = 0; i < N; i++){
        res ^= A[i];
    }
    
    return res;
}