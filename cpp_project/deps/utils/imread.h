
#ifndef UNTITLED2_IMREAD_H
#define UNTITLED2_IMREAD_H

#include <vector>
#include <fstream>
#include <cstdint>
#include <string>
#include <array>
#include <cassert>

template<typename T>
std::vector<T> imread(std::string fpath, std::array<int, 3> shape)
{
    auto size = shape[0] * shape[1] * shape[2];
    std::vector<T> out(size);

    std::ifstream infile(fpath);
    assert(infile.good());
    infile.read((char*)out.data(), size*sizeof(T));

    return out;
}


#endif //UNTITLED2_IMREAD_H
