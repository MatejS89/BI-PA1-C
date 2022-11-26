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

int loadStudent ( Plane * arr, unsigned long long countArr )
{
	int res = scanf ( "%lf,%lf: %199s", &arr[countArr].xCoord, &arr[countArr].yCoord, arr[countArr].planeName );
	return res == 3;
}

/*
int distCmp ( const void * d1, const void * d2 )
{
	return ( * ( double * )d1 - * ( double * )d2 );
}
*/

int main ()
{
	Pairs *pairs;
	Plane *arr;
	unsigned long long countArr = 0;
	unsigned long long capacityArr = 100;
	unsigned long long pairCount = 0;
	unsigned long long capacityPairs = 100;
	int inputCheck;
	arr = ( Plane * ) malloc ( sizeof ( Plane ) * capacityArr );
	pairs = ( Pairs * ) malloc ( sizeof ( Pairs ) * capacityPairs );

	printf ( "%s\n", "Pozice letadel:" );

	while ( ( inputCheck = scanf ( "%lf,%lf: %199s", &arr[countArr].xCoord, &arr[countArr].yCoord, arr[countArr].planeName) ) != EOF )
	{
		if ( inputCheck != 3 )
		{
			printf ( "%s\n", "Nespravny vstup.");
			free ( pairs );
			free ( arr );
			return 1;
		}

		countArr++;

		if ( countArr >= capacityArr - 1 )
		{
			if ( capacityArr < 1000 )
			{
				capacityArr += 100;
				arr = ( Plane * ) realloc ( arr, sizeof ( Plane ) * capacityArr );
			}
			else
			{
				capacityArr *= 3;
				arr = ( Plane * ) realloc ( arr, sizeof ( Plane ) * capacityArr );
			}
		}
	}

	if ( countArr < 2 )
	{
		printf ( "%s\n", "Nespravny vstup.");
		free ( pairs );
		free ( arr );
		return 1;
	}

	double distMin = 0;
	double currentDist;
	for ( unsigned long long i = 0; i < countArr - 1; i++ )
	{
		for ( unsigned long long q = i + 1; q < countArr; q++ )
		{
			double x1 = arr[i].xCoord;
			double y1 = arr[i].yCoord;
			double x2 = arr[q].xCoord;
			double y2 = arr[q].yCoord;

			currentDist = sqrt ( ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1) );

			if ( i == 0 && q == 1 )
			{
				distMin = currentDist;
			}

			if ( pairCount >= capacityPairs - 1 )
			{
				if ( capacityPairs < 1000 )
				{
					capacityPairs += 100;
					pairs = ( Pairs * ) realloc ( pairs, sizeof ( Pairs ) * capacityPairs );
					if ( pairs == NULL )
					{
						printf ("%s\n","REALLOC FAILED1");
					}
				}
				else
				{
					capacityPairs *= 2;
					pairs = ( Pairs * ) realloc ( pairs, sizeof ( Pairs ) * capacityPairs );
					if ( pairs == NULL)
					{
						printf ("%s\n","REALLOC FAILED2");
					}
				}
			}

			if ( fabs ( currentDist - distMin ) <= EPS * fabs ( currentDist + distMin ))
			{
				strcpy ( pairs[pairCount].planeName1, arr[i].planeName );
 				strcpy ( pairs[pairCount].planeName2, arr[q].planeName );
				pairCount++;
			}
			
			else if ( currentDist < distMin )
			{
				pairCount = 0;
				distMin = currentDist;
				free( pairs );
				pairs = ( Pairs * ) malloc ( sizeof ( Pairs ) * capacityPairs );
				strcpy ( pairs[pairCount].planeName1, arr[i].planeName );
 				strcpy ( pairs[pairCount].planeName2, arr[q].planeName );
				pairCount++;
			}
		}
	}
	free ( arr );

	printf ( "Vzdalenost nejblizsich letadel: %lf\n", distMin );
	printf ( "Nalezenych dvojic: %lld\n", pairCount );
	for ( long long unsigned i = 0; i < pairCount; i++ )
	{
		printf ( "%s - %s\n", pairs[i].planeName1, pairs[i].planeName2 );
	}

	free (pairs);
	return 0;
}