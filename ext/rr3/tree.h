#include <r3/r3.h>
#include "ruby.h"

void init_tree();

// instance methods
static VALUE initialize(VALUE self, VALUE size);
static VALUE insert_path(VALUE self, VALUE path);
static VALUE dump(VALUE self, VALUE number);

static void release(node *n);