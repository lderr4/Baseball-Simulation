#include <iostream>
#include <fstream>
#include "Batter.h"
#include <math.h>
#include <iomanip>

using namespace std;



Batter::Batter()
{
    name = "x";
}

string Batter::getName()
{
    return name;
}
void Batter::setName(string x)
{
    name = x;
}

string Batter::getTeam()
{
    return team;
}
void Batter::setTeam(string x)
{
    team = x;
}

string Batter::getPosition()
{
    return position;
}
void Batter::setPosition(string x)
{
    position = x;
}

int Batter::getAge()
{
    return age;
}
void Batter::setAge(int x)
{
    age = x;
}

int Batter::getGamesPlayed()
{
    return gamesPlayed;
}
void Batter::setGamesPlayed(int x)
{
    gamesPlayed = x;
}

int Batter::getAtBats()
{
    return atBats;
}
void Batter::setAtBats(int x)
{
    atBats = x;
}

int Batter::getRunsScored()    
{
    return runsScored;
}
void Batter::setRunsScored(int x)    
{
    runsScored = x;
}

int Batter::getHits()    
{
    return hits;      
}
void Batter::setHits(int x)   
{
    hits = x;
}

int Batter::getDoubles()    
{
    return doubles;
}
void Batter::setDoubles(int x)    
{
    doubles = x;
}

int Batter::getTriples()    
{
    return triples;
}
void Batter::setTriples(int x)    
{
    triples = x;   
}

int Batter::getHomeRuns()    
{
    return homeRuns;
}
void Batter::setHomeRuns(int x)   
{
    homeRuns = x;
}

int Batter::getRBIs()    
{
    return RBIs;
}
void Batter::setRBIs(int x)   
{
    RBIs = x;
}

int Batter::getStolenBases()    
{
    return stolenBases;
}
void Batter::setStolenBases(int x)    
{
    stolenBases = x;
}

int Batter::getCaughtStealing()   
{
    return caughtStealing;
}
void Batter::setCaughtStealing(int x)    
{
    caughtStealing = x;
}

int Batter::getWalks()    
{
    return walks;
}
void Batter::setWalks(int x)   
{
    walks = x;
}

int Batter::getStrikeouts()    
{
    return strikeouts;   
}
void Batter::setStrikeouts(int x)    
{
    strikeouts = x;
}

int Batter::getSacBunts()
{
    return sacBunts;
}
void Batter::setSacBunts(int x)
{
    sacBunts = x;
}

int Batter::getSacFlies()
{
    return sacFlies;
}
void Batter::setSacFlies(int x)
{
    sacFlies = x;
}

int Batter::getHitByPitch()   
{
    return hitByPitch;
}
void Batter::setHitByPitch(int x)    
{
    hitByPitch = x;
}

int Batter::getTotalYears()
{
    return totalYears;
}
void Batter::setTotalYears(int x)
{
    totalYears = x;
}

int Batter::getContractStartYear()
{
    return contractStartYear;
}
void Batter::setContractStartYear(int x)
{
    contractStartYear = x;
}

int Batter::getContractEndYear()
{
    return contractEndYear;
}
void Batter::setContractEndYear(int x)
{
    contractEndYear = x;
}

int Batter::getTotalMoney()
{
    return totalMoney;
}
void Batter::setTotalMoney(int x)
{
    totalMoney = x;
}

int Batter::getYearlyMoney()
{
    return yearlyMoney;
}
void Batter::setYearlyMoney(int x)
{
    yearlyMoney = x;
}

bool Batter::getHasSalary()
{
    return hasSalary;
}
void Batter::setHasSalary(bool x)
{
    hasSalary = x;
}

bool Batter::getIsFreeAgent()
{
    return isFreeAgent;
}

void Batter::setIsFreeAgent(bool x)
{
    isFreeAgent = x;
}

int Batter::getDL()
{
    return DL;
}

void Batter::setDL(int x)
{
    DL = x;
}

