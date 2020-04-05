#include<stdio.h>
#include<string.h>

int main() {
  int T, N;
  int I, J, L, Z;
  int Vet[1010][5];
  int C1, J1;
  int Menor;
  int Maior;
  int Me;
  int A;
  scanf("%d", &T);
  for(I=1;I<=T;I++) {
    scanf("%d", &N);
    for(J=1;J<=N;J++) {
      scanf("%d", &Vet[J][1]);                
      scanf("%d", &Vet[J][2]);                
      Vet[J][3] = 1;
    }            

    printf("Case #%d: ", I);
    
    C1 = 0;
    J1 = 0;
    
    A = 0;
    
    for(L=1;L<=N;L++) {
    
      Menor = 2000;
      Maior = 2000;
                        
    for(J=1;J<=N;J++) {
      if (((Menor > Vet[J][1]) || ((Menor == Vet[J][1]) && (Maior > Vet[J][2]))) && (Vet[J][3] == 1)) {
        Menor = Vet[J][1];
        Maior = Vet[J][2];
        Me = J; 
      }        
    }

    Vet[Me][3] = 0;
    
    if (C1 <= Menor) {
      C1 = Maior;      
      //printf("%d = %d C", Me, C1);
      Vet[Me][4] = 1;
    } else {
      if (J1 <= Menor) {
        J1 = Maior;      
        //printf("%d = %d J", Me, J1);
        Vet[Me][4] = 2;
      } else {
        printf("IMPOSSIBLE"); 
        A = 1;
        break;      
      }               
    }

    }
    
    if (A == 0) {
      for(J=1;J<=N;J++) {
        if (Vet[J][4] == 1) {
          printf("C");              
        } else {
          printf("J");              
        }                  
      }      
    }
    
    printf("\n");

  }

  


  return(0);    
}
