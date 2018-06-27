#include "cmd_host.h"

int
dev2host_cmd_data_len(cmd_e cmd) {
	int ret = -1;

	switch(cmd) {
		case CMD_GET_FIRMWARE_SHA1:
			ret = sizeof(cmd_data16_t);
			break;
		case CMD_GET_RTC:
			ret = sizeof(cmd_data19_t);
			break;
		case CMD_GET_ANTENNA_DEFECTIVE_COLUMNS:
			ret = sizeof(cmd_data28_t);
			break;
		case CMD_GET_ENV_PARAMS:
			ret = sizeof(cmd_data36_t);
			break;
		case CMD_GET_ACTIVE_SCHEDULE:
			ret = sizeof(cmd_data47_t);
			break;
		case CMD_GET_UTCS_TRANSMIT_SCHEDULE:
			ret = sizeof(cmd_data58_t);
			break;
		case CMD_GET_SATCOM_SCHEDULE:
			ret = sizeof(cmd_data69_t);
			break;
		case CMD_GET_PASSIVE_PROCESSING_PARAMETERS:
			ret = sizeof(cmd_data71_t);
			break;
		case CMD_GET_ATT_1:
			ret = sizeof(cmd_data82_t);
			break;
		case CMD_GET_PASSIVE_MARKS:
			ret = sizeof(cmd_data101_t);
			break;
		case CMD_GET_ACTIVE_GET_ANGLE_ID_MARKS:
			ret = sizeof(cmd_data129_t);
			break;
		case CMD_GET_UTCS_INBOX:
			ret = sizeof(cmd_data142_t);
			break;
		case CMD_GET_PASSIVE_TARGETS:
			ret = sizeof(cmd_data151_t);
			break;
		case CMD_GET_ACTIVE_TARGETS:
			ret = sizeof(cmd_data160_t);
			break;
		case CMD_GET_STREAMS:
			ret = sizeof(cmd_data172_t);
			break;
		case CMD_GET_SELF_DIAGNOSIS:
			ret = sizeof(cmd_data187_t);
			break;
		case CMD_SERVICE:
			ret = sizeof(cmd_data0_t);
			break;
		case CMD_STREAM1:
			ret = sizeof(cmd_data86_t);
			break;
		case CMD_STREAM2:
			ret = sizeof(cmd_data89_t);
			break;
		case CMD_STREAM3:
			ret = sizeof(cmd_data92_t);
			break;
		case CMD_STREAM4:
			ret = sizeof(cmd_data92_t);
			break;
		case CMD_STREAM5:
			ret = sizeof(cmd_data95_t);
			break;
		case CMD_STREAM6:
			ret = sizeof(cmd_data95_t);
			break;
		case CMD_STREAM7:
			ret = sizeof(cmd_data104_t);
			break;
		case CMD_STREAM8:
			ret = sizeof(cmd_data107_t);
			break;
		case CMD_STREAM9:
			ret = sizeof(cmd_data110_t);
			break;
		case CMD_STREAM10:
			ret = sizeof(cmd_data107_t);
			break;
		case CMD_STREAM11:
			ret = sizeof(cmd_data110_t);
			break;
		case CMD_STREAM12:
			ret = sizeof(cmd_data107_t);
			break;
		case CMD_STREAM13:
			ret = sizeof(cmd_data110_t);
			break;
		case CMD_STREAM14:
			ret = sizeof(cmd_data114_t);
			break;
		case CMD_STREAM15:
			ret = sizeof(cmd_data117_t);
			break;
		case CMD_STREAM16:
			ret = sizeof(cmd_data121_t);
			break;
		case CMD_STREAM17:
			ret = sizeof(cmd_data124_t);
			break;
		case CMD_STREAM18:
			ret = sizeof(cmd_data132_t);
			break;
		case CMD_STREAM19:
			ret = sizeof(cmd_data135_t);
			break;
		case CMD_STREAM20:
			ret = sizeof(cmd_data145_t);
			break;
		case CMD_STREAM21:
			ret = sizeof(cmd_data154_t);
			break;
		case CMD_STREAM22:
			ret = sizeof(cmd_data174_t);
			break;
		default:
			break;
	}

	return ret;
}
