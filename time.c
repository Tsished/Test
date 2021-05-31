#include "includes.h"

/*******************************************************************************************************************************

函数名称 ：void TIM_Initial(void)

函数说明 ：定时器配置

入口参数 ：//

返回值   ：//

*******************************************************************************************************************************/
void TIM_Initial(void)
{

    TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_DeInit(TIM2);
    TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
    TIM_TimeBaseStructure.TIM_Period = 2000 -1;
    TIM_TimeBaseStructure.TIM_Prescaler = 48 - 1;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
    TIM_SelectOutputTrigger(TIM2, TIM_TRGOSource_Update);
	TIM_Cmd(TIM2,ENABLE);

    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);  
}

void TIM2_IRQHandler(void)
{
  if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
  {	 
//	 if(!DS.Synchronize_Flag && DS.Arp_Status)     Arpeggiator_Deal(DS.ArpeggiatorMode);
//	 if(DS.GlideTime > 0 )                         GlideLegato_Mode(DS.GlideMode);
	 TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
  }
}

