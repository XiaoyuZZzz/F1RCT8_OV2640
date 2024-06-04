#include "stm32f10x.h"                  // Device header
#include "ov2640.h"
#include "delay.h"
#include "usart.h"
#include "led.h"

const uint8_t atk_mc2640_init_uxga_cfg[][2] = {
    {0xFF, 0x00},
    {0x2C, 0xFF},
    {0x2E, 0xDF},
    {0xFF, 0x01},
    {0x3C, 0x32},
    {0x11, 0x00},
    {0x09, 0x02},
    {0x04, 0xA8},
    {0x13, 0xE5},
    {0x14, 0x48},
    {0x2C, 0x0C},
    {0x33, 0x78},
    {0x3A, 0x33},
    {0x3B, 0xFB},
    {0x3E, 0x00},
    {0x43, 0x11},
    {0x16, 0x10},
    {0x39, 0x92},
    {0x35, 0xDA},
    {0x22, 0x1A},
    {0x37, 0xC3},
    {0x23, 0x00},
    {0x34, 0xC0},
    {0x36, 0x1A},
    {0x06, 0x88},
    {0x07, 0xC0},
    {0x0D, 0x87},
    {0x0E, 0x41},
    {0x4C, 0x00},
    {0x48, 0x00},
    {0x5B, 0x00},
    {0x42, 0x03},
    {0x4A, 0x81},
    {0x21, 0x99},
    {0x24, 0x40},
    {0x25, 0x38},
    {0x26, 0x82},
    {0x5C, 0x00},
    {0x63, 0x00},
    {0x46, 0x00},
    {0x0C, 0x3C},
    {0x61, 0x70},
    {0x62, 0x80},
    {0x7C, 0x05},
    {0x20, 0x80},
    {0x28, 0x30},
    {0x6C, 0x00},
    {0x6D, 0x80},
    {0x6E, 0x00},
    {0x70, 0x02},
    {0x71, 0x94},
    {0x73, 0xC1},
    {0x3D, 0x34},
    {0x5A, 0x57},
    {0x12, 0x00},
    {0x17, 0x11},
    {0x18, 0x75},
    {0x19, 0x01},
    {0x1A, 0x97},
    {0x32, 0x36},
    {0x03, 0x0F},
    {0x37, 0x40},
    {0x4F, 0xCA},
    {0x50, 0xA8},
    {0x5A, 0x23},
    {0x6D, 0x00},
    {0x6D, 0x38},
    {0xFF, 0x00},
    {0xE5, 0x7F},
    {0xF9, 0xC0},
    {0x41, 0x24},
    {0xE0, 0x14},
    {0x76, 0xFF},
    {0x33, 0xA0},
    {0x42, 0x20},
    {0x43, 0x18},
    {0x4C, 0x00},
    {0x87, 0xD5},
    {0x88, 0x3F},
    {0xD7, 0x03},
    {0xD9, 0x10},
    {0xD3, 0x82},
    {0xC8, 0x08},
    {0xC9, 0x80},
    {0x7C, 0x00},
    {0x7D, 0x00},
    {0x7C, 0x03},
    {0x7D, 0x48},
    {0x7D, 0x48},
    {0x7C, 0x08},
    {0x7D, 0x20},
    {0x7D, 0x10},
    {0x7D, 0x0E},
    {0x90, 0x00},
    {0x91, 0x0E},
    {0x91, 0x1A},
    {0x91, 0x31},
    {0x91, 0x5A},
    {0x91, 0x69},
    {0x91, 0x75},
    {0x91, 0x7E},
    {0x91, 0x88},
    {0x91, 0x8F},
    {0x91, 0x96},
    {0x91, 0xA3},
    {0x91, 0xAF},
    {0x91, 0xC4},
    {0x91, 0xD7},
    {0x91, 0xE8},
    {0x91, 0x20},
    {0x92, 0x00},
    {0x93, 0x06},
    {0x93, 0xE3},
    {0x93, 0x05},
    {0x93, 0x05},
    {0x93, 0x00},
    {0x93, 0x04},
    {0x93, 0x00},
    {0x93, 0x00},
    {0x93, 0x00},
    {0x93, 0x00},
    {0x93, 0x00},
    {0x93, 0x00},
    {0x93, 0x00},
    {0x96, 0x00},
    {0x97, 0x08},
    {0x97, 0x19},
    {0x97, 0x02},
    {0x97, 0x0C},
    {0x97, 0x24},
    {0x97, 0x30},
    {0x97, 0x28},
    {0x97, 0x26},
    {0x97, 0x02},
    {0x97, 0x98},
    {0x97, 0x80},
    {0x97, 0x00},
    {0x97, 0x00},
    {0xC3, 0xEF},
    {0xA4, 0x00},
    {0xA8, 0x00},
    {0xC5, 0x11},
    {0xC6, 0x51},
    {0xBF, 0x80},
    {0xC7, 0x10},
    {0xB6, 0x66},
    {0xB8, 0xA5},
    {0xB7, 0x64},
    {0xB9, 0x7C},
    {0xB3, 0xAF},
    {0xB4, 0x97},
    {0xB5, 0xFF},
    {0xB0, 0xC5},
    {0xB1, 0x94},
    {0xB2, 0x0F},
    {0xC4, 0x5C},
    {0xC0, 0xC8},
    {0xC1, 0x96},
    {0x8C, 0x00},
    {0x86, 0x3D},
    {0x50, 0x00},
    {0x51, 0x90},
    {0x52, 0x2C},
    {0x53, 0x00},
    {0x54, 0x00},
    {0x55, 0x88},
    {0x5A, 0x90},
    {0x5B, 0x2C},
    {0x5C, 0x05},
    {0xD3, 0x02},
    {0xC3, 0xED},
    {0x7F, 0x00},
    {0xDA, 0x09},
    {0xE5, 0x1F},
    {0xE1, 0x67},
    {0xE0, 0x00},
    {0xDD, 0x7F},
    {0x05, 0x00},
};

