#include <iostream>
#include <fstream>
#include "MLB.h"
#include "Batter.h"
#include "Pitcher.h"
#include "Team.h"
#include <math.h>
#include <boost/math/distributions/normal.hpp>
using namespace std;


int split(string s, char delimiter, string arr[], int len) 
{
    if(s == "") //edge case check for empty string
    {
        return 0;
    }
    else
    {
        s += delimiter; //this ensures that the last subsequence will added to the array
    }
    int arrIndex = 0; //this variable is used to increase the index of the array each time a delimiter is in the string
    string subsequence; //subsequence is each string in between the delimiter
    for(int i = 0; i <= s.length(); i++) //loop through each letter in the string s
    {
        if(s[i] == delimiter) //if the current index equals the delimiter
        {
            if(subsequence != "") //makes sure that the subsequence is not an empty string
            {
                arr[arrIndex] = subsequence; //add the subsequence to the current index
                arrIndex++; //increase the index so next time the subsequence will be added to the next element in the array
                subsequence = ""; //set the subsequence back to an empty string
            }
        }
        else
        {
            subsequence += s[i]; //if the current index is not a delimiter, then it will be added to t he subsequence
        }
    }
    return arrIndex; //the current index will equal the number of elements because it is increased by one after the last subsequence is added
}

