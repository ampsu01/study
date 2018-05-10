#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


#pragma pack(push, 1)    // 1����Ʈ ũ��� ����

typedef struct _ARCHIVE_HEADER {
	uint16_t magic;
	uint16_t version;
} ARCHIVE_HEADER, *PARCHIVE_HEADER;

typedef struct _FILE_DESC {
	char name[256];
	uint32_t size;
	uint32_t dataOffset;
} FILE_DERSC, *PFILE_SESC;

#pragma pack(pop)        // ���� ������ ���� ����(�⺻��)�� �ǵ���

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
		printf("%s ������ �����ϴ�.\n", filename);
		return -1;
	}
	
	uint8_t *buffer;
	uint32_t size;
	
	size = getFileSize(fp);
	buffer = malloc(size);
	
	if(fread(buffer, size, 1, fp) < 1)
	{
		printf("%s ���� �б� ���� \n", filename);
		ret = -1;
		goto ERROR1;
	}
}

int main(int argc, char *argv[]) {
	

	return 0;
}

#endif
