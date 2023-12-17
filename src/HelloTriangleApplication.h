

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <vector>

class HelloTriangleApplication {
public:
    void run()
    {
        init();
        mainLoop();
        cleanup();
    }

private:
    void init();
    void mainLoop();
    void cleanup();

    void initWindow();
    void clearWindow();

    void initVulkan();
    void clearVulkan();
    void createInstance();
    void printAvaliableExtensions();
    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions();
    void setupDebugMessenger();
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    GLFWwindow* window = nullptr;
    VkInstance instance = nullptr;

    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

    VkDebugUtilsMessengerEXT debugMessenger = nullptr;
};
