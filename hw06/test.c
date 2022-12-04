#ifndef __PROGTEST__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int dictCheck ( const char * (*replace)[2] )
{
	int m = 0;
	int n = 1;
	int prefixLen = 0;
	int compLen = 0;
	int i = 0;

	while ( replace[i][0] != NULL )
		i++;

	int j = 0;

	while ( replace[j][1] != NULL )
		j++;
		
	if ( i != j )
		return 0;

	while ( replace[m][0] != NULL )
	{
		if ( (replace[m][0])[0] == '\0' )
		{
			if ( (replace[m][1])[0] != '\0' )
			{
			return 0;
			}
		}
		
		while ( replace[n][0] != NULL )
		{
			prefixLen = strlen ( replace[m][0] );
			int i = 0;
			compLen = strlen ( replace[n][0]);

			if ( prefixLen > compLen )
				prefixLen = compLen;
			
			while ( (replace[m][0])[i] == (replace[n][0])[i] && ( i < prefixLen ))
			{
				i++;
				if ( i == prefixLen )
					return 0;
			}

			n++;
		}
		m++;
		n = m + 1;

	}
	return 1;
}

char * replaceWords ( const char * text, const char * (*replace)[2], char * result, int textLen )
{
	int j = 0;
	int replacement = 0;
	int i = 0;

	for ( int q = 0; q < textLen; q++ )
	{
		while ( replace[i][0] != NULL )
		{
			if ( strstr ( &text[q], replace[i][0] ) == &text[q] )
			{
				int lenDiff = strlen ( replace[i][1] ) - strlen ( replace[i][0] );

				if ( lenDiff > 0 )
				{
					int newSize = ( textLen * lenDiff + 1  );
					result = ( char * ) realloc ( result, newSize );
				}

				memcpy ( &result[j], replace[i][1], strlen ( replace[i][1] ) );
				q += strlen ( replace[i][0] ) - 1;
				j += strlen ( replace[i][1] );
				replacement = 1;
			}
			i++;
		}

		if ( replacement == 0 )
		{
			result[j] = text[q];
			j++;
		}

		replacement = 0;
		i = 0;
	}
	
	result[j] = '\0';
	return result;
}

char * newSpeak ( const char * text, const char * (*replace)[2] )
{
	if ( text == NULL )
		return 0;

	int textLen = strlen ( text );
	char * result = ( char * ) calloc ( textLen + 1, sizeof ( char ) );

	if ( dictCheck ( replace ) == 0 )
	{	
		free ( result );
		return NULL;
	}

	if ( replace[0][0] == NULL )
	{
		strcpy ( result, text );
		return result;
	}

	char * res = replaceWords ( text, replace, result, textLen );
	return res;
}


#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  char * res;

 	const char * d1 [][2] =
  {
    { "murderer", "termination specialist" },
    { "failure", "non-traditional success" },
    { "specialist", "person with certified level of knowledge" },
    { "dumb", "cerebrally challenged" },
    { "teacher", "voluntary knowledge conveyor" },
    { "evil", "nicenest deprived" },
    { "incorrect answer", "alternative answer" },
    { "student", "client" },
    { NULL, NULL }
  };


  const char * d2 [][2] =
  {
		{ "failure", "non-traditional success" },
		{ "fail", "uboptimals result" },
    { NULL, NULL }
  };

  res = newSpeak ( "Everybody is happy.", d1 );
  assert ( ! strcmp ( res, "Everybody is happy." ) );
  free ( res );

  res = newSpeak ( "The student answered an incorrect answer.", d1 );
  assert ( ! strcmp ( res, "The client answered an alternative answer." ) );
  free ( res );

  res = newSpeak ( "He was dumb, his failure was expected.", d1 );
  assert ( ! strcmp ( res, "He was cerebrally challenged, his non-traditional success was expected." ) );
  free ( res );

  res = newSpeak ( "The evil teacher became a murderer.", d1 );
  assert ( ! strcmp ( res, "The nicenest deprived voluntary knowledge conveyor became a termination specialist." ) );
  free ( res );

  res = newSpeak ( "Devil's advocate.", d1 );
  assert ( ! strcmp ( res, "Dnicenest deprived's advocate." ) );
  free ( res );

  res = newSpeak ( "Hello.", d2 );
  assert ( ! res );

  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */
