#ifndef MATCH_ENTRY
#define MATCH_ENTRY 1

#include <r3/r3.h>
#include "ruby.h"

void init_match_entry();

// def initialize(options)
static VALUE rb_match_entry_initialize(int argc, VALUE *argv, VALUE self);

static int mass_assign_i(VALUE key, VALUE value, VALUE self);

#endif /* MATCH_ENTRY */
