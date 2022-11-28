#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define EPS 1e-10

typedef struct
{
	double xCoord;
	double yCoord;
	char planeName[200];
} Plane;

typedef struct
{
	double dist;
	char planeName1[200];
	char planeName2[200];
} Pairs;

// Calculate distance between two points, return a double value of distance
double calculateDist ( Plane * arr, int i, int q )
{
	double x1 = arr[i].xCoord;
	double y1 = arr[i].yCoord;
	double x2 = arr[q].xCoord;
	double y2 = arr[q].yCoord;

	double currentDist = sqrt ( ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1) );
	return currentDist;
}

// Add pair of planes to a struct in pair array
void addPair ( Plane * arr, Pairs * pairs, int * pairCount, int i, int q )
{
	strcpy ( pairs[* pairCount].planeName1, arr[i].planeName );
	strcpy ( pairs[* pairCount].planeName2, arr[q].planeName );
	* pairCount += 1;
}

void invalidInput ( Plane * arr, Pairs * pairs )
{
	printf ( "%s\n", "Nespravny vstup.");
	free ( pairs );
	free ( arr );
}

// Realloc size of input array according to current capacity, smaller realloc for values <1000
void reallocArr ( int * capacityArr, Plane ** arr )
{
	if ( * capacityArr < 1000 )
	{
		* capacityArr += 100;
		* arr = ( Plane * ) realloc ( * arr, sizeof ( Plane ) * ( * capacityArr ) );
	}
	else
	{
		* capacityArr *= 3;
		* arr = ( Plane * ) realloc ( * arr, sizeof ( Plane ) * ( * capacityArr ) );
	}
}

int decidePair ( Plane * arr, Pairs ** pairs, double * distMin, int countArr, int * capacityPairs ) 
{
	int pairCount = 0;

	// Go through indices of Plane array
	for ( int i = 0; i < countArr; i++ )
	{
		for ( int q = i + 1; q <= countArr; q++ )
		{
			double currentDist = calculateDist ( arr, i, q );
			
			// Set distMin to currentDistance in the first iteration
			if ( i == 0 && q == 1 )
			{
				* distMin = currentDist;
			}

			// Realloc pair array if pairCount nears capacity
			if ( pairCount >= * capacityPairs - 1 )
			{
				if ( * capacityPairs < 1000 )
				{
					* capacityPairs += 100;
					* pairs = ( Pairs * ) realloc ( * pairs, sizeof ( Pairs ) * ( * capacityPairs ) );
				}
				else
				{
					* capacityPairs *= 2;
					* pairs = ( Pairs * ) realloc ( * pairs, sizeof ( Pairs ) * ( * capacityPairs ) );
				}
			}

			// CurrentDistance is the same of distMin using double comparison
			if ( fabs ( currentDist - * distMin ) <= EPS * fabs ( currentDist + * distMin ) )
			{
				addPair ( arr, *pairs, &pairCount, i, q );
			}
			else if ( currentDist < * distMin ) // A new distMin is found
			{
				pairCount = 0;
				* distMin = currentDist;
				free( * pairs );
				* pairs = ( Pairs * ) malloc ( sizeof ( Pairs ) * ( * capacityPairs ) );
				addPair ( arr, *pairs, &pairCount, i, q );
			}
		}
	}

	free ( arr );  // Free plane array, all data loaded into pair array
	return pairCount;
}

int main ()
{
	Pairs *pairs;
	Plane *arr;
	int countArr = 0;
	int capacityArr = 100;
	int capacityPairs = 100;
	int inputCheck;
	arr = ( Plane * ) malloc ( sizeof ( Plane ) * capacityArr );
	pairs = ( Pairs * ) malloc ( sizeof ( Pairs ) * capacityPairs );

	printf ( "%s\n", "Pozice letadel:" );

	// Continually check for input until EOF
	while ( ( inputCheck = scanf ( "%lf,%lf: %199s", &arr[countArr].xCoord, &arr[countArr].yCoord, arr[countArr].planeName) ) != EOF )
	{
		if ( inputCheck != 3 )
		{	
			invalidInput ( arr, pairs );
			return 1;
		}
		countArr++;

		// Realloc plane array if countArr nears capacity
		if ( countArr >= capacityArr - 1 )
		{
			reallocArr ( &capacityArr, &arr );
		}
	}

	// Check whether there are less than 2 planes on input
	if ( countArr < 2 )
	{
		invalidInput ( arr, pairs );
		return 1;
	}

	double distMin = 0;
	countArr--; // Adjustment to use as index in function

	int pairCount = decidePair ( arr, &pairs, &distMin, countArr, &capacityPairs );

	printf ( "Vzdalenost nejblizsich letadel: %lf\n", distMin );
	printf ( "Nalezenych dvojic: %d\n", pairCount );
	
	// Print pair array
	for ( int i = 0; i < pairCount; i++ )
	{
		printf ( "%s - %s\n", pairs[i].planeName1, pairs[i].planeName2 );
	}

	free (pairs);
	return 0;
}