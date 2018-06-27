#include <stdio.h>
#include "common.h"

void
print_hex_word(const unsigned char* const ptr, uint32_t size) {
	int i;
	printf("addr=%p(%d):", ptr, size);
	for(i=0;i<size;i++) {
		if(i%32==0) {
			printf("\n%06d ", i);
		}
		if(i%4==0) printf(" 0x");
		printf("%2.2X", ptr[i]);
	}
	printf("\n");
}

