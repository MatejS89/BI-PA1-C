#include <stdio.h>
#include <stdlib.h>
#define ARRAY_MAX 2000
int main ( void )
{
  int inputArray[ARRAY_MAX];
  int inputNum;
  int i = 0;
  
  printf ( "%s\n", "Posloupnost:" );
  
  while ( scanf ("%d", &inputNum) == 1)
  {
    inputArray[i] = inputNum;
    ++i;
  }

  for ( int n = 0; n < i; ++n )
  {
    printf ( "%d\n", inputArray[n] );
  }
  return 0;
}