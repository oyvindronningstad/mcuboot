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
#include "cbor_decode.h"
#include "serial_recovery_cbor_decode.h"


static bool decode_Member(
		cbor_state_t *p_state, _Member_t * p_result)
{
	cbor_print("decode_Member\n");
	cbor_string_type_t tmp_str;
	bool int_res;

	bool result = (((union_start_code(p_state) && (int_res = (((((tstrx_expect(p_state, ((tmp_str.value = "image", tmp_str.len = 5, &tmp_str)))))
	&& (intx32_decode(p_state, (&(*p_result)._Member_image)))) && (((*p_result)._Member_choice = _Member_image) || 1))
	|| (union_elem_code(p_state) && ((((tstrx_expect(p_state, ((tmp_str.value = "data", tmp_str.len = 4, &tmp_str)))))
	&& (bstrx_decode(p_state, (&(*p_result)._Member_data)))) && (((*p_result)._Member_choice = _Member_data) || 1)))
	|| (union_elem_code(p_state) && ((((tstrx_expect(p_state, ((tmp_str.value = "len", tmp_str.len = 3, &tmp_str)))))
	&& (intx32_decode(p_state, (&(*p_result)._Member_len)))) && (((*p_result)._Member_choice = _Member_len) || 1)))
	|| (union_elem_code(p_state) && ((((tstrx_expect(p_state, ((tmp_str.value = "off", tmp_str.len = 3, &tmp_str)))))
	&& (intx32_decode(p_state, (&(*p_result)._Member_off)))) && (((*p_result)._Member_choice = _Member_off) || 1)))
	|| (union_elem_code(p_state) && ((((tstrx_expect(p_state, ((tmp_str.value = "sha", tmp_str.len = 3, &tmp_str)))))
	&& (bstrx_decode(p_state, (&(*p_result)._Member_sha)))) && (((*p_result)._Member_choice = _Member_sha) || 1)))), union_end_code(p_state), int_res))));

	if (!result)
	{
		cbor_trace();
	}

	return result;
}

static bool decode_Upload(
		cbor_state_t *p_state, Upload_t * p_result)
{
	cbor_print("decode_Upload\n");
	bool int_res;

	bool result = (((map_start_decode(p_state) && (int_res = (multi_decode(3, 5, &(*p_result)._Upload_members_count, (void*)decode_Member, p_state, (&(*p_result)._Upload_members), sizeof(_Member_t))), ((map_end_decode(p_state)) && int_res)))));

	if (!result)
	{
		cbor_trace();
	}

	return result;
}



bool cbor_decode_Upload(
		const uint8_t * p_payload, size_t payload_len,
		Upload_t * p_result,
		bool complete)
{
	cbor_state_t state = {
		.p_payload = p_payload,
		.p_payload_end = p_payload + payload_len,
		.elem_count = 1
	};

	cbor_state_t state_backups[3];

	cbor_state_backups_t backups = {
		.p_backup_list = state_backups,
		.current_backup = 0,
		.num_backups = 3,
	};

	state.p_backups = &backups;

	bool result = decode_Upload(&state, p_result);

	if (!complete) {
		return result;
	}
	if (result) {
		if (state.p_payload == state.p_payload_end) {
			return true;
		} else {
			cbor_state_t *p_state = &state; // for printing.
			cbor_print("p_payload_end: 0x%x\r\n", (uint32_t)state.p_payload_end);
			cbor_trace();
		}
	}
	return false;
}