int Batter::getYears()
{
    return years;
}
void Batter::setYears(int x)
{
    years = x;
}





double Batter::getAVG()
{
    AVG = ((double)(hits))/((double)(atBats));
    return AVG;
}
double Batter::getSlug()
{
    double bases = 2*doubles + 3*triples + 4*homeRuns + (hits - (doubles + triples + homeRuns));
    slug = ((double)(bases))/((double)(atBats));
    return slug;
}

double Batter::getOBP()
{
    OBP = ((double)(hits+walks+hitByPitch))/((double)(atBats+walks+hitByPitch+sacBunts+sacFlies));
    return OBP;
}

double Batter::getOPS()
{
    OPS = slug + OBP;
    return OPS;
}
double Batter::getKRate()
{
    KRate = ((double)(strikeouts))/((double)(hits+walks+hitByPitch+atBats+sacBunts+sacFlies));
    return KRate;
}

void Batter::printBatterInfo()
{
    cout<<name;
    cout<<" Age: "<<age;
    cout<<" Position: "<<position;
    cout<<setprecision(3)<<" Batting Average: "<<AVG;
    cout<<" Home Runs: "<<homeRuns;
    cout<<" RBIs: "<<RBIs;
}
void Batter::showRatings()
{
    cout<<name;
    cout<<" Age: "<<age;
    cout<<" Position: "<<position;
    cout<<" Contact: "<<contact;
    cout<<" Power: "<<power;
    cout<<" Eye: "<<eye;
    cout<<" Overall: "<<(int)(contact*1.25+1.25*power+eye*0.5)/3;
}

double Batter::getGBRate() //finish
{
    return GBRate;
}
double Batter::getBBandHBPRate()
{
    BBandHBPRate = ((double)(walks + hitByPitch)/((double)(hits+walks+hitByPitch+atBats+sacBunts+sacFlies)));
    return BBandHBPRate;
}

void Batter::printContractInfo()
{
    cout<<name;
    cout<<" Years: "<<years;
    cout<<" Start Year: "<<contractStartYear;
    cout<<" End Year: "<<contractEndYear;
    cout<<" Total Salary: "<<printMoney(totalMoney);
    cout<<" Yearly Salary: "<<printMoney(yearlyMoney);
    

}

void Batter::printAllInfo()
{
    cout<<"  Team: "<<team;
    cout<<" Games Played: "<<gamesPlayed;
    cout<<" At Bats: "<<atBats;
    cout<<" Runs: "<<runsScored;
    cout<<" Hits: "<<hits;
    cout<<" RBI: "<<RBIs;
    cout<<" Home Runs: "<<homeRuns;
    cout<<" Stolen Bases: "<<stolenBases;
    cout<<setprecision(3)<<" AVG: "<<AVG;
    cout<<" OBP: "<<OBP;
    cout<<" SLG: "<<slug;
    cout<<" OPS: "<<OPS;

}


void Batter::showPreview()
{
    cout<<name;
    cout<<" Contact: "<<contact;
    cout<<" Power: "<<power;
    cout<<" Eye: "<<eye;
    if(consistency != 0)
    {
        cout<<" Consistency: "<<consistency;
    }
    cout<<" Overall: "<<(int)(contact*1.25+1.25*power+eye*0.5)/3;
    
}

int Batter::getContact()
{return contact;}
void Batter::setContact(int x)
{contact = x;}
int Batter::getPower()
{return power;}
void Batter::setPower(int x)
{
    power = x;
}
int Batter::getEye()
{return eye;}
void Batter::setEye(int x)
{eye = x;}
int Batter::getSpeed()
{return speed;}
void Batter::setSpeed(int x)
{speed = x;}
int Batter::getConsistency()
{return consistency;}
void Batter::setConsistency(int x)
{consistency = x;}
int Batter::getOverall()
{
    overall = (1.25*power+1.25*contact+0.5*eye)/3;
    return overall;}

int Batter::getPotential()
{
    return potential;
}
void Batter::setPotential(int x)
{
    potential = x;
}

