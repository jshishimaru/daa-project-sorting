#include <iostream>
#include <fstream>
#include <random>

int main() {
    const int SIZE = 100000; // Change this to 1000000 for size 10^6
    std::ofstream outputFile("input.txt");

    if (!outputFile) {
        std::cerr << "Failed to open the output file." << std::endl;
        return 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);

    for (int i = 0; i < SIZE; ++i) {
        int num = dis(gen);
        outputFile << num << " ";
    }

    outputFile.close();
    std::cout << "Array generated and written to input.txt successfully." << std::endl;

    return 0;
}