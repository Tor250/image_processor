#pragma once

#include "io/image_format.h"
#include "io/binary_reader.h"
#include "io/binary_writer.h"

class BMP : ImageFormat {
public:
    Image Load(const std::string &filename) override;
    void Save(const Image &image, const std::string &filename) override;

private:
    struct Header {
        char signature[2] = {'B', 'M'};
        uint32_t file_size = 0;
        uint16_t reserved[2] = {0, 0};
        uint32_t offset = 54;
    };

    struct InfoHeader {
        uint32_t header_size = 40;

        struct Size {
            int32_t width = 0;
            int32_t height = 0;
        } size = {};

        uint16_t planes = 1;
        uint16_t bits_per_pixel = 24;
        uint32_t compression = 0;
        uint32_t image_size = 0;

        struct DPI {
            int32_t hor = 300;
            int32_t ver = 300;
        } dpi = {};

        uint32_t total_colors = 0;
        uint32_t important = 0;
    };

private:
    static auto Tie(Header &header);
    static auto Tie(InfoHeader &info_header);
    static auto ReadRow(Image &image, BinaryReader &input, std::size_t row);
    static auto WriteRow(const Image &image, BinaryWriter &output, std::size_t row);
    static size_t GetRowSize(std::size_t width, std::size_t bits_per_pixel);
    static void TryValidateHeader(const Header& header);
    static void TryValidateInfoHeader(const InfoHeader& header);
};