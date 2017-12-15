#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "cbor.h"

#include "cmd_data.h"

#define PORT_MIN	2000
#define PORT_MAX	3000

#define CHECK_RET	if(ret != 0) {				\
				printf("%s:%d: ERROR\n",	\
				 __func__,__LINE__);		\
				goto exit;			\
			}

#define USE_DATA_EMULATOR
//#define USE_RANDOM_EMULATOR

dev_type_t dev = DEV_UNDEF;
URL_RESPONSE_HANDLER url_response_handler = NULL;

void
usage(char* pname, char* msg) {
	if(msg) {
		printf("%s\n", msg);
	}
	printf(	"%s <dev> <port>\n"
		"	dev	- PU | PGAS | SKGP\n"
		"	port	- port number [%d-%d]\n",
		pname, PORT_MIN, PORT_MAX
	);
	exit(255);
}

int
main(int argc, char** argv) {
	int ret = 0;
	unsigned int port = 0;
	httpd* httpd_daemon = NULL;

#ifdef USE_DATA_EMULATOR
	sensor_emulator_t* shp1_emu;
	sensor_emulator_t* shp2_emu;
	char* shp1_file[2] = {
		"./scripts/pp_pss_000_000.dat",
		"./scripts/pp_pss_000_001.dat",
	};
	char* shp2_file[2] = {
		"./scripts/pp_pss_001_000.dat",
		"./scripts/pp_pss_001_001.dat",
	};
	shp_emu_data_t shp1_emu_data = {shp1_file, 0, NULL, 0, NULL};
	shp_emu_data_t shp2_emu_data = {shp2_file, 0, NULL, 0, NULL};
	unsigned shp1_stream = 3, shp2_stream = 4;
#endif

#ifdef USE_RANDOM_EMULATOR
	sensor_emulator_t* stream_emu[PGAS_STREAM_MAX] = {NULL,};
	unsigned stream_emu_data[PGAS_STREAM_MAX];
	for(int e=0; e<PGAS_STREAM_MAX; e++) {
		stream_emu_data[e] = e;
	}
	TRACE
#endif

	//parse arguments
	if(argc != 3) {
		usage(argv[0], "bad options count");
	}
	//dev name
	if(strcmp(argv[1], "PU")==0) {
		dev = DEV_PU;
	} else if(strcmp(argv[1], "PGAS")==0) {
		dev = DEV_PGAS;
	} else if(strcmp(argv[1], "SKGP")==0) {
		dev = DEV_SKGP;
	} else {
		usage(argv[0], "bad device name");
	}
	//port number
	port = atoi(argv[2]);
	if(port > PORT_MAX || port < PORT_MIN) {
		usage(argv[0], "bad port number");
	}

	//starting httpd server accordance to device type emulated
	switch(dev) {
		case DEV_PU:
			httpd_daemon = httpd_start(port,
				pu_url_request_handler,
				&url_response_handler,
				PAGE_PU);
			break;
		case DEV_PGAS:
			httpd_daemon = httpd_start(port,
				pgas_url_request_handler,
				&url_response_handler,
				PAGE_PGAS);
			break;
		case DEV_SKGP:
			httpd_daemon = httpd_start(port,
				skgp_url_request_handler,
				&url_response_handler,
				PAGE_SKGP);
			break;
		default:
			printf("ERROR: undefined device type.\n");
			break;
	}
	if(httpd_daemon == NULL) {
		PGAS_LOG("Starting HTTPD: FAIL");
	}
	printf("Start HTTPD: port %d OK\n", port);

	ret = pgas_stream_init();
	CHECK_RET

#ifdef USE_DATA_EMULATOR
	shp1_emu = sensor_emulator_start(
			1,
			shp_emulator, (void*)&shp1_emu_data,
			shp_handler, &shp1_stream);
	shp2_emu = sensor_emulator_start(
			1,
			shp_emulator, (void*)&shp2_emu_data,
			shp_handler, &shp2_stream);
#endif

#ifdef USE_RANDOM_EMULATOR
	for(int e=0; e<PGAS_STREAM_MAX; e++) {
		stream_emu[e] = sensor_emulator_start(
			1,
			emu_stream_emulator, NULL,
			emu_stream_handler, &stream_emu_data[e]
			);
	}
#endif

	while(pgas_stream_proc(pgas_stream) == 0) ;

	//processing request in *_url_request_handler function
	(void)getc(stdin);
	PGAS_LOG("Waiting for request...");

exit:

#ifdef USE_DATA_EMULATOR
	sensor_emulator_stop(shp1_emu);
	sensor_emulator_stop(shp2_emu);
#endif

#ifdef USE_RANDOM_EMULATOR
	for(int e=0; e<PGAS_STREAM_MAX; e++) {
		sensor_emulator_stop(stream_emu[e]);
	}
#endif
	pgas_stream_cleanup();

	//cancel httpd
	ret = httpd_stop(httpd_daemon);
	if(ret != PGAS_STATUS_OK) {
		PGAS_LOG("Stopping HTTPD: FAIL");
	}
	PGAS_LOG("Stop HTTPD: OK");

	return ret;
}

