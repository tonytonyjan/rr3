#include <stdio.h>
#include <r3/r3.h>
#include "tree.h"

VALUE cRr3;
VALUE cTree;

void init_tree(){
  cRr3 = rb_const_get(rb_cObject, rb_intern("Rr3"));
  cTree = rb_define_class_under(cRr3, "Tree", rb_cObject);
  rb_define_method(cTree, "initialize", initialize, 1);
  rb_define_method(cTree, "insert_path", insert_path, 1);
  rb_define_method(cTree, "dump", dump, 1);
}

static VALUE initialize(VALUE self, VALUE size){
  node *n = r3_tree_create(FIX2INT(size));
  rb_ivar_set(self, rb_intern("node"), Data_Wrap_Struct(cTree, NULL, release, n));
  return self;
}

static VALUE insert_path(VALUE self, VALUE path){
  VALUE obj = rb_ivar_get(self, rb_intern("node"));
  node *n;
  Data_Get_Struct(obj, node, n);
  r3_tree_insert_path(n, RSTRING_PTR(path), NULL);
  return Qnil;
}

static VALUE dump(VALUE self, VALUE number){
  VALUE obj = rb_ivar_get(self, rb_intern("node"));
  node *n;
  Data_Get_Struct(obj, node, n);
  r3_tree_dump(n, FIX2INT(number));
  return Qnil;
}

static void release(node *n){
  r3_tree_free(n);
}