#include "types.h"
#include "stat.h"
#include "user.h"
#include "myfunc.h"
#define TEST2

int main(void) {
  #ifdef TEST1
  // int flag;

  // printf(1, "Part 1 Nice\n");
  // readnice();
  // printf(1, "Change Process's nice to 7\n");
  // flag = nice(7);
  // if(flag == -1)
  //   printf(1, "Error: Nice value out of range\n");
  //   else readnice();
  // // test out of bounds
  // printf(1, "Change Process's nice to 30\n");
  // flag = nice(30);
  // if(flag == -1)
  //   printf(1, "Error: Nice value out of range\n");
  //   else readnice();
  # endif
  #ifdef DDDDD
  printf(1, "HHHHHHHHHHH\n");
  #endif

  #ifdef TEST2
  printf(1, "Part 2 PRNG\n");
  int count[200];
  int total=0;
  memset(count, 0, sizeof(count));
  int i;
  for (i=0; i < 10000; i++) {
    int random_number = prng(200);
    count[random_number]++;
    total += random_number;
  }
  printf(1, "Average: %d\n", total/10000);
  for (i=0; i<200;i++)
    printf(1, "%d ", count[i]);
  #endif

  #ifdef TEST3
  // printf(1, "Part 3 Lottery\n");
  // int processnice[] = {-18,-8,-4,6,12,18};
  // int proclstlen = sizeof(processnice)/sizeof(int);
  // // int processpids[proclstlen];
  // // int proccurind = 0;

  // // int count=0;
  // int p;
  // for (int j=0; j < proclstlen; j++){
  //   p = fork();

  //   if (p == 0) { // child
  //     int p = getpid();
  //     nice(processnice[j]);
  //     printf(1, "Process %d is running and has nice %d\n", p,processnice[j]);
  //     readnice();
  //     nice(processnice[j]-2);
  //     printf(1, "Change Process %d's nice to %d\n", p, processnice[j]-2);
  //     readnice();


  //     for (int k=0; k<100000; k++){
  //       if(k%5000==0){
  //         printf(1,"Process %d has complete %d loops\n",p,k);
  //         //count++;
  //       }
  //     }
  //     break;
  //   } else if (p > 0) { // parent
  //     printf(1, "I'm merely a humble parent, I just forked %d\n", p);
  //     // processpids[proccurind] = p;
  //     // proccurind ++;
  //   }
  // }

  // for (j=0; j < proclstlen; j++){
  //   wait();
  // }
  # endif

  exit();
}