#ifndef PITCHER_H
#define PITCHER_H
#include <string>

class Pitcher
{
    private:
    std::string name;
    std::string team;
    int age;
    int gamesPlayed;
    int gamesStarted;
    int completeGames;
    int shutouts;
    int IP;
    int hits;
    int earnedRuns;
    int Ks;
    int BBs;
    int HRs;
    int W;
    int L;
    int SV;
    int BS;
    int holds;
    double ERA;
    double whip;
    std::string position;
    
    
    
    
    int totalYears;
    int contractStartYear;
    int contractEndYear;
    int totalMoney;
    int yearlyMoney;
    bool hasSalary;
    bool isFreeAgent;
    int DL;
    int potential;
    
    int years;

    int command;
    int stamina;
    int Krate;
    int gbrate;


    
    public:
    Pitcher();
    std::string getName();
    void setName(std::string);

    std::string getTeam();
    void setTeam(std::string);

    int getAge();
    void setAge(int);

    int getGamesPlayed();
    void setGamesPlayed(int);

    int getGamesStarted();
    void setGamesStarted(int);

    int getCompleteGames();
    void setCompleteGames(int);

    int getShutouts();
    void setShutouts(int);

    int getIP();
    void setIP(int);

    int getHits();
    void setHits(int);

    int getEarnedRuns();
    void setEarnedRuns(int);

    int getKs();
    void setKs(int);

    int getBBs();
    void setBBs(int);

    int getHRs();
    void setHRs(int);

    int getW();
    void setW(int);

    int getL();
    void setL(int);

    int getSV();
    void setSV(int);

    int getBS();
    void setBS(int);
    
    int getHolds();
    void setHolds(int);

    int getTotalYears();
    void setTotalYears(int);

    int getContractStartYear();
    void setContractStartYear(int);

    int getContractEndYear();
    void setContractEndYear(int);

    int getTotalMoney();
    void setTotalMoney(int);

    int getYearlyMoney();
    void setYearlyMoney(int);

    bool getHasSalary();
    void setHasSalary(bool);

    bool getIsFreeAgent();
    void setIsFreeAgent(bool);

    int getYears();
    void setYears(int);
    

    double getERA();
    double getWhip();
    void printPitcherInfo();
    void printContractInfo();
    void printAllInfo();
    void showPreview();
    void showRatings();

    void setPotential(int);
    int getPotential();

    void setPosition(std::string);

    std::string getPosition();

    int getCommand();
    int getStamina();
    int getKRate();
    int getGBRate();
    int getOverall();
    void setCommand(int);
    void setStamina(int);
    void setKRate(int);
    void setGBRate(int);

    



};

#endif