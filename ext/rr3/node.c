#include <r3/r3.h>
#include <ruby.h>
#include "node.h"

extern VALUE cRr3;
VALUE cNode;

void init_node(){
  cNode = rb_define_class_under(cRr3, "Node", rb_cObject);
}