#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> readLines(std::string fileName) {
    std::ifstream inputFile(fileName);
    std::string currLine;
    std::vector<std::string> inputs = {};

    while(std::getline(inputFile, currLine)) {
        inputs.push_back(currLine);
    }

    return inputs;
}