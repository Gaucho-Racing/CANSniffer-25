#include "Arduino.h"
#include "MLX90640_API.h"
#include "MLX90640_I2C_Driver.h"
#include "Wire.h"

void MLX90640_I2CInit()
{
  
}
int MLX90640_I2CGeneralReset(void)
{

}
int MLX90640_I2CRead(uint8_t slaveAddr,uint16_t startAddress, uint16_t nMemAddressRead, uint16_t *data)
{
    Wire.memRead(slaveAddr, startAddress, nMemAddressRead, data);

}
int MLX90640_I2CWrite(uint8_t slaveAddr,uint16_t writeAddress, uint16_t data);
void MLX90640_I2CFreqSet(int freq);

