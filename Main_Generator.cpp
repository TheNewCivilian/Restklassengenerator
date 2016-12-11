#include "Main_Generator.h"

void Main_Generator::generateWasClicked() {
  emit(valueChanged(mod_x));
}

void Main_Generator::setValue(int x){
  mod_x = x;
}
