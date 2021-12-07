#include "printMoney.cpp"
#include "Batter.cpp"
#include "Pitcher.cpp"
#include "MLB.cpp"
#include "Player.cpp"
#include "Team.cpp"
#include <iostream>
#include <math.h>
#include <unistd.h>
#include <boost/math/special_functions/sign.hpp>
#include <boost/math/distributions/normal.hpp>
using namespace std;


int main()
{
    srand (time(0));
    MLB m;
    Player p;
    m.fillPitcherStats("Pitchers2019.csv",2019,872);
    m.fillPitcherStats("Pitchers2018.csv",2018,842);
    m.fillPitcherStats("Pitchers2017.csv",2017,814);
    m.fillPitcherStats("Pitchers2016.csv",2016,801);
    m.fillPitcherStats("Pitchers2015.csv",2015,785);
    m.fillBatterStats("Batters2019.csv",2019, 693);
    m.fillBatterStats("Batters2018.csv",2018,688);
    m.fillBatterStats("Batters2017.csv",2017,675);
    m.fillBatterStats("Batters2016.csv",2016,677);
    m.fillBatterStats("Batters2015.csv",2015,694);
    m.fillContracts("Contracts2019.csv",693,true);
    m.fillContracts("Contracts2019.csv",872,false);
    m.setTeams();
    m.setYears();
    m.determineFreeAgents(2019,693,872);
    m.setStats();
    m.setConsistency();
    m.fillNames();
    


   
    Batter arr1[20];
    Pitcher arr2[20];
    m.setProspects(20,arr1, arr2);
    for(int j = 0; j < 30; j++)
    {
        for(int i = 0; i < 20; i++)
        {
            m.getTeam(j).getPProspect(i).showPreview();
            cout<<endl;
        }
        cout<<endl<<endl<<endl;
    }
 
    
       







   
    
}