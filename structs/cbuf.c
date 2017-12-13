#include "common.h"

int
cbuf_new(cbuf_t** cbuf, size_t cbuf_size, size_t data_size) {
	*cbuf = NULL;
	*cbuf = malloc(sizeof(cbuf_t));
	if(!cbuf)
		return -1;;

	(*cbuf)->head = 0;
	(*cbuf)->tail = 0;
	(*cbuf)->cbuf_size = cbuf_size;
	(*cbuf)->data_size = data_size;
	(*cbuf)->buf = malloc(cbuf_size*data_size);

	return 0;
}

int
cbuf_del(cbuf_t* cbuf) {
	if(cbuf) {
		if(cbuf->buf) {
			free(cbuf->buf);
			cbuf->buf = NULL;
		}
		free(cbuf);
	} else {
		return -1;
	}

	return 0;
}

int
cbuf_is_empty(cbuf_t *c) {
	return	c->head != c->tail;
}

int
cbuf_add(cbuf_t *c, char* data, size_t data_size) {
	int next = c->head + 1;

	if(data_size > c->data_size)
		return -1;

	if (next >= c->cbuf_size)
		next = 0;

	memcpy(&c->buf[c->head * c->data_size], data, data_size);
	//move tail
	if (next == c->tail) {
		/* Rewrite tail data with new one */
		c->tail += 1;
		if(c->tail >= c->cbuf_size) {
			c->tail = 0;
		}
	}
	//move head
	c->head = next;

	return 0;
}

int
cbuf_get(cbuf_t *c, char** data) {
	if (c->head == c->tail)
		return -1;

	*data = &c->buf[c->tail * c->data_size];

	return 0;
}

int
cbuf_remove(cbuf_t *c) {
	if (c->head == c->tail)
		return -1;

	int next = c->tail + 1;
	if(next >= c->cbuf_size)
		next = 0;
	c->tail = next;
	return 0;
}

