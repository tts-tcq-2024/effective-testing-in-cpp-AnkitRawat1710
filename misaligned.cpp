
#include <iostream>
#include <vector>
#include <cassert>
#include <iomanip>

/*int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}*/


// Define a struct to hold color information
struct ColorPair {
    const char* majorColor;
    const char* minorColor;
};

// Function to generate the color map
std::vector<ColorPair> generateColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
    std::vector<ColorPair> colorMap;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            colorMap.push_back({majorColor[i], minorColor[j]});
        }
    }
    return colorMap;
}

// Function to print the color map
void printColorMap(const std::vector<ColorPair>& colorMap) {
    std::cout << std::setw(5) << "Index" << " | " << std::setw(10) << "Major Color" << " | " << std::setw(10) << "Minor Color" << "\n";
    std::cout << std::string(40, '-') << "\n"; // Separator line
    for (size_t i = 0; i < colorMap.size(); ++i) {
        std::cout << std::setw(5) << i << " | "
                  << std::setw(10) << colorMap[i].majorColor << " | "
                  << std::setw(10) << colorMap[i].minorColor << "\n";
    }
}

int main() {
    auto colorMap = generateColorMap();
    printColorMap(colorMap);
    
    // Check the number of color pairs
    assert(colorMap.size() == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
