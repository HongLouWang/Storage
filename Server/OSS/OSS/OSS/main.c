// OSS.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "config.h"

int main(int argc, char *argv[])
{

	if (aos_http_io_initialize(NULL, 0) != AOSE_OK)
	{
		exit(1);
	}

	aos_http_io_deinitialize();


	return 0;
}

