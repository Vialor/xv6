#include "types.h"
#include "stat.h"
#include "user.h"

uint prng(uint mod);

int main(void) {
  // printf(1, "Part 1 Nice\n");
  // nice(7);
  // // test out of bounds

  // printf(1, "Part 2 PRNG\n");
  // int i;
  // for (i=0; i < 100; i++) {
  //   int r = prng(100000);
  //   printf(1, "%d\n", r);
  // }

  printf(1, "Part 3 Lottery\n");
  int processnice[] = {-20, 0, 19};
  int proclstlen = sizeof(processnice)/sizeof(int);
  // int processpids[proclstlen];
  // int proccurind = 0;

  int j;
  for (j=0; j < proclstlen; j++){
    int p = fork();

    if (p == 0) { // child
      int p = getpid();
      nice(processnice[j]);
      printf(1, "Process %d is running\n", p);
    } else if (p > 0) { // parent
      printf(1, "I'm merely a humble parent, I just forked %d\n", p);
      // processpids[proccurind] = p;
      // proccurind ++;
    }
  }

  for (j=0; j < proclstlen; j++){
    wait();
  }
  
  exit();
}
