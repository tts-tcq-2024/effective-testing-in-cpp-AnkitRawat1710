#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok, and 500 for high temperature (above a threshold)
    if (celcius > 200.0) {
        return 500; // Error response for critical temperatures
    }
    return 200; // Success for temperatures within normal range
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    std::cout << alertFailureCount << " alerts failed.\n";
    assert(alertFailureCount>=0);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
