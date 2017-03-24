#include <stdio.h>

int main()
{
  char *c;
  int i;
  int x = 0x77345678;   // Insert your magic number here with ASCII newline
                        // You only need to change the F's for the first part

  c = (char *)&x;

  printf("%c\n", *c++);
  printf("%c\n", *c++);
  printf("%c\n", *c++);
  printf("%c\n", *c++);
  
  return 0;
}
