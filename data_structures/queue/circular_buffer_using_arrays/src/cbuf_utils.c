#include "cbuf_cmn.h"
#include "cbuf_defs.h"
#include "cbuf_utils.h"

static void cb_init(cbuf_t *cb, int cb_capacity);

bool is_cb_empty(const cbuf_t *cb)
{
	if (cb == NULL) {
		LOG_DBG("cb %p", cb);
		exit (EXIT_FAILURE);
	}

	if ((cb->write_idx == -1) && (cb->read_idx == -1)) {
		return true;
	}

	return false;
}

bool is_cb_full(const cbuf_t *cb)
{
	if (cb == NULL) {
		LOG_DBG("cb %p", cb);
		exit (EXIT_FAILURE);
	}

	if (((cb->write_idx + 1) % (cb->bufsz)) == (cb->read_idx)) {
		return true;
	}

	return false;
}

void cb_reset_indices(cbuf_t *cb)
{
	if (cb == NULL) {
		LOG_DBG("cb %p", cb);
		return;
	}

    cb->read_idx = -1;
	cb->write_idx = -1;      
}

static void cb_init(cbuf_t *cb, int cb_capacity)
{
	if (cb == NULL) {
		LOG_DBG("cb %p", cb);
		exit(EXIT_FAILURE);
	}

	if (cb_capacity <= 0) {
		LOG_DBG("cb_capacity %d", cb_capacity);
		exit(EXIT_FAILURE);
	}

	//memset(cb, 0, sizeof(cbuf_t));
	memset(cb->buffer, 0, sizeof(int) * cb_capacity);

	cb->bufsz = cb_capacity;

	cb_reset_indices(cb);

	return;
}

cbuf_t *cb_create(int cb_capacity)
{
	cbuf_t *cb = NULL;

	if (cb_capacity <= 0) {
		LOG_ERR("cb_capacity %d", cb_capacity);
		return NULL;
	}

	cb = (cbuf_t *)malloc(sizeof(cbuf_t));
	if (cb == NULL) {
		LOG_ERR("malloc(): %s (%d)", strerror(errno), errno);
		return NULL;
	}

	LOG_DBG("Success: allocated cb %p", cb);

	cb->buffer = (int *)malloc(sizeof(int) * cb_capacity);
	if (cb->buffer == NULL) {
		LOG_ERR("malloc(): %s (%d)", strerror(errno), errno);
		free(cb);
		cb = NULL;
		return NULL;
	}

	LOG_DBG("Success: allocated cb->buffer %p", cb->buffer);

	cb_init(cb, cb_capacity);

	return cb;
}

void cb_destroy(cbuf_t *cb)
{
	if (cb == NULL) {
		LOG_DBG("cb %p", cb);
		return;
	}

	if (cb->buffer != NULL) {
		LOG_DBG("Freeing cb->buffer: %p", cb->buffer);
		free(cb->buffer);
		cb->buffer = NULL;
	}

	LOG_DBG("freeing cb %p", cb);
	free(cb);
	cb = NULL;

	return;
}

void cb_print_status(const cbuf_t *cb)
{
	if (cb == NULL) {
		LOG_DBG("cb %p", cb);
		return;
	}

	LOG_DBG("buffer: %p, bufsz %d, read_idx %d, write_idx %d\n", cb->buffer, cb->bufsz, cb->read_idx, cb->write_idx);
}

int cb_display(const cbuf_t *cb)
{
	if (cb == NULL) {
		LOG_DBG("cb %p", cb);
		return CBUF_OPS_FAIL;
	}

	if (is_cb_empty(cb) == true) {
		LOG_DBG("Empty circular buffer \n");
	} else {
		printf("CB: ");
	
		int i = cb->read_idx;

		while (i != cb->write_idx) {
			printf("%d ", cb->buffer[i]);
			i = (i + 1) % (cb->bufsz);
		}
		printf("%d", cb->buffer[i]);
	}

	printf("\n");

	return CBUF_OPS_SUCCESS;
}