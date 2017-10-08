#include<stdio.h>

void mul(int a[][100], int c, int r,  int c2, int r2);


int main() {

	int a[100][100], b[100][100];
	int i, j,count=0;
	int c[6],r[6];
	


	for (count = 0; count < 6; count++) {
		printf("A%d's matrix:", count + 1);
		scanf("%d %d", &c[count], &r[count]);
	}

	for (count = 0; count < 6; count++)
	for (i = 0; i < c[count]; i++)
	{
		for (j = 0; j < r[count]; j++)
		{
			a[i][j] = 1;
		}
		
	}

	for (count = 0; count < 6; count++)
	{
		printf("A%d is\n", count+1);
		for (i = 0; i < c[count]; i++)
		{
			for (j = 0; j < r[count]; j++) printf("%d\t", a[i][j]);
			printf("\n");
		}
		
	}
	//===============================================================곱할 행렬 크기 보여주기

	
	mul(a, c[0], r[0], c[1], r[1]);
	mul(a, c[0], r[1], c[2], r[2]);
	mul(a, c[0], r[2], c[3], r[3]);
	mul(a, c[0], r[3], c[4], r[4]);
	mul(a, c[0], r[4], c[5], r[5]);




	


return 0;
}

void mul(int a[][100], int c,int r, int c2, int r2)
{
	
	int i,j,k;
	int result[100][100];
	int b[100][100];


	for (i = 0; i < c2; ++i)
	{
		for (j = 0; j < r2; ++j)
		{
			b[i][j] = 1;
		}
	}

	//===========================두 행렬 곱

	for (i = 0; i < c; i++)
	{
		for (j = 0; j < r2; j++)
		{
			result[i][j] = 0;
			for (k = 0; k < r; k++)
			{

				result[i][j] += a[i][k] * b[k][j];
			}

		}
	}
	//====================곱 한  행렬을 a로 넣어주기
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < r2; j++)
		{
			a[i][j] = result[i][j];
		}
	}

	//============================================행렬 a 출력
	printf("행렬의 곱셈의 결과\n");
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < r2; j++) printf("%d\t", a[i][j]);
		printf("\n");
	}

}

	