MLB::MLB()
{
    for(int i = 0; i < 693; i++)
    {
        Batters2019[i] = Batter();
    }
        for(int i = 0; i < 688; i++)
    {
        Batters2018[i] = Batter();
    }
        for(int i = 0; i < 675; i++)
    {
        Batters2017[i] = Batter();
    }
        for(int i = 0; i < 677; i++)
    {
        Batters2016[i] = Batter();
    }
        for(int i = 0; i < 694; i++)
    {
        Batters2015[i] = Batter();
    }
}
void MLB::fillBatterStats(string fileName, int year, int len)
{
    ifstream myFile;
    myFile.open(fileName);
    string arr[19];
    string names[len];
    for(int i = 0 ; i < len; i++) //populate array
    {
        names[i] = "x";
    }
    int index = 0;

    if(myFile.is_open())
    {
        string line;
        while(getline(myFile,line))
        {
            int indext;
            bool trade = false;
            split(line,',',arr,19);
            for(int i = 0 ; i < len; i++)
            {
                if(arr[0] == names[i])
                {
                    trade = true;
                    indext = i;
                }
            }
            if(year == 2019)
            {
                if(trade == false)
                {
                    names[index] = arr[0];
                    Batters2019[index].setName(arr[0]);
                    Batters2019[index].setTeam(arr[1]);
                    Batters2019[index].setPosition(arr[2]);
                    Batters2019[index].setAge(stoi(arr[3]));
                    Batters2019[index].setGamesPlayed(stoi(arr[4]));
                    Batters2019[index].setAtBats(stoi(arr[5]));
                    Batters2019[index].setRunsScored(stoi(arr[6]));
                    Batters2019[index].setHits(stoi(arr[7]));
                    Batters2019[index].setDoubles(stoi(arr[8]));
                    Batters2019[index].setTriples(stoi(arr[9]));
                    Batters2019[index].setHomeRuns(stoi(arr[10]));
                    Batters2019[index].setRBIs(stoi(arr[11]));
                    Batters2019[index].setStolenBases(stoi(arr[12]));
                    Batters2019[index].setCaughtStealing(stoi(arr[13]));
                    Batters2019[index].setWalks(stoi(arr[14]));
                    Batters2019[index].setStrikeouts(stoi(arr[15]));
                    Batters2019[index].setSacBunts(stoi(arr[16]));
                    Batters2019[index].setSacFlies(stoi(arr[17]));
                    Batters2019[index].setHitByPitch(stoi(arr[18]));
                    Batters2019[index].getAVG();
                    Batters2019[index].getOBP();
                    Batters2019[index].getSlug();
                    Batters2019[index].getOPS();
                }
                else if (trade == true)
                {
                    Batters2019[indext].setTeam(arr[1]);
                    Batters2019[indext].setGamesPlayed(Batters2019[indext].getGamesPlayed()+stoi(arr[4]));
                    Batters2019[indext].setAtBats(Batters2019[indext].getAtBats()+stoi(arr[5]));
                    Batters2019[indext].setRunsScored(Batters2019[indext].getRunsScored()+stoi(arr[6]));
                    Batters2019[indext].setHits(Batters2019[indext].getHits() + stoi(arr[7]));
                    Batters2019[indext].setDoubles(Batters2019[indext].getDoubles() + stoi(arr[8]));
                    Batters2019[indext].setTriples(Batters2019[indext].getTriples()+stoi(arr[9]));
                    Batters2019[indext].setHomeRuns(Batters2019[indext].getHomeRuns()+stoi(arr[10]));
                    Batters2019[indext].setRBIs(Batters2019[indext].getRBIs()+stoi(arr[11]));
                    Batters2019[indext].setStolenBases(Batters2019[indext].getStolenBases()+stoi(arr[12]));
                    Batters2019[indext].setCaughtStealing(Batters2019[indext].getCaughtStealing()+stoi(arr[13]));
                    Batters2019[indext].setWalks(Batters2019[indext].getWalks()+stoi(arr[14]));
                    Batters2019[indext].setStrikeouts(Batters2019[indext].getStrikeouts()+stoi(arr[15]));
                    Batters2019[indext].setSacBunts(Batters2019[indext].getSacBunts()+stoi(arr[16]));
                    Batters2019[indext].setSacFlies(Batters2019[indext].getSacFlies()+stoi(arr[17]));
                    Batters2019[indext].setHitByPitch(Batters2019[indext].getHitByPitch()+stoi(arr[18]));
                    Batters2019[indext].getAVG();
                    Batters2019[indext].getOBP();
                    Batters2019[indext].getSlug();
                    Batters2019[indext].getOPS();
                }
                
            }
            else if(year == 2018)
            {
                if(trade == false)
                {
                    names[index] = arr[0];
                    Batters2018[index].setName(arr[0]);
                    Batters2018[index].setTeam(arr[1]);
                    Batters2018[index].setPosition(arr[2]);
                    Batters2018[index].setAge(stoi(arr[3]));
                    Batters2018[index].setGamesPlayed(stoi(arr[4]));
                    Batters2018[index].setAtBats(stoi(arr[5]));
                    Batters2018[index].setRunsScored(stoi(arr[6]));
                    Batters2018[index].setHits(stoi(arr[7]));
                    Batters2018[index].setDoubles(stoi(arr[8]));
                    Batters2018[index].setTriples(stoi(arr[9]));
                    Batters2018[index].setHomeRuns(stoi(arr[10]));
                    Batters2018[index].setRBIs(stoi(arr[11]));
                    Batters2018[index].setStolenBases(stoi(arr[12]));
                    Batters2018[index].setCaughtStealing(stoi(arr[13]));
                    Batters2018[index].setWalks(stoi(arr[14]));
                    Batters2018[index].setStrikeouts(stoi(arr[15]));
                    Batters2018[index].setSacBunts(stoi(arr[16]));
                    Batters2018[index].setSacFlies(stoi(arr[17]));
                    Batters2018[index].setWalks(stoi(arr[14]));
                    Batters2018[index].setWalks(stoi(arr[14]));
                    Batters2018[index].setHitByPitch(stoi(arr[18]));
                    Batters2018[index].getAVG();
                    Batters2018[index].getOBP();
                    Batters2018[index].getSlug();
                    Batters2018[index].getOPS();
                }
                else if (trade == true)
                {
                    Batters2018[indext].setTeam(arr[1]);
                    Batters2018[indext].setGamesPlayed(Batters2018[indext].getGamesPlayed()+stoi(arr[4]));
                    Batters2018[indext].setAtBats(Batters2018[indext].getAtBats()+stoi(arr[5]));
                    Batters2018[indext].setRunsScored(Batters2018[indext].getRunsScored()+stoi(arr[6]));
                    Batters2018[indext].setHits(Batters2018[indext].getHits() + stoi(arr[7]));
                    Batters2018[indext].setDoubles(Batters2018[indext].getDoubles() + stoi(arr[8]));
                    Batters2018[indext].setTriples(Batters2018[indext].getTriples()+stoi(arr[9]));
                    Batters2018[indext].setHomeRuns(Batters2018[indext].getHomeRuns()+stoi(arr[10]));
                    Batters2018[indext].setRBIs(Batters2018[indext].getRBIs()+stoi(arr[11]));
                    Batters2018[indext].setStolenBases(Batters2018[indext].getStolenBases()+stoi(arr[12]));
                    Batters2018[indext].setCaughtStealing(Batters2018[indext].getCaughtStealing()+stoi(arr[13]));
                    Batters2018[indext].setWalks(Batters2018[indext].getWalks()+stoi(arr[14]));
                    Batters2018[indext].setStrikeouts(Batters2018[indext].getStrikeouts()+stoi(arr[15]));
                    Batters2018[indext].setSacBunts(Batters2018[indext].getSacBunts()+stoi(arr[16]));
                    Batters2018[indext].setSacFlies(Batters2018[indext].getSacFlies()+stoi(arr[17]));
                    Batters2018[indext].setHitByPitch(Batters2018[indext].getHitByPitch()+stoi(arr[18]));
                    Batters2018[indext].getAVG();
                    Batters2018[indext].getOBP();
                    Batters2018[indext].getSlug();
                    Batters2018[indext].getOPS();
                }
                
            }
            else if(year == 2017)
            {
                if(trade == false)
                {
                    names[index] = arr[0];
                    Batters2017[index].setName(arr[0]);
                    Batters2017[index].setTeam(arr[1]);
                    Batters2017[index].setPosition(arr[2]);
                    Batters2017[index].setAge(stoi(arr[3]));
                    Batters2017[index].setGamesPlayed(stoi(arr[4]));
                    Batters2017[index].setAtBats(stoi(arr[5]));
                    Batters2017[index].setRunsScored(stoi(arr[6]));
                    Batters2017[index].setHits(stoi(arr[7]));
                    Batters2017[index].setDoubles(stoi(arr[8]));
                    Batters2017[index].setTriples(stoi(arr[9]));
                    Batters2017[index].setHomeRuns(stoi(arr[10]));
                    Batters2017[index].setRBIs(stoi(arr[11]));
                    Batters2017[index].setStolenBases(stoi(arr[12]));
                    Batters2017[index].setCaughtStealing(stoi(arr[13]));
                    Batters2017[index].setWalks(stoi(arr[14]));
                    Batters2017[index].setStrikeouts(stoi(arr[15]));
                    Batters2017[index].setSacBunts(stoi(arr[16]));
                    Batters2017[index].setSacFlies(stoi(arr[17]));
                    Batters2017[index].setWalks(stoi(arr[14]));
                    Batters2017[index].setWalks(stoi(arr[14]));
                    Batters2017[index].setHitByPitch(stoi(arr[18]));
                    Batters2017[index].getAVG();
                    Batters2017[index].getOBP();
                    Batters2017[index].getSlug();
                    Batters2017[index].getOPS();
                }
                else if (trade == true)
                {
                    Batters2017[indext].setTeam(arr[1]);
                    Batters2017[indext].setGamesPlayed(Batters2017[indext].getGamesPlayed()+stoi(arr[4]));
                    Batters2017[indext].setAtBats(Batters2017[indext].getAtBats()+stoi(arr[5]));
                    Batters2017[indext].setRunsScored(Batters2017[indext].getRunsScored()+stoi(arr[6]));
                    Batters2017[indext].setHits(Batters2017[indext].getHits() + stoi(arr[7]));
                    Batters2017[indext].setDoubles(Batters2017[indext].getDoubles() + stoi(arr[8]));
                    Batters2017[indext].setTriples(Batters2017[indext].getTriples()+stoi(arr[9]));
                    Batters2017[indext].setHomeRuns(Batters2017[indext].getHomeRuns()+stoi(arr[10]));
                    Batters2017[indext].setRBIs(Batters2017[indext].getRBIs()+stoi(arr[11]));
                    Batters2017[indext].setStolenBases(Batters2017[indext].getStolenBases()+stoi(arr[12]));
                    Batters2017[indext].setCaughtStealing(Batters2017[indext].getCaughtStealing()+stoi(arr[13]));
                    Batters2017[indext].setWalks(Batters2017[indext].getWalks()+stoi(arr[14]));
                    Batters2017[indext].setStrikeouts(Batters2017[indext].getStrikeouts()+stoi(arr[15]));
                    Batters2017[indext].setSacBunts(Batters2017[indext].getSacBunts()+stoi(arr[16]));
                    Batters2017[indext].setSacFlies(Batters2017[indext].getSacFlies()+stoi(arr[17]));
                    Batters2017[indext].setHitByPitch(Batters2017[indext].getHitByPitch()+stoi(arr[18]));
                    Batters2017[indext].getAVG();
                    Batters2017[indext].getOBP();
                    Batters2017[indext].getSlug();
                    Batters2017[indext].getOPS();
                }
            }
            else if(year == 2016)
            {
                if(trade == false)
                {
                    names[index] = arr[0];
                    Batters2016[index].setName(arr[0]);
                    Batters2016[index].setTeam(arr[1]);
                    Batters2016[index].setPosition(arr[2]);
                    Batters2016[index].setAge(stoi(arr[3]));
                    Batters2016[index].setGamesPlayed(stoi(arr[4]));
                    Batters2016[index].setAtBats(stoi(arr[5]));
                    Batters2016[index].setRunsScored(stoi(arr[6]));
                    Batters2016[index].setHits(stoi(arr[7]));
                    Batters2016[index].setDoubles(stoi(arr[8]));
                    Batters2016[index].setTriples(stoi(arr[9]));
                    Batters2016[index].setHomeRuns(stoi(arr[10]));
                    Batters2016[index].setRBIs(stoi(arr[11]));
                    Batters2016[index].setStolenBases(stoi(arr[12]));
                    Batters2016[index].setCaughtStealing(stoi(arr[13]));
                    Batters2016[index].setWalks(stoi(arr[14]));
                    Batters2016[index].setStrikeouts(stoi(arr[15]));
                    Batters2016[index].setSacBunts(stoi(arr[16]));
                    Batters2016[index].setWalks(stoi(arr[14]));
                    Batters2016[index].setWalks(stoi(arr[14]));
                    Batters2016[index].setHitByPitch(stoi(arr[18]));
                    Batters2016[index].getAVG();
                    Batters2016[index].getOBP();
                    Batters2016[index].getSlug();
                    Batters2016[index].getOPS();
                }
                else if (trade == true)
                {
                    Batters2016[indext].setTeam(arr[1]);
                    Batters2016[indext].setGamesPlayed(Batters2016[indext].getGamesPlayed()+stoi(arr[4]));
                    Batters2016[indext].setAtBats(Batters2016[indext].getAtBats()+stoi(arr[5]));
                    Batters2016[indext].setRunsScored(Batters2016[indext].getRunsScored()+stoi(arr[6]));
                    Batters2016[indext].setHits(Batters2016[indext].getHits() + stoi(arr[7]));
                    Batters2016[indext].setDoubles(Batters2016[indext].getDoubles() + stoi(arr[8]));
                    Batters2016[indext].setTriples(Batters2016[indext].getTriples()+stoi(arr[9]));
                    Batters2016[indext].setHomeRuns(Batters2016[indext].getHomeRuns()+stoi(arr[10]));
                    Batters2016[indext].setRBIs(Batters2016[indext].getRBIs()+stoi(arr[11]));
                    Batters2016[indext].setStolenBases(Batters2016[indext].getStolenBases()+stoi(arr[12]));
                    Batters2016[indext].setCaughtStealing(Batters2016[indext].getCaughtStealing()+stoi(arr[13]));
                    Batters2016[indext].setWalks(Batters2016[indext].getWalks()+stoi(arr[14]));
                    Batters2016[indext].setStrikeouts(Batters2016[indext].getStrikeouts()+stoi(arr[15]));
                    Batters2016[indext].setSacBunts(Batters2016[indext].getSacBunts()+stoi(arr[16]));
                    Batters2016[indext].setSacFlies(Batters2016[indext].getSacFlies()+stoi(arr[17]));
                    Batters2016[indext].setHitByPitch(Batters2016[indext].getHitByPitch()+stoi(arr[18]));
                    Batters2016[indext].getAVG();
                    Batters2016[indext].getOBP();
                    Batters2016[indext].getSlug();
                    Batters2016[indext].getOPS();
                }
            }
            else if(year == 2015)
            {
                if(trade == false)
                {
                    names[index] = arr[0];
                    Batters2015[index].setName(arr[0]);
                    Batters2015[index].setTeam(arr[1]);
                    Batters2015[index].setPosition(arr[2]);
                    Batters2015[index].setAge(stoi(arr[3]));
                    Batters2015[index].setGamesPlayed(stoi(arr[4]));
                    Batters2015[index].setAtBats(stoi(arr[5]));
                    Batters2015[index].setRunsScored(stoi(arr[6]));
                    Batters2015[index].setHits(stoi(arr[7]));
                    Batters2015[index].setDoubles(stoi(arr[8]));
                    Batters2015[index].setTriples(stoi(arr[9]));
                    Batters2015[index].setHomeRuns(stoi(arr[10]));
                    Batters2015[index].setRBIs(stoi(arr[11]));
                    Batters2015[index].setStolenBases(stoi(arr[12]));
                    Batters2015[index].setCaughtStealing(stoi(arr[13]));
                    Batters2015[index].setWalks(stoi(arr[14]));
                    Batters2015[index].setStrikeouts(stoi(arr[15]));
                    Batters2015[index].setSacBunts(stoi(arr[16]));
                    Batters2015[index].setSacFlies(stoi(arr[17]));
                    Batters2015[index].setWalks(stoi(arr[14]));
                    Batters2015[index].setWalks(stoi(arr[14]));
                    Batters2015[index].setHitByPitch(stoi(arr[18]));
                    Batters2015[index].getAVG();
                    Batters2015[index].getOBP();
                    Batters2015[index].getSlug();
                    Batters2015[index].getOPS();
                }
                else if (trade ==true)
                {

                    Batters2015[indext].setTeam(arr[1]);
                    Batters2015[indext].setGamesPlayed(Batters2015[indext].getGamesPlayed()+stoi(arr[4]));
                    Batters2015[indext].setAtBats(Batters2015[indext].getAtBats()+stoi(arr[5]));
                    Batters2015[indext].setRunsScored(Batters2015[indext].getRunsScored()+stoi(arr[6]));
                    Batters2015[indext].setHits(Batters2015[indext].getHits() + stoi(arr[7]));
                    Batters2015[indext].setDoubles(Batters2015[indext].getDoubles() + stoi(arr[8]));
                    Batters2015[indext].setTriples(Batters2015[indext].getTriples()+stoi(arr[9]));
                    Batters2015[indext].setHomeRuns(Batters2015[indext].getHomeRuns()+stoi(arr[10]));
                    Batters2015[indext].setRBIs(Batters2015[indext].getRBIs()+stoi(arr[11]));
                    Batters2015[indext].setStolenBases(Batters2015[indext].getStolenBases()+stoi(arr[12]));
                    Batters2015[indext].setCaughtStealing(Batters2015[indext].getCaughtStealing()+stoi(arr[13]));
                    Batters2015[indext].setWalks(Batters2015[indext].getWalks()+stoi(arr[14]));
                    Batters2015[indext].setStrikeouts(Batters2015[indext].getStrikeouts()+stoi(arr[15]));
                    Batters2015[indext].setSacBunts(Batters2015[indext].getSacBunts()+stoi(arr[16]));
                    Batters2015[indext].setSacFlies(Batters2015[indext].getSacFlies()+stoi(arr[17]));
                    Batters2015[indext].setHitByPitch(Batters2015[indext].getHitByPitch()+stoi(arr[18]));
                    Batters2015[indext].getAVG();
                    Batters2015[indext].getOBP();
                    Batters2015[indext].getSlug();
                    Batters2015[indext].getOPS();
                }
            }
            

            index++;
        }

    }
    myFile.close();
   

}
int MLB::getBatterIndex(string name, int year)
{
    if(year == 2019)
    {
        for(int i = 0; i < 693; i++)
        {
            if(Batters2019[i].getName() == name)
            {
                return i;
            }
        }
    }
    else if(year == 2018)
    {
        for(int i = 0; i < 688; i++)
        {
            if(Batters2018[i].getName() == name)
            {
                return i;
            }
        }
    }
    else if(year == 2017)
    {
        for(int i = 0; i < 675; i++)
        {
            if(Batters2017[i].getName() == name)
            {
                return i;
            }
        }
    }
    else if(year == 2016)
    {
        for(int i = 0; i < 677; i++)
        {
            if(Batters2016[i].getName() == name)
            {
                return i;
            }
        }
    }
    else
    {
        for(int i = 0; i < 694; i++)
        {
            if(Batters2015[i].getName() == name)
            {
                return i;
            }
        }  
    }
    return -1;
}
Batter MLB::getBatter(int index, int year)
{
    if(year == 2019)
    {
        return Batters2019[index];
    }
    else if(year == 2018)
    {
        return Batters2018[index];
    }
    else if(year == 2017)
    {
        return Batters2017[index];
    }
    else if(year == 2016)
    {
        return Batters2016[index];
    }
    else
    {
        return Batters2015[index];
    }
    Batter b;
    return b;
}

