#include <stdio.h>
#include <stdlib.h>

int main ( void )
{
	char beginInputBracket, endInputBracket;
	int grade;
	int arrayIndex = 0;
	int gradesArray[1000];
	char firstChar, lastChar;

	scanf ( "%c", &beginInputBracket );
	if ( beginInputBracket == '{' )
	{
		while ( scanf ( "%c%d%c", &firstChar, &grade, &lastChar ) == 3 && firstChar == ' ' )
			{
				gradesArray[arrayIndex] = grade;
				arrayIndex++;
				if ( grade < 0 || grade > 1000000000 )
				{
					printf ("%s\n", "Nespravny vstup." );
					return 1;
				}
				if ( lastChar != ',' )
				{
					break;
				}
			}
		
		if ( ( scanf ( "%c", &endInputBracket ) == 1 && endInputBracket != '}' )
					|| arrayIndex <= 2 )
		{
			printf ("%s\n", "Nespravny vstup." );
			return 1;
		}
	}
	
	for ( int i = 0; i < arrayIndex; i++ )
	{
		printf ( "%d\n", gradesArray[i] );
	}
	return 0;
}