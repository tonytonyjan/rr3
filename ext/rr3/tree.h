#include <r3/r3.h>
#include "ruby.h"

void init_tree();

// instance methods
static VALUE initialize(VALUE self, VALUE size);
// def insert_path(path, data = nil)
static VALUE insert_path(int argc, VALUE *argv, VALUE self);
static VALUE compile(VALUE self);
static VALUE match(VALUE self, VALUE path);
static VALUE dump(VALUE self, VALUE level);

// private functions
static void release(node *n);
inline static node* root(VALUE self);