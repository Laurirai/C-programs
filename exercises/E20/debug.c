#include "debug.h"
#include <stdio.h>
#include <stdarg.h>

static int current_debug_level;

void set_debug_level(int debug_level){
  if (debug_level > 4){
    current_debug_level = 4;
  }
  if (debug_level < 0){
    current_debug_level = 0;
  }
  else {
    current_debug_level = debug_level;
  }
}

int dprintf(int debug_level, const char *fmt, ...){
  if (debug_level <= current_debug_level){
    va_list args;
    va_start(args, fmt);

    fprintf(stderr, "[DBG%d]", debug_level);

    vfprintf(stderr, fmt, args);
    va_end(args);
  }
  return 0;
}