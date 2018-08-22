#include "stdafx.h"
#include "Config.h"

void init_oss(oss_request_options_t *options)
{
	aos_pool_t *pool;

	//Init Memorize pool
	aos_pool_create(&pool, NULL);

	aos_str_set(&options->config->endpoint, endp);
	aos_str_set(&options->config->access_key_id, oss_AK);
	aos_str_set(&options->config->access_key_secret, oss_SK);

	options->config->is_cname = 0;

	options->ctl = aos_http_controller_create(options->pool, 0);
}