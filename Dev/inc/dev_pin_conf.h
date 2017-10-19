#ifndef __DEV_PIN_CONF
#define __DEV_PIN_CONF

#define LED_ON	0
#define LED_OFF	1

/**********************************************************
										UART PIN SET
***********************************************************

UART2	RX	--	PA10
UART2 TX	--	PA9

***********************************************************/

#define UART2_TX_PIN	GPIO_Pin_9
#define UART2_TX_GPIO 	GPIOA
#define UART2_TX_CLK	RCC_AHB1Periph_GPIOA

#define UART2_RX_PIN	GPIO_Pin_10
#define UART2_RX_GPIO	GPIOA
#define UART2_RX_CLK	RCC_AHB1Periph_GPIOA


/**********************************************************
					BASE PIN SET
***********************************************************

LED	BASE	--	PC8
SYSTEM RST 	-- 	PA6

***********************************************************/

#define LED_BASE_PIN			GPIO_Pin_8
#define LED_BASE_GPIO 			GPIOC
#define LED_BASE_GPIO_CLK		RCC_AHB1Periph_GPIOC

#define SYSTEM_RST_PIN			GPIO_Pin_6
#define SYSTEM_RST_GPIO 		GPIOA
#define SYSTEM_RST_GPIO_CLK		RCC_AHB1Periph_GPIOA

/**********************************************************
					I2C PIN SET
***********************************************************						
SCL	--	PB6
SDA	--	PB7	
***********************************************************/

#define SCL_PIN GPIO_Pin_6	
#define SDA_PIN	GPIO_Pin_7

#define SCL_GPIO	GPIOB
#define SDA_GPIO	GPIOB
#define I2C_GPIO	GPIOB

#define SCL_GPIO_CLK	RCC_AHB1Periph_GPIOB
#define SDA_GPIO_CLK	RCC_AHB1Periph_GPIOB
#define I2C_GPIO_CLK	RCC_AHB1Periph_GPIOB

/**********************************************************
										LCD_ST7789 PIN SET
***********************************************************		
RESET	--	PE2
CS 		-- 	PD7
ADDR 	-- 	PD11
WR		-- 	PD5
RD		-- 	PD4
D0		--  PD14
D1		--	PD15
D2		--	PD0
D3		--	PD1
D4		--	PE7
D5		--	PE8
D6		--	PE9
D7		--	PE10
D8		--	PE11
D9		--	PE12
D10		--	PE13
D11		--	PE14
D12		--	PE15
D13		--	PD8
D14		--	PD9
D15		--	PD10
***********************************************************/

#define LCD_RST_PIN		GPIO_Pin_2
#define LCD_CS_PIN		GPIO_Pin_7
#define LCD_ADDR_PIN	GPIO_Pin_11
#define LCD_WR_PIN		GPIO_Pin_5
#define LCD_RD_PIN		GPIO_Pin_4
#define LCD_D0_PIN		GPIO_Pin_14
#define LCD_D1_PIN		GPIO_Pin_15
#define LCD_D2_PIN		GPIO_Pin_0
#define LCD_D3_PIN		GPIO_Pin_1
#define LCD_D4_PIN		GPIO_Pin_7
#define LCD_D5_PIN		GPIO_Pin_8
#define LCD_D6_PIN		GPIO_Pin_9
#define LCD_D7_PIN		GPIO_Pin_10
#define LCD_D8_PIN		GPIO_Pin_11
#define LCD_D9_PIN		GPIO_Pin_12
#define LCD_D10_PIN		GPIO_Pin_13
#define LCD_D11_PIN		GPIO_Pin_14
#define LCD_D12_PIN		GPIO_Pin_15
#define LCD_D13_PIN		GPIO_Pin_8
#define LCD_D14_PIN		GPIO_Pin_9
#define LCD_D15_PIN		GPIO_Pin_10

#define LCD_FSMCD_PIN (LCD_D2_PIN | LCD_D3_PIN | LCD_RD_PIN | LCD_WR_PIN \
											| LCD_CS_PIN | LCD_D13_PIN | LCD_D14_PIN | LCD_D15_PIN | LCD_ADDR_PIN | LCD_D0_PIN | LCD_D1_PIN)
											
#define LCD_FSMCE_PIN (LCD_D4_PIN | LCD_D5_PIN | LCD_D6_PIN | LCD_D7_PIN | LCD_D8_PIN \
											| LCD_D9_PIN | LCD_D10_PIN | LCD_D11_PIN | LCD_D12_PIN)
											
#define LCD_RST_GPIO			GPIOE
#define LCD_RST_GPIO_CLK	RCC_AHB1Periph_GPIOE

#define LCD_PWR_GPIO		GPIOE
#define LCD_BL_PWR_GPIO	GPIOF
#define LCD_RS_GPIO			GPIOE
#define LCD_RW_GPIO			GPIOE
#define LCD_EN_GPIO			GPIOC
#define LCD_DA_GPIO			GPIOF

