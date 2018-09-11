#include "Config.h"
#include "Timer.h"
#include <os.h>

void Delay( int period )
{
	OS_ERR *err;
	OSTimeDly (period, OS_OPT_TIME_DLY, err);
}


