#include <r3/r3.h>
#include "match_entry.h"

extern VALUE rb_mRr3;
VALUE rb_cMatchEntry;

void init_match_entry(){
  rb_cMatchEntry = rb_define_class_under(rb_mRr3, "MatchEntry", rb_cObject);
  rb_define_method(rb_cMatchEntry, "initialize", rb_match_entry_initialize, -1);
  rb_define_attr(rb_cMatchEntry, "route_data", 1, 0);
  rb_define_attr(rb_cMatchEntry, "path", 1, 0);
  rb_define_attr(rb_cMatchEntry, "request_method", 1, 0);
  rb_define_attr(rb_cMatchEntry, "host", 1, 0);
  rb_define_attr(rb_cMatchEntry, "remote_addr", 1, 0);
  rb_define_attr(rb_cMatchEntry, "vars", 1, 0);
}

static VALUE rb_match_entry_initialize(int argc, VALUE *argv, VALUE self){
  VALUE opt;
  rb_scan_args(argc, argv, "0:", &opt);
  if(!NIL_P(opt)) rb_hash_foreach(opt, mass_assign_i, self);
  return self;
}

static int mass_assign_i(VALUE key, VALUE value, VALUE self){
  VALUE key_str = rb_id2str(SYM2ID(key));
  char iv_str[100] = "@";
  strncat(iv_str, RSTRING_PTR(key_str), RSTRING_LEN(key_str));
  rb_iv_set(self, iv_str, value);
  return ST_CONTINUE;
}