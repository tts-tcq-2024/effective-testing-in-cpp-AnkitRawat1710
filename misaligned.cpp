#include <iostream>
#include <assert.h>

//Typedef for a print function
typedef void(*PrintFunc)(int, const char*, const char*);

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printFunc(i * 5 + j, majorColor[i], minorColor[j]);
        }
    }
    return i * j;
}

//Real print function
void realPrint(int pairNumber, const char* major, const char* minor){
std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
}


int main() {
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
