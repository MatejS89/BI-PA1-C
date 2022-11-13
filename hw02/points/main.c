#include <stdio.h>
#include <math.h>
#define ERROR 1e-12

double pointA[2], pointB[2], pointC[2];
int checkPointA, checkPointB, checkPointC;
double slopeAB, slopeBC;
double sum;
double maxX, maxY;


int main () {
	printf ("%s\n", "Bod A:");
	checkPointA = scanf ("%lf %lf", &pointA[0], &pointA[1]);

	if ( checkPointA != 2 ) 
		{
		printf ("%s\n", "Nespravny vstup.");
		return 1;
		}

	printf ("%s\n", "Bod B:");
	checkPointB = scanf ("%lf %lf", &pointB[0], &pointB[1]);
	
	if ( checkPointB != 2 ) 
		{
		printf ("%s\n", "Nespravny vstup.");
		return 1;
		}


	printf ("%s\n", "Bod C:");
	checkPointC = scanf ("%lf %lf", &pointC[0], &pointC[1]);

	if ( checkPointC != 2 ) 
		{
		printf ("%s\n", "Nespravny vstup.");
		return 1;
		}

	if ( ( (pointA[0] == pointB[0]) && (pointA[1] == pointB[1]) ) || ( (pointA[0] == pointC[0]) && (pointA[1] == pointC[1]) ) || ( (pointB[0] == pointC[0]) && (pointB[1] == pointC[1]) ) )
		{
		printf("%s\n", "Nektere body splyvaji.");
		return 1;
		}

	slopeAB = ( ( pointB[1] - pointA[1] ) / ( pointB [0] - pointA[0] ) );
	slopeBC = ( ( pointC[1] - pointB[1] ) / ( pointC [0] - pointB[0] ) );

	sum = fabs ( slopeAB + slopeBC );
	if ( slopeAB == slopeBC || fabs (slopeAB - slopeBC) <= ERROR * sum || ( (pointA[0] == pointB[0]) && (pointC[0] == pointB[0]) && (pointC[0] == pointA[0]) ) )
	{
		printf ("%s\n", "Body lezi na jedne primce.");
		if ( (pointA[0] != pointB[0])  && (pointB[0] != pointC[0]) && (pointC[0] != pointA[0]) )
		{
			maxX = pointA[0] > pointB[0] ? pointA[0] : pointB[0];
			maxX = maxX > pointC[0] ? maxX : pointC[0];
			if ( maxX == pointA[0])
			{
			if ( pointB[0] > pointC[0] )
				{
				printf ("%s\n", "Prostredni je bod B.");
				}
				else
				{
				printf ("%s\n","Prostredni je bod C.");
				}
			}

			if ( maxX == pointB[0])
			{
				if ( pointA[0] > pointC[0] )
				{
				printf ("%s\n", "Prostredni je bod A.");
				}
				else
				{
				printf ("%s\n","Prostredni je bod C.");
				}
			}

			if ( maxX == pointC[0])
			{
				if ( pointB[0] > pointA[0] )
				{
				printf ("%s\n", "Prostredni je bod B.");
				}
				else
				{
				printf ("%s\n","Prostredni je bod A.");
				}
			}
		}
		else
		{
			maxY = pointA[1] > pointB[1] ? pointA[1] : pointB[1];
			maxY = maxY > pointC[1] ? maxY : pointC[1];
			if ( maxY == pointA[1])
			{
				if ( pointB[1] > pointC[1] )
				{
				printf ("%s\n", "Prostredni je bod B.");
				}
				else
				{
				printf ("%s\n","Prostredni je bod C.");
				}
			}

			if ( maxY == pointB[1])
			{
				if ( pointA[1] > pointC[1] )
				{
				printf ("%s\n", "Prostredni je bod A.");
				}
				else
				{
				printf ("%s\n","Prostredni je bod C.");
				}
			}

			if ( maxY == pointC[1])
			{
				if ( pointB[1] > pointA[1] )
				{
				printf ("%s\n", "Prostredni je bod B.");
				}
				else
				{
				printf ("%s\n","Prostredni je bod A.");
				}
	
			}
		}
		return 0;
		
	}
	else 
	{
	printf ("%s\n","Body nelezi na jedne primce.");
	}
}
