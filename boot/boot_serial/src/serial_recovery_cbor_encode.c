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

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "cbor_encode.h"
#include "serial_recovery_cbor_encode.h"


static bool encode_repeated_Response_union_images_map_image(
		cbor_state_t *p_state, const Response_union_images_map_image_t * p_input)
{
	cbor_print("encode_repeated_Response_union_images_map_image\n");
	cbor_string_type_t tmp_str;

	bool result = ((((tstrx_encode(p_state, ((tmp_str.value = "image", tmp_str.len = 5, &tmp_str)))))
	&& (uintx32_encode(p_state, (&(*p_input)._Response_union_images_map_image)))));

	if (!result)
	{
		cbor_trace();
	}

	return result;
}

static bool encode_repeated_Response_union_images_map(
		cbor_state_t *p_state, const Response_union_images_map_t * p_input)
{
	cbor_print("encode_repeated_Response_union_images_map\n");
	cbor_string_type_t tmp_str;
	bool int_res;

	bool result = (((map_start_encode(p_state, 3) && (int_res = (present_encode(&((*p_input)._Response_union_images_map_image_present), (void*)encode_repeated_Response_union_images_map_image, p_state, (&(*p_input)._Response_union_images_map_image))
	&& (((tstrx_encode(p_state, ((tmp_str.value = "slot", tmp_str.len = 4, &tmp_str)))))
	&& (uintx32_encode(p_state, (&(*p_input)._Response_union_images_map_slot))))
	&& (((tstrx_encode(p_state, ((tmp_str.value = "version", tmp_str.len = 7, &tmp_str)))))
	&& (bstrx_encode(p_state, (&(*p_input)._Response_union_images_map_version))))), ((map_end_encode(p_state, 3)) && int_res)))));

	if (!result)
	{
		cbor_trace();
	}

	return result;
}

static bool encode_repeated_Response_union__rc_off(
		cbor_state_t *p_state, const Response_union__rc_off_t * p_input)
{
	cbor_print("encode_repeated_Response_union__rc_off\n");
	cbor_string_type_t tmp_str;

	bool result = ((((tstrx_encode(p_state, ((tmp_str.value = "off", tmp_str.len = 3, &tmp_str)))))
	&& (uintx32_encode(p_state, (&(*p_input)._Response_union__rc_off)))));

	if (!result)
	{
		cbor_trace();
	}

	return result;
}

static bool encode_Response(
		cbor_state_t *p_state, const Response_t * p_input)
{
	cbor_print("encode_Response\n");
	cbor_string_type_t tmp_str;
	bool int_res;

	bool result = (((map_start_encode(p_state, 2) && (int_res = (((((*p_input)._Response_union_choice == _Response_union_images) ? (((tstrx_encode(p_state, ((tmp_str.value = "images", tmp_str.len = 6, &tmp_str)))))
	&& (list_start_encode(p_state, 3) && (int_res = (multi_encode(1, 3, &(*p_input)._Response_union_images_map_count, (void*)encode_repeated_Response_union_images_map, p_state, (&(*p_input)._Response_union_images_map), sizeof(Response_union_images_map_t))), ((list_end_encode(p_state, 3)) && int_res))))
	: (((*p_input)._Response_union_choice == _Response_union__rc) ? (((((tstrx_encode(p_state, ((tmp_str.value = "rc", tmp_str.len = 2, &tmp_str)))))
	&& (intx32_encode(p_state, (&(*p_input)._Response_union__rc_rc))))
	&& present_encode(&((*p_input)._Response_union__rc_off_present), (void*)encode_repeated_Response_union__rc_off, p_state, (&(*p_input)._Response_union__rc_off))))
	: false)))), ((map_end_encode(p_state, 2)) && int_res)))));

	if (!result)
	{
		cbor_trace();
	}

	return result;
}



bool cbor_encode_Response(
		uint8_t * p_payload, size_t payload_len,
		const Response_t * p_input,
		size_t *p_payload_len_out)
{
	cbor_state_t state = {
		.p_payload = p_payload,
		.p_payload_end = p_payload + payload_len,
		.elem_count = 1
	};

	cbor_state_t state_backups[5];

	cbor_state_backups_t backups = {
		.p_backup_list = state_backups,
		.current_backup = 0,
		.num_backups = 5,
	};

	state.p_backups = &backups;

	bool result = encode_Response(&state, p_input);

	if (p_payload_len_out != NULL) {
		*p_payload_len_out = ((size_t)state.p_payload - (size_t)p_payload);
	}
	return result;
}
