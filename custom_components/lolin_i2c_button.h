#ifndef __I2C_BUTTON_H
#define __I2C_BUTTON_H

#include <esphome.h>
#include <Wire.h>
#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace lolin_i2c_button {
	
enum I2C_OLED_BUTTON_CMD
{
  GET_SLAVE_STATUS = 0x01,
  RESET_SLAVE,
  CHANGE_I2C_ADDRESS,
  GET_KEY_VALUE,
  CHANGE_KEY_A_LONG_PRESS_TIME,
  CHANGE_KEY_B_LONG_PRESS_TIME,
  CHANGE_KEY_A_DOUBLE_PRESS_INTERVAL,
  CHANGE_KEY_B_DOUBLE_PRESS_INTERVAL
};

enum KEY_VALUE
{
    KEY_VALUE_NONE = 0x00,
    KEY_VALUE_SHORT_PRESS,
    KEY_VALUE_LONG_PRESS,
    KEY_VALUE_DOUBLE_PRESS,
    KEY_VALUE_HOLD
};

	
};
class I2CButton : public PollingComponent, public BinarySensor {
 public:
  I2CButton(unsigned char address = DEFAULT_I2C_BUTTON_ADDRESS);
  void setup() override;
  void update() override;
  unsigned char get(void);
	unsigned char reset(void);
	unsigned char changeAddress(unsigned char address);
  unsigned char getInfo(void);

	unsigned char BUTTON_A;
	unsigned char BUTTON_B;
  unsigned char VERSION=0;
  unsigned char PRODUCT_ID=0;

  

 protected:
  uint8_t address_;
  uint8_t last_state_;
  bool changed_;

  unsigned char sendData(unsigned char *data, unsigned char len);
  void readButtonState();
 private:
	unsigned char _address;
	unsigned char send_data[2] = {0};
	unsigned char get_data[2]={0};
	unsigned char sendData(unsigned char *data, unsigned char len);

};

#endif
