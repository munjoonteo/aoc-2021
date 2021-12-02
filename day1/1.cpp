#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../helpers/readlines.h"
#include "1.h"

int main() {
    part1();
    part2();
}

void part1() {
    std::ofstream output("./day1/output", output.app);

    std::vector<std::string> depths = readLines("./day1/input");

    int prevDepth = 0;
    int timesIncreased = 0;
    for (std::vector<std::string>::iterator curr = depths.begin(); curr < depths.end(); ++curr) {
        int currDepth = std::atoi((*curr).c_str());
        if (curr - depths.begin() == 0) {
            prevDepth = currDepth;
        } else {
            if (currDepth > prevDepth) ++timesIncreased;
            prevDepth = currDepth;
        }
    }

    output << timesIncreased << "\n";
}

void part2() {
    std::ofstream output("./day1/output", output.app);

    std::vector<std::string> depths = readLines("./day1/input");

    int prevDepth = 0;
    int timesIncreased = 0;
    for (std::vector<std::string>::iterator curr = depths.begin(); curr < depths.end(); ++curr) {
        if (depths.end() - curr < 2) {
            break;
        }

        std::string first = (*curr);
        std::string second = *(curr + 1);
        std::string third = *(curr + 2);

        int currDepth = std::atoi(first.c_str()) + std::atoi(second.c_str()) + std::atoi(third.c_str());

        if (curr - depths.begin() == 0) {
            prevDepth = currDepth;
        } else {
            if (currDepth > prevDepth) ++timesIncreased;
            prevDepth = currDepth;
        }
    }

    output << timesIncreased << "\n";
}