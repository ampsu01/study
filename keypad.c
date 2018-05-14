#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValidNumber(char *str) {

	// inputString에 포함된 숫자의 개수
	int len = 0;

	// inputString에 대한 parsing을 수행
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


	// [1]. 자리수 범위
	// 최소 6자리, 최대 15자리
	if ( len < 6 || len > 15 )
	{
		printf("Error: Number Length(%d)\n", len);
		return false;
	}

	// [2]. 숫자 체크
	// 0~9만 가능
	for ( int i = 0; i < len; i++ )
	{
		nDigit[i] = atoi(num[i]);

		if ( nDigit[i] < 0 || nDigit[i] > 9 )
		{
			printf("Error: Not Number(%d)\n", nDigit[i]);
			return false;
		}
	}

	// [3]. 중복체크
	// 중복된 숫자 연속 3회 이상 불가
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


	// [4]. 연속된 숫자
	// 연속된 숫자 3자리 이상 불가
	for ( int i=0; i < len; i++ )
	{
		if ( nDigit[i] == 0 )
			nDigit[i] = 10;
	}

	for ( int i=1; i < len-1; i++ )
	{
		// i-1, i, i+1 비교
		if ( ((nDigit[i-1] + 1) == nDigit[i] &&
			  (nDigit[i] + 1) == nDigit[i+1]) )
		{
			printf("Error: Continuous number\n");
			return false;
		}
	}

	// [5]. 연속된 동일패턴
	// 동일패턴이 연속으로 이어질 수 없슴
	int i, j;
	int fIdx, sIdx;

	for ( i = 0; i < len-1; i++ )
	{
		for ( j = i+1; j < len; j++ )
		{
			// 데이터 초기화
			bDupFlag = false;
			nDupCnt = 0;

			// 최초로 일치하는 위치 찾기
			if ( nDigit[i] == nDigit[j] )
			{
				fIdx = i;
				sIdx = j;

				int f, s;
				for ( f = fIdx, s = sIdx; f < sIdx; f++, s++ )
				{
					// s 범위: sIdx ~ (len-1)
					// s가 len(입력된 숫자 길이)를 벗어나는 경우 패턴 불일치로 판단
					if ( s >= len )
					{
						bDupFlag = false;
						break;
					}

					// 패턴 일치하면 일치하는 개수까지 체크
					if ( nDigit[f] == nDigit[s] )
					{
						bDupFlag = true;
						nDupCnt++;
					}
					// 불일치하면 다음 패턴 체크
					else
					{
						bDupFlag = false;
						break;
					}
				}

				if ( bDupFlag == true )
				{
					// f == sIdx 조건을 추가함으로써 연속된 패턴인지 체크함
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
