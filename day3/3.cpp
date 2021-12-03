#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../helpers/readlines.h"
#include "3.h"

const int BITSTRINGLENGTH = 12;

int main() {
    part1();
    part2();
}

void part1() {
    std::ofstream output("./day3/output", output.app);

    std::vector<std::string> bitstrings = readLines("./day3/input");

    int bitcounts[BITSTRINGLENGTH] = {};
    int gamma = 0;
    int epsilon = 0;

    for (std::vector<std::string>::iterator curr = bitstrings.begin(); curr < bitstrings.end(); ++curr) {
        for (int i = 0; i < BITSTRINGLENGTH; ++i) {
            if ((*curr)[i] == '0') {
                --bitcounts[i];
            } else {
                ++bitcounts[i];
            }
        }
    }

    for (int i = 0; i < BITSTRINGLENGTH; ++i) {
        if (bitcounts[i] > 0) {
            gamma = gamma ^ (1 << (BITSTRINGLENGTH - i - 1));
        } else {
            epsilon = epsilon ^ (1 << (BITSTRINGLENGTH - i - 1));
        }
    }

    output << gamma * epsilon << "\n";
}

void part2() {
    std::ofstream output("./day3/output", output.app);

    std::vector<std::string> bitstrings = readLines("./day3/input");
    int oxygen = std::stoi(filter(bitstrings, true), nullptr, 2);
    int co2 = std::stoi(filter(bitstrings, false), nullptr, 2);

    output << oxygen * co2 << "\n";
}

std::string filter(std::vector<std::string> bitstrings, bool isOxy) {
    int bitcounts[BITSTRINGLENGTH] = {};
    std::vector<std::string> filtered = bitstrings;

    for (int i = 0; i < BITSTRINGLENGTH; ++i) {
        if (filtered.size() == 1) break;

        for (std::vector<std::string>::iterator curr = filtered.begin(); curr < filtered.end(); ++curr) {
            if ((*curr)[i] == '0') {
                --bitcounts[i];
            } else {
                ++bitcounts[i];
            }
        }


        std::vector<std::string> newFiltered = {};

        auto checkDigitIs1 = [i](std::string curr) { return curr[i] == '1'; };
        auto checkDigitIs0 = [i](std::string curr) { return curr[i] == '0'; };

        if ((isOxy && bitcounts[i] >= 0) or (!isOxy && bitcounts[i] < 0)) {
            std::copy_if(filtered.begin(), filtered.end(), std::back_inserter(newFiltered), checkDigitIs1);
        } else {
            std::copy_if(filtered.begin(), filtered.end(), std::back_inserter(newFiltered), checkDigitIs0);
        }


        filtered = newFiltered;
    }

    return filtered.at(0);
}