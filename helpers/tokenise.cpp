#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> tokenise(std::string command) {
    std::vector<std::string> splitCommand {};
    std::string currWord;
    std::stringstream ss(command);

    while (ss >> currWord) {
        splitCommand.push_back(currWord);
    }

    return splitCommand;
}