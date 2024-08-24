#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
int main() {
    const int SIZE = 50000; // Change this to 1000000 for size 10^6
    std::ofstream outputFile("input.txt");

    if (!outputFile) {
        std::cerr << "Failed to open the output file." << std::endl;
        return 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100);

    outputFile << 4 << std::endl; //number of arrays
    outputFile << SIZE << std::endl;

    // random array
    for (int i = 0; i < SIZE; ++i) {
        int num = dis(gen);
          outputFile << num << " ";
    }
    outputFile << std::endl;

    // sorted arrray
    for (int i = 1; i <= SIZE; ++i) {
        outputFile << i << " ";
    }
    outputFile << std::endl;

    //reverse sorted array
    // for (int i = SIZE; i >= 1; --i) {
    //     outputFile << i << " ";
    // }
    // outputFile << std::endl;
        
    // partial sorted array
    vector <int> partial;
    for( int i = 1 ; i <= SIZE/2 ; i++){
         
        partial.push_back(i);

    }
    shuffle(partial.begin(),partial.end(),gen);
    for( int i = 0 ; i < SIZE/2 ; i++){
        outputFile << partial[i] << " ";
    }

    for( int i = SIZE/2 + 1 ; i <= SIZE ; i++){
        outputFile << i << " ";
    }


    outputFile.close();
    std::cout << "Array generated and written to input.txt successfully." << std::endl;

    return 0;
}