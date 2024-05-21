#include "blchoice.h"
#include <fstream>
#include <sstream>

void Storage::readCsv(const std::string &path, strvec &table)
{
    std::ifstream file(path);
    std::string line;
    std::getline(file, line);
    while (!file.eof()){
        std::getline(file, line);
        std::stringstream ss(line);
        std::string field;
        std::vector<std::string> row;
        while (std::getline(ss, field, ','))
        {
            if (field.empty())
            {
                field = "0";
            }
            row.push_back(field);
        }
        table.push_back(row);
    }
};

void Storage::writeCsv(const std::string &path, std::vector<std::string> &text)
{
    std::ofstream file(path);
    std::string ftext = "";
    for (int i = 0; i < text.size(); i++)
    {
        ftext.append(text[i]).append(",");
    }
    file.close();
}

