#include "cbuf_defs.h"
#include "cbuf_cmn.h"
#include "cbuf_ops.h"
#include "cbuf_utils.h"

int cb_enqueue(cbuf_t *cb, int value)
{
	if (cb == NULL) {
		LOG_ERR("cb %p", cb);
		return CBUF_OPS_FAIL;
	}

	if (is_cb_full(cb) == true) {
		printf("\n");
		LOG_DBG("circular buffer full. Cannot enqueue\n");
		return CBUF_OPS_FAIL;
	}

	if (is_cb_empty(cb) == true) {
		cb->write_idx = cb->read_idx = 0;
		cb->buffer[cb->write_idx] = value;
	} else {
		/* Increment or wrap around the write_idx */
		cb->write_idx = (cb->write_idx + 1) % (cb->bufsz);
		cb->buffer[cb->write_idx] = value;
	}

	return CBUF_OPS_SUCCESS;
}

int cb_dequeue(cbuf_t *cb, int *data)
{
	if (cb == NULL) {
		LOG_ERR("cb %p", cb);
		return CBUF_OPS_FAIL;
	}

	if (data == NULL) {
		LOG_ERR("data %p", data);
		return CBUF_OPS_FAIL;
	}

	if (is_cb_empty(cb) == true) {
		printf("\n");
		LOG_DBG("circular buffer empty. Cannot dequeue\n");
		return CBUF_OPS_FAIL;
	}

	LOG_DBG("Dequeing %d", cb->buffer[cb->read_idx]);

	*data = cb->buffer[cb->read_idx];

	memset(&(cb->buffer[cb->read_idx]), 0, sizeof(int));

	/* If only one element in queue, reset indexes else increment/wrap read_idx */
	(cb->read_idx == cb->write_idx) ? cb_reset_indices(cb) :
			(cb->read_idx = (cb->read_idx + 1) % (cb->bufsz));

	return CBUF_OPS_SUCCESS;
}