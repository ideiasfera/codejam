#include<stdio.h>
#include<string.h>

int main() {
  int T;
  int I;
  int J;
  int K;
  char S[110];
  scanf("%d", &T);
  for(I=1;I<=T;I++) {
    scanf("%s", S);
    printf("Case #%d: ", I);
    K = strlen(S);
    
    for(J=0;J<K;J++) {
      if (S[J] == '0') {
        if (J > 0) {
          if (S[J-1] != '0') {
            printf(")0");         
          } else {
            printf("0");         
          }
        } else {
          printf("0");         
        }
      } else {
        if (J > 0) {
          if (S[J-1] != '0') {
            if (S[J-1] == S[J]) {
              printf("%c", S[J]);         
            } else {
              printf(")(%c", S[J]);         
            }
          } else {
            printf("(%c", S[J]);         
          }
        } else {
          printf("(%c", S[J]);       
        }               
      }              
    }
    
    if (S[K-1] != '0') {
      printf(")");         
    }

    printf("\n");    
  }
  return(0);    
}
