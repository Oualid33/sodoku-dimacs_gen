/* 
	Copyright Oualid Demigha, 2019
  
*/

#include <stdio.h>

/* 

This function maps index (i,j,k) in the logical representation 
to a linear index for the DIMACS format 

*/
int index2nbr(int i, int j, int k) {
	return ((i-1)*81+(j-1)*9+k);
}


int main() {
	
	int i, j, k, c, l, s1, s2;
	printf("c This file describes a Sodoku Model in DIMACS format\n");
	printf("c We have 729 variables and 8129 clauses\n");
	printf("p cnf 729 11774\n");

	// Cells
	//printf("c CELLS\n");
	for (i = 1; i < 10; i++) {
	//printf("c\n");
		for (j = 1; j < 10; j++) {
			for (k = 1; k < 10; k++) {
				printf("%d ", index2nbr(i, j, k));
			}
			printf("0\n");
		}
	}


	// Lines
	//printf("c LINES\n");
	for (i = 1; i < 10; i++) {
		//printf("c L%d\n", i);
		for (k = 1; k < 10; k++) {
			for (j = 1; j < 10; j++) {
				c = 1;
				while ((c < 10) && (c != j)) {
					printf("-%d -%d 0\n", index2nbr(i, j, k), index2nbr(i, c, k));
					c++;
				}
			//printf("\n");
			}
		}
	}
	// Columns
	//printf("c COLUMNS\n");
	for (j = 1; j < 10; j++) {
		//printf("c C%d\n", j);
		for (k = 1; k < 10; k++) {
			for (i = 1; i < 10; i++) {
				l = 1;
				while ((l < 10) && (l != i)) {
					printf("-%d -%d 0\n", index2nbr(i, j, k), index2nbr(l, j, k));
					l++;
				}
			//printf("\n");
			}
		}
	 }

	// Squares
	//printf("c SQUARES\n");
	for (s1 = 1; s1 < 10; s1 += 3) {
		for (i = s1; i < s1 + 3; i++) {
			for (s2 = 1; s2 < 10; s2 += 3) {
				for (j = s2; j < s2 + 3; j++) {
					//printf("%d - %d \n", s1, s2);
					for (k = 1; k < 10; k++) {
						l = s1; 
						while (l < s1 + 3) {
							c = s2;
							while (c < s2 + 3) {
								if ((i != l) || (j != c)) 
									printf(" -%d -%d 0\n", index2nbr(i, j, k), index2nbr(l, c, k));
								c++;
							}
						l++;
						}
					}
				}
			}
		}
	}
	// Pre-defined
	printf("%d 0\n", index2nbr(1, 2, 6)); // 1
	printf("%d 0\n", index2nbr(1, 4, 7)); // 2
	printf("%d 0\n", index2nbr(1, 7, 1)); // 3
	printf("%d 0\n", index2nbr(1, 8, 5)); // 4
	printf("%d 0\n", index2nbr(2, 3, 3)); // 5
	printf("%d 0\n", index2nbr(2, 4, 9)); // 6
	printf("%d 0\n", index2nbr(2, 7, 8)); // 7
	printf("%d 0\n", index2nbr(3, 3, 2)); // 8
	printf("%d 0\n", index2nbr(3, 4, 3)); // 9
	printf("%d 0\n", index2nbr(3, 8, 4)); // 10
	printf("%d 0\n", index2nbr(3, 9, 9)); // 11
	printf("%d 0\n", index2nbr(4, 3, 7)); // 12
	printf("%d 0\n", index2nbr(4, 6, 4)); // 13
	printf("%d 0\n", index2nbr(5, 2, 4)); // 14
	printf("%d 0\n", index2nbr(5, 5, 9)); // 15
	printf("%d 0\n", index2nbr(5, 8, 8)); // 16
	printf("%d 0\n", index2nbr(6, 4, 1)); // 17
	printf("%d 0\n", index2nbr(6, 7, 4)); // 18
	printf("%d 0\n", index2nbr(7, 1, 6)); // 19
	printf("%d 0\n", index2nbr(7, 2, 7)); // 20
	printf("%d 0\n", index2nbr(7, 6, 9)); // 21
	printf("%d 0\n", index2nbr(7, 7, 3)); // 22
	printf("%d 0\n", index2nbr(8, 3, 9)); // 23
	printf("%d 0\n", index2nbr(8, 6, 2)); // 24
	printf("%d 0\n", index2nbr(8, 7, 5)); // 25
	printf("%d 0\n", index2nbr(9, 2, 2)); // 26
	printf("%d 0\n", index2nbr(9, 3, 8)); // 27
	printf("%d 0\n", index2nbr(9, 6, 7)); // 28
	printf("%d 0\n", index2nbr(9, 8, 6)); // 29

	return 0;
}
