/**
 * pico-key.cpp
 * main class and objects
 */

#include "../include/pico-key.h"

int pico_key::main() {
  stdio_init_all();
  tusb_init();

  std::cout << "\n1. Build Bad USB script\n";
  std::cout << "2. Test Bad USB script\n";
  std::cout << "3. Fake USB drive\n";
  std::cout << "4. STM32F1-Picopwner\n";
  std::cout << "5. Misc\n";
  std::cout << "6. Options\n";
  sleep_ms(1000);

  int choice;
  std::cout << "\n> ";
  std::cin >> choice;

  switch (choice) {
  case 1:
    buildScript();
    break;
  case 2:
    testScript();
    break;
  case 3:
    fakeUSB();
    break;
  case 4:
    stm();
    break;
  case 5:
    misc();
    break;
  case 6:
    options();
    break;
  default:
    std::cout << "\n" << choice << ": Invalid choice :/\n";
    break;
  }
}

void pico_key::boot() {}

void pico_key::info() {}
