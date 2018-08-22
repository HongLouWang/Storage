#include "stdafx.h"
#include "Config.h"

int init_multipart_upload()
{
	aos_pool_t *p = NULL;
	aos_string_t bucket;
	aos_string_t object;
	aos_table_t *headers = NULL;
	aos_table_t *resp_headers = NULL;
	oss_request_options_t *options = NULL;
	oss_request_options_t upload_file = NULL;
	aos_string_t upload_id;
	oss_upload_file_t *upload_file = NULL;
	aos_status_t *s = NULL;
	oss_list_upload_part_params_t *params = NULL;
	aos_list_t complete_part_list;
	oss_list_part_content_t *part_content = NULL;
	aos_pool_create(&p, NULL);

	options = oss_request_options_create(p);
	init_oss(options);

	headers = aos_table_make(p, 1);
	aos_str_set(&bucket, "");
	aos_str_set(&object, "");

	s = oss_init_multipart_upload(options, &bucket, &object, &upload_id, headers, &resp_headers);

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

	return 0;
}