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

static  OS_TCB   AppTaskStartTCB;
static  OS_TCB	 AppTaskTimeClock;


/*
*********************************************************************************************************
*                                                STACKS
*********************************************************************************************************
*/

static  CPU_STK  AppTaskStartStk[APP_TASK_START_STK_SIZE];
static  CPU_STK	 APP_TASK_CLOCK_STK[APP_TASK_CLOCK];



/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/


static  void  AppTaskStart  	(void *p_arg);

static	void  AppClock				(void * p_arg);

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
    OS_ERR  err;

    OSInit(&err);                                               /* Init uC/OS-III.                                      */

    OSTaskCreate((OS_TCB     *)&AppTaskStartTCB,                /* Create the start task                                */
                 (CPU_CHAR   *)"App Task Start",
                 (OS_TASK_PTR ) AppTaskStart,
                 (void       *) 0,
                 (OS_PRIO     ) APP_TASK_START_PRIO,
                 (CPU_STK    *)&AppTaskStartStk[0],
                 (CPU_STK_SIZE) APP_TASK_CLOCK_STK_SIZE / 10,
                 (CPU_STK_SIZE) APP_TASK_CLOCK_STK_SIZE,
                 (OS_MSG_QTY  ) 5u,
                 (OS_TICK     ) 0u,
                 (void       *) 0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);

    OSStart(&err);                                              /* Start multitasking (i.e. give control to uC/OS-III). */
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
			
	OSTaskCreate((OS_TCB			  *)&AppTaskTimeClock,
							 (CPU_CHAR			*)"CLOCK",
							 (OS_TASK_PTR		 ) AppClock,
							 (void					*)1,
							 (OS_PRIO				 )APP_TASK_CLOCK,
							 (CPU_STK    		*)&APP_TASK_CLOCK_STK[0],
							 (CPU_STK_SIZE	 ) APP_TASK_CLOCK_STK_SIZE / 10,
							 (CPU_STK_SIZE	 ) APP_TASK_CLOCK_STK_SIZE,
							 (OS_MSG_QTY		 ) 10,
							 (OS_TICK				 ) 10,
							 (void					*) 0,
							 (OS_OPT				 ) (OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
							 (OS_ERR				*)&err);
							 
								
								
	OSTaskDel( & AppTaskStartTCB, & err);

	
}

void TmrCallback(OS_TMR *p_tmr, void *p_arg)
{
	CPU_INT32U				cpu_clk_freq;
	CPU_SR_ALLOC();
	
	
}

static void AppTaskTmr( void * p_arg)
{
	OS_ERR									err;
	OS_TMR									my_tmr;
	
	(void)p_arg;
	
	OSTmrCreate((OS_TMR				*)&my_tmr,
							(CPU_CHAR			*)"MySoftTimer",
							(OS_TICK			 )1,
							(OS_TICK			 )1,
							(OS_OPT				 )OS_OPT_TMR_PERIODIC,
							(OS_TMR_CALLBACK_PTR)TmrCallback,
							(void					*)"Time Over!",
							(OS_ERR				*)err);
							
	OSTmrStart	((OS_TMR		*)&my_tmr,
							 (OS_ERR		*)err);
							
	//ts_start = OS_TS_GET();
	
}

static void AppClock(void * p_arg)
{
	
}










