// Copyright (c) 2021 Kandakov Danil (p2034 or the_lll_end)
// https://github.com/p2034



#include <fstream>
#include <stdexcept>

#include "core/oefile.h"



// key must have 256 bits (32 bytes/symbols) (size in bytes), or 128/192 bits
void oefile::save(const uint8_t* key, uint16_t keySize, const uint8_t* data, uint32_t dataSize,
                  std::string fileName) {
  std::ofstream file;

  file.open(fileName); {
    if (!file.is_open())
      throw std::invalid_argument("Can not open file '" + fileName + "'");

    if (this->odata_.save(key, keySize, data, dataSize, &file) == -1)
      throw std::invalid_argument("Undefined error: Something changed in crypto");

  } file.close();
}