void MLB::fillPitcherStats(string fileName, int year, int len)
{
    ifstream myFile;
    myFile.open(fileName);
    string arr[18];
    int index = 0;
    string names[len];
    for(int i = 0 ; i < len; i++) //populate array
    {
        names[i] = "x";
    }

    if(myFile.is_open())
    {
        string line;
        while(getline(myFile,line))
        {
            int indext;
            bool trade = false;
            split(line,',',arr,18);
            for(int i = 0 ; i < len; i++)
            {
                if(arr[0] == names[i])
                {
                    trade = true;
                    indext = i;
                }
            }
            if(year == 2019)
            {
                if(trade == false)
                {
                    names[index] = arr[0];
                    Pitchers2019[index].setName(arr[0]);
                    Pitchers2019[index].setTeam(arr[1]);
                    Pitchers2019[index].setAge(stoi(arr[2]));
                    Pitchers2019[index].setGamesPlayed(stoi(arr[3]));
                    Pitchers2019[index].setGamesStarted(stoi(arr[4]));
                    Pitchers2019[index].setCompleteGames(stoi(arr[5]));
                    Pitchers2019[index].setShutouts(stoi(arr[6]));
                    Pitchers2019[index].setIP(stoi(arr[7]));
                    Pitchers2019[index].setHits(stoi(arr[8]));
                    Pitchers2019[index].setEarnedRuns(stoi(arr[9]));
                    Pitchers2019[index].setKs(stoi(arr[10]));
                    Pitchers2019[index].setBBs(stoi(arr[11]));
                    Pitchers2019[index].setHRs(stoi(arr[12]));
                    Pitchers2019[index].setW(stoi(arr[13]));
                    Pitchers2019[index].setL(stoi(arr[14]));
                    Pitchers2019[index].setSV(stoi(arr[15]));
                    Pitchers2019[index].setBS(stoi(arr[16]));
                    Pitchers2019[index].setHolds(stoi(arr[17]));
                    Pitchers2019[index].getERA();
                    Pitchers2019[index].getWhip();
                    Pitchers2019[index].getPosition();
                }
                else if(trade == true)
                {
                    
                    Pitchers2019[indext].setTeam(arr[1]);
                    Pitchers2019[indext].setGamesPlayed(Pitchers2019[indext].getGamesPlayed()+stoi(arr[3]));
                    Pitchers2019[indext].setGamesStarted(Pitchers2019[indext].getGamesStarted()+stoi(arr[4]));
                    Pitchers2019[indext].setShutouts(Pitchers2019[indext].getShutouts()+stoi(arr[6]));
                    Pitchers2019[indext].setIP(Pitchers2019[indext].getIP()+stoi(arr[7]));
                    Pitchers2019[indext].setHits(Pitchers2019[indext].getHits()+stoi(arr[8]));
                    Pitchers2019[indext].setEarnedRuns(Pitchers2019[indext].getEarnedRuns()+stoi(arr[9]));
                    Pitchers2019[indext].setKs(Pitchers2019[indext].getKs()+stoi(arr[10]));
                    Pitchers2019[indext].setBBs(Pitchers2019[indext].getBBs() + stoi(arr[11]));
                    Pitchers2019[indext].setHRs(Pitchers2019[indext].getHRs() + stoi(arr[12]));
                    Pitchers2019[indext].setW(Pitchers2019[indext].getW()+stoi(arr[13]));
                    Pitchers2019[indext].setL(Pitchers2019[indext].getL()+stoi(arr[14]));
                    Pitchers2019[indext].setSV(Pitchers2019[indext].getSV()+stoi(arr[15]));
                    Pitchers2019[indext].setBS(Pitchers2019[indext].getBS()+stoi(arr[16]));
                    Pitchers2019[indext].setHolds(Pitchers2019[indext].getHolds()+stoi(arr[17]));
                    Pitchers2019[indext].getERA();
                    Pitchers2019[indext].getWhip();
                    Pitchers2019[indext].getPosition();
                }
                
            }
            else if(year == 2018)
            {
                if(trade == false)
                {
                    Pitchers2018[index].setName(arr[0]);
                    Pitchers2018[index].setTeam(arr[1]);
                    Pitchers2018[index].setAge(stoi(arr[2]));
                    Pitchers2018[index].setGamesPlayed(stoi(arr[3]));
                    Pitchers2018[index].setGamesStarted(stoi(arr[4]));
                    Pitchers2018[index].setCompleteGames(stoi(arr[5]));
                    Pitchers2018[index].setShutouts(stoi(arr[6]));
                    Pitchers2018[index].setIP(stoi(arr[7]));
                    Pitchers2018[index].setHits(stoi(arr[8]));
                    Pitchers2018[index].setEarnedRuns(stoi(arr[9]));
                    Pitchers2018[index].setKs(stoi(arr[10]));
                    Pitchers2018[index].setBBs(stoi(arr[11]));
                    Pitchers2018[index].setHRs(stoi(arr[12]));
                    Pitchers2018[index].setW(stoi(arr[13]));
                    Pitchers2018[index].setL(stoi(arr[14]));
                    Pitchers2018[index].setSV(stoi(arr[15]));
                    Pitchers2018[index].setBS(stoi(arr[16]));
                    Pitchers2018[index].setHolds(stoi(arr[17]));
                    Pitchers2018[index].getERA();
                    Pitchers2018[index].getWhip();
                    Pitchers2018[index].getPosition();
                }
                else if(trade == true)
                {
                    Pitchers2018[indext].setTeam(arr[1]);
                    Pitchers2018[indext].setGamesPlayed(Pitchers2018[indext].getGamesPlayed()+stoi(arr[3]));
                    Pitchers2018[indext].setGamesStarted(Pitchers2018[indext].getGamesStarted()+stoi(arr[4]));
                    Pitchers2018[indext].setShutouts(Pitchers2018[indext].getShutouts()+stoi(arr[6]));
                    Pitchers2018[indext].setIP(Pitchers2018[indext].getIP()+stoi(arr[7]));
                    Pitchers2018[indext].setHits(Pitchers2018[indext].getHits()+stoi(arr[8]));
                    Pitchers2018[indext].setEarnedRuns(Pitchers2018[indext].getEarnedRuns()+stoi(arr[9]));
                    Pitchers2018[indext].setKs(Pitchers2018[indext].getKs()+stoi(arr[10]));
                    Pitchers2018[indext].setBBs(Pitchers2018[indext].getBBs() + stoi(arr[11]));
                    Pitchers2018[indext].setHRs(Pitchers2018[indext].getHRs() + stoi(arr[12]));
                    Pitchers2018[indext].setW(Pitchers2018[indext].getW()+stoi(arr[13]));
                    Pitchers2018[indext].setL(Pitchers2018[indext].getL()+stoi(arr[14]));
                    Pitchers2018[indext].setSV(Pitchers2018[indext].getSV()+stoi(arr[15]));
                    Pitchers2018[indext].setBS(Pitchers2018[indext].getBS()+stoi(arr[16]));
                    Pitchers2018[indext].setHolds(Pitchers2018[indext].getHolds()+stoi(arr[17]));
                    Pitchers2018[indext].getERA();
                    Pitchers2018[indext].getWhip();
                    Pitchers2018[indext].getPosition();
                }
            }
            else if(year == 2017)
            {
                if(trade == false)
                {
                    Pitchers2017[index].setName(arr[0]);
                    Pitchers2017[index].setTeam(arr[1]);
                    Pitchers2017[index].setAge(stoi(arr[2]));
                    Pitchers2017[index].setGamesPlayed(stoi(arr[3]));
                    Pitchers2017[index].setGamesStarted(stoi(arr[4]));
                    Pitchers2017[index].setCompleteGames(stoi(arr[5]));
                    Pitchers2017[index].setShutouts(stoi(arr[6]));
                    Pitchers2017[index].setIP(stoi(arr[7]));
                    Pitchers2017[index].setHits(stoi(arr[8]));
                    Pitchers2017[index].setEarnedRuns(stoi(arr[9]));
                    Pitchers2017[index].setKs(stoi(arr[10]));
                    Pitchers2017[index].setBBs(stoi(arr[11]));
                    Pitchers2017[index].setHRs(stoi(arr[12]));
                    Pitchers2017[index].setW(stoi(arr[13]));
                    Pitchers2017[index].setL(stoi(arr[14]));
                    Pitchers2017[index].setSV(stoi(arr[15]));
                    Pitchers2017[index].setBS(stoi(arr[16]));
                    Pitchers2017[index].setHolds(stoi(arr[17]));
                    Pitchers2017[index].getERA();
                    Pitchers2017[index].getWhip();
                    Pitchers2017[index].getPosition();
                }
                else if(trade == true)
                {
                    Pitchers2017[indext].setTeam(arr[1]);
                    Pitchers2017[indext].setGamesPlayed(Pitchers2017[indext].getGamesPlayed()+stoi(arr[3]));
                    Pitchers2017[indext].setGamesStarted(Pitchers2017[indext].getGamesStarted()+stoi(arr[4]));
                    Pitchers2017[indext].setShutouts(Pitchers2017[indext].getShutouts()+stoi(arr[6]));
                    Pitchers2017[indext].setIP(Pitchers2017[indext].getIP()+stoi(arr[7]));
                    Pitchers2017[indext].setHits(Pitchers2017[indext].getHits()+stoi(arr[8]));
                    Pitchers2017[indext].setEarnedRuns(Pitchers2017[indext].getEarnedRuns()+stoi(arr[9]));
                    Pitchers2017[indext].setKs(Pitchers2017[indext].getKs()+stoi(arr[10]));
                    Pitchers2017[indext].setBBs(Pitchers2017[indext].getBBs() + stoi(arr[11]));
                    Pitchers2017[indext].setHRs(Pitchers2017[indext].getHRs() + stoi(arr[12]));
                    Pitchers2017[indext].setW(Pitchers2017[indext].getW()+stoi(arr[13]));
                    Pitchers2017[indext].setL(Pitchers2017[indext].getL()+stoi(arr[14]));
                    Pitchers2017[indext].setSV(Pitchers2017[indext].getSV()+stoi(arr[15]));
                    Pitchers2017[indext].setBS(Pitchers2017[indext].getBS()+stoi(arr[16]));
                    Pitchers2017[indext].setHolds(Pitchers2017[indext].getHolds()+stoi(arr[17]));
                    Pitchers2017[indext].getERA();
                    Pitchers2017[indext].getWhip();
                    Pitchers2017[indext].getPosition();
                }
                
            }
            else if(year == 2016)
            {
                if(trade == false)
                {
                    Pitchers2016[index].setName(arr[0]);
                    Pitchers2016[index].setTeam(arr[1]);
                    Pitchers2016[index].setAge(stoi(arr[2]));
                    Pitchers2016[index].setGamesPlayed(stoi(arr[3]));
                    Pitchers2016[index].setGamesStarted(stoi(arr[4]));
                    Pitchers2016[index].setCompleteGames(stoi(arr[5]));
                    Pitchers2016[index].setShutouts(stoi(arr[6]));
                    Pitchers2016[index].setIP(stoi(arr[7]));
                    Pitchers2016[index].setHits(stoi(arr[8]));
                    Pitchers2016[index].setEarnedRuns(stoi(arr[9]));
                    Pitchers2016[index].setKs(stoi(arr[10]));
                    Pitchers2016[index].setBBs(stoi(arr[11]));
                    Pitchers2016[index].setHRs(stoi(arr[12]));
                    Pitchers2016[index].setW(stoi(arr[13]));
                    Pitchers2016[index].setL(stoi(arr[14]));
                    Pitchers2016[index].setSV(stoi(arr[15]));
                    Pitchers2016[index].setBS(stoi(arr[16]));
                    Pitchers2016[index].setHolds(stoi(arr[17]));
                    Pitchers2016[index].getERA();
                    Pitchers2016[index].getWhip();
                    Pitchers2016[index].getPosition();
                }
                else if(trade == true)
                {
                    Pitchers2016[indext].setTeam(arr[1]);
                    Pitchers2016[indext].setGamesPlayed(Pitchers2016[indext].getGamesPlayed()+stoi(arr[3]));
                    Pitchers2016[indext].setGamesStarted(Pitchers2016[indext].getGamesStarted()+stoi(arr[4]));
                    Pitchers2016[indext].setShutouts(Pitchers2016[indext].getShutouts()+stoi(arr[6]));
                    Pitchers2016[indext].setIP(Pitchers2016[indext].getIP()+stoi(arr[7]));
                    Pitchers2016[indext].setHits(Pitchers2016[indext].getHits()+stoi(arr[8]));
                    Pitchers2016[indext].setEarnedRuns(Pitchers2016[indext].getEarnedRuns()+stoi(arr[9]));
                    Pitchers2016[indext].setKs(Pitchers2016[indext].getKs()+stoi(arr[10]));
                    Pitchers2016[indext].setBBs(Pitchers2016[indext].getBBs() + stoi(arr[11]));
                    Pitchers2016[indext].setHRs(Pitchers2016[indext].getHRs() + stoi(arr[12]));
                    Pitchers2016[indext].setW(Pitchers2016[indext].getW()+stoi(arr[13]));
                    Pitchers2016[indext].setL(Pitchers2016[indext].getL()+stoi(arr[14]));
                    Pitchers2016[indext].setSV(Pitchers2016[indext].getSV()+stoi(arr[15]));
                    Pitchers2016[indext].setBS(Pitchers2016[indext].getBS()+stoi(arr[16]));
                    Pitchers2016[indext].setHolds(Pitchers2016[indext].getHolds()+stoi(arr[17]));
                    Pitchers2016[indext].getERA();
                    Pitchers2016[indext].getWhip();
                    Pitchers2016[indext].getPosition();
                }
                
            }
            else
            {
                if(trade == false)
                {
                    Pitchers2015[index].setName(arr[0]);
                    Pitchers2015[index].setTeam(arr[1]);
                    Pitchers2015[index].setAge(stoi(arr[2]));
                    Pitchers2015[index].setGamesPlayed(stoi(arr[3]));
                    Pitchers2015[index].setGamesStarted(stoi(arr[4]));
                    Pitchers2015[index].setCompleteGames(stoi(arr[5]));
                    Pitchers2015[index].setShutouts(stoi(arr[6]));
                    Pitchers2015[index].setIP(stoi(arr[7]));
                    Pitchers2015[index].setHits(stoi(arr[8]));
                    Pitchers2015[index].setEarnedRuns(stoi(arr[9]));
                    Pitchers2015[index].setKs(stoi(arr[10]));
                    Pitchers2015[index].setBBs(stoi(arr[11]));
                    Pitchers2015[index].setHRs(stoi(arr[12]));
                    Pitchers2015[index].setW(stoi(arr[13]));
                    Pitchers2015[index].setL(stoi(arr[14]));
                    Pitchers2015[index].setSV(stoi(arr[15]));
                    Pitchers2015[index].setBS(stoi(arr[16]));
                    Pitchers2015[index].setHolds(stoi(arr[17]));
                    Pitchers2015[index].getERA();
                    Pitchers2015[index].getWhip();
                    Pitchers2015[index].getPosition();
                }
                else if(trade == true)
                {
                    Pitchers2015[indext].setTeam(arr[1]);
                    Pitchers2015[indext].setGamesPlayed(Pitchers2015[indext].getGamesPlayed()+stoi(arr[3]));
                    Pitchers2015[indext].setGamesStarted(Pitchers2015[indext].getGamesStarted()+stoi(arr[4]));
                    Pitchers2015[indext].setShutouts(Pitchers2015[indext].getShutouts()+stoi(arr[6]));
                    Pitchers2015[indext].setIP(Pitchers2015[indext].getIP()+stoi(arr[7]));
                    Pitchers2015[indext].setHits(Pitchers2015[indext].getHits()+stoi(arr[8]));
                    Pitchers2015[indext].setEarnedRuns(Pitchers2015[indext].getEarnedRuns()+stoi(arr[9]));
                    Pitchers2015[indext].setKs(Pitchers2015[indext].getKs()+stoi(arr[10]));
                    Pitchers2015[indext].setBBs(Pitchers2015[indext].getBBs() + stoi(arr[11]));
                    Pitchers2015[indext].setHRs(Pitchers2015[indext].getHRs() + stoi(arr[12]));
                    Pitchers2015[indext].setW(Pitchers2015[indext].getW()+stoi(arr[13]));
                    Pitchers2015[indext].setL(Pitchers2015[indext].getL()+stoi(arr[14]));
                    Pitchers2015[indext].setSV(Pitchers2015[indext].getSV()+stoi(arr[15]));
                    Pitchers2015[indext].setBS(Pitchers2015[indext].getBS()+stoi(arr[16]));
                    Pitchers2015[indext].setHolds(Pitchers2015[indext].getHolds()+stoi(arr[17]));
                    Pitchers2015[indext].getERA();
                    Pitchers2015[indext].getWhip();
                    Pitchers2015[indext].getPosition();
                }
                
            }
           

            index++;
        }

    }
    else
    {
        cout<<"Error opening file"<<endl;
    }
  

}

