#include <stdio.h>
#include <string.h>

void floydAlgorithm(int W[100][100], int n, int start, int finish){
	int i, j, k, D[n][n];
	char solution[n][n][100];
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			D[i][j] = W[i][j];
			sprintf(solution[i][j],"%d > %d\n",i+1,j+1);
		}
	}

	char* solusi;

	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (D[i][k] + D[k][j] < D[i][j]){
					 strcpy(solution[i][j], solution[i][k]);
					 strcat(solution[i][j], solution[k][j]);
					 D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}

	printf("Distance Matrix\n");
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if (i==j) printf("0 "); else printf("%d ", D[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("solusi:\n");
	printf("%s\n", solution[start-1][finish-1]);

	printf("Jarak minimum dari %d ke %d adalah %d\n", start, finish, D[start-1][finish-1]);
}

int main(int argc, char const *argv[])
{
	FILE *f;
	int n,i,j;


	f = fopen("input.txt","r");
	fscanf(f, "%d\n", &n);

    int start = 1;
	int finish = 10;

	int weightMatrix[100][100];

	printf("Weight Matrix\n");
	for (i=0;i<n;i++){
		for (j=0;j<n;j++)
		{
			fscanf(f, "%d", &weightMatrix[i][j]);
		}
	}

	fclose(f);

	for (i=0;i<n;i++){
		for (j=0;j<n;j++)
		{
			printf("%d ", weightMatrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	floydAlgorithm(weightMatrix,n,start,finish);

	return 0;
}
