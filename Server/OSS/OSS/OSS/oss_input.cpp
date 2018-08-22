#include "stdafx.h"
#include "Config.h"

int put_object_from_file(char bucketname, char objectname)
{
	aos_pool_t *p = NULL;
	aos_string_t bucket;
	aos_string_t object;
	aos_table_t *headers = NULL;
	aos_table_t *resp_headers = NULL;
	oss_request_options_t *options = NULL;
	char *filename = __FILE__;
	aos_status_t *s = NULL;
	aos_string_t file;

	options = oss_request_options_create(p);
	init_oss(options);

	headers = aos_table_make(options -> pool, 1);
	apr_table_set(headers, OSS_CONTENT_TYPE, "image/jepg");
	aos_str_set(&bucket, bucketname);
	aos_str_set(&object, objectname);
	aos_str_set(&file, filename);
	aos_str_set(&file, filename);

	s = oss_put_object_from_file(options, &bucket, &object, &file, headers, &resp_headers);
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