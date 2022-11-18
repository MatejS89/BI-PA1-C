#include <stdio.h>
#include <stdlib.h>
#define ARRAY_MAX 2000

void sumOfElements( int *arrLength, int inputArray[], int sumArray[], int * sumArrLength )
{
	int q = 1;
	int sum = inputArray[0];
	for ( int i = 0; i <= *arrLength - 1;)
	{
		for ( int n = q; n < *arrLength;)
		{
			sum += inputArray[n];
			n++;
			sumArray[*sumArrLength] = sum;
			*sumArrLength += 1;
		}

		i++;
		sum = inputArray[i];
		q = i+1;
	}
}

void checkSameElements( int sumArray[], int * sumArrLength, int * sameSum ) 
{
	int q = 1;
	for ( int i = 0; i < *sumArrLength - 1;)
	{
		while ( q <= *sumArrLength - 1 )
		{
			if ( sumArray[i] == sumArray[q] )
			{
				*sameSum += 1;
			}
		q++;
		}
		i++;
		q = i+1;
	}
	printf ( "Pocet dvojic: %d\n", *sameSum );
}

int main( void )
{
	int sumArrLength = 0;
	int sumArray[2000];
  int inputArray[ARRAY_MAX];
  int arrLength = 0;
  int sameSum = 0;
  printf ( "%s\n", "Posloupnost:" );
  

	while ( scanf ( "%d", &inputArray[arrLength] ) == 1 )
	{
		arrLength += 1;
	}

	if ( arrLength == 0 || arrLength > 2000 || ( ! feof (stdin) ) )
	{
		printf ("%s\n", "Nespravny vstup.");
		return 1;
	}

/*
  for ( int n = 0; n < arrLength; ++n )
  {
    printf ( "%d\n", inputArray[n] );
  }
*/  

  sumOfElements( &arrLength, inputArray, sumArray, &sumArrLength );
	
	checkSameElements( sumArray, &sumArrLength, &sameSum );


/*		for ( int p = 0; p < sumArrLength; )
		{
			printf("\n%d", sumArray[p]);
			p++;
		}
*/

}
