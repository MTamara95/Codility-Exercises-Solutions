// task: https://app.codility.com/programmers/lessons/1-iterations/binary_gap

int solution(int N) {

    int max = 0, counter = 0;
    N = (unsigned) N;
    
    while(N > 0){
        if(N == 1)
            break;
        counter = 0;
        if(N&1){
            N >>= 1;
            while((N&1) == 0){
                counter++;
                N >>= 1;
            }
        }
        else
            N >>= 1;
        if(counter > max)
            max = counter;
    }
    
    return max;
}