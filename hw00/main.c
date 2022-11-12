#include <stdio.h>

int main()
{
	int linenumber;
	char check;
  
  //  Check user input

  printf ( "%s\n", "ml' nob:" );
	if ( scanf( "%d %c ", &linenumber, &check ) != 1 || linenumber > 9 || linenumber < 1 ) {
		printf ( "%s\n", "luj" );
		return 1;
  }
  // Determine output
  else
  {
	  printf("%s\n","Qapla'");
	
    if (linenumber == 1) 
    {
		  printf ( "%s\n", "noH QapmeH wo' Qaw'lu'chugh yay chavbe'lu' 'ej wo' choqmeH may' DoHlu'chugh lujbe'lu'.");
	  }
	  if (linenumber == 2) 
    {
		  printf ( "%s\n", "bortaS bIr jablu'DI' reH QaQqu' nay'.");
	  }
	  if (linenumber == 3) 
    {
		  printf ( "%s\n", "Qu' buSHa'chugh SuvwI', batlhHa' vangchugh, qoj matlhHa'chugh, pagh ghaH SuvwI''e'.");
	  }
	  if (linenumber == 4) 
    {
		  printf ( "%s\n", "bISeH'eghlaH'be'chugh latlh Dara'laH'be'.");
	  }
	  if (linenumber == 5) 
    {
		  printf ( "%s\n", "qaStaHvIS wa' ram loS SaD Hugh SIjlaH qetbogh loD.");
	  }
	  if (linenumber == 6) 
    {
		  printf ( "%s\n", "Suvlu'taHvIS yapbe' HoS neH.");
	  }
	  if (linenumber == 7) 
    {
		  printf ( "%s\n", "Ha'DIbaH DaSop 'e' DaHechbe'chugh yIHoHQo'.");
	  }
	  if (linenumber == 8) 
    {
		  printf ( "%s\n", "Heghlu'meH QaQ jajvam.");
	  }
	  if (linenumber == 9) 
    {
		  printf ( "%s\n", "leghlaHchu'be'chugh mIn lo'laHbe' taj jej.");
	  }
	  return 0;
	}
}