const uint8_t atk_mc2640_set_yuv422_cfg[][2] = {
    {0xFF, 0x00},
    {0xDA, 0x10},
    {0xD7, 0x03},
    {0xDF, 0x00},
    {0x33, 0x80},
    {0x3C, 0x40},
    {0xE1, 0x77},
    {0x00, 0x00},
};

const uint8_t atk_mc2640_set_jpeg_cfg[][2] = {
    {0xFF, 0x01},
    {0xE0, 0x14},
    {0xE1, 0x77},
    {0xE5, 0x1F},
    {0xD7, 0x03},
    {0xDA, 0x10},
    {0xE0, 0x00},
};


void OV2640_HW_Reset(void)
{
    // Reset Camera
    GPIO_ResetBits(PCLK_PWDN_HREF_RESET_VSYNC_GPIO, RESET_PIN);
    delay_ms(10);
    GPIO_SetBits(PCLK_PWDN_HREF_RESET_VSYNC_GPIO, RESET_PIN);
    delay_ms(10);
}

void OV2640_SetPowerDownMode(BitAction BitVal)
{
    // Set Device into Normal Mode
    if (BitVal)
    {
        GPIO_SetBits(PCLK_PWDN_HREF_RESET_VSYNC_GPIO, PWDN_PIN);
    }
    else
    {
        GPIO_ResetBits(PCLK_PWDN_HREF_RESET_VSYNC_GPIO, PWDN_PIN);
    }
}

uint16_t OV2640_GetPID(void)
{
    uint16_t PID;
    SCCB_Write(0xFF, 0x01);
    PID = SCCB_Read(OV2640_SENSOR_PIDH);
    PID <<= 8;
    PID |= SCCB_Read(OV2640_SENSOR_PIDL);
    return PID;
}

uint16_t OV2640_GetMID(void)
{
    uint16_t MID;
    SCCB_Write(0xFF, 0x01);
    MID= SCCB_Read(OV2640_SENSOR_MIDH);
    MID <<= 8;
    MID |= SCCB_Read(OV2640_SENSOR_MIDL);
    return MID;
}

void OV2640_InitConfig(void)
{
    
    uint16_t i ;
    uint16_t cfg_len = sizeof(atk_mc2640_init_uxga_cfg) / sizeof(atk_mc2640_init_uxga_cfg[0]);
   
    for (i = 0; i < cfg_len; i++)
    {
        SCCB_Write(atk_mc2640_init_uxga_cfg[i][0], atk_mc2640_init_uxga_cfg[i][1]);
    }
   
}

