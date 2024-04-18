#include "io/binary_reader.h"

BinaryReader::BinaryReader(const std::string &filename) : file_(filename, std::ios::binary) {}

BinaryReader::~BinaryReader() {
    file_.close();
}