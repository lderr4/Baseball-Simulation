#include <iostream>
#include <fstream>
#include "Pitcher.h"
#include <math.h>
#include <iomanip>

using namespace std;

    Pitcher::Pitcher()
    {
        name = "x";
    }
    string Pitcher::getName()
    {
        return name;
    }
    void Pitcher::setName(string x)
    {
        name = x;
    }

    string Pitcher::getTeam()
    {
        return team;
    }
    void Pitcher::setTeam(string x)
    {
        team = x;
    }

    int Pitcher::getAge()
    {
        return age;
    }
    void Pitcher::setAge(int x)
    {
        age = x;
    }
    int Pitcher::getGamesPlayed()
    {
        return gamesPlayed;
    }
    void Pitcher::setGamesPlayed(int x)
    {
        gamesPlayed = x;
    }
    int Pitcher::getGamesStarted()
    {
        return gamesStarted;
    }
    void Pitcher::setGamesStarted(int x)
    {
        gamesStarted = x;
    }

    int Pitcher::getCompleteGames()
    {
        return completeGames;
    }
    void Pitcher::setCompleteGames(int x)
    {
        completeGames = x;
    }

    int Pitcher::getShutouts()
    {
        return shutouts;
    }
    void Pitcher::setShutouts(int x)
    {
        shutouts = x;
    }

    int Pitcher::getIP()
    {
        return IP;
    }
    void Pitcher::setIP(int x)
    {
        IP = x;
    }

    int Pitcher::getHits()
    {
        return hits;
    }
    void Pitcher::setHits(int x)
    {
        hits = x;
    }

    int Pitcher::getEarnedRuns()
    {
        return earnedRuns;
    }
    void Pitcher::setEarnedRuns(int x)
    {
        earnedRuns = x;
    }

    int Pitcher::getKs()
    {
        return Ks;
    }
    void Pitcher::setKs(int x)
    {
        Ks = x;
    }

    int Pitcher::getBBs()
    {
        return BBs;
    }
    void Pitcher::setBBs(int x)
    {
        BBs = x;
    }

    int Pitcher::getHRs()
    {
        return HRs;
    }
    void Pitcher::setHRs(int x)
    {
        HRs = x;
    }

    int Pitcher::getW()
    {
        return W;
    }
    void Pitcher::setW(int x)
    {
        W = x;
    }

    int Pitcher::getL()
    {
        return L;
    }
    void Pitcher::setL(int x)
    {
        L = x;
    }

    int Pitcher::getSV()
    {
        return SV;
    }
    void Pitcher::setSV(int x)
    {
        SV = x;
    }

    int Pitcher::getBS()
    {
        return BS;
    }
    void Pitcher::setBS(int x)
    {
        BS = x;
    }
    
    int Pitcher::getHolds()
    {
        return holds;
    }
    void Pitcher::setHolds(int x)
    {
        holds = x;
    }

    int  Pitcher::getTotalYears()
{
    return totalYears;
}
    void Pitcher::setTotalYears(int x)
    {
        totalYears = x;
    }

    int Pitcher::getContractStartYear()
    {
        return contractStartYear;
    }
    void Pitcher::setContractStartYear(int x)
    {
        contractStartYear = x;
    }

    int Pitcher::getContractEndYear()
    {
        return contractEndYear;
    }
    void Pitcher::setContractEndYear(int x)
    {
        contractEndYear = x;
    }

    int Pitcher::getTotalMoney()
    {
        return totalMoney;
    }
    void Pitcher::setTotalMoney(int x)
    {
        totalMoney = x;
    }

    int Pitcher::getYearlyMoney()
    {
        return yearlyMoney;
    }
    void Pitcher::setYearlyMoney(int x)
    {
        yearlyMoney = x;
    }


    bool Pitcher::getHasSalary()
    {
        return hasSalary;
    }

    bool Pitcher::getIsFreeAgent()
    {
        return isFreeAgent;
    }

    void Pitcher::setIsFreeAgent(bool x)
    {
        isFreeAgent = x;
    }


    void Pitcher::setHasSalary(bool x)
    {
        hasSalary = x;
    }

    int Pitcher::getYears()
    {
        return years;
    }
    void Pitcher::setYears(int x)
    {
        years = x;
    }

    double Pitcher::getERA()
    {
        ERA = ((double)(earnedRuns*9))/((double)(IP));
        return ERA;
    }
    double Pitcher::getWhip()
    {
        whip = ((double)(BBs + hits))/((double)(IP));
        return whip;
    }

    string Pitcher::getPosition()
    {
        if(gamesPlayed == 0)
        {
            return position;
        }
        else
        {
            if((double)gamesStarted/(double)gamesPlayed > 0.8)
            {
                position = "SP";
                return position;
            }
            else if(SV >= 10)
            {
                position = "CL";
                return position;
            }
            else
            {
                position = "RP";
                return position;
            }
        }
        
        
        
    }

    void Pitcher::printPitcherInfo()
    {

        cout<<name;
        cout<<" Age: "<<age;
        cout<<" Position: "<<position;
        cout<<" IP: "<<IP;
        cout<<" Ks: "<<Ks;
        cout<<setprecision(3)<<" Earned Run Average: "<<ERA;
        if(position == "CL")
        {
            cout<<" Saves: "<<SV;
        }
        if(position == "RP")
        {
            cout<<" Holds: "<<holds;
        }
       
    }