#define LCD_PWR_GPIO_CLK		RCC_AHB1Periph_GPIOE
#define LCD_BL_PWR_GPIO_CLK	RCC_AHB1Periph_GPIOF
#define LCD_RS_GPIO_CLK			RCC_AHB1Periph_GPIOE
#define LCD_RW_GPIO_CLK			RCC_AHB1Periph_GPIOE
#define LCD_EN_GPIO_CLK			RCC_AHB1Periph_GPIOC
#define LCD_DA_GPIO_CLK			RCC_AHB1Periph_GPIOF 

/**********************************************************
										SPI PIN SET
***********************************************************						
MISO	--	PD15
MOSI	--	PG2
SCK		-- 	PG3
NSS		--	PG4
***********************************************************/

#define SPI1_SW_MISO_PIN	GPIO_Pin_15
#define SPI1_SW_MOSI_PIN	GPIO_Pin_2
#define SPI1_SW_SCK_PIN		GPIO_Pin_3
#define SPI1_SW_NSS_PIN		GPIO_Pin_4

#define SPI1_SW_GPIO_CLK_D	RCC_AHB1Periph_GPIOD
#define SPI1_SW_GPIO_CLK_G	RCC_AHB1Periph_GPIOG

#define SPI1_SW_GPIO_D	GPIOD
#define SPI1_SW_GPIO_G	GPIOG

/**********************************************************
										KEY PIN SET
***********************************************************						
KEY0	--	PE15			 	BYPASS		
KEY1	--	PE14			 	MUTE
KEY2	-- 	PE13			 	COUGH
KEY3	--	PE12				2~8S
KEY4	--	PE11				DUMP
KEY5	--	PE10				EXIT
KEY6	--	PE9					START
KEY7	--	PE8					DOWN
KEY8	--	PE7					ENTER	
KEY9	--	PG1					UP
***********************************************************/

#define KEY0_PIN				GPIO_Pin_15
#define KEY0_GPIO 			GPIOE
#define KEY0_GPIO_CLK		RCC_AHB1Periph_GPIOE

#define KEY1_PIN				GPIO_Pin_14
#define KEY1_GPIO 			GPIOE
#define KEY1_GPIO_CLK		RCC_AHB1Periph_GPIOE

#define KEY2_PIN				GPIO_Pin_13
#define KEY2_GPIO 			GPIOE
#define KEY2_GPIO_CLK		RCC_AHB1Periph_GPIOE

#define KEY3_PIN				GPIO_Pin_12
#define KEY3_GPIO 			GPIOE
#define KEY3_GPIO_CLK		RCC_AHB1Periph_GPIOE

#define KEY4_PIN				GPIO_Pin_11
#define KEY4_GPIO 			GPIOE
#define KEY4_GPIO_CLK		RCC_AHB1Periph_GPIOE

#define KEY5_PIN				GPIO_Pin_10
#define KEY5_GPIO 			GPIOE
#define KEY5_GPIO_CLK		RCC_AHB1Periph_GPIOE

#define KEY6_PIN				GPIO_Pin_9
#define KEY6_GPIO 			GPIOE
#define KEY6_GPIO_CLK		RCC_AHB1Periph_GPIOE

#define KEY7_PIN				GPIO_Pin_8
#define KEY7_GPIO 			GPIOE
#define KEY7_GPIO_CLK		RCC_AHB1Periph_GPIOE

#define KEY8_PIN				GPIO_Pin_7
#define KEY8_GPIO 			GPIOE
#define KEY8_GPIO_CLK		RCC_AHB1Periph_GPIOE

#define KEY9_PIN				GPIO_Pin_1
#define KEY9_GPIO 			GPIOG
#define KEY9_GPIO_CLK		RCC_AHB1Periph_GPIOG

#define KEY_GPIOE_PIN		KEY0_PIN | KEY1_PIN | KEY4_PIN | KEY5_PIN | KEY6_PIN | KEY7_PIN | KEY8_PIN
#define KEY_GPIOE				GPIOE
#define KEY_GPIOE_CLK		RCC_AHB1Periph_GPIOE

#define KEY_GPIOG_PIN		KEY9_PIN
#define KEY_GPIOG				GPIOG
#define KEY_GPIOG_CLK		RCC_AHB1Periph_GPIOG

#define KEY_LED_GPIO_PIN	KEY2_PIN | KEY3_PIN
#define KEY_LED_GPIO			GPIOE
#define KEY_LED_GPIO_CLK	RCC_AHB1Periph_GPIOE

/**********************************************************
										SDCARD PIN SET
***********************************************************						
SDCARD_MOSI	--	PA7
SDCARD_MISO	-- 	PA6
SDCARD_SCK	--	PA5
SDCARD_CS		--	PA4
***********************************************************/

#define SDCARD_SPI_CLK		RCC_APB2Periph_SPI1

#define SDCARD_MOSI_PIN		GPIO_Pin_7
#define SDCARD_MISO_PIN		GPIO_Pin_6
#define SDCARD_SCK_PIN		GPIO_Pin_5
#define SDCARD_CS_PIN			GPIO_Pin_4

#define SDCARD_GPIO_CLK		RCC_APB2Periph_GPIOA

#define SDCARD_GPIO				GPIOA



#endif

