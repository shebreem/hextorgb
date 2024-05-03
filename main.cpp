#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

int hexToInt(char hex) {
    if (hex >= '0' && hex <= '9') return hex - '0';
    else if (hex >= 'A' && hex <= 'F') return hex - 'A' + 10;
    else if (hex >= 'a' && hex <= 'f') return hex - 'a' + 10;
    else return -1;
}

int hexToDecimal(string hex) {
    int decimal = 0;
    for (char c : hex) {
        decimal = decimal * 16 + hexToInt(c);
    }
    return decimal;
}

void red(string hex) {
    int r = hexToDecimal(hex.substr(0, 2));
    cout << "r: " << r << endl;
}

void green(string hex) {
    int g = hexToDecimal(hex.substr(2, 2));
    cout << "g: " << g << endl;
}

void blue(string hex) {
    int b = hexToDecimal(hex.substr(4, 2));
    cout << "b: " << b << endl;
}

int main() {
    cout << "converter by leon" << endl;
    string hex;
    cout << "hex: ";
    cin >> hex;
    if (hex.length() == 6) {
        red(hex);
        green(hex);
        blue(hex);
        std::this_thread::sleep_for(std::chrono::seconds(15));
    }
    else {
        cout << "needs to be 6 letters doffus" << endl;
    }
    return 0;
}
