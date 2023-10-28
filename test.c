#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
  // printf(1, "Part 1 Nice\n");
  // nice(7);
  // // test out of bounds

  printf(1, "Part 2 PRNG\n");
  int i;
  for (i=0; i < 100; i++) {
    int r = prng(100000);
    printf(1, "%d\n", r);
  }

  exit();
}
