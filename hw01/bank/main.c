#include <stdio.h>
#include <math.h>

int main()
{
	double cInterest, dInterest;
	double total = 0;
	double increase;
	int dayInput, dayDiff;
	int i;
	int currentDay = 0;
	int amount = 1;
	double increaseTrunc;
	printf ("%s\n", "Zadejte kreditni urok [%]:");
	if ( scanf (" %lf", &cInterest) != 1 || cInterest < 0)
	{
	printf ("%s\n", "Nespravny vstup.");
	return 1;
	}
	
	printf ("%s\n", "Zadejte debetni urok [%]:");
	if ( scanf (" %lf", &dInterest) != 1 || dInterest < 0)
	{
	printf ("%s\n", "Nespravny vstup.");
	return 1;
	}

	printf ("%s\n", "Zadejte transakce:");

	while ( amount != 0 )
	{
		if ( scanf (" %d, %d", &dayInput, &amount) != 2 || dayInput < currentDay)
		{
			printf ("%s\n", "Nespravny vstup.");
			return 1;
		}
		dayDiff = dayInput - currentDay;
		
		for ( i = 1; i <= dayDiff; ++i )
		{
			if ( total >= 0 )
			{
				increase = total * cInterest / 100;
			}

			if ( total < 0 )
			{
				increase = total * dInterest / 100;
			}
			
			increaseTrunc = trunc ( increase * 100 ) / 100;
			total += increaseTrunc;
			++currentDay;
		}
		total += amount;
	}
	printf ("Zustatek: %.2lf\n", total);
	return 0;
}
