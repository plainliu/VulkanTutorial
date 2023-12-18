#include "ShaderProcess.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

const char* ShaderPath = "shaders";
const char* ComplerCommand = "glslc.exe %s -o %s";

void ShaderProcess::compileShaders()
{
    namespace fs = std::filesystem;

    // enum shader and compile
    for (const auto& entry : fs::recursive_directory_iterator(getRootPath() + "/" + ShaderPath))
    {
        const auto filenameStr = entry.path().filename().string();
        if (entry.is_directory())
        {
            std::cout << "dir:  " << filenameStr << '\n';
        }
        else if (entry.is_regular_file())
        {
            std::cout << "file: " << filenameStr << '\n';
        }
        else
            std::cout << "??    " << filenameStr << '\n';
    }
}

void ShaderProcess::compileShader(const std::string& fileName)
{
    auto absPath = getRootPath() + "/" + fileName;
    auto targetSpvPath = absPath + ".spv";

    auto command = std::string(ComplerCommand);

    std::vector<char> buf(1 + std::snprintf(nullptr, 0, ComplerCommand, absPath.c_str(), targetSpvPath.c_str()));
    std::snprintf(buf.data(), buf.size(), ComplerCommand, absPath.c_str(), targetSpvPath.c_str());

    std::system(buf.data());
}

std::string ShaderProcess::getRootPath()
{
    std::string rootDir(ROOT_SOURCE_DIR);
    return rootDir;
}

std::vector<char> ShaderProcess::readFile(const std::string& filename)
{
    std::ifstream file(getRootPath() + "/" + filename, std::ios::ate | std::ios::binary);

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
