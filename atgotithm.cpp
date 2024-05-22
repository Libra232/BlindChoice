#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>


// random
struct TableRow {
    std::string name;
    std::string author;
    std::string description;
    std::string link;
    std::string genre;
    int year;
};

TableRow getRandomRow(const std::vector<TableRow>& table) {
    if (table.empty()) {
        throw std::runtime_error("Table is empty");
    }
    std::srand(std::time(nullptr));
    int randomIndex = std::rand() % table.size();
    return table[randomIndex];
}


// genre sorting
TableRow getRandomRowByGenre(const std::vector<TableRow>& table, const std::string& genre) {
    std::vector<TableRow> filteredRows;
    for (const auto& row : table) {
        if (row.genre == genre) {
            filteredRows.push_back(row);
        }
    }

    if (filteredRows.empty()) {
        throw std::runtime_error("No rows found with the specified genre");
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int randomIndex = std::rand() % filteredRows.size();

    return filteredRows[randomIndex];
}


// year sorting
TableRow getRandomRowByYear(const std::vector<TableRow>& table, int year) {
    std::vector<TableRow> filteredRows;
    for (const auto& row : table) {
        if (row.year == year) {
            filteredRows.push_back(row);
        }
    }

    if (filteredRows.empty()) {
        throw std::runtime_error("No rows found for the given year.");
    }

    std::srand(std::time(nullptr));

    int randomIndex = std::rand() % filteredRows.size();
    return filteredRows[randomIndex];
}
