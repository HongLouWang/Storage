#include "stdafx.h"
#include "Config.h"

int append_object_from_file()
{
	aos_pool_t *p = NULL;
	aos_string_t bucket;
	aos_string_t object;
	aos_table_t *headers1 = NULL;
	aos_table_t *headers2 = NULL;
	aos_table_t *resp_headers = NULL;
	oss_request_options_t *options = NULL;
	char *filename = __FILE__;
	aos_status_t *s = NULL;
	aos_string_t file;
	int64_t position = 0;
	char *next_append_position = NULL;

	aos_pool_create(&p, NULL);

	options = oss_request_options_create(p);
	init_oss(options);

	headers1 = aos_table_make(options->pool, 0);
	headers2 = aos_table_make(options->pool, 0);
	aos_str_set(&bucket, "");
	aos_str_set(&object, "");
	aos_str_set(&file, filename);

	s = oss_head_object(options, &bucket, &object, headers1, &resp_headers);

	if (aos_status_is_ok(s))
	{
		aos_pool_destroy(p);
		return 0;
	}
	else
	{
		aos_pool_destroy(p);
		return 1;
	}

}