int MLB::getPitcherIndex(string name, int year)
{
    if(year == 2019)
    {
        for(int i = 0; i < 872; i++)
        {
            if(Pitchers2019[i].getName() == name)
            {
                return i;
            }
        }
    }
    else if(year == 2018)
    {
        for(int i = 0; i < 842; i++)
        {
            if(Pitchers2018[i].getName() == name)
            {
                return i;
            }
        }
    }
    else if(year == 2017)
    {
        for(int i = 0; i < 814; i++)
        {
            if(Pitchers2017[i].getName() == name)
            {
                return i;
            }
        }
    }
    else if(year == 2016)
    {
        for(int i = 0; i < 801; i++)
        {
            if(Pitchers2016[i].getName() == name)
            {
                return i;
            }
        }
    }
    else
    {
        for(int i = 0; i < 785; i++)
        {
            if(Pitchers2015[i].getName() == name)
            {
                return i;
            }
        }  
    }
    return -1;
}

Pitcher MLB::getPitcher(int index,int year)
{
    if(year == 2019)
    {
        return Pitchers2019[index];
    }
    else if(year == 2018)
    {
        return Pitchers2018[index];
    }
    else if(year == 2017)
    {
        return Pitchers2017[index];
    }
    else if(year == 2016)
    {
        return Pitchers2016[index];
    }
    else if(year)
    {
        return Pitchers2015[index];      
    }
    Pitcher p;
    return p;
}

void MLB::fillContracts(string fileName, int len, bool isBatter)
{
    ifstream myFile;
    myFile.open(fileName);
    string arr[5];
    string years;
    string startYear;
    string endYear;
    string totalMoney;
    bool hasContract;
    if(isBatter == true)
    {
        for(int i = 0; i < len; i++)
        {
            Batters2019[i].setHasSalary(false);
        }
    }
    else if(isBatter == false)
    {
        for(int i = 0; i < len; i++)
        {
            Pitchers2019[i].setHasSalary(false);
        }
    }
    if(myFile.is_open())
    {
        string line;
        while(getline(myFile,line))
        {
            for(int i = 0; i < 5; i++)
            {
                arr[i] = "n";
            }
            split(line,',',arr,5);
            for(int i = 0; i < len; i++)
            {

                if(isBatter == true)
                {

                    if(arr[0] == Batters2019[i].getName()) 
                    {
                        //cout<<"Name:" <<arr[0];
                        if(arr[1][1] !=  ' ') 
                        {
                            years = arr[1].substr(0,2);
                            //cout<<" years: "<<years;
                        }
                        else 
                        {
                            years = arr[1].substr(0,2);
                            //cout<<" years: "<<years;
                        }
                    
                        if(stoi(years) < 10)
                        {
                            startYear = arr[1].substr(3,4);
                            //cout<<" start year: "<<startYear;
                        }
                        else
                        {
                            startYear = arr[1].substr(4,4);
                            //cout<<" start year: "<<startYear;
                        }

                        if(stoi(years) == 1)
                        {
                            endYear = startYear;
                            //cout<<" end year: "<<endYear;
                        }
                        else if(stoi(years) < 10 && stoi(years) > 1)
                        {
                            endYear = "20" + arr[1].substr(8,2);
                            //cout<<" end year: "<<endYear;
                        }
                        else
                        {
                            endYear  = "20" + arr[1].substr(9,2);
                            //cout<<" end year: "<<endYear;
                        }
                        if(arr[4] == "n")
                        {
                            totalMoney = arr[2].substr(2) + arr[3].substr(0,3);
                            //cout<<" Total money: "<<totalMoney;
                        }
                        else
                        {                        
                            totalMoney = arr[2].substr(2) + arr[3].substr(0,3) + arr[4].substr(0,3);
                            //cout<<" Total money: "<<totalMoney;
                        }
                        //cout<<endl;
                        Batters2019[i].setTotalYears(stoi(years));
                        Batters2019[i].setContractStartYear(stoi(startYear));
                        Batters2019[i].setContractEndYear(stoi(endYear));
                        Batters2019[i].setTotalMoney(stoi(totalMoney));
                        Batters2019[i].setYearlyMoney(stoi(totalMoney)/stoi(years));
                        Batters2019[i].setHasSalary(true);
                    }
                }
                else if(isBatter == false)
                {
                    if(arr[0] == Pitchers2019[i].getName()) 
                    {
                        //cout<<"Name:" <<arr[0];
                        if(arr[1][1] !=  ' ') 
                        {
                            years = arr[1].substr(0,2);
                            //cout<<" years: "<<years;
                        }
                        else 
                        {
                            years = arr[1].substr(0,2);
                            //cout<<" years: "<<years;
                        }
                        
                        if(stoi(years) < 10)
                        {
                            startYear = arr[1].substr(3,4);
                            //cout<<" start year: "<<startYear;
                        }
                        else
                        {
                            startYear = arr[1].substr(4,4);
                            //cout<<" start year: "<<startYear;
                        }

                        if(stoi(years) == 1)
                        {
                            endYear = startYear;
                            //cout<<" end year: "<<endYear;
                        }
                        else if(stoi(years) < 10 && stoi(years) > 1)
                        {
                            endYear = "20" + arr[1].substr(8,2);
                            //cout<<" end year: "<<endYear;
                        }
                        else
                        {
                            endYear  = "20" + arr[1].substr(9,2);
                            //cout<<" end year: "<<endYear;
                        }
                        if(arr[4] == "n")
                        {
                            totalMoney = arr[2].substr(2) + arr[3].substr(0,3);
                            //cout<<" Total money: "<<totalMoney;
                        }
                        else
                        {                        
                            totalMoney = arr[2].substr(2) + arr[3].substr(0,3) + arr[4].substr(0,3);
                            //cout<<" Total money: "<<totalMoney;
                        }
                        
                        
                        Pitchers2019[i].setTotalYears(stoi(years));
                        Pitchers2019[i].setContractStartYear(stoi(startYear));
                        Pitchers2019[i].setContractEndYear(stoi(endYear));
                        Pitchers2019[i].setTotalMoney(stoi(totalMoney));
                        Pitchers2019[i].setYearlyMoney(stoi(totalMoney)/stoi(years));
                        Pitchers2019[i].setHasSalary(true);
                        //cout<<Pitchers2019[i].getName()<<"   "<<Pitchers2019[i].getTotalYears()<<"   "<<Pitchers2019[i].getTotalMoney();
                    }
                
                }
            }  
        }
    }
    else
    {
        cout<<"Error opening file"<<endl;
    }
}

