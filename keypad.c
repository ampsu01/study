#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValidNumber(char *str) {

	// inputString�� ���Ե� ������ ����
	int len = 0;

	// inputString�� ���� parsing�� ����
	char *num[20] = {0, };
	int nDigit[20] = {0, };

	char temp[100] = {0, };
	strncpy(temp, str, strlen(str));
	for(num[len++] = strtok(temp, ","); (num[len] = strtok(NULL, ","))!=NULL; len++)
		;


	for ( int i = 0; i < len; i++ )
	{
		printf("%s ", num[i]);
	}
	printf("\n");


	// [1]. �ڸ��� ����
	// �ּ� 6�ڸ�, �ִ� 15�ڸ�
	if ( len < 6 || len > 15 )
	{
		printf("Error: Number Length(%d)\n", len);
		return false;
	}

	// [2]. ���� üũ
	// 0~9�� ����
	for ( int i = 0; i < len; i++ )
	{
		nDigit[i] = atoi(num[i]);

		if ( nDigit[i] < 0 || nDigit[i] > 9 )
		{
			printf("Error: Not Number(%d)\n", nDigit[i]);
			return false;
		}
	}

	// [3]. �ߺ�üũ
	// �ߺ��� ���� ���� 3ȸ �̻� �Ұ�
	bool bDupFlag = false;
	int nDupCnt = 0;

	for ( int i=0; i < len; i++ )
	{
		bDupFlag = false;
		nDupCnt = 0;

		for ( int j = i+1; j < len; j++ )
		{
			if ( nDigit[i] == nDigit[j] )
			{
				bDupFlag = true;
				nDupCnt++;

				if ( nDupCnt >= 2 )
				{
					printf("Error: Duplicated number\n");
					return false;
				}
			}
			else
				break;
		}
	}


	// [4]. ���ӵ� ����
	// ���ӵ� ���� 3�ڸ� �̻� �Ұ�
	for ( int i=0; i < len; i++ )
	{
		if ( nDigit[i] == 0 )
			nDigit[i] = 10;
	}

	for ( int i=1; i < len-1; i++ )
	{
		// i-1, i, i+1 ��
		if ( ((nDigit[i-1] + 1) == nDigit[i] &&
			  (nDigit[i] + 1) == nDigit[i+1]) )
		{
			printf("Error: Continuous number\n");
			return false;
		}
	}

	// [5]. ���ӵ� ��������
	// ���������� �������� �̾��� �� ����
	int i, j;
	int fIdx, sIdx;

	for ( i = 0; i < len-1; i++ )
	{
		for ( j = i+1; j < len; j++ )
		{
			// ������ �ʱ�ȭ
			bDupFlag = false;
			nDupCnt = 0;

			// ���ʷ� ��ġ�ϴ� ��ġ ã��
			if ( nDigit[i] == nDigit[j] )
			{
				fIdx = i;
				sIdx = j;

				int f, s;
				for ( f = fIdx, s = sIdx; f < sIdx; f++, s++ )
				{
					// s ����: sIdx ~ (len-1)
					// s�� len(�Էµ� ���� ����)�� ����� ��� ���� ����ġ�� �Ǵ�
					if ( s >= len )
					{
						bDupFlag = false;
						break;
					}

					// ���� ��ġ�ϸ� ��ġ�ϴ� �������� üũ
					if ( nDigit[f] == nDigit[s] )
					{
						bDupFlag = true;
						nDupCnt++;
					}
					// ����ġ�ϸ� ���� ���� üũ
					else
					{
						bDupFlag = false;
						break;
					}
				}

				if ( bDupFlag == true )
				{
					// f == sIdx ������ �߰������ν� ���ӵ� �������� üũ��
					if ( f == sIdx && nDupCnt >= 2 )
					{
						printf("Error: Same Pattern\n");
						return false;
					}
				}
			}
		}
	}

	return true;

}

int main(void)
{
	bool isValid = false;
	char input[100];

	do {
		printf("Input numbers : ");

		gets(input);
		isValid = isValidNumber(input);
		if(!isValid)
		{
			printf("It is not numbers to be ruled");
		}
	} while (!isValid);

	return 0;

}
