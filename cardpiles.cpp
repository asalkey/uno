#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

#include "cardpiles.h"

const int PLAYER_CARDS_AMT = 7;

CardPiles::CardPiles(){}

CardPiles::~CardPiles(){}

void CardPiles::createPiles(){
    getCards();
    
    srand(time(0)); //seed
    //int ranNum = rand() % ca
    
    int player = 1,playerCards = 0,count = 0;
    
    for (int i = 0; i < cardsAmt(); i++ )
    {
        if(i==0){
            //one in the discard to start the game
            addDiscardPile(cardsValue[i],cardsColour[i]);
            deleteCards(i);
        }
        
        if(PLAYER_CARDS_AMT >= count  && player <= 2){
            if(player == 1){
                //player gets 7 cards
                addPlayerPile(cardsValue[i],cardsColour[i]);
            }else{
                //computer gets 7 cards
                addComputerPile(cardsValue[i],cardsColour[i]);
            }
            deleteCards(i);
            playerCards++;
        }
        
        if(playerCards == PLAYER_CARDS_AMT){
            player++;
            count = 0;
        }
        
        count++;
        
        //the rest of cards in draw pile
        addDrawPile(cardsValue[i],cardsColour[i]);
        deleteCards(i);
    }
}

void CardPiles::addDiscardPile(string &value,string &colour){
    discardPileValue.push_back(value);
    discardPileColour.push_back(colour);
}

void CardPiles::addDrawPile(string &value,string &colour){
    drawPileValue.push_back(value);
    drawPileColour.push_back(colour);
}

void CardPiles::addPlayerPile(string &value,string &colour){
    playerPileValue.push_back(value);
    playerPileColour.push_back(colour);
}

void CardPiles::addComputerPile(string &value,string &colour){
    computerPileValue.push_back(value);
    computerPileColour.push_back(colour);
}

void CardPiles::removeDrawPile(int &index){
    //check if exists if not throw error
    if(drawPileAmt() <= index){
        throw("removeDrawPile: Index passed does not exist");
    }
    
    drawPileValue.erase(drawPileValue.begin()+index);
    drawPileColour.erase(drawPileColour.begin()+index);
}

void CardPiles::removePlayerPile(int &index){
    //check if exists if not throw error
    if(playerPileAmt() <= index){
        throw("removePlayerPile: Index passed does not exist");
    }
    
    playerPileValue.erase(playerPileValue.begin()+index);
    playerPileColour.erase(playerPileColour.begin()+index);
}

void CardPiles::removeComputerPile(int &index){
    //check if exists if not throw error
    if(computerPileAmt() <= index){
        throw("removeComputerPile: Index passed does not exist");
    }
    
    computerPileValue.erase(playerPileValue.begin()+index);
    computerPileColour.erase(playerPileColour.begin()+index);
}

void CardPiles::getDiscardPile(string &value,string &colour,int &i){
    //check if exists if not throw error
    if(discardPileAmt() <= i){
        throw("getDiscardPile: Index passed does not exist");
    }
    
    value = discardPileValue[i];
    colour = discardPileColour[i];
}

void CardPiles::getDrawPile(string &value,string &colour,int &i){
    //check if exists if not throw error
    if(discardPileAmt() <= i){
        throw("getDrawPile: Index passed does not exist");
    }
    
    value = drawPileValue[i];
    colour = drawPileColour[i];
}

void CardPiles::getPlayerPile(string &value,string &colour,int &i){
    //check if exists if not throw error
    if(playerPileAmt() <= i){
        throw("getPlayerPile: Index passed does not exist");
    }
    
    value = playerPileValue[i];
    colour = playerPileColour[i];
}

void CardPiles::getComputerPile(string &value,string &colour,int &i){
    //check if exists if not throw error
    if(playerPileAmt() <= i){
        throw("getComputerPile: Index passed does not exist");
    }
    
    value = computerPileValue[i];
    colour = computerPileColour[i];
}

void CardPiles::displayPlayerPile(){
    //check if same as colour if not throw
    for(int i = 0; i < playerPileAmt(); i++){
        cout << "\n CARD #: " << i+1 << endl;
        cout << setw(13) << setfill('*') << "\n";
        cout << " "  << playerPileValue[i] << " " << playerPileColour[i] << endl;
        cout << setw(13) << setfill('*') << "\n";
    }
}

long CardPiles::playerPileAmt(){
    //check if same as colour if not throw
    if(playerPileValue.size() != playerPileColour.size()){
        throw("Player value and colour not the same size");
    }
    
    return playerPileValue.size();
}

long CardPiles::computerPileAmt(){
    //check if same as colour if not throw
    if(computerPileValue.size() != computerPileColour.size()){
        throw("Computer value and colour not the same size");
    }
    
    return computerPileValue.size();
}

long CardPiles::discardPileAmt(){
    //check if same as colour if not throw
    if(discardPileValue.size() != discardPileColour.size()){
        throw("Discard value and colour not the same size");
    }
    
    return discardPileValue.size();
}

long CardPiles::drawPileAmt(){
    //check if same as colour if not throw
    if(drawPileValue.size() != drawPileColour.size()){
        throw("Draw value and colour not the same size");
    }
    
    return computerPileValue.size();
}
