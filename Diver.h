#ifndef DIVER_H
#define DIVER_H

#include <string>
#include <stdexcept>

class Diver
{
    public:
    Diver(std::string firstName, std::string lastName, int amountDives, int amountJudges, char division);
    ~Diver();
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getFullName() const;
    int getAmountDives() const;
    std::string getDive(int index) const;
    void addDive(int index, std::string dive);
    void addJudgeScore(int index, int judgeNumber, double score);
    int getJudgeScore(int index, int judgeNumber) const;
    void addIndDiveScore(int index, double score);
    double getIndDiveScore(int index) const;
    double getTotalScore() const;
    void setTotalScore(double score);
    char getDivision() const;

    private:
    std::string m_firstName;
    std::string m_lastName;
    std::string* m_dives;
    int m_amountDives;
    int m_amountJudges;
    double** m_judgeScores;
    double* m_indDiveScores;
    double m_totalScore;
    char m_division;
};
#endif
