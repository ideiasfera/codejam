#include<stdio.h>
#include<string.h>

int T;
int Mat[60][60];
int N;
int K;
int Achou;
int I;

int sorteio(int A, int B) {
  int C;
  int D;
  int E;  
  int A1, A2;
  if (Mat[A][B] == 0) {
    for(C=1;C<=N;C++) {
      E = 0;
      for(D=1;D<=N;D++) {
        if (Mat[A][D] == C) {
          E = 1;              
        }                  
        if (Mat[D][B] == C) {
          E = 1;              
        }                  
      }
      if (E == 0) {
        Mat[A][B] = C;
        if (A == N) {
          if (B == N) {
          } else {
            if (Achou == 0) {
              sorteio(1,B+1);
            }                  
          }
        } else {
          if (Achou == 0) {
            sorteio(A+1,B);
          }                  
        }
        Mat[A][B] = 0;            
      }
    }               
  } else {
    if (A == N) {
      if (B == N) {
        if (Achou == 0) {
          printf("Case #%d: POSSIBLE\n", I);
          for(A1=1;A1<=N;A1++) {
            for(A2=1;A2<=N;A2++) {
              if (A2 == 1) {
                printf("%d", Mat[A1][A2]);                 
              } else {
                printf(" %d", Mat[A1][A2]);                 
              }
            }
            printf("\n");
          }               
          Achou = 1;                  
        }
      } else {
        if (Achou == 0) {
          sorteio(1,B+1);
        }                  
      }      
    } else {
      if (Achou == 0) {
        sorteio(A+1,B);                  
      }
    }
  }

    
}

int sorteiodiagonal(int A, int B) {
  int C;
  int Soma;
  int A1, A2;  
  for(C=1;C<=N;C++) {
    Mat[A][B] = C;
    if ((A == N) && (B == N)) {
      Soma = 0;  
      for(A1=1;A1<=N;A1++) {
        Soma = Soma + Mat[A1][A1];
      }
      if (Soma == K) {
        if (Achou == 0) {
          sorteio(1,1);
        }       
      }
    } else {
      if (Achou == 0) {
        sorteiodiagonal(A+1,B+1);
      }      
    }                     
  }    
}

int main() {
  int A1, A2;
  int Soma;
  scanf("%d", &T);
  for(I=1;I<=T;I++) {
    scanf("%d", &N);            
    scanf("%d", &K);   
    for(A1=1;A1<=N;A1++) {
      for(A2=1;A2<=N;A2++) {
        Mat[A1][A2] = 0;                 
      }
    }    
    Achou = 0;        
    sorteiodiagonal(1,1);    
    
    if (Achou == 0) {
      printf("Case #%d: IMPOSSIBLE\n", I);          
    }  
  }   
  return(0);  
}
