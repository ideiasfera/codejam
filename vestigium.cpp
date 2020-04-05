#include<stdio.h>
#include<string.h>

int main() {
  int T, N;
  int I, J, K, L;
  int Mat[101][101];
  int Linha, Coluna;
  int D;
  int Achou;
  scanf("%d", &T);
  for(I=1;I<=T;I++) {
    scanf("%d", &N);
    for(J=1;J<=N;J++) {
      for(K=1;K<=N;K++) {
        scanf("%d", &Mat[J][K]);                 
      }     
    }
    
    D = 0;
    
    for(J=1;J<=N;J++) {
      D = D + Mat[J][J];                  
    }
    
    
    Achou = 0;
    Linha = 0;
    for(J=1;J<=N;J++) {
      for(K=1;K<=N;K++) {
        for(L=1;L<=N;L++) {
          if ((Mat[J][K] == Mat[J][L]) && (K != L)) {
            Linha = Linha + 1;
            Achou = 1;
            break;
          }
        }                            
        if (Achou == 1) {                
          break;          
        }
      }
      Achou = 0;
    } 

    Achou = 0;
    Coluna = 0;
    for(K=1;K<=N;K++) {
      for(J=1;J<=N;J++) {
        for(L=1;L<=N;L++) {
          if ((Mat[J][K] == Mat[L][K]) && (J != L)) {
            Coluna = Coluna + 1;
            Achou = 1;
            break;
          }
        }                            
        if (Achou == 1) {                
          break;          
        }
      }
      Achou = 0;
    } 

    
    printf("Case #%d: %d %d %d\n",I, D, Linha, Coluna);
  }
  return(0);    
}

