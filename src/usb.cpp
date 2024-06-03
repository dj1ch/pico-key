/**
 * usb.cpp
 * handles usb spoofing
*/

#include "../include/usb.h"

/**
 * see https://github.com/samyk/poisontap/blob/master/pi_startup.sh for fake id's
*/

tusb_desc_device_t deviceDescriptor = {
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = 0x0200, // USB 2.0

    .bDeviceClass       = 0,
    .bDeviceSubClass    = 0,
    .bDeviceProtocol    = 0,
    .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,

    .idVendor           = 0x1d6b, // linux foundation
    .idProduct          = 0x0104, // multi-function composite gadget
    .bcdDevice          = 0x0100,
    .iManufacturer      = 0x01,
    .iProduct           = 0x02, 
    .iSerialNumber      = 0x03,

    .bNumConfigurations = 1
};

void usb::fake_usb() {
    // start false
    led = false;

    std::cout << "\n1. Start LED blinking\n";
    std::cout << "2. Stop LED blinking\n";
    std::cout << "\n> ";

    int choiceA;
    std::cin >> choiceA;

    switch (choiceA) {
        case 1:
            if (led) {
                std::cout << "Already running! :/\n";
            } else {
                led = true;
                gpio_init(LED_PIN);
                gpio_set_dir(LED_PIN, GPIO_OUT);

                while (led) {
                    gpio_put(LED_PIN, 1); // led on
                    sleep_ms(500);
                    gpio_put(LED_PIN, 0); // led off
                    sleep_ms(500);

                    if (std::cin >> choiceA && choiceA == 2) {
                        led = false;
                    }
                }
            }
            break;

        case 2:
            led = false;
            gpio_put(LED_PIN, 0);
            break;

        default:
            std::cout << choiceA << ": Invalid choice\n";
    }
}

void usb::spoof_id() {
    // init regardless
    tusb_init();

    tud_descriptor_device_register(&deviceDescriptor);
}