#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "../helpers/readlines.h"
#include "2.h"

int main() {
    part1();
    part2();
}

void part1() {
    std::ofstream output("./day2/output", output.app | output.trunc);

    std::vector<std::string> commands = readLines("./day2/input");

    int depth = 0;
    int hori = 0;
    for (std::vector<std::string>::iterator curr = commands.begin(); curr < commands.end(); ++curr) {
        std::vector<std::string> splitCommand = tokenise(*curr);

        std::string command = splitCommand.at(0);
        int dist = std::atoi(splitCommand.at(1).c_str());

        if (command == "forward") {
            hori += dist;
        } else if (command == "down") {
            depth += dist;
        } else if (command == "up") {
            depth -= dist;
        }
    }

    output << depth * hori << "\n";
    std::cout << depth * hori << "\n";
}

void part2() {
    std::ofstream output("./day2/output", output.app | output.trunc);

    std::vector<std::string> commands = readLines("./day2/input");

    int depth = 0;
    int hori = 0;
    int aim = 0;
    for (std::vector<std::string>::iterator curr = commands.begin(); curr < commands.end(); ++curr) {
        std::vector<std::string> splitCommand = tokenise(*curr);

        std::string command = splitCommand.at(0);
        int dist = std::atoi(splitCommand.at(1).c_str());

        if (command == "forward") {
            hori += dist;
            depth += aim * dist;
        } else if (command == "down") {
            aim += dist;
        } else if (command == "up") {
            aim -= dist;
        }
    }

    output << depth * hori << "\n";
    std::cout << depth * hori << "\n";
}

std::vector<std::string> tokenise(std::string command) {
    std::vector<std::string> splitCommand {};
    std::string currWord;
    std::stringstream ss(command);

    while (ss >> currWord) {
        splitCommand.push_back(currWord);
    }

    return splitCommand;
}