#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG
#define TRACE {printf("%s:%d: trace\n", __func__, __LINE__);}
#define ERROR {printf("%s:%d: error\n", __func__,__LINE__);}
void print_hex(const unsigned char* const ptr, int size);
void print_hex_word(const unsigned char* const ptr, int size);
int push_file(char* fname, void* obj, int size);
int pull_file(char* fname, unsigned char** obj, int* size);

#endif