void MLB::fillContracts2(string fileName, int len)
{
    ifstream myFile;
    myFile.open(fileName);
    string arr[6];
    string years;
    string startYear;
    string endYear;
    string totalMoney;
    int index = 0;
    int nu = 0;
    if(myFile.is_open())
    {
        string line;
        while(getline(myFile,line))
        {
            
            for(int i = 0; i < 6; i++) //fill split array
            {
                arr[i] = "x";
            }
            split(line,',',arr,6);
            string name = "";
            bool n = true;
            for(int i = 0; i < arr[0].length(); i++) 
            {
                if(arr[0][i] == '(')
                {
                    n = false;
                }
                if(n == true)
                {
                    name += arr[0][i];
                }
 

            }
            name.erase(name.length()-1); //tested
            
            for(int i = 0; i < 693; i++)
            {
                if(Batters2019[i].getName() == name)
                {
                    Batters2019[i].setTotalYears(stoi(arr[1]));
                    Batters2019[i].setContractStartYear(stoi(arr[0].substr(name.length()+2,4)));
                    Batters2019[i].setContractEndYear(stoi(arr[0].substr(name.length()+7,4)));
                    //cout<<name<<" s: "<<Batters2019[i].getContractStartYear()<<" e: "<<Batters2019[i].getContractEndYear()<<" y: "<<Batters2019[i].getTotalYears()<<endl;
                    nu++;
                }
            }
            
        
        }
       
    }
    cout<<nu<<endl;
}

void MLB::displayRoster(string team, int year)
{
    bool SS = false;
    bool FBase = false; 
    bool SBase = false;
    bool TBase = false;
    bool C = false;
    int OF = 0;
    int lineup = 0;
    string p;
    int two;
    int three;
    int four;
    int five;
    int six;
    int seven;
    int eight;
    int nine;

    if(year == 2019)
    {
        cout<<"Starting Lineup 2019 Stats:"<<endl;
        for(int i = 0; i < 693; i++)
        {
            if(Batters2019[i].getTeam() == team && lineup < 9)
            {
                p = Batters2019[i].getPosition();
                if(p == "2B" && SBase == false)
                {
                    four = i;
                    SBase = true;
                    lineup++;
                }
                else if(p == "SS" && SS ==false)
                {
                    six = i;
                    SS = true;
                    lineup++;
                }
                else if(p == "C" && C == false)
                {
                    two = i;
                    C = true;
                    lineup++;
                }
                else if(p == "1B" && FBase == false)
                {
                    three = i;
                    FBase = true;
                    lineup++;
                }
                else if(p == "3B" && TBase == false)
                {
                    five = i;
                    TBase = true;
                    lineup++;
                }
                else if(p == "OF" && OF < 3)
                {
                    if(OF == 0)
                    {
                        seven = i;
                    }
                    else if(OF == 1)
                    {
                        eight = i;
                    }
                    else if(OF == 2)
                    {
                        nine = i;
                    }
                    OF++;
                    lineup++;

                }
            }
        }
        Batters2019[two].printBatterInfo();
        Batters2019[three].printBatterInfo();
        Batters2019[four].printBatterInfo();
        Batters2019[five].printBatterInfo();
        Batters2019[six].printBatterInfo();
        Batters2019[seven].printBatterInfo();
        Batters2019[eight].printBatterInfo();
        Batters2019[nine].printBatterInfo();
        cout<<endl;

        int SP = 0;
        int sp[5];
        int RP = 0;
        int rp[4];
        bool CL = false;
        int cl;
        for(int i = 0; i < 872; i++)
        {
            if(Pitchers2019[i].getTeam() == team && SP+RP+CL < 10)
            {
                if(Pitchers2019[i].getPosition() == "SP" && SP < 5)
                {
                    sp[SP] = i;
                    SP++;
                }
                else if(Pitchers2019[i].getPosition() == "RP" && RP < 4)
                {
                    rp[RP] = i;
                    RP++;
                }
                else if(Pitchers2019[i].getPosition() == "CL" && CL == false)
                {
                    cl = i;
                    CL = true;
                }
            }
        }
        cout<<"Starting Pitchers: "<<endl;
        for(int i = 0; i < 5; i++)
        {
            Pitchers2019[sp[i]].printPitcherInfo();
        }
        cout<<endl<<"Relief Pitchers:"<<endl;
        for(int i = 0; i< 4; i++)
        {
            Pitchers2019[rp[i]].printPitcherInfo();
        }
        Pitchers2019[cl].printPitcherInfo();

        

    }

    
}

void MLB::determineFreeAgents(int year, int Blen, int Plen)
{
    if(year == 2019)
    {
        for(int i = 0; i < Blen; i++)
        {
            if((Batters2019[i].getContractEndYear() == 2019  && Batters2019[i].getYears() >= 5) || Batters2019[i].getHasSalary() == false)
            {
                Batters2019[i].setIsFreeAgent(true);
            }
            else
            {
                Batters2019[i].setIsFreeAgent(false);
            }
        }
        for(int i = 0; i < Plen; i++)
        {
            if((Pitchers2019[i].getContractEndYear() == 2019 && Pitchers2019[i].getYears() >= 5 )|| Pitchers2019[i].getHasSalary() == false)
            {
                Pitchers2019[i].setIsFreeAgent(true);
            }
            else
            {
                Pitchers2019[i].setIsFreeAgent(false);
            }
        }
    }
    
}

void MLB::setTeams()
{
    league[0].setName("ARI");
    league[1].setName("ATL");
    league[2].setName("BAL");
    league[3].setName("BOS");
    league[4].setName("CWS");
    league[5].setName("CHC");
    league[6].setName("CIN");
    league[7].setName("CLE");
    league[8].setName("COL");
    league[9].setName("DET");
    league[10].setName("HOU");
    league[11].setName("KC");
    league[12].setName("LAA");
    league[13].setName("LAD");
    league[14].setName("MIA");
    league[15].setName("MIL");
    league[16].setName("MIN");
    league[17].setName("NYY");
    league[18].setName("NYM");
    league[19].setName("OAK");
    league[20].setName("PHI");
    league[21].setName("PIT");
    league[22].setName("SD");
    league[23].setName("SF");
    league[24].setName("SEA");
    league[25].setName("TB");
    league[26].setName("STL");
    league[27].setName("TEX");
    league[28].setName("TOR");
    league[29].setName("WAS");
    for(int i = 0; i < 30; i++)
    {   int cap = 0;
        
        league[i].setTeamNumber(i+1);
        int index = 0;
        int indexx = 0;
        for(int j = 0; j < 693; j ++)
        {
            if(Batters2019[j].getTeam() == league[i].getName())
            {
                if(Batters2019[j].getIsFreeAgent() == false)
                {
                    league[i].setBatter(Batters2019[j], index);
                    index++;
                }
                if(Batters2019[j].getHasSalary() == true)
                {
                    cap += Batters2019[j].getTotalMoney()/Batters2019[j].getTotalYears();
                }

                
            }
        }
       
        for(int k = 0; k < 872; k++)
        {
            if(Pitchers2019[k].getTeam() == league[i].getName())
            {
                if(Pitchers2019[k].getIsFreeAgent() == false)
                {
                    league[i].setPitcher(Pitchers2019[k],indexx);
                    indexx++;
                }
                if(Pitchers2019[k].getHasSalary() == true)
                {
                    cap+=Pitchers2019[k].getTotalMoney()/Pitchers2019[k].getTotalYears();
                }
 
            }
        }
        league[i].setCapSpace(cap);
    }

}


Team MLB::getTeam(int t)
{
    return league[t];
}

void MLB::setYears()
{
    int years;
    bool found;
    for(int i = 0; i < 693; i++)
    {
        years = 1;
        found = false;
        for(int j = 0; j < 688; j++)
        {
            if(found == false && Batters2018[j].getName() == Batters2019[i].getName())
            {
                years++;
                found = true;
            }
        }
        found = false;
        for(int j = 0; j < 675; j++)
        {
            if(found == false && Batters2017[j].getName() == Batters2019[i].getName())
            {
                years++;
                found = true;
            }
        }
        found = false;
        for(int j = 0; j < 677; j++)
        {
            if(found == false && Batters2016[j].getName() == Batters2019[i].getName() )
            {
                years++;
                found = true;
            }
        }
        found = false;
        for(int j = 0; j < 694; j++)
        {
            if(found == false && Batters2015[j].getName() == Batters2019[i].getName() )
            {
                years++;
                found = true;
            }
        }
        Batters2019[i].setYears(years);
        //cout<<Batters2019[i].getName()<<": "<<years<<endl;
    }
    
    for(int i = 0; i < 872; i++)
    {
        years = 1;
        found = false;
        for(int j = 0; j < 842; j++)
        {
            if(found == false && Pitchers2018[j].getName() == Pitchers2019[i].getName())
            {
                years++;
                found = true;
            }
        }
        found = false;
        for(int j = 0; j < 814; j++)
        {
            if(found == false && Pitchers2017[j].getName() == Pitchers2019[i].getName())
            {
                years++;
                found = true;
            }
        }
        found = false;
        for(int j = 0; j < 801; j++)
        {
            if(found == false && Pitchers2016[j].getName() == Pitchers2019[i].getName())
            {
                years++;
                found = true;
            }
        }
        found = false;
        for(int j = 0; j < 785; j++)
        {
            if(found == false && Pitchers2015[j].getName() == Pitchers2019[i].getName())
            {
                years++;
                found = true;
            }
        }
        Pitchers2019[i].setYears(years);
        //cout<<Pitchers2019[i].getName()<<": "<<years<<endl;
    }
}

void MLB::fillFreeAgency(Batter arr1[], Pitcher arr2[], string team, int arr[])
{
    int index = 0;
    
    
    for(int i = 0; i < 200; i++)
    {
        arr1[i] = Batter();
    }
    for(int i = 0; i < 693; i++)
    {
        if(Batters2019[i].getIsFreeAgent() == true && team != Batters2019[i].getTeam() && Batters2019[i].getContractEndYear() != 0)
        {
           
            arr1[index] = Batters2019[i];
            //arr1[index].showPreview();
            //cout<<endl;
            index++;
        }
    }
    arr[0] = index;
    index = 0;
    for(int i = 0; i < 872; i++)
    {
        if(Pitchers2019[i].getIsFreeAgent() == true && team != Pitchers2019[i].getTeam() && Pitchers2019[i].getContractEndYear() != 0)
        {
           
            arr2[index] = Pitchers2019[i];
            index++;
        }
    }
    
    arr[1] = index;
}

