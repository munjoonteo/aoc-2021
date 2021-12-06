void part1();
void part2();
std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> getPoints(
    std::vector<std::string> lines,
    int *maxSize
);
int getOverlapPoints(std::vector<std::vector<int>> grid, int maxSize);