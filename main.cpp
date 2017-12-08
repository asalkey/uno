#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>

using namespace std;

const int PLAYER_CARDS_AMT = 7;

class Cards
{
private:
public:
    vector<string> cardsColour;
    vector<string> cardsValue;
    Cards();
    void getCards();
    void computerPile();
};

Cards::Cards(){ getCards();  }

void Cards::getCards(){
    string str, value,colour;
    ifstream f2;
    f2.open("/Users/andy/Desktop/c++/final/final/cards.txt");
    
    if (f2.fail())
    {
        cout << "Can't open file\n";
        exit(-1);
    }
    

    int count = 0;
    while (!f2.eof())
    {
        getline(f2, str);
        stringstream strStream(str);
        //strStream >> value;
     
        while (!strStream.eof())
        {
            strStream >> value >> colour;
            
            cardsColour.push_back(colour);
            cardsValue.push_back(value);
        }
        
        count++;
    }
}

class CardPiles: public Cards
{
private:
    vector<string> drawPileValue;
    vector<string> drawPileColour;
    
    vector<string> playerPileValue;
    vector<string> playerPileColour;
    
    vector<string> computerPileValue;
    vector<string> computerPileColour;
    
    vector<string> discardPileValue;
    vector<string> discardPileColour;
public:
    CardPiles();
    void addDiscardPile(string &value,string &type);
    void addDrawPile(string &value,string &type);
    void addPlayerPile(string &value,string &type);
    void addComputerPile(string &value,string &type);
    void removeDiscardPile(int &key);
    void removeDrawPile(int &key);
    void removePlayerPile(int &key);
    void removeComputerPile(int &key);
    vector<string> getDiscardPile();
    vector<string> getDrawPile();
    vector<string> getPlayerPile();
    vector<string> getComputerPile();
    void createPiles();
};

CardPiles::CardPiles(){
}

void CardPiles::createPiles(){
    int player = 1,playerCards = 1,count = 0;
    
    for (int i = 0; i < cardsValue.size(); i++ )
    {
        if(PLAYER_CARDS_AMT >= count){
            if(player == 1){
                playerPileValue.push_back(cardsValue[i]);
                playerPileColour.push_back(cardsColour[i]);
            }else{
                computerPileValue.push_back(cardsValue[i]);
                computerPileColour.push_back(cardsColour[i]);
            }
            cardsValue.erase (cardsValue.begin()+i);
            cardsColour.erase (cardsColour.begin()+i);
            
            playerCards++;
        }
        
        if(playerCards == PLAYER_CARDS_AMT && player < 2){
            player++;
            count = 0;
        }
        
        count++;
        
      
        
        //cout << i;
    }

    
    //drawPileValue.push_back();
    cout << computerPileValue.size();
    cout << playerPileValue.size();
    //cout << cardsValue.size();
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
    discardPileColour.push_back(colour);
}

void CardPiles::addComputerPile(string &value,string &colour){
    computerPileValue.push_back(value);
    computerPileColour.push_back(colour);
}

void CardPiles::removeDiscardPile(int &key){
    discardPileValue.erase(discardPileValue.begin()+key);
    discardPileColour.erase(discardPileColour.begin()+key);
}

void CardPiles::removeDrawPile(int &key){
    drawPileValue.erase(drawPileValue.begin()+key);
    drawPileColour.erase(drawPileColour.begin()+key);
}

void CardPiles::removePlayerPile(int &key){
    playerPileValue.erase(playerPileValue.begin()+key);
    playerPileColour.erase(playerPileColour.begin()+key);
}

void CardPiles::removeComputerPile(int &key){
    computerPileValue.erase(playerPileValue.begin()+key);
    computerPileColour.erase(playerPileColour.begin()+key);
}

vector<string> CardPiles::getDiscardPile(){
    return discardPileColour;
}

vector<string> CardPiles::getDrawPile(){
    return drawPileColour;
}

vector<string> CardPiles::getPlayerPile(){
    return playerPileColour;
}

vector<string> CardPiles::getComputerPile(){
    return computerPileColour;
}

class Game{
public:
    void playGame();
    void isMatch();
    void computerTurn();
    void skip();
};


void Game::playGame(){
    //bool isPlaying = 0;
    
    CardPiles *cardPiles = nullptr;
    //make cardPiles dynamic .. variable name newGame
    
    int cardSelect = 0;
    
    cout << "UNO" << endl;
    cout << "Press 1 to play" << endl;
    cout << "Press 2 for instructions" << endl;
    //if less than 1 or greater than 2 throw
    
    //instructions press 1 to play
    
    cout << "Your hand:" << endl;
    cardPiles->getPlayerPile();
    
    cout << "Top of discard pile:";
    cardPiles->getDiscardPile();
    
    cout << "Select a card or choose 8 to skip";
    //if choice less than 1 throw error
    //does card match top discard if so remove if not throw error
    cardPiles->removePlayerPile(cardSelect);
    
    //if skip draw card
    
    //computer turn
    
    //delete newGame
}


int main()
{
    
    Cards cards;
    CardPiles divyUp;
    divyUp.createPiles();
    

    return 0;
}
