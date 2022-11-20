#include <stdio.h>
#include <stdlib.h>

void intervalAdjust( int *intervalBeg, int *intervalEnd, char firstChar, char lastChar )
{
	if ( *intervalBeg < 0 )
		{
			*intervalBeg = 0;
		}
	
	if ( firstChar == '(' )
	{
		*intervalBeg += 1;
	}
	
	if ( lastChar == ')' )
	{
		*intervalEnd -= 1;
	}
}

int checkArray( int intervalBeg, int intervalEnd, int arrayIndex, int gradesArray[] )
{
	int elementCount = 0;
	for ( int i = 0; i < arrayIndex; i++ )
	{
		if ( ( gradesArray[i] >= intervalBeg ) && ( gradesArray[i] <= intervalEnd ) )
		{
			elementCount++;
		}
	}
	return elementCount;
}

int main ( void )
{
	char beginInputBracket, endInputBracket;
	char firstChar, lastChar;
	int grade;
	int arrayIndex = 0;
	int gradesArray[1000];
	int intervalBeg, intervalEnd;
	int conversions;
	
	printf ( "%s\n", "Pocty bodu:");

	scanf ( "%c", &beginInputBracket );

	if ( beginInputBracket == '{' )
	{
		while ( scanf ( "%c%d%c", &firstChar, &grade, &lastChar ) == 3 && firstChar == ' ' )
			{
				gradesArray[arrayIndex] = grade;
				arrayIndex++;
				if ( grade <= 0 || grade >= 1000000000 )
				{
					printf ("%s\n", "Nespravny vstup." );
					return 1;
				}
				if ( lastChar != ',' )
				{
					break;
				}
			}
		if ( scanf ( " %c", &endInputBracket ) && endInputBracket != '}' )
		{
			printf ("%s\n", "Nespravny vstup." );
			return 1;
		}
	}
	else
	{
		printf ("%s\n", "Nespravny vstup." );
		return 1;
	}
	

	printf ( "%s\n" , "Intervaly:" );

	while ( ( conversions = scanf ( " %c%d;%d%c", &firstChar, &intervalBeg, &intervalEnd, &lastChar ) ) != EOF )
	{
		if ( conversions != 4 )
		{
			printf ( "%s\n", "Nespravny vstup." );
			return 1;
		}

		if (
			( firstChar == '<'
			 || firstChar == '(' ) 
			 &&
			 ( lastChar == '>'
			 || lastChar == ')' )
			)

		{
			intervalAdjust( &intervalBeg, &intervalEnd, firstChar, lastChar );
			int elementCount = checkArray( intervalBeg, intervalEnd, arrayIndex, gradesArray );
			printf ( " -> %d\n", elementCount );
		}
		
		else 
		{
			printf ( "%s\n", "Nespravny vstup." );
			return 1;
		}
	}

	

	/*for ( int i = intervalBeg; i < intervalEnd; i++ )
	{
		
		printf ( "%d\n", gradesArray[i] );
	}*/

	return 0;
}