#include "computer/computer.h"
#include <cstring>
#include <iostream>

Computer::HardDrive::HardDrive(unsigned int megabytes) : size{megabytes} {}

Computer::HardDrive::HardDrive() : size(0) {}

void Computer::HardDrive::setSize(const unsigned int size) {
  this->size = size;
}

Computer::Computer(unsigned int sizeDrive, const char *brand, double price)
    : drive{sizeDrive}, price{price} {
  this->brand = new char[strlen(brand) + 1];
  strcpy(this->brand, brand);
}

Computer::~Computer() { delete[] brand; }

void Computer::data() const {
  std::cout << "drive: " << drive.getSize() << "\tbrand: " << brand
            << "\tprice: " << std::endl;
}

SIZE::SIZE(unsigned int height, unsigned int width)
    : height{height}, width{width} {}

ComputerWithMonitor::ComputerWithMonitor(unsigned int sizeDrive,
                                         const char *brand, double price,
                                         unsigned int height,
                                         unsigned int width)
    : Computer{sizeDrive, brand, price}, monitorSize{height, width} {}

void ComputerWithMonitor::data() const {
  Computer::data();
  std::cout << "monitor: " << monitorSize.width << "x" << monitorSize.height
            << std::endl;
}