#ifndef LIBBSP_AARCH64_RASPBERRYPI_I2C_H
#define LIBBSP_AARCH64_RASPBERRYPI_I2C_H

#include <bsp/utility.h>
#include <dev/i2c/i2c.h>
#include <bsp/rpi-gpio.h>
#include <bsp/raspberrypi.h>

typedef enum {
  raspberrypi_bscm0,
  raspberrypi_bscm1,
  raspberrypi_bscm3,
  raspberrypi_bscm4,
  raspberrypi_bscm5,
  raspberrypi_bscm6
} raspberrypi_bsc_masters;

#define BCM2711_I2C_CONTROL       0x0
#define BCM2711_I2C_STATUS        0x4
#define BCM2711_I2C_DLEN          0x8
#define BCM2711_I2C_SLAVE_ADDRESS 0xc
#define BCM2711_I2C_FIFO          0x10
#define BCM2711_I2C_DIV           0x14
#define BCM2711_DELAY             0x18

#define BSC_CORE_CLK_HZ           150000000

#define C_REG(bus)                BCM2835_REG((bus)->base_address + BCM2711_I2C_CONTROL)
#define C_I2CEN                   (1 << 15)
#define C_INTR                    (1 << 10)
#define C_INTT                    (1 << 9)
#define C_INTD                    (1 << 8)
#define C_ST                      (1 << 7)
#define C_CLEAR                   (1 << 5)
#define C_READ                    (1 << 0)

#define S_REG(bus)                BCM2835_REG((bus)->base_address + BCM2711_I2C_STATUS)
#define S_CLKT                    (1 << 9)
#define S_ERR                     (1 << 8)
#define S_RXF                     (1 << 7)
#define S_TXE                     (1 << 6)
#define S_RXD                     (1 << 5)
#define S_TXD                     (1 << 4)
#define S_RXR                     (1 << 3)
#define S_TXW                     (1 << 2)
#define S_DONE                    (1 << 1)
#define S_TA                      (1 << 0)

rtems_status_code rpi_i2c_init(raspberrypi_bsc_masters master, uint32_t bus_clock);

#endif /* LIBBSP_AARCH64_RASPBERRYPI_I2C_H */