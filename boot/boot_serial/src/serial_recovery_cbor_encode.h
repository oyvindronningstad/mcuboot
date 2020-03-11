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

#ifndef SERIAL_RECOVERY_CBOR_ENCODE_H__
#define SERIAL_RECOVERY_CBOR_ENCODE_H__

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "cbor_encode.h"


typedef struct {
	uint32_t _Response_union_images_map_image;
} Response_union_images_map_image_t;

typedef struct {
	Response_union_images_map_image_t _Response_union_images_map_image;
	size_t _Response_union_images_map_image_present;
	uint32_t _Response_union_images_map_slot;
	cbor_string_type_t _Response_union_images_map_version;
} Response_union_images_map_t;

typedef struct {
	uint32_t _Response_union__rc_off;
} Response_union__rc_off_t;

typedef struct {
	union {
		struct {
			Response_union_images_map_t _Response_union_images_map[3];
			size_t _Response_union_images_map_count;
		};
		struct {
			int32_t _Response_union__rc_rc;
			Response_union__rc_off_t _Response_union__rc_off;
			size_t _Response_union__rc_off_present;
		};
	};
	enum {
		_Response_union_images,
		_Response_union__rc,
	} _Response_union_choice;
} Response_t;


bool cbor_encode_Response(
		uint8_t * p_payload, size_t payload_len,
		const Response_t * p_input,
		size_t *p_payload_len_out);


#endif // SERIAL_RECOVERY_CBOR_ENCODE_H__
