
// 이미지 확대 및 회전문제

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i, j;
	int s, t;
	char img[4][2] = {  {'A', 'E'},
						{'B', 'F'},
						{'C', 'G'},
						{'D', 'H'}  };
	int nOrgRow = 4;
	int nOrgCol = 2;

	char extendImg[8][4] = {0, };		// 2배
	//char extendImg[12][6] = {0, };	// 3배

	int nMultiple = 2;	// 2배

	char tmp;

	// 1번. nMultimple 배수로 데이터 확대
	for(i = 0; i < nOrgRow; i++)
	{
		for(j=0; j < nOrgCol; j++)
		{
			tmp = img[i][j];

			for(s=0; s < nMultiple; s++)
			{
				for(t=0; t < nMultiple; t++)
					extendImg[i*nMultiple + s][j*nMultiple + t] = tmp;
			}

		}
	}

	// 결과 확인
	printf("%d Multiple Image\n", nMultiple);
	for(i = 0; i < nOrgRow * nMultiple; i++)
	{
		for(j = 0; j < nOrgCol * nMultiple; j++)
			printf("%c", extendImg[i][j]);

		printf("\n");
	}


	// 2번. 배수로 확대한 데이터를 왼쪽으로 90도 회전
	char rotationImg[4][8];
	int maxRowIdx = nOrgCol * nMultiple - 1;

	for(i = 0; i < nOrgRow * nMultiple; i++)
	{
		for(j = 0; j < nOrgCol * nMultiple; j++)
			rotationImg[maxRowIdx - j][i] = extendImg[i][j];
	}

	// 결과 확인
	printf("Rotation Image\n");
	for(i = 0; i < nOrgCol * nMultiple; i++)
	{
		for(j = 0; j < nOrgRow * nMultiple; j++)
			printf("%c", rotationImg[i][j]);

		printf("\n");
	}


	return 0;
}
