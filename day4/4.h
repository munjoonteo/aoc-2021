struct Cell;

void part1();
void part2();
std::vector<std::unordered_map<std::string, Cell>> getBoards(std::vector<std::string> bingo);
bool checkBingo (std::unordered_map<std::string, Cell> board);
int getFinalScore(std::unordered_map<std::string, Cell> board, int prevNumber);
