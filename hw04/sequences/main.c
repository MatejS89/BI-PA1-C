#include <stdio.h>
#include <stdlib.h>
#define ARRAY_MAX 2000

void sumOfElements( int *arrLength, int inputArray[], int sumArray[], int * sumArrLength)
{
	int q = 1;

	for ( int i = 0; i < *arrLength - 1; )
	{
		while ( q < *arrLength )
		{
			{
				sumArray[*sumArrLength] = inputArray[i] + inputArray[q];
				*sumArrLength += 1;
			}
		q++;
		}
		i++;
		q = i+1;
	}
}

int main( void )
{
	int sumArrLength = 0;
	int sumArray[2000];
  int inputArray[ARRAY_MAX];
  int inputNum;
  int arrLength = 0;
  
  printf ( "%s\n", "Posloupnost:" );
  
  while ( scanf ("%d", &inputNum) == 1)
  {
    inputArray[arrLength] = inputNum;
    ++arrLength;
  }

  /*for ( int n = 0; n < i; ++n )
  {
    printf ( "%d\n", inputArray[n] );
  }
  return 0;
  */

  sumOfElements( &arrLength, inputArray, sumArray, &sumArrLength);
	

	for ( int p = 0; p < sumArrLength; )
		{
			printf("%d\n", sumArray[p]);
			p++;
		}

}