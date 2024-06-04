#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "ov2640.h"
#include "timer.h"

//ALIENTEK Mini STM32开发板范例代码11
//TFTLCD显示实验   
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司 
 int main(void)
 { 
     NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
     LED_Init();
     delay_init();
    uart_init(115200);
    TIM3_Int_Init(5000-1,7200-1);
    OV2640_Init();
     
    
     printf("PID:%x\r\n",OV2640_GetPID());
     printf("MID:%x\r\n",OV2640_GetMID());
     
     
    while (1)
    {
        OV2640_TestCaptureUART();
        
        
    }
}
