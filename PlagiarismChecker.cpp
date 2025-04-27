#include "PlagiarismChecker.h"
#include <sstream>
#include <set>
#include <algorithm>
#include <cctype>
#include <iterator>

PlagiarismChecker::PlagiarismChecker() {

    dataset.push_back({ "Doc1", "I love KB" });
    dataset.push_back({ "Doc2", "Cigs and cool classic combo" });
    dataset.push_back({ "Doc3", "KB is hell" });
}

PlagiarismChecker::~PlagiarismChecker() {
}

std::vector<std::pair<std::string, double>> PlagiarismChecker::checkPlagiarism(const std::string &inputText) const
{
    std::vector<std::pair<std::string, double>> results;
    auto inputTokens = tokenizeString(inputText);
    for (const auto &doc : dataset)
    {
        auto docTokens = tokenizeString(doc.second);
        double similarity = computeJaccard(inputTokens, docTokens);
        results.push_back({ doc.first, similarity });
    }
    return results;
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

    std::set<std::string> set1(tokens1.begin(), tokens1.end());
    std::set<std::string> set2(tokens2.begin(), tokens2.end());
    std::vector<std::string> intersection;
    std::set_intersection(set1.begin(), set1.end(),
                          set2.begin(), set2.end(),
                          std::back_inserter(intersection));
    std::vector<std::string> unionSet;
    std::set_union(set1.begin(), set1.end(),
                   set2.begin(), set2.end(),
                   std::back_inserter(unionSet));

    double similarity = 0.0;
    if (!unionSet.empty())
    {
        similarity = static_cast<double>(intersection.size()) / unionSet.size();
    }
    return similarity;
}
