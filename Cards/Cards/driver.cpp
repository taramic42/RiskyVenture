//
//  main.cpp
//  Cards
//
//  Created by Katerina Tambakis on 2018-10-04.
//  Copyright © 2018 Katerina Tambakis. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Deck.hpp"
#include "Card.hpp"
#include "Hand.hpp"
#include "Map.hpp"
#include <fstream>
using namespace std;



int main()
{
   /* char response,response1;
    int size=10;
    int first=size/3;
    int second=2*first;
    int third=size;
    
    
    Map m=Map("/Users/katerinatambakis/Desktop/risk/Cards/Alabama/Alabama.map");
    
    for(int i=0;i<m.size();i++)
    {
        m.getCountry(i).display();
    }
    
    */
    std::string line;
    std::vector<std::string> lineList;
    std::ifstream inputFile;
    inputFile.open("/Users/katerinatambakis/Desktop/risk/Cards/Alabama/Alabama.map");
    
    while (!inputFile.eof()) {
        getline(inputFile, line);
        lineList.push_back(line);
    }
    Map m2=Map(lineList);
    
  /*
    vector <Card> deck;

        for(int j=0;j<first;j++)
        {
            Card c=Card("infatry","bob");
            deck.push_back(c);
        }
        for(int j=first;j<second;j++)
        {
            Card c=Card("artillery","bob");
            deck.push_back(c);
        }
        for(int j=second;j<third;j++)
        {
            
            Card c=Card("cavalry","bob");
            deck.push_back(c);
        }

    Deck d= Deck(deck);
    Hand h;
    //create deck
    cout<<"deck created\n";
    //shuffle
    d.shuffleDeck();
    
    do{
        cout<<"draw a card?(y for yes n for no)\n";
        cin>>response;
        
        if(response!='y'&& response!='Y')
        {
            cout<<"thanks for playing\n";
            exit(1);
        }
        
    if(!d.checkDeck())
    { d.replenishDeck();
        d.shuffleDeck();
    }

        Card card=d.draw();// draw from deck
        h.newCard(card);//save in hand
    
        cout<<"you drew: "<<card.getName()<<","<<card.getType()<<endl;
        
        h.displayHand();
        
        cout<<"exchange a card?(y for yes n for no)\n";
        cin>>response1;
        
        if(response1=='n'||response1=='N')
        continue;
        
        int n=d.getArmy();
        
        Card dis=h.exchange(n);//take from hand
    
         d.discardDeck(dis);//put in discard deck
        
       int army=h.getArmy();
        
        cout<<"you have "<<army<<" troops!\n";
        
    }while(response=='y'||response=='Y');
    */
    return 0;
}


