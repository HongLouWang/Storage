#include "stdafx.h"
#include "config.h"

int oss_new_bucket()
{
	aos_pool_t *p;
	oss_request_options_t *options;
	aos_status_t *s;
	aos_table_t *resp_headers;
	oss_acl_e oss_acl = OSS_ACL_PRIVATE;
	char *bucket_name;
	aos_string_t bucket;

	aos_pool_create(&p, NULL);

	options = oss_request_options_create(p);
	init_oss(options);
	aos_str_set(&bucket, "storage-pullman");
	s = oss_create_bucket(options, &bucket, oss_acl, &resp_headers);

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


