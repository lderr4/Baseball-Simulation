#ifndef BATTER_H
#define BATTER_H
#include <string>

class Batter
{
    private:
    std::string name;
    std::string team;
    std::string position;
    int age;
    int gamesPlayed;
    int atBats;
    int runsScored;
    int hits;
    int doubles;
    int triples;
    int homeRuns;
    int RBIs;
    int stolenBases;
    int caughtStealing;
    int walks;
    int strikeouts;
    int sacBunts;
    int sacFlies;
    int hitByPitch;
    
    double AVG; 
    double OBP; 
    double slug; 
    double OPS;
    double KRate;
    
    double BBandHBPRate; //chance that a hitter walks or gets hit by a pitch
    double GBRate; //rate of balls in play that are grounders
    double FBRate; //rate of balls in play that are fly balls
    
    int totalYears;
    int contractStartYear;
    int contractEndYear;
    int totalMoney;
    int yearlyMoney;

    bool hasSalary;
    bool isFreeAgent;
    int DL;
    
    int years;  //years in league

    int power; //all values 0-100
    int contact;
    int eye;
    int speed;
    int consistency;
    int overall;
    int potential;


    public:
    Batter();

    std::string getName();
    void setName(std::string);

    std::string getTeam();
    void setTeam(std::string);

    std::string getPosition();
    void setPosition(std::string);

    int getAge();
    void setAge(int);

    int getGamesPlayed();
    void setGamesPlayed(int);

    int getAtBats();
    void setAtBats(int);

    int getRunsScored();
    void setRunsScored(int);

    int getHits();
    void setHits(int);

    int getDoubles();
    void setDoubles(int);

    int getTriples();
    void setTriples(int);

    int getHomeRuns();
    void setHomeRuns(int);

    int getRBIs();
    void setRBIs(int);

    int getStolenBases();
    void setStolenBases(int);

    int getCaughtStealing();
    void setCaughtStealing(int);

    int getWalks();
    void setWalks(int);

    int getStrikeouts();
    void setStrikeouts(int);

    int getSacBunts();
    void setSacBunts(int);

    int getSacFlies();
    void setSacFlies(int);

    int getHitByPitch();
    void setHitByPitch(int);


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

    int getDL();
    void setDL(int);
    
    int getYears();
    void setYears(int);


    double getAVG();
    double getOBP();
    double getSlug();
    double getOPS();
    double getKRate();
    double getGBRate();
    double getBBandHBPRate();

    void printBatterInfo();
    void printAllInfo();
    void printContractInfo();
    void showRatings();
    void showPreview();

    int getPower(); 
    void setPower(int);
    int getContact();
    void setContact(int);
    int getEye();
    void setEye(int);
    int getSpeed();
    void setSpeed(int);
    int getConsistency();
    void setConsistency(int);
    int getOverall();
    void setOverall(int);
    int getPotential();
    void setPotential(int);


 
};

#endif