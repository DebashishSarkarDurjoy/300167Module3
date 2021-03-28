#include <stdio.h>
#include <stdlib.h>

int fact(int num) {
    if (num == 1) return 1;
    else {
      return num * fact(num - 1);
    }
}

int main(int argc, char* argv[]) {

  int result = 0;
  int input = atoi(argv[1]);

  result = fact(input);

  printf("%d! is %d", input, result);



  return 0;
}
