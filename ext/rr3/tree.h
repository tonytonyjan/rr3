#ifndef RR3_TREE
#define RR3_TREE 1

#include <r3/r3.h>
#include "ruby.h"

void init_tree();

// def initialize(size)
static VALUE rb_tree_initialize(VALUE self, VALUE size);
// def insert_path(path, data = nil)
static VALUE rb_tree_insert_path(int argc, VALUE *argv, VALUE self);
// def compile()
static VALUE rb_tree_compile(VALUE self);
// def compile(path)
static VALUE rb_tree_match(VALUE self, VALUE path);
// def dump(level)
static VALUE rb_tree_dump(VALUE self, VALUE level);

static void release(node *n);
inline static node* root(VALUE self);

#endif