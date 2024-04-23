/**
 * usb.c
 * fake usb related things/disguising
*/

#include "usb.h"

// fake usb id's

/**
 * see https://github.com/samyk/poisontap/blob/master/pi_startup.sh for fake id's
*/

tusb_desc_device_t deviceDescriptor = {
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = 0x0200, // USB 2.0
    .bDeviceClass       = USB_CLASS_PER_INTERFACE,
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

// faking usb drive blinking
void fakeUSB(void) {
    bool led = false;

    printf("\n1. Start LED blinking\n");
    printf("2. Stop LED blinking\n");
    printf("\n> ");

    int choiceA;
    scanf("%d", &choiceA);
    switch (choiceA) {
        case 1:
            if (led) {
                printf("Already running! :/\n");
            } else {
                led = true;
                while (led) {
                    gpio_put(LED_PIN, 1); // led on
                    sleep_ms(500);
                    gpio_put(LED_PIN, 0); // led off
                    sleep_ms(500);

                    if (scanf("%d", &choiceA) == 1 && choiceA == 2) {
                        led = false;
                    }
                }
            }
            break;

        case 2:
            led = false;
            break;

        default:
            printf("%d: Invalid choice\n", choiceA);
    }
}

// spoof device id's based on deviceDescriptor
void spoofID(void) {
    // init regardless
    tusb_init();

    tud_descriptor_device_register(&deviceDescriptor);
}