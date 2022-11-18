#include <stdio.h>
#include <stdlib.h>
#define ARRAY_MAX 2000

void insertSum( size_t * sumArrLength, int ** sumArray, int sum, size_t sumIndex)
{
	if ( sumIndex >= * sumArrLength )
	{
	* sumArrLength = ( * sumArrLength ) * 2 + 1;
	
	*sumArray = ( int * )realloc( * sumArray, ( * sumArrLength ) * sizeof (int) );
	}

	( *sumArray )[sumIndex] = sum;
}

int sumOfElements( int * arrLength, int inputArray[], int ** sumArray, size_t * sumArrLength )
{
	int sum = inputArray[0];
	size_t sumIndex = 0;
	for ( int i = 0; i <= * arrLength - 1; i++ )
	{
		for ( int n = i + 1; n < * arrLength; n++ )
		{
			sum += inputArray[n];
			insertSum( sumArrLength, sumArray, sum, sumIndex );
			sumIndex += 1;
		}
		sum = inputArray[i + 1];
	}
	return sumIndex;
}

void checkSameElements( int sumArray[], int * sumIndex, int * sameSum ) 
{
	for ( int i = 0; i < *sumIndex - 1; i++)
	{
		for ( int j = i + 1; j <= *sumIndex - 1; j++ )
		{
			if ( sumArray[i] == sumArray[j] )
			{
				*sameSum += 1;
			}
		}
	}
	printf ( "Pocet dvojic: %d\n", *sameSum );
}

int main( void )
{
	size_t sumArrLength = 0;
  int inputArray[ARRAY_MAX];
  int arrLength = 0;
  int sameSum = 0;
	int * sumArray = ( int * ) malloc ( 0 * sizeof( int ));

  printf ( "%s\n", "Posloupnost:" );

	while ( scanf ( "%d", &inputArray[arrLength] ) == 1 )
	{
		arrLength += 1;
	}

	if ( arrLength == 0 || arrLength > 2000 || ( ! feof ( stdin ) ) )
	{
		printf ("%s\n", "Nespravny vstup.");
		return 1;
	}


/*  for ( int n = 0; n < arrLength; ++n )
  {
    printf ( "%d\n", inputArray[n] );
  }
*/  

	int sumIndex = sumOfElements( &arrLength, inputArray, &sumArray, &sumArrLength );
	checkSameElements( sumArray, &sumIndex, &sameSum );
/*	
	for ( int p = 0; p < sumIndex; )
		{
			printf("\n%d", sumArray[p]);
			p++;
		}
*/	
	free( sumArray );
}
