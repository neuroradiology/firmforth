#ifndef FIRMFORTH_H
#define FIRMFORTH_H

#include <stdint.h>

union cell {
  intptr_t i;
  uintptr_t u;
  char *s;
  const char *cs;
};

typedef void (*word)(union cell *param_stack[]);

struct dict {
  const char *name;
  int compile_only : 1;
  int immediate : 1;
  int smudge : 1;
  word code;
  struct dict *next;
};

#endif