//引脚初始化
void OV2640_IOInit(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//使能引脚复用
    RCC_APB2PeriphClockCmd(RCC_APB_OV2640, ENABLE);
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
    
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    // RESET, output
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = RESET_PIN;
    GPIO_Init(PCLK_PWDN_HREF_RESET_VSYNC_GPIO, &GPIO_InitStructure);
    // HREF, VSYNC, input
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = HREF_PIN | VSYNC_PIN;
    GPIO_Init(PCLK_PWDN_HREF_RESET_VSYNC_GPIO, &GPIO_InitStructure);
    // PCLK, input
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = PCLK_PIN;
    GPIO_Init(PCLK_PWDN_HREF_RESET_VSYNC_GPIO, &GPIO_InitStructure);
    // PWDN, output
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = PWDN_PIN;
    GPIO_Init(PCLK_PWDN_HREF_RESET_VSYNC_GPIO, &GPIO_InitStructure);
    // DATA, input
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = DATA0_PIN | DATA1_PIN | DATA2_PIN | DATA3_PIN | DATA4_PIN | DATA5_PIN | DATA6_PIN | DATA7_PIN;
    GPIO_Init(DATA_GPIO, &GPIO_InitStructure);
}

void OV2640_SetOutputJPEG(void)
{
    uint16_t cfg_index;
    uint16_t cfg_len = sizeof(atk_mc2640_set_yuv422_cfg) / sizeof(atk_mc2640_set_yuv422_cfg[0]);
    for (cfg_index = 0; cfg_index < cfg_len; cfg_index++)
    {
        SCCB_Write(atk_mc2640_set_yuv422_cfg[cfg_index][0], atk_mc2640_set_yuv422_cfg[cfg_index][1]);
    }
    cfg_len = sizeof(atk_mc2640_set_jpeg_cfg) / sizeof(atk_mc2640_set_jpeg_cfg[0]);
    for (cfg_index= 0; cfg_index < cfg_len; cfg_index++)
    {
        SCCB_Write(atk_mc2640_set_jpeg_cfg[cfg_index][0], atk_mc2640_set_jpeg_cfg[cfg_index][1]);
    }
}


void OV2640_SetOutputSize(uint16_t width, uint16_t height)
{
    uint16_t output_width;
    uint16_t output_height;

    output_width = width >> 2;
    output_height = height >> 2;

    SCCB_Write(0xFF, 0x00);
    SCCB_Write(OV2640_DSP_RESET, 0x04);
    SCCB_Write(OV2640_DSP_ZMOW, (uint8_t)(output_width & 0x00FF));
    SCCB_Write(OV2640_DSP_ZMOH, (uint8_t)(output_height & 0x00FF));
    SCCB_Write(OV2640_DSP_ZMHH, ((uint8_t)(output_width >> 8) & 0x03) | ((uint8_t)(output_height >> 6) & 0x04));
    SCCB_Write(OV2640_DSP_RESET, 0x00);
}

void OV2640_Init(void)
{
    OV2640_IOInit();
    
    OV2640_HW_Reset();
    
    
    SW_SCCB_Init();
   
    OV2640_InitConfig();

    SCCB_Write(0XFF, 0x00);
    SCCB_Write(0XD3, 16); // DVP PCLK division
    SCCB_Write(0XFF, 0x01);
    SCCB_Write(0X11, 6); // CLK division

    OV2640_SetOutputJPEG();
    OV2640_SetOutputSize(320, 240);
    
}

void OV2640_TestCaptureUART(void)
{
    uint8_t jpeg_buffer[1024] = {0};
    
    uint32_t buffer_inedex = 0;
    uint32_t jpeg_valid_start = 0;
    while(OV2640_VSYNC == 0); // wait for new frame VSYNC rising edge
    while (OV2640_VSYNC == 1) // wait for new frame VSYNC falling edge
    {
        while (OV2640_HREF == 1) // when HREF high, read row
        {
            while (OV2640_PCLK == 0); // wait for PCLK rising edge and read data
            jpeg_buffer[buffer_inedex] = OV2640_DATA;
            buffer_inedex++;
            while (OV2640_PCLK == 1); //  wait for PCLK falling edge, update data
        }
    }
    
    for (jpeg_valid_start = 0; jpeg_valid_start < buffer_inedex; jpeg_valid_start++)
    {
        if (jpeg_buffer[jpeg_valid_start] == 0xFF && jpeg_buffer[jpeg_valid_start + 1] == 0xD8)
        {
            uint32_t jpeg_valid_end = 0;
            for (jpeg_valid_end = jpeg_valid_start; jpeg_valid_end < buffer_inedex; jpeg_valid_end++)
            {
                if (jpeg_buffer[jpeg_valid_end] == 0xD9 && jpeg_buffer[jpeg_valid_end - 1] == 0xFF)
                {
                    USART_Transmit(jpeg_buffer + jpeg_valid_start, jpeg_valid_end - jpeg_valid_start + 1);
                    break;
                }
            }
        }
    }
}