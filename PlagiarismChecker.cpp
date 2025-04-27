#include "PlagiarismChecker.h"
#include <sstream>
#include <set>
#include <algorithm>
#include <cctype>
#include <iterator>

PlagiarismChecker::PlagiarismChecker() {

}

PlagiarismChecker::~PlagiarismChecker() {
}

std::vector<std::pair<std::string, double>> PlagiarismChecker::checkPlagiarism(const std::string &inputText) const {
    return {};
}

std::vector<std::string> PlagiarismChecker::tokenizeString(const std::string &text) const {

    std::vector<std::string> tokens;
    std::string cleaned;
    cleaned.reserve(text.size());
    for (char ch : text) {
        if (std::isalnum(static_cast<unsigned char>(ch))) {
            cleaned.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(ch))));
        } else {
            cleaned.push_back(' ');
        }
    }
    std::istringstream iss(cleaned);
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

double PlagiarismChecker::computeJaccard(const std::vector<std::string> &tokens1, const std::vector<std::string> &tokens2) const {
    return 0.0;
}
