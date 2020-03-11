/*
 * This file has been generated from the cddl_gen submodule.
 * Commit 5c4976150399c648ef090b5fd1c2384e42a73530
 */

/*
 * Copyright (c) 2020 Nordic Semicondctor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Generated with cddl_gen.py (https://github.com/oyvindronningstad/cddl_gen)
 * at: 2020-03-11 15:49:27
 */

#ifndef SERIAL_RECOVERY_CBOR_DECODE_H__
#define SERIAL_RECOVERY_CBOR_DECODE_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "cbor_decode.h"


typedef struct {
	union {
		struct {
			int32_t _Member_image;
		};
		struct {
			cbor_string_type_t _Member_data;
		};
		struct {
			int32_t _Member_len;
		};
		struct {
			int32_t _Member_off;
		};
		struct {
			cbor_string_type_t _Member_sha;
		};
	};
	enum {
		_Member_image,
		_Member_data,
		_Member_len,
		_Member_off,
		_Member_sha,
	} _Member_choice;
} _Member_t;

typedef struct {
	_Member_t _Upload_members[5];
	size_t _Upload_members_count;
} Upload_t;


bool cbor_decode_Upload(
		const uint8_t * p_payload, size_t payload_len,
		Upload_t * p_result,
		bool complete);


#endif // SERIAL_RECOVERY_CBOR_DECODE_H__
