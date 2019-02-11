// task: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation

struct Results solution(int A[], int N, int K) {
    struct Results result;
    int i = 0, j = 0, tmp = 0;
    int B[N];
    result.N = N;
    
    for(j = 0; j < K; j++){
        for(i = 0; i < N; i++){
            B[i] = A[i];
        }
        tmp = A[N-1];
        for(i = 0; i < N-1; i++){
            A[i+1] = B[i];
        }
        A[0] = tmp;
    }
    
    result.A = A;
    
    return result;
}