// task: https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/count_factors/

#include<stdio.h>
#include<limits.h>

/* 24: 1, 2, 3, 4, 6, 8, 12, 24
    24 = 1*24 = 24*1
       = 2*12 = 12*2
       = 3*8 = 8*3
       = 4*6 = 6*4
       
    25: 1, 5, 25
    25 = 1*25 = 25*1
       = 5*5
*/

int solution(int N){
    long i = 1, res = 0;

    while(i*i < N && i*i < INT_MAX){ // when N is number ~INT_MAX, and i*i != N - overflow
        if(N%i == 0)
            res += 2;
        i++;
    }
    if(i*i == N)
        res++; // symmetric, we count it just once

    return res;
}

//int main() {
//   int N1 = 1000000000, N2 = INT_MAX, N3 = 2147395600, N = 7, res = 0;
//   
//   printf("N1: %d, N2: %d, N3: %d, N: %d\n", solution(N1), solution(N2), solution(N3), solution(N));
//   
//   return 0;
//}