void Pitcher::printContractInfo()
{
    cout<<name;
    cout<<" Years: "<<years;
    cout<<" Start Year: "<<contractStartYear;
    cout<<" End Year: "<<contractEndYear;
    cout<<" Total Salary: "<<printMoney(totalMoney);
    cout<<" Yearly Salary: "<<printMoney(yearlyMoney);
    

}

void Pitcher::printAllInfo()
{
    
    cout<<" Team "<<team;
    cout<<" Games Played: "<<gamesPlayed;
    cout<<" Games Started: "<<gamesStarted;
    cout<<" IP: "<<IP;
    cout<<" ER: "<<earnedRuns;
    cout<<" Ks: "<<Ks;
    if(position == "SP")
    {
        cout<<" Wins: "<<W;
        cout<<" Losses: "<<L;
    }
    else if(position == "CL")
    {
        cout<<" Saves: "<<SV;
        cout<<" Blown Saves: "<<BS;
    }
    else
    {
        cout<<" Saves: "<<SV;
        cout<<" Holds: "<<holds;
    }
    cout<<" ERA: "<<ERA;
    cout<<" Whip: "<<whip;

    
    
}

void Pitcher::showPreview()
{
    cout<<name;
    cout<<" Position: "<<position;
    cout<<" Command: "<<command;
    cout<<" Strikeout Rate: "<<Krate;
    cout<<" Ground Ball Rate: "<<gbrate;
    cout<<" Stamina: "<<stamina;
    if(position == "SP")
    {
        cout<<" Overall: "<<(int)(((1.1666*command + 1.1666*Krate + 1.1666*stamina + 0.5*gbrate)/4) + 0.5);
    }
    else
    {
        cout<<" Overall: "<<(int)((command+Krate+gbrate)/3);
    }
    
}

int Pitcher::getPotential()
{
    return potential;
}
void Pitcher::setPotential(int x)
{
    potential = x;
}

int Pitcher::getCommand()
{
    return command;
}
int Pitcher::getStamina()
{return stamina;}
int Pitcher::getKRate()
{return Krate;}
int Pitcher::getGBRate()
{
    return gbrate;
}
void Pitcher::setCommand(int x)
{command = x;}
void Pitcher::setStamina(int x)
{stamina = x;}
void Pitcher::setKRate(int x)
{Krate = x;}
void Pitcher::setGBRate(int x)
{
    gbrate = x;
}

int Pitcher::getOverall()
{
    if(position == "SP")
    {
        return (int)(((1.1666*command + 1.1666*Krate + 1.1666*stamina + 0.5*gbrate)/4) + 0.5);
    }
    else
    {
        return (int)((command+Krate+gbrate)/3);
    }
}

void Pitcher::setPosition(string x)
{
    position = x;
}

void Pitcher::showRatings()
{
    cout<<name;
    cout<<" Age: "<<age;
    cout<<" Position: "<<getPosition();
    cout<<" Command: "<<command;
    cout<<" Stamina: "<<stamina;
    cout<<" K Rate: "<<Krate;
    cout<<" GB Rate: "<<gbrate;
    cout<<" Overall: "<<getOverall();

}