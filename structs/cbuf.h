#ifndef CBUF_H
#define CBUF_H

typedef struct cbuf_t {
	int head;
	int tail;
	size_t cbuf_size;
	size_t data_size;
	char* buf;
} cbuf_t;

int cbuf_new(cbuf_t** cbuf, size_t cbuf_size, size_t data_size);
int cbuf_del(cbuf_t* cbuf);
int cbuf_is_empty(cbuf_t* cbuf);
int cbuf_add(cbuf_t *c, char* data, size_t data_size);
int cbuf_get(cbuf_t *c, char** data);
int cbuf_remove(cbuf_t *c);

#endif
