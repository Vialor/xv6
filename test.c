#include "types.h"
#include "stat.h"
#include "user.h"
#include "myfunc.h"
#define TEST3_CASE3
#define TOTAL_FLOPS 1000000000
#define DIVIDED_FLOPS 50000000

int main(void) {
  #ifdef TEST1
  int curnice;

  printf(1, "Part 1 Nice\n");
  printf(1, "1. Change Process's nice to 7\n");
  curnice = nice(7);
  if(curnice != 7)
    printf(1, "Error: Nice value is not 7\n");
  else
    printf(1, "Pass\n");

  printf(1, "2. Change Process's nice to 11 (increment by 4)\n");
  curnice = nice(4);
  if(curnice != 11)
    printf(1, "Error: Nice value is not 11\n");
  else
    printf(1, "Pass\n");

  printf(1, "3. Change Process's nice to 9 (decrement by 2)\n");
  curnice = nice(-2);
  if(curnice != 9) {
    printf(1, "Error: Nice value is not 9\n");
  }
  else
    printf(1, "Pass\n");

  printf(1, "4. Cannot Change Process's nice to 20 (increment by 11)\n");
  curnice = nice(11);
  if(curnice != -1)
    printf(1, "Error: Nice value out of range, should be invalid\n");
  else
    printf(1, "Pass\n");
  # endif

  #ifdef TEST2
  printf(1, "Part 2 PRNG\n");
  int count[200];
  int total=0;
  memset(count, 0, sizeof(count));
  int i;
  for (i=0; i < 10000; i++) {
    int random_number = prng(100);
    count[random_number]++;
    total += random_number;
  }
  printf(1, "Average: %d\n", total/10000);
  for (i=0; i<100;i++)
    printf(1, "%d,", count[i]);
  printf(1, "\n====================\n");
  #endif

  # ifdef TEST3_CASE1
  printf(1, "Part 3 Lottery Test Case_1\n");
  int processnice[] = {-20, -10, 0, 9, 19};
  int proclstlen = sizeof(processnice)/sizeof(int);

  int p;
  int j, k;
  for (j=0; j < proclstlen; j++){
    p = fork();

    if (p == 0) { // child
      int p = getpid();
      nice(processnice[j]);
      for (k=0; k < TOTAL_FLOPS; k++){
        if(k % DIVIDED_FLOPS == 0){
          printf(1,"%d", p);
        }
      }
      break;
    }
  }
  if (p > 0) {
    for (j=0; j < proclstlen; j++){
      wait();
    }
    printf(1, "\n");
  }
  # endif

  # ifdef TEST3_CASE2
  printf(1, "Part 3 Lottery Test Case_2\n\n");
  int originnice[] = {0,0,0,0,0};
  int proclstlen = sizeof(originnice)/sizeof(int);

  int p;
  int j, k;
  for (j=0; j < proclstlen; j++){
    p = fork();

    if (p == 0) { // child
      int p = getpid();
      nice(originnice[j]);    
      for (k=0; k < TOTAL_FLOPS; k++){
        if(k % (DIVIDED_FLOPS / 2)==0){
          printf(1,"%d", p);
        }
        if(k == TOTAL_FLOPS / 4){
          nice((j-3)*4);
        }
      }
      break;
    }
  }

  if (p > 0) {
    for (j=0; j < proclstlen; j++){
      wait();
    }
    printf(1, "\n");
  }
  # endif

  # ifdef TEST3_CASE3
  printf(1, "Part 3 Lottery Test Case_3\n\n");
  int originnice[] = {5, 5, -20};
  int proclstlen = sizeof(originnice)/sizeof(int);

  int p;
  int j, k;
  for (j=0; j < proclstlen; j++){
    p = fork();

    if (p == 0) { // child
      int p = getpid();
      nice(originnice[j]);
      for (k=1; k <= TOTAL_FLOPS; k++){
        if(k % (DIVIDED_FLOPS / 2) == 0){
          printf(1,"%d", p);
        }
        if(k % (TOTAL_FLOPS / 10) == 0 && j == 2){
          nice(4);
        }
      }
      break;
    }
  }

  if (p > 0) {
    for (j=0; j < proclstlen; j++){
      wait();
    }
    printf(1, "\n");
  }
  # endif
  exit();
}