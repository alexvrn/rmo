#ifndef LOG_H
#define LOG_H

#include "stdio.h"

#define PGAS_LOG(X)	pgas_log(X);

void pgas_log(char* str);

#endif
