// task: https://app.codility.com/programmers/lessons/3-time_complexity/frog_jmp

int solution(int X, int Y, int D) {

    return (Y-X)/D + (((Y-X)%D == 0)? 0 : 1);

}