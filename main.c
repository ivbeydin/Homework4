#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 6386)
#pragma warning(disable: 6385)

void find_MultEdges(int** arr, int knot, int edge, char word) {
	int con = 0, n = 0, k = 0;
	int* help_arr = (int*)calloc(edge, sizeof(int));
	if (help_arr == NULL)
		exit(1);

	for (int i = 0; i < edge; i++) {
		if (help_arr[i] != 1) {
			for (int j = 0; j < knot; j++) {
				if (arr[i][j] == 1) {
					con++;
					k = n;
					n = j;
				}
				if (con == 2)
					for (int p = 0; p < edge; p++)
						if ((arr[p][k] == 1) && (arr[p][n] == 1) && (p != i)) {
							printf("Edge %c, ", word + p);
							help_arr[p] = 1;
							con++;
						}
				if (con > 2) {
					printf("Edge %c - multiple edges between knots %d and %d\n", word + i, n + 1, k + 1);
					help_arr[i] = 1;
				}
			}
			con = 0;
		}
	}
}

int main(void) {
	char word = 'a';
	int knot, edge;
	int** arr = NULL;

	printf("Number of your knots: ");
	if (scanf("%d", &knot) != 1)
		exit(1);
	printf("Number of your edges: ");
	if (scanf("%d", &edge) != 1)
		exit(1);

	arr = (int**)malloc(edge * sizeof(int*));
	if (arr == NULL)
		exit(1);
	for (int i = 0; i < edge; i++)
		arr[i] = (int*)malloc(knot * sizeof(int));

	printf("Complete array:\n  |");
	for (int i = 0; i < edge; i++)
		printf("%c ", word++);
	printf("\n");
	for (int i = 0; i < knot; i++) {
		printf(" %d|", i + 1);
		for (int j = 0; j < edge; j++) {
			if (arr[i] == NULL)
				exit(1);
			if (scanf("%d", &arr[j][i]) != 1)
				exit(1);
		}
	}

	find_MultEdges(arr, knot, edge, 'a');

	for (int i = 0; i < edge; i++)
		free(arr[i]);
	free(arr);
	return 0;
}
