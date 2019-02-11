// task: https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/

#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}   

int solution(int A[], int N) {
    
    int i = 0, j = 0, x = 0, num = 0;
    int *L = malloc(N*sizeof(int)), *D = malloc(N*sizeof(int));
    
    for(i = 0; i < N; i++){
        L[i] = i - A[i];
        D[i] = i + A[i];
    }
    
    qsort(L, N, sizeof(int), cmpfunc);
    qsort(D, N, sizeof(int), cmpfunc);
    
    i = 0;
    j = 0;
    while(i < N){
        if(L[i] <= D[j]){
            i++;
            num += x;
            x++;
            //printf("L: %d,x = %d\n", L[i-1], x);
        }
        else{
            j++;
            x--;
            //printf("D: %d, x = %d\n", D[j-1], x);
        }
    }
    
    /* the function should return -1 if the result is greater than 10,000,000: */
    if(num > 10000000)
        return -1;
        
    return num;
    
}

//int main() {
//   
//   int A[] = {1,5,2,1,4,0};
//   int N = 6, res = 0;
//   
//   res = solution(A, N);
//   printf("%d\n", res);
//   
//   return 0;
//   
//}