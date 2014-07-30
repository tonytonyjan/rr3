#include "node.h"
#include "tree.h"

VALUE cRr3;

void Init_rr3(){
  cRr3 = rb_const_get(rb_cObject, rb_intern("Rr3"));
  init_node();
  init_tree();
}