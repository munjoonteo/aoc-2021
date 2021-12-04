#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../helpers/readlines.h"
#include "../helpers/tokenise.h"
#include "4.h"

struct Cell {
    bool found;
    int row, column;
    bool operator==(const Cell& other) const {
        return (found == other.found and row == other.row and column == other.column);
    }
};

int main() {
    part1();
    part2();
}

void part1() {
    std::ofstream output("./day4/output", output.app);

    std::vector<std::string> bingo = readLines("./day4/input");
    std::vector<std::string> nums = tokenise(bingo.at(0), ',');
    bingo.erase(bingo.begin());
    bingo.erase(bingo.begin());

    std::vector<std::unordered_map<std::string, Cell>> boards = getBoards(bingo);

    for (auto num : nums) {
        for (auto &board : boards) {
            if (board.find(num) == board.end()) continue;

            board[num].found = true;

            if (checkBingo(board)) {
                output << getFinalScore(board, atoi(num.c_str())) << "\n";
                return;
            }
        }
    }

    output << "No solution :( \n";
}

void part2() {
    std::ofstream output("./day4/output", output.app);

    std::vector<std::string> bingo = readLines("./day4/input");
    std::vector<std::string> nums = tokenise(bingo.at(0), ',');
    bingo.erase(bingo.begin());
    bingo.erase(bingo.begin());

    std::vector<std::unordered_map<std::string, Cell>> boards = getBoards(bingo);
    std::vector<std::unordered_map<std::string, Cell>> notWonBoards = {};

    auto totalBoards = boards.size();

    for (auto num : nums) {
        std::vector<std::unordered_map<std::string, Cell>> justWonBoards = {};

        for (auto &board : boards) {
            if (board.find(num) == board.end()) continue;

            board[num].found = true;

            if (checkBingo(board)) {
                notWonBoards.push_back(board);
                justWonBoards.push_back(board);
            }

            if (notWonBoards.size() == totalBoards) {
                output << getFinalScore(board, atoi(num.c_str())) << "\n";
                return;
            }
        }

        std::vector<std::unordered_map<std::string, Cell>>::iterator it = boards.begin();

        while (it != boards.end()) {
            if (std::find(justWonBoards.begin(), justWonBoards.end(), *it) != justWonBoards.end()) {
                it = boards.erase(it);
            } else {
                ++it;
            }
        }
    }

    output << "No solution :( \n";
}

std::vector<std::unordered_map<std::string, Cell>> getBoards(std::vector<std::string> bingo) {
    std::vector<std::unordered_map<std::string, Cell>> boards = {};
    std::unordered_map<std::string, Cell> currBoard = {};
    int currRowNumber = 0;

    for (std::vector<std::string>::iterator currRow = bingo.begin(); currRow < bingo.end(); ++currRow) {
        if (*currRow == "") {
            boards.push_back(currBoard);
            currBoard = {};
            currRowNumber = 0;
            continue;
        }

        std::vector<std::string> bingoNums = tokenise(*currRow);

        for (std::size_t i = 0; i < bingoNums.size(); ++i) {
            currBoard[bingoNums.at(i)] = Cell{ false, currRowNumber, (int) i };
        }

        ++currRowNumber;
    }

    boards.push_back(currBoard);

    return boards;
}

bool checkBingo(std::unordered_map<std::string, Cell> board) {
    const int DIMS = 5;
    std::vector<int> rows(DIMS, 0);
    std::vector<int> cols(DIMS, 0);

    for (auto cell : board) {
        auto cellData = cell.second;
        if (!cellData.found) continue;

        ++rows.at(cellData.row);
        ++cols.at(cellData.column);

        if (rows.at(cellData.row) == DIMS or cols.at(cellData.column) == DIMS) {
            return true;
        }
    }

    return false;
}

int getFinalScore(std::unordered_map<std::string, Cell> board, int prevNumber) {
    int totalScore = 0;

    for (auto cell : board) {
        if (cell.second.found) continue;
        totalScore += atoi(cell.first.c_str());
    }

    return totalScore * prevNumber;
}