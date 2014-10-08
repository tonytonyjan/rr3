#include <r3/r3.h>
#include "tree.h"

extern VALUE rb_mRr3;
VALUE rb_cTree;

void init_tree(){
  rb_cTree = rb_define_class_under(rb_mRr3, "Tree", rb_cObject);
  rb_define_attr(rb_cTree, "root", 1, 0);
  rb_define_method(rb_cTree, "initialize", rb_initialize, 1);
  rb_define_method(rb_cTree, "insert_path", rb_insert_path, -1);
  rb_define_method(rb_cTree, "compile!", rb_compile, 0);
  rb_define_method(rb_cTree, "match", rb_match, 1);
  rb_define_method(rb_cTree, "dump", rb_dump, 1);
}

static VALUE rb_initialize(VALUE self, VALUE size){
  node *n = r3_tree_create(FIX2INT(size));
  rb_ivar_set(self, rb_intern("@root"), Data_Wrap_Struct(rb_cObject, NULL, release, n));
  return self;
}

static VALUE rb_insert_path(int argc, VALUE *argv, VALUE self){
  VALUE path, *data;
  Data_Make_Struct(rb_cObject, VALUE, NULL, -1, data);
  rb_scan_args(argc, argv, "11", &path, data);
  char *errstr = NULL;
  node *ret = r3_tree_insert_pathl_ex(root(self), RSTRING_PTR(path), RSTRING_LEN(path), NULL, data, &errstr);
  if(ret == NULL){
    rb_raise(rb_eRuntimeError, "%s", errstr);
    free(errstr);
  }
  return Qnil;
}

static VALUE rb_compile(VALUE self){
  char *errstr = NULL;
  if(r3_tree_compile(root(self), &errstr) != 0){
    rb_raise(rb_eRuntimeError, "%s", errstr);
    free(errstr);
  }
  return Qnil;
}

static VALUE rb_match(VALUE self, VALUE path){
  node *matched_node = r3_tree_matchl(root(self), RSTRING_PTR(path), RSTRING_LEN(path), NULL); // TODO: support entry
  return matched_node ? *((VALUE*) matched_node->data) : Qfalse;
}

static VALUE rb_dump(VALUE self, VALUE level){
  r3_tree_dump(root(self), FIX2INT(level));
  return Qnil;
}

static void release(node *n){
  r3_tree_free(n);
}

inline static node* root(VALUE self){
  node *root;
  Data_Get_Struct(rb_ivar_get(self, rb_intern("@root")), node, root);
  return root;
}