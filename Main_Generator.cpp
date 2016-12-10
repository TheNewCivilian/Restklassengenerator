#include "Main_Generator.h"

void Main_Generator::generateWasClicked() {
  int i = 1, j = 1;
  for(i= 1;i<mod_x ;i++) {
    for(j=1; j<mod_x ;j++){
      int a = (i*j)%mod_x ;
      if(a > mod_x/2) {
        printf("%4i", (mod_x -a)*-1);
      } else {
        printf("%4i", a);
      }
    }
    printf("\n");
  }
}

void Main_Generator::setValue(int x){
  mod_x = x;
}
