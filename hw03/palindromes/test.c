#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int nextPalindrome ( unsigned long long from, 
                     int radix,
                     unsigned long long * next )
{
  unsigned long long asset, value;
  int i = 0;
  int q = 0;
  int s, end;
  int conversion[65];

  if ( from < 0
    || from >= ULONG_MAX
    || radix < 2
    || radix > 36
     )
    {
      return 0;
    }

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

    while ( conversion[q] == conversion[s])
    {
      if ( ( ( q == s ) && ( odd == 0 ) ) || ( ( q == s - 1 ) && ( odd == 1 ) ) || ( ( q == 0 ) && ( s == 1) ))
      {
        *next = from;
        end = 1;
        break;
      }
      ++q;
      --s;
    }
  } while ( ( end != 1 ) && ( from <= ULONG_MAX ) );
  
  
  return 1;
}


#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  unsigned long long next;
  assert ( nextPalindrome ( 123, 10, &next ) == 1
           && next == 131 );
  assert ( nextPalindrome ( 188, 10, &next ) == 1
           && next == 191 );
  assert ( nextPalindrome ( 1441, 10, &next ) == 1
           && next == 1551 );
  assert ( nextPalindrome ( 95, 15, &next ) == 1
           && next == 96 ); /* 96 = 66 (radix 15) */
  assert ( nextPalindrome ( 45395, 36, &next ) == 1
           && next == 45431 ); /* 45431 = z1z (radix 36) */
  assert ( nextPalindrome ( 1027, 2, &next ) == 1
           && next == 1057 ); /* 1057 = 10000100001 (radix 2) */
  assert ( nextPalindrome ( 1000, 100, &next ) == 0
           && next == 1057 );
  assert ( nextPalindrome ( 18446744073709551614LLu, 2, &next ) == 1
           && next == 18446744073709551615LLu ); /* 18446744073709551615 = 1111111111111111111111111111111111111111111111111111111111111111 (radix 2) */
  assert ( nextPalindrome ( 18446744073709551615LLu, 2, &next ) == 0
           && next == 18446744073709551615LLu );
  return 0;
}
#endif /* __PROGTEST__ */
