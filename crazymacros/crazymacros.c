/* 
 * This program creates a function based on the defined input
 * and then calls that function main().  The function itself
 * simply prints the value defined.
 */  
#include <stdio.h>

#ifndef PROG
#define PROG default
#endif

#define VERSION_FUNC_NAME_HELPER(x,y) x##y
#define VERSION_FUNC_NAME(y) VERSION_FUNC_NAME_HELPER(function_,y)
#define VERSION_HELPER(y) #y
#define VERSION(y) \
  void VERSION_FUNC_NAME(y)(){ \
    /* ##y = y */ \
    printf(" - " VERSION_HELPER(y) " -\n"); \
  };

VERSION(PROG);

#define CALL_VERSION_FUNC(version) \
  VERSION_FUNC_NAME(version)();

int main(int argc, char *argv[]){
  CALL_VERSION_FUNC(PROG);
  return 0;
}