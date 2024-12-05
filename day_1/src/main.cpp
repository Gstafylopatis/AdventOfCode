#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

int part_1() {
    std::ifstream input("../../day_1/input.txt");
    if (!input.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    std::string line;
    std::vector<int> numbers1, numbers2;
    while (std::getline(input, line)) {
        std::string token;
        size_t pos = 0;

        while ((pos = line.find(' ')) != std::string::npos) {
            token = line.substr(0, pos);
            numbers1.emplace_back(atoi(token.c_str()));
            line.erase(0, pos + 3);
            numbers2.emplace_back(atoi(line.c_str()));
        }
    }


    std::ranges::stable_sort(numbers1);
    std::ranges::stable_sort(numbers2);

    int sum = 0;

    for (int i = 0; i < numbers1.size(); i++) {
        if (const int distance = numbers1[i] - numbers2[i]; distance < 0) {
            sum += distance * -1;
        } else {
            sum += distance;
        }
    }

    return sum;
}

int part_2() {
    std::ifstream input("../day_1/input.txt");
    if (!input.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    std::string line;
    std::vector<int> numbers1, numbers2;
    while (std::getline(input, line)) {
        std::string token;
        size_t pos = 0;

        while ((pos = line.find(' ')) != std::string::npos) {
            token = line.substr(0, pos);
            numbers1.emplace_back(atoi(token.c_str()));
            line.erase(0, pos + 3);
            numbers2.emplace_back(atoi(line.c_str()));
        }
    }

    int sum = 0;
    for (const int i : numbers1) {
        int num_of_occurences = 0;
        for (int j : numbers2) {
            if (i == j) {
                num_of_occurences++;
            }
        }

        sum += num_of_occurences * i;
    }

    return sum;
}

int main() {
    std::cout << part_2();
    return 0;
}
