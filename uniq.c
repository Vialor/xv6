#include "types.h"
#include "stat.h"
#include "user.h"
#include <stdbool.h>

bool flag_d = false; // only display repeated lines
bool flag_c = false; // count
bool flag_i = false; // ignore case

char
tolower(char c)
{
  return 65 <= c && c <= 90 ? c + 32 : c;
}

int
uniq_strcmp(const char *p, const char *q)
{
  while (*p){
    if (tolower(*p) != tolower(*q) || (!flag_i && *p != *q))
      break;
    p++, q++;
  }
  return (uchar)*p - (uchar)*q;
}

void
uniq_print(int fd, int count, char* line)
{
  if (count < 1 || (flag_d && count == 1)) {
    return;
  }
  if (flag_c) {
    printf(fd, "%d %s", count, line);
  } else {
    printf(fd, line);
  }
}

void
uniq(int fd0, int fd1)
{
  char cur[1024];
  char last[1024];
  char buf[512];

  int i, n;
  int j = 0;
  int count = 0;
   while((n = read(fd0, buf, sizeof(buf))) > 0) {
    for (i=0; i<n; i++) {
      cur[j++] = buf[i];

      if (buf[i] == '\n') {
        cur[j] = '\0';
        j = 0;
        if (uniq_strcmp(last, cur) != 0) {
          uniq_print(fd1, count, last);
          count = 1;
          strcpy(last, cur);
        } else {
          count++;
        }
      }
    }
  }
  if(n >= 0) {
    cur[j++] = '\n';
    cur[j] = '\0';
    if (uniq_strcmp(last, cur) != 0) {
      uniq_print(fd1, count, last);
      uniq_print(fd1, 1, cur);
    } else {
      uniq_print(fd1, count + 1, last);
    }
  }

  if(n < 0) {
    printf(fd1, "uniq: read error\n");
    exit();
  }
}

int
main(int argc, char *argv[])
{
  char* input = 0;
  char* output = 0;
  int i;
  for (i=1; i<argc; i++) {
    if (strcmp(argv[i], "-i") == 0) {
      flag_i = true;
    } else if (strcmp(argv[i], "-d") == 0) {
      flag_d = true;
    } else if (strcmp(argv[i], "-c") == 0) {
      flag_c = true;
    } else if (!input) {
      input = argv[i];
    } else if (!output) {
      output = argv[i];
    } else {
      printf(2, "uniq: extra operands\n", argv[i]);
      exit();
    }
  }


  int fd0, fd1;
  if (input && output){
    if((fd0 = open(input, 0)) < 0){
      printf(2, "uniq: cannot open %s\n", input);
    } else if((fd1 = open(output, 0)) < 0) {
      printf(2, "uniq: cannot open %s\n", output);
    } else {
      uniq(fd0, fd1);
      close(fd0);
      close(fd1);
    }
  } else if (input){
    if((fd0 = open(input, 0)) < 0){
      printf(2, "uniq: cannot open %s\n", input);
    } else {
      uniq(fd0, 1);
      close(fd0);
    }
  } else {
    uniq(0, 1);
  }
  exit();
}
