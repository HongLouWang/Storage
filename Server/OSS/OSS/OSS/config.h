#pragma once

#ifndef CONFIG_H_
#define CONFIG_H_

#pragma(lib,"oss_c_sdk.lib");

//Define bucket information
#define endp "oss-us-west-1.aliyuncs.com"		//Endpoint
#define oss_AK "LTAIZgqEct7hoLqY"				//OSS AK
#define oss_SK "nJ5YvEmgN6eUi9M6Vtkye0AK5gkfYy" //OSS SK



#include "stdafx.h"
#include "aos_log.h"
#include "aos_util.h"
#include "aos_string.h"
#include "aos_status.h"
#include "oss_auth.h"
#include "oss_util.h"
#include "oss_api.h"
#include "oss_define.h"


void init_oss(oss_request_options_t *options);
int put_object_from_file(char bucketname, char objectname);
int init_multipart_upload();

#endif // !CONFIG_H_

