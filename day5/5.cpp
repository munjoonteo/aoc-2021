#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../helpers/readlines.h"
#include "../helpers/tokenise.h"
#include "5.h"

int main() {
    part1();
    part2();
}

std::string const DELIM = " -> ";

void part1() {
    std::ofstream output("./day5/output", output.app);

    std::vector<std::string> lines = readLines("./day5/input");

    int maxSize = 0;
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> points = getPoints(lines, &maxSize);
    std::vector<std::vector<int>> grid(maxSize, std::vector<int>(maxSize, 0));

    for (auto line : points) {
        auto start = line.first;
        auto end = line.second;

        auto x1 = start.first;
        auto y1 = start.second;

        auto x2 = end.first;
        auto y2 = end.second;

        if (x1 == x2) {
            for (int i = std::min(y1, y2); i <= std::max(y1, y2); ++i) {
                ++grid[i][x1];
            }
        } else if (y1 == y2) {
            for (int i = std::min(x1, x2); i <= std::max(x1, x2); ++i) {
                ++grid[y1][i];
            }
        }
    }

    output << getOverlapPoints(grid, maxSize) << "\n";
}

void part2() {
    std::ofstream output("./day5/output", output.app);

    std::vector<std::string> lines = readLines("./day5/input");

    int maxSize = 0;
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> points = getPoints(lines, &maxSize);
    std::vector<std::vector<int>> grid(maxSize, std::vector<int>(maxSize, 0));

    for (auto line : points) {
        auto start = line.first;
        auto end = line.second;

        auto x1 = start.first;
        auto y1 = start.second;

        auto x2 = end.first;
        auto y2 = end.second;

        if (x1 == x2) {
            for (int i = std::min(y1, y2); i <= std::max(y1, y2); ++i) {
                ++grid[i][x1];
            }
        } else if (y1 == y2) {
            for (int i = std::min(x1, x2); i <= std::max(x1, x2); ++i) {
                ++grid[y1][i];
            }
        } else if (std::abs(x1 - x2) == std::abs(y1 - y2)) {
            if (x1 < x2 and y1 < y2) { // top left to bottom right
                for (int i = x1, j = y1; i <= x2; ++i, ++j) {
                    ++grid[j][i];
                }
            } else if (x1 > x2 and y1 > y2) { // bottom right to top left
                for (int i = x2, j = y2; i <= x1; ++i, ++j) {
                    ++grid[j][i];
                }
            } else if (x1 > x2 and y1 < y2) { // bottom left to top right
                for (int i = x1, j = y1; i >= x2; --i, ++j) {
                    ++grid[j][i];
                }
            } else { // top right to bottom left
                for (int i = x1, j = y1; i <= x2; ++i, --j) {
                    ++grid[j][i];
                }
            }
        }
    }

    output << getOverlapPoints(grid, maxSize) << "\n";
}

std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> getPoints(std::vector<std::string> lines, int *maxSize) {
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> points = {};

    for (auto line : lines) {
        auto startPoint = line.substr(0, line.find(DELIM));
        auto endPoint = line.substr(line.find(DELIM) + DELIM.size());

        auto startSplit = tokenise(startPoint, ',');
        auto endSplit = tokenise(endPoint, ',');

        auto x1 = atoi(startSplit.at(0).c_str());
        auto y1 = atoi(startSplit.at(1).c_str());

        auto x2 = atoi(endSplit.at(0).c_str());
        auto y2 = atoi(endSplit.at(1).c_str());

        int currMax = std::max(x2, y2);
        *maxSize = std::max(currMax, *maxSize);

        std::pair<int, int> startPair (x1, y1);
        std::pair<int, int> endPair (x2, y2);
        std::pair<std::pair<int, int>, std::pair<int, int>> linePair (startPair, endPair);

        points.push_back(linePair);
    }

    *maxSize = *maxSize + 1;

    return points;
}

int getOverlapPoints(std::vector<std::vector<int>> grid, int maxSize) {
    int overlapPoints = 0;
    for (int i = 0; i < maxSize; ++i) {
        for (int j = 0; j < maxSize; ++j) {
            if (grid[i][j] > 1) ++overlapPoints;
        }
    }

    return overlapPoints;
}