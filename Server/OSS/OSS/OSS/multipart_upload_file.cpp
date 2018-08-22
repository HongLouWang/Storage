#include "stdafx.h"
#include "config.h"

int multipart_upload_file()
{
	aos_pool_t *p = NULL;
	aos_string_t bucket;
	aos_string_t object;
	int is_cname = 0;
	aos_table_t  *headers = NULL;
	aos_table_t *complet_headers = NULL;
	aos_table_t *resp_headers = NULL;
	oss_request_options_t *options = NULL;
	aos_string_t upload_id;
	oss_upload_file_t *upload_file = NULL;
	aos_status_t *s = NULL;
	oss_list_upload_part_params_t *params = NULL;
	aos_list_t complete_part_list;
	oss_list_part_content_t *part_content = NULL;
	oss_complete_part_content_t *complete_part_content = NULL;
	extern const char MULTIPART_UPLOAD_FILE_PATH[];

	int part_num1 = 1;
	int part_num2 = 2;

	aos_pool_create(&p, NULL);

	options = oss_request_options_create(p);
	init_oss(options);

	headers = aos_table_make(p, 1);
	resp_headers = aos_table_make(options->pool, 5);
	aos_str_set(&bucket, "");
	aos_str_set(&object, "");

	upload_file = oss_create_upload_file(p);
	aos_str_set(&upload_file->filename, MULTIPART_UPLOAD_FILE_PATH);
	upload_file->file_pos = 0;
	upload_file->file_last = 200 * 1024;
	s = oss_upload_part_from_file(options, &bucket, &object, &upload_id, part_num1, upload_file, &resp_headers);

	if (aos_status_is_ok(s))
	{
		
	}
	else
	{
		return 1;
	}

	upload_file->file_pos = 200 * 1024;
	upload_file->file_last = GetFileSize(MULTIPART_UPLOAD_FILE_PATH);



}