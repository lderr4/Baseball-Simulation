#ifndef MLB_H
#define MLB_H
#include "Batter.h"
#include "Pitcher.h"
#include "Team.h"
#include <string>

class MLB
{
    private:
    Batter Batters2019[693];
    Batter Batters2018[688];
    Batter Batters2017[675];
    Batter Batters2016[677];
    Batter Batters2015[694];

    Pitcher Pitchers2019[872];
    Pitcher Pitchers2018[842];
    Pitcher Pitchers2017[814];
    Pitcher Pitchers2016[801];
    Pitcher Pitchers2015[785];

    Team league[30];

    std::string firstNames[1000];
    std::string lastNames[11099];


   


    public:
    MLB();
    void fillBatterStats(std::string, int,int);
    int getBatterIndex(std::string,int);
    Batter getBatter(int,int);

    void fillPitcherStats(std::string, int,int);
    int getPitcherIndex(std::string, int);
    Pitcher getPitcher(int,int);
 
    void fillContracts(std::string, int, bool);
    void fillContracts2(std::string, int);

    void displayRoster(std::string, int);   

    void determineFreeAgents(int,int,int);

    void setTeams();

    int getSpendingMoney(std::string, int len);

    Team getTeam(int);

    void setYears();

    void fillFreeAgency(Batter[], Pitcher[],std::string, int[]);
    void showFreeAgency(bool, std::string, Batter[], Pitcher[], Batter[], Pitcher[]);
    void showAllStats(bool isBatter, std::string name);
    int estimateValue(bool isBatter, std::string name);

    void setStats();
    void setConsistency();

    void fillNames();
    std::string generateName();
    void setProspects(int, Batter[], Pitcher[]);
    void showProspects();
    void viewPreviousContract(bool,std::string);
 
};

#endif