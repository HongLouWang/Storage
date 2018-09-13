/*
*********************************************************************************************************
*                                              EXAMPLE CODE
*
*                          (c) Copyright 2003-2013; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                            EXAMPLE CODE
*
*                                     ST Microelectronics STM32
*                                              on the
*
*                                     Micrium uC-Eval-STM32F107
*                                        Evaluation Board
*
* Filename      : app.c
* Version       : V1.00
* Programmer(s) : EHS
*                 DC
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include <includes.h>
#include "Config.h"


/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                                 TCB
*********************************************************************************************************
*/

static  OS_TCB		AppTaskStartTCB;
static 	OS_TCB		AppWiFiTCB;


/*
*********************************************************************************************************
*                                                STACKS
*********************************************************************************************************
*/

static  CPU_STK  AppTaskStartStk[APP_TASK_START_STK_SIZE];
static  CPU_STK	 AppTaskWiFi[APP_TASK_WIFI_STK_SIZE];



/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/


static  void  AppTaskStart  	(void *p_arg);
void AppWiFi();

/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.  It is assumed that your code will call
*               main() once you have performed all necessary initialization.
*
* Arguments   : none
*
* Returns     : none
*********************************************************************************************************
*/

int  main (void)
{
	OS_ERR err;	
	
	/* 初始化"uC/OS-III"内核 */  
	OSInit(&err);	
	
	/*创建任务*/
	OSTaskCreate((OS_TCB     *)&AppTaskStartTCB,              // 任务控制块指针          
               (CPU_CHAR   *)"App Task Start",		          // 任务名称
               (OS_TASK_PTR )AppTaskStart, 	                // 任务代码指针
               (void       *)0,			                    	 	// 传递给任务的参数parg
               (OS_PRIO     )APP_TASK_START_PRIO,			  		// 任务优先级
               (CPU_STK    *)&AppTaskStartStk[0],	          // 任务堆栈基地址
               (CPU_STK_SIZE)APP_TASK_START_STK_SIZE/10,	  // 堆栈剩余警戒线
               (CPU_STK_SIZE)APP_TASK_START_STK_SIZE,		  	// 堆栈大小
               (OS_MSG_QTY  )1u,			                      // 可接收的最大消息队列数
               (OS_TICK     )0u,			                      // 时间片轮转时间
               (void       *)0,			                    	  // 任务控制块扩展信息
               (OS_OPT      )(OS_OPT_TASK_STK_CHK | 
                              OS_OPT_TASK_STK_CLR),	     		// 任务选项
               (OS_ERR     *)&err);		                   	  // 返回值
	  
  /* 启动多任务系统，控制权交给uC/OS-III */
  OSStart(&err);  
}


/*
*********************************************************************************************************
*                                          STARTUP TASK
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Arguments   : p_arg   is the argument passed to 'AppTaskStart()' by 'OSTaskCreate()'.
*
* Returns     : none
*
* Notes       : 1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                  used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/

static  void  AppTaskStart (void *p_arg)
{
    CPU_INT32U  cpu_clk_freq;
    CPU_INT32U  cnts;
    OS_ERR      err;


   (void)p_arg;

    BSP_Init();                                                 /* Initialize BSP functions                             */
    CPU_Init();

    cpu_clk_freq = BSP_CPU_ClkFreq();                           /* Determine SysTick reference freq.                    */
    cnts = cpu_clk_freq / (CPU_INT32U)OSCfg_TickRate_Hz;        /* Determine nbr SysTick increments                     */
    OS_CPU_SysTickInit(cnts);                                   /* Init uC/OS periodic time src (SysTick).              */

    Mem_Init();                                                 /* Initialize Memory Management Module                  */

#if OS_CFG_STAT_TASK_EN > 0u
    OSStatTaskCPUUsageInit(&err);                               /* Compute CPU capacity with no task running            */
#endif

    CPU_IntDisMeasMaxCurReset();

//Program Start
	
}

static void AppTaskCreate(void)
{
	OS_ERR					err;
	OSTaskCreate((OS_TCB						*)&AppWiFiTCB,
							(CPU_CHAR					*)"AppTaskCreate WiFi Connect",
							(OS_TASK_PTR			 )AppWiFi,
							(void							*)0,
							(OS_PRIO					 )APP_TASK_WIFI,
							(CPU_STK					*)&AppTaskWiFi[0],
							(CPU_STK_SIZE			 )APP_TASK_WIFI_STK_SIZE/10,
							(CPU_STK_SIZE			 )APP_TASK_WIFI_STK_SIZE,
							(OS_MSG_QTY				 )1,
							(OS_TICK					 )0,
							(void							*)0,
							(OS_OPT						 )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
							(OS_ERR						*)&err);
}

void AppWiFi()
{
	OS_ERR err;
	if(Init_WiFi())
	{
		if(Init_Server_Con(33))
		{
			OSTimeDly(100, OS_OPT_TIME_DLY, &err);

		}
	}
	else
	{
		
	}
}










