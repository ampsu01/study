#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


#pragma pack(push, 1)    // 1바이트 크기로 정렬

typedef struct _ARCHIVE_HEADER {
	uint16_t magic;
	uint16_t version;
} ARCHIVE_HEADER, *PARCHIVE_HEADER;

typedef struct _FILE_DESC {
	char name[256];
	uint32_t size;
	uint32_t dataOffset;
} FILE_DERSC, *PFILE_SESC;

#pragma pack(pop)        // 정렬 설정을 이전 상태(기본값)로 되돌림

typedef struct _ARCHIVE {
	ARCHIVE_HEADER header;
	FILE *fp;
} ARCHIVE, *PARCHIVE;

#define ARCHIVE_NAME "archive.bin"

uint32_t getFileSize(FILE *fp)
{
	uint32_t size;
	uint32_t currPos = ftell(fp);
	
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	
	fseek(fp, currPos, SEEK_SET);
	
	return size;
}

int append(PARCHIVE archive, char *filename)
{
	int ret = 0;
	
	FILE *fp = fopen(filename, "rb");
	if(fp == NULL)
	{
		printf("%s 파일이 없습니다.\n", filename);
		return -1;
	}
	
	uint8_t *buffer;
	uint32_t size;
	
	size = getFileSize(fp);
	buffer = malloc(size);
	
	if(fread(buffer, size, 1, fp) < 1)
	{
		printf("%s 파일 읽기 실패 \n", filename);
		ret = -1;
		goto ERROR1;
	}
}

int main(int argc, char *argv[]) {
	

	return 0;
}

#endif