void MLB::showFreeAgency(bool isBatter, string position, Batter arr1[], Pitcher arr2[], Batter arr3[], Pitcher arr4[])
{
    for(int i = 0; i < 200 ; i++)
    {
        arr3[i] = Batter();
        arr4[i] = Pitcher();
    }
    int index = 1;
    cout<<"Type the player number to view player info"<<endl;
    if(isBatter == true)
    {
        if(position != "x")
        {
            for(int i = 0; i < 200; i++)
            {
                if(arr1[i].getName() != "x" && arr1[i].getPosition() == position)
                {
                    cout<<index<<". "<<arr1[i].getName()<<" Overall: "<<arr1[i].getOverall()<<endl;
                    arr3[index-1] = arr1[i];
                    index++;
                }
            }
        }
        else if(position == "x")
        {
            
            for(int i = 0; i < 200; i++)
            {
                if(arr1[i].getName() != "x")
                {
                    cout<<index<<". "<<arr1[i].getName()<<" Position: "<<arr1[i].getPosition()<<" Overall: "<<arr1[i].getOverall()<<endl;
                    arr3[index-1] = arr1[i];
                    index++;
                }
            }
        }
    }
    else if(isBatter == false)
    {
        if(position != "x")
        {
            for(int i = 0; i < 200; i++)
            {
                if(arr2[i].getName() != "x" && arr2[i].getPosition() == position)
                {
                    cout<<index<<". "<<arr2[i].getName()<<" Overall: "<<arr2[i].getOverall()<<endl;
                    arr4[index-1] = arr2[i];
                    index++;
                }
            }
        }
        else if(position == "x")
        {
            
            for(int i = 0; i < 200; i++)
            {
                if(arr2[i].getName() != "x")
                {
                    cout<<index<<". "<<arr2[i].getName()<<" Position: "<<arr2[i].getPosition()<<" Overall: "<<arr2[i].getOverall()<<endl;
                    arr4[index-1] = arr2[i];
                    index++;
                }
            }
        }
    }
}



void MLB::showAllStats(bool isBatter, string name)
{
    if(isBatter == true)
    {
        
        for(int i = 0 ; i < 693; i++)
        {
            if(Batters2019[i].getName() == name )
            {
                cout<<"Name: "<<Batters2019[i].getName();
                cout<<" Age: "<<Batters2019[i].getAge();
                cout<<" Position: "<<Batters2019[i].getPosition()<<" Contact: "<<Batters2019[i].getContact()<<" Power: "<<Batters2019[i].getPower()<<" Eye: "<<Batters2019[i].getEye()<<" Overall: "<<Batters2019[i].getOverall();
                if(Batters2019[i].getConsistency() != 0)
                {
                    cout<<" Consistency: "<<Batters2019[i].getConsistency();
                }
                cout<<endl;
                cout<<"Year: 2019";
                Batters2019[i].printAllInfo();
            }
        }
        cout<<endl;
        for(int i = 0; i < 688; i++)
        {
            if(Batters2018[i].getName() == name )
            {
                cout<<"Year: 2018";
                Batters2018[i].printAllInfo();
            }
        }
        cout<<endl;
        for(int i = 0; i < 675; i++)
        {
            if(Batters2017[i].getName() == name )
            {
                cout<<"Year: 2017";
                Batters2017[i].printAllInfo();
            }
        }
        cout<<endl;
        for(int i = 0; i < 677; i++)
        {
            if(Batters2016[i].getName() == name )
            {
                cout<<"Year: 2016";
                Batters2016[i].printAllInfo();
            }
        }
        cout<<endl;
        for(int i = 0; i < 694; i++)
        {
            if(Batters2015[i].getName() == name )
            {
                cout<<"Year: 2015";
                Batters2015[i].printAllInfo();
            }
        }
        cout<<endl;
        
    }
    else
    {
        for(int i = 0 ; i < 872; i++)
        {
            if(Pitchers2019[i].getName() == name )
            {
                cout<<setprecision(3);
                cout<<"Name: "<<Pitchers2019[i].getName();
                cout<<" Age: "<<Pitchers2019[i].getAge();
                cout<<" Position: "<<Pitchers2019[i].getPosition();
                cout<<" Command: "<<Pitchers2019[i].getCommand()<<" Strikeout Rate: "<<Pitchers2019[i].getKRate()<<" Stamina: "<<Pitchers2019[i].getStamina()<<" Groundball Rate: "<<Pitchers2019[i].getGBRate()<<" Overall: "<<Pitchers2019[i].getOverall()<<endl;
                cout<<"Year: 2019 ";
                Pitchers2019[i].printAllInfo();
            }
        }
        cout<<endl;
        for(int i = 0; i < 842; i++)
        {
            if(Pitchers2018[i].getName() == name )
            {
                cout<<"Year: 2018";
                Pitchers2018[i].printAllInfo();
            }
        }
        cout<<endl;
        for(int i = 0; i < 814; i++)
        {
            if(Pitchers2017[i].getName() == name )
            {
                cout<<"Year: 2017";
                Pitchers2017[i].printAllInfo();
            }
        }
        cout<<endl;
        for(int i = 0; i < 801; i++)
        {
            if(Pitchers2016[i].getName() == name )
            {
                cout<<"Year: 2016";
                Pitchers2016[i].printAllInfo();
            }
        }
        cout<<endl;
        for(int i = 0; i < 785; i++)
        {
            if(Pitchers2015[i].getName() == name )
            {
                cout<<"Year: 2015";
                Pitchers2015[i].printAllInfo();
            }
        }
        cout<<endl;
    }
    
}

int MLB::estimateValue(bool isBatter, string name)
{
    return 0;
}

