#include "Meet.h"

Meet::Meet()
{
    std::cout << "Age group (1 = 8U, 2 = 10U, 3 = 12U, 4 = 14U, 5 = 16U, 6 = 18U): ";
    std::cin >> m_ageGroup;
    if (m_ageGroup == 1)
    {
        m_amountADives = 3;
        m_amountBDives = 3;
    }
    else if (m_ageGroup == 2)
    {
        m_amountADives = 4;
        m_amountBDives = 3;
    }
    else if (m_ageGroup == 3)
    {
        m_amountADives = 5;
        m_amountBDives = 4;
    }
    else if (m_ageGroup == 4)
    {
        m_amountADives = 6;
        m_amountBDives = 4;
    }
    else if (m_ageGroup == 5 || m_ageGroup == 6)
    {
        m_amountADives = 6;
        m_amountBDives = 5;
    }
    std::cout << "Amount of divers: ";
    std::cin >> m_amountDivers;
    std::cout << "Amount of judges: ";
    std::cin >> m_amountJudges;
    m_divers = new Diver*[m_amountDivers];
    std::cout << std::endl;
}

void Meet::addDivers()
{
    std::string firstName = "";
    std::string lastName = "";
    char division;
    Diver* tempDiver;
    for (int i = 0; i < m_amountDivers; i++)
    {
        std::cout << "Diver " << i+1 << " first name: ";
        std::cin >> firstName;
        std::cout << "Diver " << i+1 << " last name: ";
        std::cin >> lastName;
        std::cout << firstName << " " << lastName << "'s division: ";
        std::cin >> division;
        if (division == 'A')
        {
            tempDiver = new Diver(firstName, lastName, m_amountADives, m_amountJudges, division);
        }
        else
        {
            tempDiver = new Diver(firstName, lastName, m_amountBDives, m_amountJudges, division);
        }
        addDives(tempDiver);
        m_divers[i] = tempDiver;
        std::cout << std::endl;
    }
    if (m_amountDivers > 1)
    {
        shuffle();
    }
    std::cout << "DIVE ORDER" << std::endl;
    std::cout << "----------" << std::endl;
    showDiversUnranked();
    std::cout << std::endl;
}

void Meet::compete()
{
    int diveIndex;
    for (int i = 0; i < m_amountADives; i++)
    {
        std::cout << "ROUND " << i+1 << std::endl;
        std::cout << "-------" << std::endl;
        for (int j = 0; j < m_amountDivers; j++)
        {
            if (m_divers[j]->getDivision() == 'A')
            {
                diveIndex = getDiveIndex(m_divers[j]->getDive(i));
                std::cout << m_divers[j]->getFullName() << " will be competing a " << m_divers[j]->getDive(i) << ":" << std::endl;
                std::cout << m_diveDescriptions[diveIndex] << " DD: " << m_diveDD[diveIndex] << std::endl;
                scoreDive(m_divers[j], i, m_diveDD[diveIndex]);
                std::cout << std::endl;
            }
            else if (m_divers[j]->getDivision() != 'A' && i < m_amountBDives)
            {
                diveIndex = getDiveIndex(m_divers[j]->getDive(i));
                std::cout << m_divers[j]->getFullName() << " will be competing a " << m_divers[j]->getDive(i) << ":" << std::endl;
                std::cout << m_diveDescriptions[diveIndex] << " DD: " << m_diveDD[diveIndex] << std::endl;
                scoreDive(m_divers[j], i, m_diveDD[diveIndex]);
                std::cout << std::endl;
            }
        }
        std::cout << "ROUND " << i+1 << " STANDINGS" << std::endl;
        std::cout << "-----------------" << std::endl;
        showDiversRanked();
        std::cout << std::endl;
    }
}

void Meet::addDives(Diver* diver)
{
    std::string tempDive = "";
    bool validDive = false;
    for (int i = 0; i < diver->getAmountDives(); i++)
    {
        do
        {
            validDive = false;
            std::cout << "Dive " << i+1 << ": ";
            std::cin >> tempDive;
            for (int j = 0; j < 139; j++)
            {
                if (m_diveNumbers[j] == tempDive)
                {
                    validDive = true;
                }
            }
            if (validDive == false)
            {
                std::cout << "Please enter a valid dive." << std::endl;
            }
        } while (validDive == false);
        diver->addDive(i, tempDive);
    }
}

void Meet::shuffle()
{
    int random;
    Diver* tempDiver;
    for (int i = 0; i < m_amountDivers; i++)
    {
        random = rand() % (m_amountDivers-1);
        tempDiver = m_divers[random];
        m_divers[random] = m_divers[i];
        m_divers[i] = tempDiver;
    }
}

void Meet::showDiversUnranked()
{
    for (int i = 0; i < m_amountDivers; i++)
    {
        std::cout << i+1 << ". " << m_divers[i]->getFullName() << std::endl;
    }
}

void Meet::showDiversRanked()
{
    int aDivers = 0;
    int bDivers = 0;
    int cDivers = 0;
    Diver** sorted = new Diver*[m_amountDivers];
    Diver* tempDiver;
    for (int i = 0; i < m_amountDivers; i++)
    {
        sorted[i] = m_divers[i];
    }
    for (int j = 0; j < m_amountDivers; j++)
    {
        for (int k = j+1; k < m_amountDivers; k++)
        {
            if (sorted[j]->getTotalScore() < sorted[k]->getTotalScore())
            {
                tempDiver = sorted[j];
                sorted[j] = sorted[k];
                sorted[k] = tempDiver;
            }
        }
    }
    std::cout << "A STANDINGS" << std::endl;
    std::cout << "-----------" << std::endl;
    for (int l = 0; l < m_amountDivers; l++)
    {
        if (sorted[l]->getDivision() == 'A')
        {
            aDivers = aDivers + 1;
            std::cout << aDivers << ". " << sorted[l]->getFullName() << " " << sorted[l]->getTotalScore() << std::endl;
        }
    }
    std::cout << "B STANDINGS" << std::endl;
    std::cout << "-----------" << std::endl;
    for (int l = 0; l < m_amountDivers; l++)
    {
        if (sorted[l]->getDivision() == 'B')
        {
            bDivers = bDivers + 1;
            std::cout << bDivers << ". " << sorted[l]->getFullName() << " " << sorted[l]->getTotalScore() << std::endl;
        }
    }
    std::cout << "C STANDINGS" << std::endl;
    std::cout << "-----------" << std::endl;
    for (int l = 0; l < m_amountDivers; l++)
    {
        if (sorted[l]->getDivision() == 'C')
        {
            cDivers = cDivers + 1;
            std::cout << cDivers << ". " << sorted[l]->getFullName() << " " << sorted[l]->getTotalScore() << std::endl;
        }
    }
}

int Meet::getDiveIndex(std::string dive)
{
    int diveIndex;
    for (int k = 0; k < 139; k++)
    {
        if (m_diveNumbers[k] == dive)
        {
            diveIndex = k;
        }
    }
    return diveIndex;
}

void Meet::scoreDive(Diver* diver, int dive, double dd)
{
    double judgeScore;
    double diveScore = 0;
    for (int i = 0; i < m_amountJudges; i++)
    {
        std::cout << "Judge " << i+1 << " score: ";
        std::cin >> judgeScore;
        diver->addJudgeScore(dive, i, judgeScore);
    }
    for (int j = 0; j < m_amountJudges; j++)
    {
        diveScore = diveScore + diver->getJudgeScore(dive, j);
    }
    diveScore = diveScore * dd;
    diver->setTotalScore(diveScore);
    diver->addIndDiveScore(dive, diveScore);
}
