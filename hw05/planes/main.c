#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

int main ()
{
	Pairs *pairs;
	Plane *arr;
	unsigned long long count = 0;
	unsigned long long capacity = 5;
	unsigned long long pairCount = 0;
	arr = ( Plane * ) malloc ( sizeof ( Plane ) * capacity );
	pairs = ( Pairs * ) malloc ( sizeof ( Pairs ) * 1000 );

	printf ( "%s\n", "Pozice letadel:" );

	while ( scanf ( "%lf,%lf: %199s", &arr[count].xCoord, &arr[count].yCoord, arr[count].planeName ) == 3 )
	{
		count++;
		if ( count == capacity - 1 )
		{
			capacity *= 2;
			arr = ( Plane * ) realloc ( arr, sizeof ( Plane ) * capacity );
		}
	}

	for ( unsigned long long i = 0; i <= count - 1; i++ )
	{
		for ( unsigned long long q = i + 1; q < count; q++ )
		{
			

			double x1 = arr[i].xCoord;
			double y1 = arr[i].yCoord;
			double x2 = arr[q].xCoord;
			double y2 = arr[q].yCoord;

			pairs[pairCount].dist = sqrt ( ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1) );
			printf ( "\n%lf %s %s", pairs[pairCount].dist, arr[i].planeName, arr[q].planeName );
			pairCount ++;
			/*strcpy ( arr[i].planeName, pairs[i].planeName1 );
 			strcpy ( arr[q].planeName, pairs[i].planeName2 );*/
		}
	}

	
/*
	for ( size_t i = 0; i < count; i++ )
	{
		printf ( "%lf %lf %s\n", arr[i].xCoord, arr[i].yCoord, arr[i].planeName );
	}

	printf ( "\n" );
	for ( unsigned long long i = 0; i < pairCount; i++ )
	{
		printf ( "%lf %s %s\n", pairs[i].dist, pairs[i].planeName1, pairs[i].planeName2 );
	}
	*/
	free ( arr );
	free ( pairs );
	return 0;
}