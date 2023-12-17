#include "ShaderProcess.h"

#include <fstream>
#include <vector>
#include <filesystem>

#include <iostream>

const char* ShaderPath = "src/shaders";

void ShaderProcess::compileShaders()
{
    namespace fs = std::filesystem;

    // enum shader and compile
    for (const auto& entry : fs::recursive_directory_iterator(ShaderPath)) {
        const auto filenameStr = entry.path().filename().string();
        if (entry.is_directory()) {
            std::cout << "dir:  " << filenameStr << '\n';
        }
        else if (entry.is_regular_file()) {
            std::cout << "file: " << filenameStr << '\n';
        }
        else
            std::cout << "??    " << filenameStr << '\n';

        // std::system("glslc.exe shader.vert -o vert.spv");
    }
}

std::vector<char> ShaderProcess::readFile(const std::string& filename)
{
    std::ifstream file(filename, std::ios::ate | std::ios::binary);

    if (!file.is_open())
    {
        throw std::runtime_error("failed to open file!");
    }

    size_t fileSize = (size_t)file.tellg();
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);

    file.close();

    return buffer;
}
