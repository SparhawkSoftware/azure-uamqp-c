// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef WSIO_H
#define WSIO_H

#ifdef __cplusplus
extern "C" {
#include <cstddef>
#include <cstdbool>
#else
#include <stddef.h>
#include <stdbool.h>
#endif /* __cplusplus */

#include "xio.h"
#include "sasl_mechanism.h"
#include "logger.h"

typedef struct WSIO_CONFIG_TAG
{
	const char* host;
	int port;
	const char* protocol_name;
	const char* relative_path;
	bool use_ssl;
	const char* trusted_ca;
} WSIO_CONFIG;

extern CONCRETE_IO_HANDLE wsio_create(void* io_create_parameters, LOGGER_LOG logger_log);
extern void wsio_destroy(CONCRETE_IO_HANDLE ws_io);
extern int wsio_open(CONCRETE_IO_HANDLE ws_io, ON_BYTES_RECEIVED on_bytes_received, ON_IO_STATE_CHANGED on_io_state_changed, void* callback_context);
extern int wsio_close(CONCRETE_IO_HANDLE ws_io);
extern int wsio_send(CONCRETE_IO_HANDLE ws_io, const void* buffer, size_t size, ON_SEND_COMPLETE on_send_complete, void* callback_context);
extern void wsio_dowork(CONCRETE_IO_HANDLE ws_io);
extern const IO_INTERFACE_DESCRIPTION* wsio_get_interface_description(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* WSIO_H */