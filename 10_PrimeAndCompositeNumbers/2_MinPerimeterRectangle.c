// task: https://app.codility.com/programmers/lessons/10-prime_and_composite_numbers/min_perimeter_rectangle/

int solution(int N) {
    int i = 0, A = 1, B = N, min = 2*(A+B);
    
    for(i = 1; i*i <= N; i++){
        if(N%i == 0){
            A = i;
            B = N/i;
        }
        if(2*(A+B) < min)
            min = 2*(A+B);
    }
        
    return min;
    
}