void MLB::setStats()
{
    boost::math::normal norm;
    
    // double slugmean = 0;
    // double slugstd = 0;
    // double slugz;

    // double hrmean = 0;
    double pa;
    // double hrstd = 0;
    // double hrz;

    double xbmean = 0;
    double xbstd = 0;
    double xbz;

    double conmean = 0;
    double constd = 0;
    double conz;

    double eyemean = 0;
    double eyestd = 0;
    double eyez;

    int len = 0;
    for(int i = 0; i < 693; i++)
    {
        if(isnan(Batters2019[i].getSlug()) == false && Batters2019[i].getAtBats() > 50)
        {
            //slugmean += Batters2019[i].getSlug();
            pa = Batters2019[i].getAtBats()+Batters2019[i].getWalks()+Batters2019[i].getHitByPitch()+Batters2019[i].getHits();
            //hrmean += ((double)Batters2019[i].getHomeRuns())/((double)pa);
            xbmean += ((1.268*(double)Batters2019[i].getDoubles() + 1.610*(double)Batters2019[i].getTriples() + 2.086*(double)Batters2019[i].getHomeRuns())/((double)Batters2019[i].getAtBats()));
            conmean += Batters2019[i].getAVG();
            eyemean += (double)(Batters2019[i].getWalks()+Batters2019[i].getHitByPitch()) / pa;
            len++;
        }

    }
    // slugmean = (slugmean)/((double)(len));
    // hrmean = (hrmean)/((double)(len));
    xbmean = xbmean / (double)len;
    conmean = conmean/(double)len;
    eyemean = eyemean / len;
    //cout<<"mean: "<<eyemean<<endl;
    for(int i = 0; i < 693; i++)
    {
        if(isnan(Batters2019[i].getSlug()) == false && Batters2019[i].getAtBats() > 50)
        {
            pa = Batters2019[i].getAtBats()+Batters2019[i].getWalks()+Batters2019[i].getHitByPitch()+Batters2019[i].getHits();
            //slugstd += pow(Batters2019[i].getSlug()-slugmean,2);
            //hrstd += pow((double)((double)Batters2019[i].getHomeRuns())/((double)(Batters2019[i].getAtBats()+Batters2019[i].getWalks()+Batters2019[i].getHitByPitch()+Batters2019[i].getHits()))-hrmean,2);
            xbstd += pow(((1.268*(double)Batters2019[i].getDoubles() + 1.610*(double)Batters2019[i].getTriples() + 2.086*(double)Batters2019[i].getHomeRuns()) / ((double)(Batters2019[i].getAtBats()))) - xbmean, 2);
            constd += pow((Batters2019[i].getAVG() - conmean),2);
            eyestd += pow(((double)(Batters2019[i].getWalks()+Batters2019[i].getHitByPitch()) / pa)-eyemean,2);
        }
    }
    //slugstd = sqrt(((double)slugstd/(double)len));
    //hrstd = sqrt((double)(hrstd/((double)len)));
    xbstd = sqrt((double)(xbstd)/len);
    constd = sqrt(constd/(double)len);
    eyestd = sqrt(eyestd/len);
    //cout<<"std: "<<eyestd<<endl;
    for(int i = 0; i < 693; i++)
    {
        if(Batters2019[i].getAtBats() > 50)
        {
            pa = Batters2019[i].getAtBats()+Batters2019[i].getWalks()+Batters2019[i].getHitByPitch()+Batters2019[i].getHits();
            //slugz = ((double)Batters2019[i].getSlug()-(double)slugmean)/(double)slugstd;
           // pa = Batters2019[i].getAtBats()+Batters2019[i].getWalks()+Batters2019[i].getHitByPitch()+Batters2019[i].getHits();
            //hrz = ((((double)Batters2019[i].getHomeRuns()/pa) - hrmean)/hrstd);
            xbz = ((((1.268*(double)Batters2019[i].getDoubles() + 1.610*(double)Batters2019[i].getTriples() + 2.086*(double)Batters2019[i].getHomeRuns())/((double)Batters2019[i].getAtBats()))) - xbmean) / xbstd;
            conz = ((Batters2019[i].getAVG() - conmean)/constd);
            eyez = ((((double)(Batters2019[i].getWalks()+Batters2019[i].getHitByPitch()) / pa)-eyemean)/eyestd);
            //cout<<Batters2019[i].getName()<<": "<<100*cdf(complement(norm,-1*eyez))<<" rate: "<<(double)(Batters2019[i].getWalks()+Batters2019[i].getHitByPitch())/pa<<endl;
            Batters2019[i].setPower(((int)100*cdf(complement(norm,-1*xbz)))+0.5);
            Batters2019[i].setContact((int)100*cdf(complement(norm,-1*conz))+0.5);
            Batters2019[i].setEye((int)100*cdf(complement(norm,-1*eyez))+0.5);
            
            
        }
        else
        {
            //cout<<i<<Batters2019[i].getName()<<endl;
            Batters2019[i].setPower(0);
            Batters2019[i].setContact(0);
            Batters2019[i].setEye(0);
        }
    }


    
    double kmean1 = 0; //sp stats
    double kstd1 = 0;
    double kz1;

    double smean1 = 0; // sp stats
    double sstd1 = 0;
    double sz1;

    double cmean1 = 0; //sp stats
    double cstd1 = 0;
    double cz1;

    double gbmean = 0;
    double gbstd = 0;
    double gbz;

    double kmean2 = 0; //rp stats
    double kstd2 = 0;
    double kz2;

    double smean2 = 0; //rp
    double sstd2 = 0;
    double sz2;


    double cmean2 = 0; //rp stats
    double cstd2 = 0;
    double cz2;

    double stmean = 0;
    double ststd = 0;
    double stz;

    int count = 0;
    int count2 = 0;

    for(int i = 0; i < 872; i++)
    {
        if(Pitchers2019[i].getPosition() == "SP" && Pitchers2019[i].getIP() > 20)
        {
            if((double)Pitchers2019[i].getGamesStarted()/(double)Pitchers2019[i].getGamesPlayed() < 1)
            {
                smean1 += (double)Pitchers2019[i].getIP()/(double)Pitchers2019[i].getGamesStarted();
            }
            else
            {
                smean1 += (double)Pitchers2019[i].getIP()/(double)Pitchers2019[i].getGamesStarted();
            }
            
            kmean1 += (double)Pitchers2019[i].getKs()/(double)Pitchers2019[i].getIP();
            cmean1 += (double)Pitchers2019[i].getWhip();
            gbmean += (double)Pitchers2019[i].getHRs()/ (double)Pitchers2019[i].getHits();
            count++;

        }
        else if(Pitchers2019[i].getPosition() != "SP" && Pitchers2019[i].getIP() > 20)
        {
            kmean2 += (double)Pitchers2019[i].getKs()/(double)Pitchers2019[i].getIP();
            smean2 += (double)Pitchers2019[i].getHRs()/ (double)Pitchers2019[i].getHits();
            cmean2 += (double)Pitchers2019[i].getWhip();
            stmean += (double)Pitchers2019[i].getIP()/(double)Pitchers2019[i].getGamesPlayed();
            count2++;
        }
    }
    kmean1 = kmean1/ (double)count;
    smean1 = smean1 / (double)count;
    cmean1 = cmean1 / (double)count;
    gbmean = gbmean / (double)count;

    kmean2 = kmean2/ (double)count2;
    smean2 = smean2 / (double)count2;
    cmean2 = cmean2 / (double)count2;
    stmean = stmean / (double)count2;

    // cout<<"kmean "<<kmean2<<endl;
    // cout<<"smean "<<smean2<<endl;
    // cout<<"cmean "<<cmean2<<endl;
    for(int i = 0; i < 872; i++)
    {
        if(Pitchers2019[i].getPosition() == "SP" && Pitchers2019[i].getIP() > 20)
        {
           kstd1 += pow(((double)Pitchers2019[i].getKs()/(double)Pitchers2019[i].getIP()) - kmean1, 2);
           sstd1 += pow(((double)Pitchers2019[i].getIP()/(double)Pitchers2019[i].getGamesStarted())- smean1,2);
           cstd1 += pow(Pitchers2019[i].getWhip() - cmean1,2);
            gbstd += pow(((double)Pitchers2019[i].getHRs()/ (double)Pitchers2019[i].getHits()) - gbmean,2);
            
        }
        else if(Pitchers2019[i].getPosition() != "SP" && Pitchers2019[i].getIP() > 20)
        {
            kstd2 += pow(((double)Pitchers2019[i].getKs()/(double)Pitchers2019[i].getIP()) - kmean2,2);
            sstd2 += pow(((double)Pitchers2019[i].getHRs()/ (double)Pitchers2019[i].getHits()) - smean2,2);
            cstd2 += pow((double)Pitchers2019[i].getWhip() -cmean2, 2);
            ststd += pow(((double)Pitchers2019[i].getIP()/(double)Pitchers2019[i].getGamesPlayed())- stmean,2);
            
        }
        
    }
    kstd1 = sqrt(kstd1/(double)count);
    sstd1 = sqrt(sstd1/(double)count);
    cstd1 = sqrt(cstd1/(double)count);
    gbstd = sqrt(gbstd/(double)count);

    kstd2 = sqrt(kstd2/(double)count2);
    sstd2 = sqrt(sstd2/(double)count2);
    cstd2 = sqrt(cstd2/(double)count2);
    ststd = sqrt(ststd/(double)count2);
    // cout<<"kstd "<<kstd2<<endl;
    // cout<<"sstd "<<sstd2<<endl;
    // cout<<"cstd "<<cstd2<<endl;
     for(int i = 0; i < 872; i++)
    {
        if(Pitchers2019[i].getPosition() == "SP" && Pitchers2019[i].getIP() > 20)
        {
            kz1 = ((double)Pitchers2019[i].getKs()/(double)Pitchers2019[i].getIP() - kmean1) / kstd1;
            sz1 = ((double)Pitchers2019[i].getIP()/(double)Pitchers2019[i].getGamesStarted() - smean1) / sstd1;
            cz1 = (Pitchers2019[i].getWhip() - cmean1) / cstd1;
            gbz = ((double)Pitchers2019[i].getHRs()/ (double)Pitchers2019[i].getHits() - gbmean) / gbstd;
            Pitchers2019[i].setKRate(((int)100*cdf(complement(norm,-1*kz1)))+0.5);
            Pitchers2019[i].setStamina((int)100*cdf(complement(norm,-1*sz1))+0.5);
            Pitchers2019[i].setCommand((int)100*cdf(complement(norm,cz1))+0.5);
            Pitchers2019[i].setGBRate((int)100*cdf(complement(norm,gbz))+0.5);
        }
        else if(Pitchers2019[i].getPosition() != "SP" && Pitchers2019[i].getIP() > 20)
        {
            kz2 = ((double)Pitchers2019[i].getKs()/(double)Pitchers2019[i].getIP() - kmean2) / kstd2; //krate
            sz2 = ((double)Pitchers2019[i].getHRs()/(double)Pitchers2019[i].getHits() - smean2) / sstd2; //gb rate
            cz2 = (Pitchers2019[i].getWhip() - cmean1) / cstd1; //command
            stz = ((double)Pitchers2019[i].getIP()/(double)Pitchers2019[i].getGamesPlayed() - stmean) / ststd; //stamina
            Pitchers2019[i].setKRate(((int)100*cdf(complement(norm,-1*kz2)))+0.5);
            Pitchers2019[i].setStamina((int)100*cdf(complement(norm,-1*stz))+0.5);
            Pitchers2019[i].setCommand((int)100*cdf(complement(norm,cz2))+0.5);
            Pitchers2019[i].setGBRate((int)100*cdf(complement(norm,sz2))+0.5);
            
            

        }
        else
        {
            Pitchers2019[i].setStamina(0);
            Pitchers2019[i].setKRate(0);
            Pitchers2019[i].setCommand(0);
            kz1 = 0;
            sz1 = 0;
            cz1 = 0;
        }
        // cout<<i;
        // Pitchers2019[i].showPreview();
        // cout<<" IP:"<<Pitchers2019[i].getIP();
        // cout<<" Games: "<<Pitchers2019[i].getGamesPlayed();
        // //cout<<Pitchers2019[i].getName()<<"kz: "<<kz1<<" sz1: "<<sz1<<" cz1: "<<cz1;
        // cout<<endl;
    }    
}

