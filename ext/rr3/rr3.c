#include "rr3.h"
#include "tree.h"
#include "match_entry.h"

VALUE rb_mRr3;

void Init_rr3(void){
  rb_mRr3 = rb_define_module("Rr3");
  init_match_entry();
  init_tree();
}
