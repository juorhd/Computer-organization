#include <stdio.h>

/* 
   Use d0, d1, and carry_in to compute a return value.
   If necessary, use the carry_out pointer to return additional information
*/
int add_two_bits(int d0, int d1, int carry_in, int *carry_out)
{
  if (carry_out==NULL) return (d0^d1) ^ carry_in;
  *carry_out = d0&d1 + (carry_in & ( d0 ^ d1 ));
  return (d0^d1) ^ carry_in;
}

int main()
{
  int i;
  int d0[4];
  int d1[4];
  int ci[4];
  int sum[4];

  /* Call add_two_bits multiple times */
  for (i=0; i<4; ++i){  
    printf("Enter binary digit d0[%d]: ", i); 
    scanf("%d", &d0[i]);  
    d0[i] = !!d0[i]; 
  }
  for (i=0; i<4; ++i){
    printf("Enter binary digit d1[%d]: ", i); 
    scanf("%d", &d1[i]);  
    d1[i] = !!d1[i]; 
  }   
  sum[3] =  add_two_bits(d0[3], d1[3], 0, &ci[3]);
  for (i=2; i>=0; --i)   sum[i] = add_two_bits(d0[i], d1[i], ci[i+1], &ci[i]); 
  if (ci[0]) {
    printf("%d%d%d%d + %d%d%d%d = %d%d%d%d with a carry\n", 
          d0[0],d0[1],d0[2],d0[3],d1[0],d1[1],d1[2],d1[3], sum[0], sum[1], sum[2], sum[3]);
  }
  else {
        printf("%d%d%d%d + %d%d%d%d = %d%d%d%d without a carry\n", 
          d0[0],d0[1],d0[2],d0[3],d1[0],d1[1],d1[2],d1[3], sum[0], sum[1], sum[2], sum[3]);
  }
  return 0;
}
