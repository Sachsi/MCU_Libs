#ifndef FT6236_H
#define FT6236_H

#include "stm32g0xx_hal.h"
#include <stdint.h>

/* FT6236 I2C Address */
#define FT6236_I2C_ADDR         0x38

/* FT6236 Registers */
#define FT6236_REG_DEV_MODE     0x00
#define FT6236_REG_GEST_ID      0x01
#define FT6236_REG_TD_STATUS    0x02
#define FT6236_REG_P1_XH        0x03
#define FT6236_REG_P1_XL        0x04
#define FT6236_REG_P1_YH        0x05
#define FT6236_REG_P1_YL        0x06
#define FT6236_REG_P1_WEIGHT    0x07
#define FT6236_REG_P1_MISC      0x08
#define FT6236_REG_P2_XH        0x09
#define FT6236_REG_P2_XL        0x0A
#define FT6236_REG_P2_YH        0x0B
#define FT6236_REG_P2_YL        0x0C
#define FT6236_REG_CHIPID       0xA3
#define FT6236_REG_FIRMID       0xA6
#define FT6236_REG_FOCALTECH_ID 0xA8

#define FT6236_CHIPID           0x36

typedef struct {
    I2C_HandleTypeDef *i2c;
    GPIO_TypeDef *irq_port;
    uint16_t irq_pin;
    
    uint16_t x;
    uint16_t y;
    uint8_t touched;
    uint8_t points;
} FT6236_t;

/* Function declarations */
uint8_t FT6236_Init(FT6236_t *touch, I2C_HandleTypeDef *i2c);
void FT6236_ReadTouchData(FT6236_t *touch);
uint8_t FT6236_IsTouched(FT6236_t *touch);
uint16_t FT6236_GetX(FT6236_t *touch);
uint16_t FT6236_GetY(FT6236_t *touch);

#endif /* FT6236_H */
