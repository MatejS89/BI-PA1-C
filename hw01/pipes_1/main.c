#include <stdio.h>
#include <math.h>

int main() {
	int roomSize;
	int checkRoom, checkPoint1, checkPoint2;
	int x1, y1, z1;
	int x2, y2, z2;
	int lengthPipe1, lengthPipe2;
	double lengthHose;
	int coordSizeMax;
	int diffX, diffY, diffZ;
	int diffX1, diffY1;
	int diffX2, diffY2;

	//load inputs and check inputs
	
	printf ("%s\n", "Rozmer mistnosti:");
	checkRoom = scanf (" %d", &roomSize);
	
	if (checkRoom != 1 || roomSize < 40) {
		printf ("%s\n","Nespravny vstup.");
		return 1;
	}
	
	coordSizeMax = roomSize - 20;
		
	printf ("%s\n", "Bod #1:");
	checkPoint1 = scanf (" %d %d %d", &x1, &y1, &z1);
	if (checkPoint1 != 3 || z1 == 0 || z1 == roomSize) {
		printf ("%s\n","Nespravny vstup.");
		return 1;
	}	
	if ((x1 > coordSizeMax && x1 < roomSize) || (y1 > coordSizeMax && y1 < roomSize) || (z1 > coordSizeMax && z1 < roomSize)) {
		printf ("%s\n", "Nespravny vstup.");
		return 1; 
	}

	if ( (x1 == 0 || x1 == roomSize) && ((y1 < 20 || y1 > coordSizeMax) || (z1 < 20 || z1 > coordSizeMax) )) { 
		printf ( "%s\n", "Nespravny vstup.");
		return 1;
	}
	
	if ( (y1 == 0 || y1 == roomSize) && ((x1 < 20 || x1 > coordSizeMax) || (z1 < 20 || z1 > coordSizeMax)) ) {
		printf ("%s\n","Nespravny vstup.");
		return 1;	
	}
	
	printf ("%s\n", "Bod #2:");
	checkPoint2 = scanf (" %d %d %d", &x2, &y2, &z2);

	if (checkPoint2 != 3 || z2 == 0 || z2 == roomSize) {
		printf ( "%s\n","Nespravny vstup.");
		return 1;
	}

	if ((x2 > coordSizeMax && x2 < roomSize) || (y2 > coordSizeMax && y2 < roomSize) || (z2 > coordSizeMax && z2 < roomSize) || z2 == 0 || z2 == roomSize ) {
		printf ("%s\n", "Nespravny vstup.");
		return 1; 
	}

	if ( (x2 == 0 || x2 == roomSize) && ((y2 < 20 || y2 > coordSizeMax) || (z2 < 20 || z2 > coordSizeMax) )) { 
		printf ( "%s\n", "Nespravny vstup.");
		return 1;
	}
	
	if ( (y2 == 0 || y2 == roomSize) && ((x2 < 20 || x2 > coordSizeMax) || (z2 < 20 || z2 > coordSizeMax) )) {
		printf ("%s\n","Nespravny vstup.");
		return 1;
	}
	
	diffX = abs (x2 - x1);
	diffY = abs (y2 - y1);
	diffZ = abs (z2 - z1);
	
	if ((diffX < roomSize || diffY < roomSize || diffZ < roomSize) && (diffX != roomSize && diffY != roomSize && diffZ != roomSize) ) { 	
		lengthPipe1 = diffX + diffY + diffZ;
		
		printf("Delka potrubi: %d\n", lengthPipe1);
		lengthHose = sqrt(pow(diffX + diffY,2) + pow(diffZ,2));
		printf("Delka hadice: %f\n", lengthHose);
		return 0;
	}
	if (diffX == roomSize || diffY == roomSize || diffZ == roomSize) {
			
		diffX1 = roomSize - x1;
		diffY1 = roomSize - y1;
		diffX2 = roomSize - x2;
		diffY2 = roomSize - y2;
		
		lengthPipe1 = diffX1 + diffX2 + diffY1 + diffY2 + diffZ;
		lengthPipe2 = roomSize - diffX1 + roomSize - diffY1 + roomSize - diffX2 + roomSize - diffY2 + diffZ;
		if (lengthPipe2 < lengthPipe1) {
			printf("Delka potrubi: %d\n", lengthPipe2);
			diffX1 = roomSize - diffX1;
			diffX2 = roomSize - diffX2;
			diffY1 = roomSize - diffY1;
			diffY2 = roomSize - diffY2;
			
		} else {printf("Delka potrubi: %d\n", lengthPipe1);
		}
		lengthHose = sqrt(pow(diffX1 + diffX2 + diffY1 + diffY2,2) + pow(diffZ,2));
		printf("Delka hadice: %f\n", lengthHose);
		return 0;
		
	}
	
}	 
