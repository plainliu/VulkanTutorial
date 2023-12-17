#include <fstream>
#include <vector>

class ShaderProcess
{
    static void compileShaders();

    static std::vector<char> readFile(const std::string& filename);
};
