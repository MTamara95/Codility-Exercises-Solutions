// task: https://app.codility.com/programmers/lessons/5-prefix_sums/genomic_range_query/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Results {
  int * A;
  int M; // Length of the array
};

struct Results solution(char *S, int P[], int Q[], int M){

  struct Results res;
  int i = 0, j = 0, nA = 0, nC = 0, nG = 0, nT = 0, n = strlen(S);
  int *A, *C, *G, *T, *R = malloc(M*sizeof(int));

  res.M = M;
  for(i = 0; i < M; i++){
    R[i] = 0;
  }
  
  for(i = 0; i < n; i++){
    if(S[i] == 'A')
      nA++;
    else if(S[i] == 'C')
      nC++;
    else if(S[i] == 'G')
      nG++;
    else // S[i] = 'T'
      nT++;
  }
  A = malloc(nA*sizeof(int));
  C = malloc(nC*sizeof(int));
  G = malloc(nG*sizeof(int));
  T = malloc(nT*sizeof(int));

  nA = nC = nG = nT = 0;
  for(i = 0; i < n; i++){
    if(S[i] == 'A')
      A[nA++] = i;
    else if(S[i] == 'C')
      C[nC++] = i;
    else if(S[i] == 'G')
      G[nG++] = i;
    else // S[i] = 'T'
      T[nT++] = i;
  }


  for(i = 0; i < M; i++){
    
    j = 0;
    while(j < nA && A[j] < P[i]){
      j++;
    }
    if(A[j] >= P[i] && A[j] <= Q[i]){
        R[i] = 1;
        continue;
    }

    j = 0;
    while(j < nC && C[j] < P[i]){
      j++;
    }
    if(C[j] >= P[i] && C[j] <= Q[i]){
        R[i] = 2;
        continue;
    }

    j = 0;
    while(j < nG && G[j] < P[i]){
      j++;
    }
    if(G[j] >= P[i] && G[j] <= Q[i]){
        R[i] = 3;
        continue;
    }

    R[i] = 4;
    
  }
  

  res.A = R;

  return res;
}

//int main() {
//    
//   char *S = "CAGCCTA";
//   int P[] = {2,5,0}, Q[] = {4,5,6};
//   int M = 3, i = 0;
//   struct Results res;
//   
//   res = solution(S, P, Q, M);
//   for(i = 0; i < res.M; i++)
//        printf("%d ", res.A[i]);
//    printf("\n");
//   
//   return 0;
//   
//}