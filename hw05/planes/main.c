#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define EPS 1e-6

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

int distCmp ( const void * d1, const void * d2 )
{
	if ( * ( double * )d1 > * ( double * )d2) 
	return 1;
	if ( * ( double * )d1 < * ( double * )d2)
	return -1;
	else
	return 0;
}

int main ()
{
	Pairs *pairs;
	Plane *arr;
	unsigned long long countArr = 0;
	unsigned long long capacityArr = 5;
	unsigned long long pairCount = 0;
	unsigned long long capacityPairs = 5;
	int inputCheck;
	arr = ( Plane * ) malloc ( sizeof ( Plane ) * capacityArr );
	pairs = ( Pairs * ) malloc ( sizeof ( Pairs ) * capacityPairs );

	printf ( "%s\n", "Pozice letadel:" );

	do
	{
		inputCheck = ( scanf ( "%lf,%lf: %199s", &arr[countArr].xCoord, &arr[countArr].yCoord, arr[countArr].planeName ) ) ;
		if ( inputCheck != 3 )
		{
			printf ( "%s\n", "\nNespravny vstup.");
			free ( pairs );
			free ( arr );
			return 1;
		}

		countArr++;
		if ( countArr == capacityArr - 1 )
		{
			capacityArr *= 2;
			arr = ( Plane * ) realloc ( arr, sizeof ( Plane ) * capacityArr );
		}
	} while ( ( inputCheck == 3 ) );

	if ( countArr < 2 )
	{
		printf ( "%s\n", "\nNespravny vstup.");
		free ( pairs );
		free ( arr );
		return 1;
	}

	for ( unsigned long long i = 0; i <= countArr - 1; i++ )
	{
		for ( unsigned long long q = i + 1; q < countArr; q++ )
		{
			double x1 = arr[i].xCoord;
			double y1 = arr[i].yCoord;
			double x2 = arr[q].xCoord;
			double y2 = arr[q].yCoord;

			pairs[pairCount].dist = sqrt ( ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1) );
			strcpy ( pairs[pairCount].planeName1, arr[i].planeName );
 			strcpy ( pairs[pairCount].planeName2, arr[q].planeName );
			
			pairCount ++;
			if ( pairCount == capacityPairs - 1 )
			{
				capacityPairs *= 2;
				pairs = ( Pairs * ) realloc ( pairs, sizeof ( Pairs ) * capacityPairs );
			}
		}
	}
	free ( arr );
	qsort ( pairs, pairCount, sizeof ( Pairs ), distCmp );

	unsigned long long matchPairs = 0, i = 0;
	double matchValue = pairs[0].dist;
	
	while ( pairs[i].dist - matchValue <= EPS * ( pairs[i].dist + matchValue ) )
	{
		matchPairs++;
		i++;
	}
	printf ( "\nNejblizsi vzdalenost letadel: %lf\n", matchValue );
	printf ( "Nalezenych dvojic: %lld\n", matchPairs );
	for ( long long unsigned i = 0; i < matchPairs; i++ )
	{
		printf ( "%s - %s\n", pairs[i].planeName1, pairs[i].planeName2 );
	}

/*
	for ( size_t i = 0; i < count; i++ )
	{
		printf ( "%lf %lf %s\n", arr[i].xCoord, arr[i].yCoord, arr[i].planeName );
	}

	
	for ( unsigned long long i = 0; i < pairCount; i++ )
	{
		printf ( "%lf %s %s\n", pairs[i].dist, pairs[i].planeName1, pairs[i].planeName2 );
	}
	*/
	free ( pairs );
	return 0;
}