#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "../helpers/readlines.h"
#include "../helpers/tokenise.h"
#include "6.h"


int main() {
    part1();
    part2();
}

void part1() {
    const int DAYS = 80;

    std::ofstream output("./day6/output", output.app);

    std::vector<std::string> startingFishes = tokenise(readLines("./day6/input").at(0), ',');
    std::vector<int> fishes;
    for (auto fish : startingFishes) {
        fishes.push_back(atoi(fish.c_str()));
    }

    for (int currDay = 0; currDay < DAYS; ++currDay) {
        int newFish = 0;

        for (auto& fish : fishes) {
            if (fish > 0) {
                --fish;
            } else {
                fish = 6;
                ++newFish;
            }
        }

        for (int i = 0; i < newFish; ++i) fishes.push_back(8);
    }

    output << fishes.size() << "\n";
}

void part2() {
    const int DAYS = 4;

    std::ofstream output("./day6/output", output.app);

    std::vector<std::string> rawStartingFishes = tokenise(readLines("./day6/input").at(0), ',');

    // First = timer value
    // Second = day born
    std::queue<std::pair<int, int>> fishes;
    unsigned long totalFishes = rawStartingFishes.size();
    for (auto fish : rawStartingFishes) {
        int initialState = atoi(fish.c_str());
        fishes.push(std::pair<int, int>(6, initialState + 1));
        fishes.push(std::pair<int, int>(8, initialState + 1));
    }

    while (!fishes.empty()) {
        auto fish = fishes.front();
        fishes.pop();
        int currTimer = fish.first;
        int birthday = fish.second;

        if (DAYS - birthday < 9) continue; // This fish will no longer produce any offspring

        int birthingDay = birthday + currTimer + 1;
        int nOffspring = (DAYS - birthingDay) / 6;
        std::cout << nOffspring << "\n";
        totalFishes += nOffspring;

        for (int i = birthingDay; i < DAYS; i = i + 6) fishes.push(std::pair<int, int>(8, birthingDay));
    }

    output << totalFishes << "\n";
}