void MLB::setConsistency()
{
    boost::math::normal norm;
    double arr[693];
    double meann = 0;
    double stdd = 0;
    int count = 0;
    int  x = 0;
    for(int i = 0; i < 693; i++)
    {
        double mean = 0;
        double std = 0;
        bool found = false;
        arr[i] = 0;
        bool one = false;
        bool two = false;
        bool three = false;
        bool four = false;
        bool five = false;
        string name = Batters2019[i].getName();
        //cout<<i<<endl;
        if(found == false && Batters2019[i].getYears() == 1)
        {   
            Batters2019[i].setConsistency(0);
            //cout<<name;
            //arr[i] = 0;
            x++;
            found = true;
        }
        else if(Batters2019[i].getYears() == 2)
        {
            for(int j = 0; j < 688; j++)
            {
                if(found == false && Batters2018[j].getName() == name)
                {
                    int n = 0;
                    if(Batters2019[i].getAtBats() > 100)
                    {
                        mean += Batters2019[i].getOPS();
                        n++;
                        one = true;
                    }
                    if(Batters2018[j].getAtBats() > 100)
                    {
                        mean += Batters2018[j].getOPS();
                        n++;
                        two = true;
                    }
                   
                    if(n > 1)
                    {
                        mean = mean / (double)n;
                        if(two == true)
                        {
                            std += pow(Batters2018[j].getOPS()-mean,2);
                        }
                        if(one == true)
                        {
                            std += pow(Batters2019[i].getOPS()-mean,2);
                        }
                        
                        std = sqrt(std/(double)n);
                        arr[i] = std;
                    }
                    found = true;
                    x++;
                    //cout<<i<<Batters2019[i].getName()<<std<<"   "<<mean<<endl;
                }
                
            }
        }
        else if(Batters2019[i].getYears() == 3)
        {
            for(int j = 0; j < 688; j++)
            {
                if(found == false && Batters2018[j].getName() == name)
                {
                    
                    for(int k = 0; k < 675; k++)
                    {
                        if(found == false && Batters2017[k].getName() == name)
                        {
                            int n = 0;
                            if(Batters2019[i].getAtBats() > 100)
                            {
                                mean += Batters2019[i].getOPS();
                                n++;
                                one = true;
                            }
                            if(Batters2018[j].getAtBats() > 100)
                            {
                                mean += Batters2018[j].getOPS();
                                n++;
                                two = true;
                            }
                            if(Batters2017[k].getAtBats() > 100)
                            {
                                mean += Batters2017[k].getOPS();
                                n++;
                                three = true;
                            }
                            if(n > 1)
                            {
                                mean = mean / (double)n;
                                if(two == true)
                                {
                                    std += pow(Batters2018[j].getOPS()-mean,2);
                                }
                                if(one == true)
                                {
                                    std += pow(Batters2019[i].getOPS()-mean,2);
                                }
                                if(three == true)
                                {
                                    std += pow(Batters2017[k].getOPS()-mean,2);
                                }
                                std = sqrt(std/(double)n);
                                arr[i] = std;
                            }
                            found = true;
                            x++;
                            //cout<<i<<Batters2019[i].getName()<<std<<"   "<<mean<<endl;
                        }
                    }
                }
            } 
        }
        else if(Batters2019[i].getYears() == 4)
        {
            for(int j = 0; j < 688; j++)
            {
                if(found == false && Batters2018[j].getName() == name)
                {
                    for(int k = 0; k < 675; k++)
                    {
                        if(found == false &&Batters2017[k].getName() == name)
                        {
                            for(int l = 0; l < 677; l++)
                            {
                                if(found == false && Batters2016[l].getName() == name)
                                {
                                    int n = 0;
                                    if(Batters2019[i].getAtBats() > 100)
                                    {
                                        mean += Batters2019[i].getOPS();
                                        n++;
                                        one = true;
                                    }
                                    if(Batters2018[j].getAtBats() > 100)
                                    {
                                        mean += Batters2018[j].getOPS();
                                        n++;
                                        two = true;
                                    }
                                    if(Batters2017[k].getAtBats() > 100)
                                    {
                                        mean += Batters2017[k].getOPS();
                                        n++;
                                        three = true;
                                    }
                                    if(Batters2016[l].getAtBats() > 100)
                                    {
                                        mean += Batters2016[l].getOPS();
                                        n++;
                                        four = true;
                                    }
                                    if(n > 1)
                                    {
                                        mean = mean / (double)n;
                                        if(two == true)
                                        {
                                            std += pow(Batters2018[j].getOPS()-mean,2);
                                        }
                                        if(one == true)
                                        {
                                            std += pow(Batters2019[i].getOPS()-mean,2);
                                        }
                                        if(three == true)
                                        {
                                            std += pow(Batters2017[k].getOPS()-mean,2);
                                        }
                                        if(four== true)
                                        {
                                            std += pow(Batters2016[l].getOPS()-mean,2);
                                        }
                                        
                                        std = sqrt(std/(double)n);
                                        arr[i] = std;
                                    }
                                    found = true;
                                    x++;
                                    //cout<<i<<Batters2019[i].getName()<<std<<"   "<<mean<<endl;
                                    //cout<<name<<endl;
                                }
                            }
                        }
                    }
                }
            } 
        }
        else if(Batters2019[i].getYears() == 5)
        {
            for(int j = 0; j < 688; j++)
            {
                if(found == false && Batters2018[j].getName() == name)
                {
                    for(int k = 0; k < 675; k++)
                    {
                        if(found == false && Batters2017[k].getName() == name)
                        {
                            for(int l = 0; l < 677; l++)
                            {
                                if(found == false && Batters2016[l].getName() == name)
                                {
                                    for(int m = 0; m < 694; m++)
                                    {
                                        if(found == false && Batters2015[m].getName() == name)
                                        {
                                            
                                            int n = 0;
                                            if(Batters2019[i].getAtBats() > 100)
                                            {
                                                mean += Batters2019[i].getOPS();
                                                n++;
                                                one = true;
                                            }
                                            if(Batters2018[j].getAtBats() > 100)
                                            {
                                                mean += Batters2018[j].getOPS();
                                                n++;
                                                two = true;
                                            }
                                            if(Batters2017[k].getAtBats() > 100)
                                            {
                                                mean += Batters2017[k].getOPS();
                                                n++;
                                                three = true;
                                            }
                                            if(Batters2016[l].getAtBats() > 100)
                                            {
                                                mean += Batters2016[l].getOPS();
                                                n++;
                                                four = true;
                                            }
                                            if(Batters2015[m].getAtBats() > 100)
                                            {
                                                mean += Batters2015[m].getOPS();
                                                n++;
                                                five = true;
                                            }
                                            if(n > 1)
                                            {
                                                mean = mean / (double)n;
                                                if(two == true)
                                                {
                                                    std += pow(Batters2018[j].getOPS()-mean,2);
                                                }
                                                if(one == true)
                                                {
                                                    std += pow(Batters2019[i].getOPS()-mean,2);
                                                }
                                                if(three == true)
                                                {
                                                    std += pow(Batters2017[k].getOPS()-mean,2);
                                                }
                                                if(four== true)
                                                {
                                                    std += pow(Batters2016[l].getOPS()-mean,2);
                                                }
                                                if(five  == true)
                                                {
                                                    std += pow(Batters2015[m].getOPS()-mean,2);
                                                }
                                                
                                                std = sqrt(std/(double)n);
                                                arr[i] = std;
                                            }
                                            found = true;
                                            x++;
                                            //cout<<i<<Batters2019[i].getName()<<std<<"   "<<mean<<endl;
                                            //cout<<name<<endl;
                                        }
                                        
                                    }
                                }
                            }
                        }
                    }
                }
            } 
        }
        if(isnan(arr[i]) == false && found == true && arr[i] != 0)
        {
            meann += arr[i];
            count++;
        }
    }
    //cout<<"xxxxxx"<<endl;
    meann = meann / (double)(count);
    for(int i = 0; i < 693; i++)
    {
        if(isnan(arr[i]) == false && arr[i] != 0 && isinf(arr[i]) != 1)
        {
            stdd += pow(arr[i] - meann,2);
            //cout<<i<<".  "<<stdd<<".    "<<Batters2019[i].getYears()<<endl;
        }
    }
    stdd = sqrt(stdd/(double)(count));
    //cout<<"mean: "<<meann<<"   "<<x<<endl;
    //cout<<"std: "<<stdd<<endl;
    double z;
    for(int i = 0; i < 693; i++)
    {
        z = (arr[i]-meann)/stdd;
        
        if(isnan(z) == false && arr[i] != 0)
        {
            Batters2019[i].setConsistency((int)100*cdf(complement(norm,z))+0.5);
        }
        //cout<<Batters2019[i].getName()<<Batters2019[i].getConsistency()<<" z: "<<z<<" std: "<<arr[i]<<endl;
    }
}


void MLB::fillNames()
{
    ifstream myFile;
    myFile.open("firstNames.csv");
    int index = 0;
    string line;
    if(myFile.is_open())
    {
        while(getline(myFile,line))
        {
            if(index < 3000)
            {
                bool comma = false;
                string name = "";
                for(int i = 0; i < line.length(); i++)
                {
                    if(line[i] == ',')
                    {
                        comma = true;
                    }
                    if(comma == false)
                    {
                        name += line[i];
                    }
                    
                }
                
                firstNames[index] = name;
                index++;
            
            }
        }
    }
    myFile.close();

    ifstream myFile2;
    myFile2.open("lastNames.txt");
    index = 0;
    int i = 0;
    if(myFile2.is_open())
    {
        
        while(getline(myFile2,line))
        {
            if(i < 11099)
            {
                if((index + 1) % 8 == 0)
                {
                    lastNames[i] = line;
                    i++;
                }
                index++;
            }
            
        }
    }
    myFile.close();
}

string MLB::generateName()
{
    
    int x = rand()%1000;
    int y = rand()%11099;
    return firstNames[x] + " " + lastNames[y];
}

void MLB::setProspects(int x, Batter arr1[], Pitcher arr2[])
{
    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            int random = rand()%100+1; //1 - 100
            int position = rand()%8+2; //2-9
            Batter x1 = Batter();
            x1.setName(generateName());
            x1.setAge(rand()%8 + 19);
            if(position == 2)
            {
                x1.setPosition("C");
            }
            else if(position == 3)
            {
                x1.setPosition("1B");
            }
            else if(position == 4)
            {
                x1.setPosition("2B");

            }
             else if(position == 5)
            {
                x1.setPosition("3B");

            }
             else if(position == 6)
            {
                x1.setPosition("SS");

            }
             else if(position == 7)
            {
                x1.setPosition("OF");

            }
             else if(position == 8)
            {
                x1.setPosition("OF");

            }
             else if(position == 9)
            {
                x1.setPosition("OF");

            }
            
            if(random <= 2) //really good prospect 1% chance
            {
                x1.setContact(rand()%40 + 60);
                x1.setPower(rand()%40 + 60);
                x1.setEye(rand()%40 + 60);
            }
            else if(random < 20) //2-11 10%, two per team
            {
                x1.setContact(rand()%45 + 25);
                x1.setPower(rand()%45 + 25);
                x1.setEye(rand()%45 + 25);
            }
            else if(random < 42) // 22% chance
            {
                x1.setContact(rand()%40 + 10);
                x1.setPower(rand()%40 + 10);
                x1.setEye(rand()%40 + 10);
            }
            else if(random < 62) //20% chance
            {
                x1.setContact(rand()%35 + 5);
                x1.setPower(rand()%35 + 5);
                x1.setEye(rand()%35 + 5);
            }
            else //39%
            {
                x1.setContact(rand() % 30 + 1);
                x1.setPower(rand() % 30 + 1);
                x1.setEye(rand() % 30 + 1);

            }
            if(i+1 == x)
            {
                arr1[j] = x1;
            }
            x1.setConsistency(0);
            league[i].setBProspect(x1,j);
        }
        

    }


    for(int i = 0; i < 30; i++) //league
    {
        bool hasCloser = false;
        for(int j = 0; j < 20; j++) //team
        {
            
            int random = rand()%100+1; //1 - 100
            Pitcher x2 = Pitcher();
            x2.setName(generateName());
            x2.setAge(rand()%8 + 19);
            int position = rand()%13+1;
            string p;
            //cout<<position<<endl;
            
            if(position < 6)
            {
                p = "SP";
                //cout<<"yyy"<<endl;
            }
            else if(position < 13)
            {
                p = "RP";
                //cout<<"zzz"<<endl;
            } 
            else if(position == 13)
            {
                if(hasCloser == false)
                {
                    p = "CL";
                    hasCloser = true;
                    //cout<<"aaa"<<endl;
                }
                else
                {
                    p =  "RP";
                    //cout<<"bbb"<<endl;
                }
               
            }
            
            x2.setPosition(p);
            if(random <= 2) //really good prospect 1% chance
            {
                x2.setCommand(rand()%40 + 60);
                x2.setKRate(rand()%40 + 60);
                x2.setGBRate(rand()%40 + 60);
                x2.setStamina(rand()%40 + 60);
            }
            else if(random < 20) //2-11 10%, two per team
            {
                x2.setCommand(rand()%45 + 25);
                x2.setKRate(rand()%45 + 25);
                x2.setGBRate(rand()%45 + 25);
                x2.setStamina(rand()%45 + 25);
            }
            else if(random < 42) // 22% chance
            {
                x2.setCommand(rand()%40 + 10);
                x2.setKRate(rand()%40 + 10);
                x2.setGBRate(rand()%40 + 10);
                x2.setStamina(rand()%40 + 10);
                


            }
            else if(random < 62) //20% chance
            {
                x2.setCommand(rand()%35 + 5);
                x2.setKRate(rand()%35 + 5);
                x2.setGBRate(rand()%35 + 5);
                x2.setStamina(rand()%35 + 5);
            }
            else //39%
            {
                x2.setCommand(rand() % 30 + 1);
                x2.setKRate(rand() % 30 + 1);
                x2.setGBRate(rand() % 30 + 1);
                x2.setStamina(rand() % 30 + 1);

            }
            if(i+1 == x)
            {
                arr2[j] = x2;
            }
            league[i].setPProspect(x2,j);
        }
        

    }
}

void MLB::viewPreviousContract(bool isBatter,string name)
{
    if(isBatter == true)
    {
        for(int i = 0 ; i < 693; i++)
        {
            if(Batters2019[i].getName() == name)
            {
                if(Batters2019[i].getHasSalary() == true)
                {
                    Batters2019[i].printContractInfo();
                }
                else
                {
                    cout<<"Previous Contract not available.";
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < 872; i++)
        {
            if(Pitchers2019[i].getName() == name)
            {
                if(Pitchers2019[i].getHasSalary() == true)
                {
                    Pitchers2019[i].printContractInfo();
                }
                else
                {
                    cout<<"Previous Contract not available.";
                }
            }  
        }
    }
}



    
