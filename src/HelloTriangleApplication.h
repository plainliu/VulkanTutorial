

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <vector>
#include <optional>

struct QueueFamilyIndices
{
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete()
    {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

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
    void pickPhysicalDevice();
    bool isDeviceSuitable(VkPhysicalDevice device);
    int rateDeviceSuitability(VkPhysicalDevice device);
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    void createLogicalDevice();
    void createSurface();

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

    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

    VkDevice device = VK_NULL_HANDLE;

    VkQueue graphicsQueue = nullptr;
    VkQueue presentQueue = nullptr;

    VkSurfaceKHR surface = nullptr;
};
