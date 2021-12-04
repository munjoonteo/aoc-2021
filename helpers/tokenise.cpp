#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> tokenise(std::string command, char sep = ' ') {
    std::vector<std::string> splitCommand {};
    std::string currWord;
    std::istringstream ss(command);

    while (std::getline(ss, currWord, sep)) {
        if (currWord != "") splitCommand.push_back(currWord);
    }

    return splitCommand;
}