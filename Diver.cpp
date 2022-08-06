#include "Diver.h"

Diver::Diver(std::string firstName, std::string lastName, int amountDives, int amountJudges, char division)
{
    m_firstName = firstName;
    m_lastName = lastName;
    m_dives = new std::string[amountDives];
    m_amountDives = amountDives;
    m_amountJudges = amountJudges;
    m_judgeScores = new double*[amountDives];
    for (int i = 0; i < amountDives; i++)
    {
        m_judgeScores[i] = new double[amountJudges];
    }
    m_indDiveScores = new double[amountDives];
    m_totalScore = 0.0;
    m_division = division;
}

Diver::~Diver()
{
    delete[] m_dives;
    delete[] m_indDiveScores;
    for (int i = 0; i < m_amountDives; i++)
    {
        delete m_judgeScores[i];
    }
    delete[] m_judgeScores;
}

std::string Diver::getFirstName() const
{
    return m_firstName;
}

std::string Diver::getLastName() const
{
    return m_lastName;
}

std::string Diver::getFullName() const
{
    return (m_firstName + " " + m_lastName);
}

int Diver::getAmountDives() const
{
    return m_amountDives;
}

std::string Diver::getDive(int index) const
{
    if (index < 0 || index >= m_amountDives)
    {
        throw(std::runtime_error("Invalid index"));
    }
    else
    {
        return m_dives[index];
    }
}

void Diver::addDive(int index, std::string dive)
{
    if (index < 0 || index >= m_amountDives)
    {
        throw(std::runtime_error("Invalid index"));
    }
    else
    {
        m_dives[index] = dive;
    }
}

void Diver::addJudgeScore(int index, int judgeNumber, double score)
{
    if (index < 0 || index >= m_amountDives || judgeNumber < 0 || judgeNumber >= m_amountJudges)
    {
        throw(std::runtime_error("Invalid index"));
    }
    else
    {
        m_judgeScores[index][judgeNumber] = score;
    }
}

int Diver::getJudgeScore(int index, int judgeNumber) const
{
    if (index < 0 || index >= m_amountDives || judgeNumber < 0 || judgeNumber >= m_amountJudges)
    {
        throw(std::runtime_error("Invalid index"));
    }
    else
    {
        return m_judgeScores[index][judgeNumber];
    }
}

void Diver::addIndDiveScore(int index, double score)
{
    if (index < 0 || index >= m_amountDives)
    {
        throw(std::runtime_error("Invalid index"));
    }
    else
    {
        m_indDiveScores[index] = score;
    }
}

double Diver::getIndDiveScore(int index) const
{
    if (index < 0 || index >= m_amountDives)
    {
        throw(std::runtime_error("Invalid index"));
    }
    else
    {
        return m_indDiveScores[index];
    }
}

double Diver::getTotalScore() const
{
    return m_totalScore;
}

void Diver::setTotalScore(double score)
{
    m_totalScore = m_totalScore + score;
}

char Diver::getDivision() const
{
    return m_division;
}
