// task: https://app.codility.com/programmers/lessons/5-prefix_sums/count_div/

int solution(int A, int B, int K) {
    
    if((A == B) && (A%K != 0))
        return 0;
    if((A == B) && (A%K == 0))
        return 1;
        
    while(A%K != 0){
       A++; /* we are modifying left limit - to starts from number which is divisible by K */
   }
        
    return (B-A)/K + 1;
    
}