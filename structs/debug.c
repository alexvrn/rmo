#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


void
print_hex(const unsigned char* const ptr, int size) {
	int i;
	for(i=0;i<size;i++) {
		printf("0x%2.2x, ", ptr[i]);
		if((i+1)%16==0 && i!=0 && i!=(size-1)) printf("\n");
	}
	printf("\n");
}

void
print_hex_word(const unsigned char* const ptr, int size) {
	int i;

	if(!ptr || size<=0)
		return;

	printf("HEX DUMP %p(%d byte)", ptr, size);
	for(i=0;i<size;i++) {
		if(i%32==0) {
			printf("\n%06d ", i);
		}
		if(i%4==0) printf(" 0x");
			printf("%2.2x", ptr[i]);
	}
	printf("\n");
}

int
push_file(char* fname, void* obj, int size) {
	if (!obj) {
		printf("ERROR: can't write NULL buffer in %s file.\n", fname);
		return -1;
	}
	FILE * file;
	file = fopen(fname, "wb");
	if (file != NULL) {
		fwrite(obj, size, 1, file);
		fclose(file);
	} else {
		printf("Error: can't open file %s.\n", fname);
		return errno;
	}
	//printf("push: %s %d\n", fname, size);
	return 0;
}

int
pull_file(char* fname, unsigned char** obj, int* size) {
	/* Stat file size */
	struct stat sb;
	if (stat(fname, &sb) == -1) {
		printf("Error: can't stat file %s.\n", fname);
		exit(errno);
	}
	*size = sb.st_size;

	/* Allocate buffer for file data */
	*obj = malloc(*size);

	/* Read file in buffer */
	FILE * file;
	file = fopen(fname, "rb");
	if (file != NULL) {
		if(fread(*obj, *size, 1, file) != 1) {
			printf("Error: can't  read from file %s %d byte!!!\n", fname, *size);
			fclose(file);
			exit(errno);
		}
		fclose(file);
	} else {
		printf("Error: can't open file %s.\n", fname);
		exit(errno);
	}
	return 0;
}

