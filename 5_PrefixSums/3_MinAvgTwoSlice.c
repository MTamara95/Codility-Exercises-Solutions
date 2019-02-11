// task: https://app.codility.com/programmers/lessons/5-prefix_sums/min_avg_two_slice/

/* 2 by 2 el. - if the average of first part is greater, it will break the total average;
 * if the average of second one is greater, the other breaks total average;
 * if the average is equal, if second number from the first part would in the second part, or first number from the second part would in the first part,
 * it might could correct the average - so, minAvg slice contains 2 or 3 parts */

#include<stdio.h>

int solution(int A[], int N){
    
    int i = 0, minI = 0;
    float sum = 0, min = 0;
    
    min = (A[0] + A[1])/2;
    minI = 0;
    for(i = 0; i < N-1; i++){
        sum = (A[i]+A[i+1])/2.0;
        if(sum < min){
            min = sum;
            minI = i;
        }
    }
    for(i = 0; i < N-2; i++){
        sum = (A[i]+A[i+1]+A[i+2])/3.0;
        if(sum < min){
            min = sum;
            minI = i;
        }
    }
    
    return minI;
    
}

//int main() {
//   
//   int A[] = {10, 10, -1, 2, 4, -1, 2, -1};
//   int res = 0, N = 8;
//   
//   res = solution(A, N);
//   printf("%d\n", res);
//   
//   return 0;
//   
//}