#ifndef PGAS_H
#define PGAS_H

#include "stdio.h"
#include "common.h"

typedef struct pgas_config_t {
	unsigned time_is_set :1;
	unsigned timestamp;

	

	unsigned defectiveColumns[PGA_COUNT_MAX];

} pgas_config_t;

#endif

