#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    std::vector<std::string> lines; // Use a vector to store lines dynamically
    std::string line;

    while (std::getline(inputFile, line)) {
        lines.push_back(line); // Add each line to the vector
    }


    inputFile.close();


    std::vector<int> side_1;
    std::vector<int> side_2;

    for (int i = 0; i < lines.size(); i++) {
        std::string line = lines[i];

        // Parse the line, use 3 spaces as delimiter
        int pos1 = line.find(" ");
        int pos2 = line.find(" ", pos1 + 1);
        int pos3 = line.find(" ", pos2 + 1);

        std::string str1 = line.substr(0, pos1);
        // std::string str2 = line.substr(pos1 + 2, );
        std::string str2 = line.substr(pos3 + 1, line.size() - pos3);

        std::cout << str1 << " " << str2 << std::endl;


        side_1.push_back(std::stoi(str1));
        side_2.push_back(std::stoi(str2));
    }

    int count = 0;


    //sort the sides

    std::sort(side_1.begin(), side_1.end());
    std::sort(side_2.begin(), side_2.end());

    std::unordered_map<int, int> dict;

    for (int i = 0; i < side_1.size(); i++) {
        dict[side_2[i]]++;
    }

    for (int i = 0; i < side_1.size(); i++) {
        if (dict[side_1[i]] > 0) {
          count += (dict[side_1[i]] * side_1[i]);
        }
    }




    std::cout << "The total is: " << count << std::endl;
    

    return 0;
}
