#ifndef PLAGIARISMCHECKER_H
#define PLAGIARISMCHECKER_H

#include <vector>
#include <string>
#include <utility>

class PlagiarismChecker
{
public:
    PlagiarismChecker();
    ~PlagiarismChecker();

    std::vector<std::pair<std::string, double>> checkPlagiarism(const std::string &inputText) const;

private:
    std::vector<std::pair<std::string, std::string>> dataset;

    std::vector<std::string> tokenizeString(const std::string &text) const;
    double computeJaccard(const std::vector<std::string> &tokens1, const std::vector<std::string> &tokens2) const;
};
#endif // PLAGIARISMCHECKER_H
