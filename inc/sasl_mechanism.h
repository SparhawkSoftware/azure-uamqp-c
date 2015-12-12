// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef SASL_MECHANISM_H
#define SASL_MECHANISM_H

#include "link.h"
#include "message.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

	typedef struct SASL_MECHANISM_INSTANCE_TAG* SASL_MECHANISM_HANDLE;
	typedef void* CONCRETE_SASL_MECHANISM_HANDLE;

	typedef struct INIT_BYTES_TAG
	{
		const void* bytes;
		size_t length;
	} SASL_MECHANISM_BYTES;

	typedef CONCRETE_SASL_MECHANISM_HANDLE(*SASL_MECHANISM_CREATE)(void* config);
	typedef void(*SASL_MECHANISM_DESTROY)(CONCRETE_SASL_MECHANISM_HANDLE concrete_sasl_mechanism);
	typedef int(*SASL_MECHANISM_GET_INIT_BYTES)(CONCRETE_SASL_MECHANISM_HANDLE concrete_sasl_mechanism, SASL_MECHANISM_BYTES* init_bytes);
	typedef const char*(*SASL_MECHANISM_GET_MECHANISM_NAME)(CONCRETE_SASL_MECHANISM_HANDLE concrete_sasl_mechanism);

	typedef struct SASL_MECHANISM_INTERFACE_TAG
	{
		SASL_MECHANISM_CREATE concrete_sasl_mechanism_create;
		SASL_MECHANISM_DESTROY concrete_sasl_mechanism_destroy;
		SASL_MECHANISM_GET_INIT_BYTES concrete_sasl_mechanism_get_init_bytes;
		SASL_MECHANISM_GET_MECHANISM_NAME concrete_sasl_mechanism_get_mechanism_name;
	} SASL_MECHANISM_INTERFACE_DESCRIPTION;

	extern SASL_MECHANISM_HANDLE saslmechanism_create(const SASL_MECHANISM_INTERFACE_DESCRIPTION* sasl_mechanism_interface_description, void* sasl_mechanism_create_parameters);
	extern void saslmechanism_destroy(SASL_MECHANISM_HANDLE sasl_mechanism);
	extern int saslmechanism_get_init_bytes(SASL_MECHANISM_HANDLE sasl_mechanism, SASL_MECHANISM_BYTES* init_bytes);
	extern const char* saslmechanism_get_mechanism_name(SASL_MECHANISM_HANDLE sasl_mechanism);
	extern int saslmechanism_challenge(SASL_MECHANISM_HANDLE sasl_mechanism, const SASL_MECHANISM_BYTES* challenge_bytes, SASL_MECHANISM_BYTES* response_bytes);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SASL_MECHANISM_H */