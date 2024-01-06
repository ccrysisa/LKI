#include <stdio.h>

int foo() {
  printf("enter foo\n");
  int bar = 1;
  bar += 3;
  printf("bar = %d\n", bar);

  return bar;
}

int main() {
    printf("main function\n");
    int result = foo();
    printf("after foo, result = %d\n", result);

    return 0;
}