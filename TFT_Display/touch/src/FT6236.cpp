#include "FT6236.h"

static uint8_t FT6236_ReadReg(FT6236_t *touch, uint8_t reg, uint8_t *data, uint16_t len)
{
    if (HAL_I2C_Master_Transmit(touch->i2c, (FT6236_I2C_ADDR << 1), &reg, 1, HAL_MAX_DELAY) != HAL_OK) {
        return 0;
    }
    
    if (HAL_I2C_Master_Receive(touch->i2c, (FT6236_I2C_ADDR << 1), data, len, HAL_MAX_DELAY) != HAL_OK) {
        return 0;
    }
    
    return 1;
}

static uint8_t FT6236_WriteReg(FT6236_t *touch, uint8_t reg, uint8_t data)
{
    uint8_t buf[2] = {reg, data};
    if (HAL_I2C_Master_Transmit(touch->i2c, (FT6236_I2C_ADDR << 1), buf, 2, HAL_MAX_DELAY) != HAL_OK) {
        return 0;
    }
    return 1;
}

uint8_t FT6236_Init(FT6236_t *touch, I2C_HandleTypeDef *i2c)
{
    uint8_t chipid;
    
    touch->i2c = i2c;
    touch->touched = 0;
    touch->points = 0;
    touch->x = 0;
    touch->y = 0;
    
    /* Read chip ID to verify */
    if (!FT6236_ReadReg(touch, FT6236_REG_CHIPID, &chipid, 1)) {
        return 0;
    }
    
    if (chipid != FT6236_CHIPID) {
        return 0;
    }
    
    /* Set device mode to normal */
    FT6236_WriteReg(touch, FT6236_REG_DEV_MODE, 0x00);
    
    return 1;
}

void FT6236_ReadTouchData(FT6236_t *touch)
{
    uint8_t data[6];
    uint8_t td_status;
    
    /* Read touch status */
    if (!FT6236_ReadReg(touch, FT6236_REG_TD_STATUS, &td_status, 1)) {
        touch->touched = 0;
        return;
    }
    
    touch->points = td_status & 0x0F;
    
    if (touch->points == 0) {
        touch->touched = 0;
        return;
    }
    
    /* Read first touch point data */
    if (!FT6236_ReadReg(touch, FT6236_REG_P1_XH, data, 6)) {
        touch->touched = 0;
        return;
    }
    
    /* Extract X and Y coordinates */
    touch->x = ((data[0] & 0x0F) << 8) | data[1];
    touch->y = ((data[2] & 0x0F) << 8) | data[3];
    touch->touched = 1;
}

uint8_t FT6236_IsTouched(FT6236_t *touch)
{
    return touch->touched;
}

uint16_t FT6236_GetX(FT6236_t *touch)
{
    return touch->x;
}

uint16_t FT6236_GetY(FT6236_t *touch)
{
    return touch->y;
}
