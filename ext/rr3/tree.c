#include <stdio.h>
#include <r3/r3.h>
#include "tree.h"

extern VALUE cRr3, cNode;
VALUE cTree;

void init_tree(){
  cTree = rb_define_class_under(cRr3, "Tree", rb_cObject);
  rb_define_attr(cTree, "root", 1, 0);
  rb_define_method(cTree, "initialize", initialize, 1);
  rb_define_method(cTree, "insert_path", insert_path, -1);
  rb_define_method(cTree, "compile!", compile, 0);
  rb_define_method(cTree, "match", match, 1);
  rb_define_method(cTree, "dump", dump, 1);
}

static VALUE initialize(VALUE self, VALUE size){
  node *n = r3_tree_create(FIX2INT(size));
  rb_ivar_set(self, rb_intern("@root"), Data_Wrap_Struct(cNode, NULL, release, n));
  return self;
}

static VALUE insert_path(int argc, VALUE *argv, VALUE self){
  VALUE path, *data;
  Data_Make_Struct(rb_cObject, VALUE, NULL, -1, data);
  rb_scan_args(argc, argv, "11", &path, data);
  r3_tree_insert_pathl(root(self), RSTRING_PTR(path), RSTRING_LEN(path), data);
  return Qnil;
}

static VALUE compile(VALUE self){
  char *errstr = NULL;
  if(r3_tree_compile(root(self), &errstr) != 0){
    rb_raise(rb_eRuntimeError, "%s", errstr);
    free(errstr);
  }
  return Qnil;
}

static VALUE match(VALUE self, VALUE path){
  node *matched_node = r3_tree_matchl(root(self), RSTRING_PTR(path), RSTRING_LEN(path), NULL); // TODO: support entry
  return matched_node ? *((VALUE*) matched_node->data) : Qnil;
}

static VALUE dump(VALUE self, VALUE level){
  r3_tree_dump(root(self), FIX2INT(level));
  return Qnil;
}

static void release(node *n){
  r3_tree_free(n);
}

inline static node* root(VALUE self){
  VALUE _root = rb_ivar_get(self, rb_intern("@root"));
  node *root; Data_Get_Struct(_root, node, root);
  return root;
}