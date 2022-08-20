
#include "catch.hpp"
#include "mylib.cpp"
#include "imread.h"

#include <vector>

TEST_CASE("test1")
{
    std::vector<uint8_t> inframe = imread<uint8_t>("data/input_random_image.bin", {1, 640, 480});
    std::vector<uint8_t> out1(640*480);
    std::vector<uint8_t> out2(640*480);

    mylib_image input;
    input.w = 640;
    input.h = 480;
    input.buffer = reinterpret_cast<uint8_t*>(inframe.data());

    mylib_output_frame output;
    output.output1.w = 640;
    output.output1.h = 480;
    output.output1.buffer = reinterpret_cast<uint8_t*>(out1.data());
    output.output2.w = 640;
    output.output2.h = 480;
    output.output2.buffer = reinterpret_cast<uint8_t*>(out2.data());

    mylib_process(&input, &output);

    for(auto i=0u; i<out1.size(); ++i)
    {
        REQUIRE(out1[i] < 64);
        REQUIRE(out2[i] < 8);
    }

}


TEST_CASE("test2")
{
    std::vector<uint8_t> inframe = imread<uint8_t>("input_image.bin", {1, 640, 480});
    std::vector<uint8_t> out1(640*480);
    std::vector<uint8_t> out2(640*480);

    mylib_image input;
    input.w = 640;
    input.h = 480;
    input.buffer = reinterpret_cast<uint8_t*>(inframe.data());

    mylib_output_frame output;
    output.output1.w = 640;
    output.output1.h = 480;
    output.output1.buffer = reinterpret_cast<uint8_t*>(out1.data());
    output.output2.w = 640;
    output.output2.h = 480;
    output.output2.buffer = reinterpret_cast<uint8_t*>(out2.data());

    mylib_process(&input, &output);

    for(auto i=0u; i<out1.size(); ++i)
    {
        REQUIRE(out1[i] < 64);
        REQUIRE(out2[i] < 8);
    }

}