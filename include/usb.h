/**
 * usb.h
 * usb spoofing headers
 */

#ifndef USB_H
#define USB_H

#include "hardware/gpio.h"
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "tusb.h"
#include "tusb_option.h"

class usb {
public:
  void fake_usb();
  void spoof_id();

private:
  bool led;
};

#endif // USB_H