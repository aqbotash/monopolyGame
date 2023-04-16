#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <windows.h> 
using namespace std;
#include <stdio.h>
#include <vector>
#include <thread>

class Player{
public:
 string Name;
 int Money;
 int Position;
 bool gameOn = true;
 Player(string name, int money){
   Name = name;
   Money = money;
   Position = 0;
 }
};

int IncomeTax(int money){
  int tax = money/10;
  money -=tax;
  return money;
}
// 5 Chance methods
int chance1(){
  cout<<"You must treat Naruto and his friends with ramen, and you should pay 500 dollars";
  return -500;
}

int chance2(){
  cout<<"You must go to task with Kakasi's group, and you will receive 700 dollars";
  return 700;
}

int chance3(){
  cout<<"You must play Chess with Shikamaru Naara. You will spend 200 dollars to buy snacks to eat furing the play.";
  return -200;
}

int chance4(){
  cout<<"You are under the influence of Amaterasu of Sasuke and you should pay 1000 dollars to get rid of it.";
 return -1000;
}
int chance5(){
  cout<<"You must receive a gift of 5 kage, which is 1500 dollars.";
  return 1500;
}



//Creating vector of methods of Chances
vector<int (*)()> chanceMethods = {&chance1, &chance2, &chance3, &chance4, &chance5};

vector<string> spaces = {"Go", "Strana Tumana", "Hidden cloud village", "Strana Ognya", "Income Tax", "Konoha", "Strana Ovoshei","Chance","Strana dozhdya", "Strana Peska", "Visit Jail", "Ubezhishe Oratimaru", "Strana Vetra", "Strana Vody","Strana Zemli", "Strana Zvuka", "Strana Molnii", "Chance","Strana Zhelezy","Strana Neba" "Free Parking", "Strana skrytogo kamnya", "Chance", "Strana skrytoi luny","Деревня скрытого водопада", "Деревня скрытой дымки", "Country of Snow", "Country of Iron", "Derevnya skrytyh dolin", "1", "Go to jail","2", "3","Community chance", "4","5", "Chance", "6","7","8"};

vector<string> owners ={"X","no", "no","no","X","no","no", "X", "no", "no", "X","no","no","no","no","no","no","X","no","no","free","no","X","no","no","no","no","no","no","no","X","no","no","X", "no","no","X", "no","no","no"};



int main() {

  //Intro
  cout<<"Salem"<<endl;
  string nameOfPlayer;
  int money=200000;
  int numOfPlayers;
  cout<<"Please, enter the number of players: ";
  cin>>numOfPlayers;
  vector<Player> players;


  
  //Creating players
  for(int i=0;i<numOfPlayers;i++){
    cout<<"Enter the name of player"<<to_string(i+1)<<":";
    cin>>nameOfPlayer;
    Player player(nameOfPlayer, money);
    players.push_back(player);
    cout<<players[i].Name<<", you are player"<<to_string(i+1)<<". Your current amount of money is "<<players[i].Money<<endl; 
  }
  
  
  //Game start
  bool game = true;
  int index=0;
  //Chances count index;
  int chanceIndex=0;
  while(game){
    
    //Rolling die and identifying number of steps
  cout<<"Rolling die for "<<" "<<players[index].Name<<endl;
  Sleep(3);
  int steps = rand()%6+1;
  cout<<"You are stepping "<<steps<<" steps"<<endl;
    
    //Regulating position of a player
    if(players[index].Position+steps>39) {
      players[index].Position = players[index].Position%10;
        }
    else players[index].Position = steps;
    cout<<"Your are in "<<spaces[players[index].Position]<< " "<< endl;

    
    // Conditions
    if(spaces[players[index].Position] == "Income Tax"){
      cout<<"You should pay Income Tax";
      players[index].Money=IncomeTax(players[index].Money);
    }
    else if(owners[players[index].Position]=="Y" ){
      cout<<"You should rent this place for 200 dollars"<<endl;
      players[index].Money -=200;
    }
    else if(spaces[players[index].Position] == "Chance"){
      if(chanceIndex>=chanceMethods.size()) cout<<"There is no chance cards left. You are free to go!"<<endl;
      else {
        chanceMethods[chanceIndex]();
        players[index].Money += chanceMethods[chanceIndex]();
      }
      chanceIndex++;
    }
    else if(spaces[players[index].Position]=="Free Parking"){
      cout<<"This is Free Parking. You mus not pay anything"<<endl;
    }
    else {
      cout<<"Will you buy this property?";
      bool yes;
      cin>>yes;
      if(yes){
        players[index].Money -=200;
        owners[players[index].Position] = "Y";
      } 
    }
    
    //Printing player's current money
    cout<<"Your money is "<< players[index].Money<<endl;

    //Check if player can continue the game
    if(players[index].Money<=0){
      players[index].gameOn = false;
      numOfPlayers--;
      players.erase(players.begin()+index);
    }

    
    //iterating players
    index++;
    //resetting index
    if(index==numOfPlayers) index=0;

    if(players.size()==0){
      game = false;
      cout<<"Game over! The winner is "<<players[0].Name;
      
    } 
    Sleep(2);
  }
  
}