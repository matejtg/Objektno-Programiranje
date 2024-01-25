#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <cctype>

std::string toUpperCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

int main() {
    // otvaranje
    std::string filePath = "words.txt";
    std::ifstream inputFile;
    inputFile.open(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return 1; 
    }

    // citanje i upis
    std::istream_iterator<std::string> inputIterator(inputFile);
    std::istream_iterator<std::string> endIterator;
    std::vector<std::string> words(inputIterator, endIterator);

    std::cout << "Original words: ";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // trazenje rj
    std::string targetWord = "liar";
    std::vector<size_t> positions;
    auto it = std::find(words.begin(), words.end(), targetWord);
    while (it != words.end()) {
        positions.push_back(std::distance(words.begin(), it));
        it = std::find(++it, words.end(), targetWord);
    }

    std::cout << "Positions of '" << targetWord << "': ";
    for (const auto& pos : positions) {
        std::cout << pos << " ";
    }
    std::cout << std::endl;

    // izbacivanje
    std::string substringToRemove = "ar";
    words.erase(std::remove_if(words.begin(), words.end(),
        [substringToRemove](const std::string& str) {
            return str.find(substringToRemove) != std::string::npos;
        }),
        words.end());

    std::cout << "Words after removal: ";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    // u veliko sl
    std::transform(words.begin(), words.end(), words.begin(), toUpperCase);

    // Ispis
    std::cout << "Final words: ";
    for (const auto& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}
