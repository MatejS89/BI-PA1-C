#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main ( )
{
  unsigned long long from, next;
  int radix, numberOfInputs;
  unsigned long long asset, value;
  int i = 0;
  int q = 0;
  int end;
  int s;
  int conversion[65];

  // Input conditions

  numberOfInputs = scanf ( " %llu, %d", &from, &radix );

  if ( numberOfInputs != 2
    || from < 0
    || from >= ULONG_MAX
    || radix < 2
    || radix > 36
     )
    {
      return 1;
    }

  // Conversion from base 10 to radix

  do
  {
    end = 0;
    i = 0;
    from += 1;
    value = from;
    while ( value != 0 )
    {
      asset = value % radix;
      value /= radix;
      conversion[i] = asset;
      ++i;
    }
  
    s = i-1;
    int odd = s % 2;
    q = 0;

  // Check if number is palindrome after conversion
    
    while ( conversion[q] == conversion[s])
    {
      if ( ( ( q == s ) && ( odd == 0 ) ) || ( ( q == s - 1 ) && ( odd == 1 ) ) || ( ( q == 0 ) && ( s == 1) ))
      { 
        end = 1;
        break;
      }
      ++q;
      --s;
    }
  } while ( ( end != 1 ) && ( from <= ULONG_MAX ) );
  
  printf ("%llu\n", from);
  return 0;
}
