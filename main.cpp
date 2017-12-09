#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>

using namespace std;

const int PLAYER_CARDS_AMT = 7;
const int TOP_OF_DISCARD_PILE = 0;

class Cards
{
private:
public:
    vector<string> cardsColour;
    vector<string> cardsValue;
    Cards();
    void getCards();
};

Cards::Cards(){}

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
    void createPiles();
    void addDiscardPile(string &value,string &type);
    void addDrawPile(string &value,string &type);
    void addPlayerPile(string &value,string &type);
    void addComputerPile(string &value,string &type);
    void removeDiscardPile(int &key);
    void removeDrawPile(int &key);
    void removePlayerPile(int &key);
    void removeComputerPile(int &key);
    void getDiscardPile(string &value,string &colour,int &i);
    void getPlayerPile(string &value,string &colour,int &i);
    void getDrawPile(string &value,string &colour,int &i);
    void getComputerPile(string &value,string &colour,int &i);
    void displayPlayerPile();
    long  playerPileAmt();
    long  computerPileAmt();
};

CardPiles::CardPiles(){}

void CardPiles::createPiles(){
    getCards();
    
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
        
        discardPileValue.push_back(cardsValue[i]);
        discardPileColour.push_back(cardsColour[i]);
        //cardsValue.erase (cardsValue.begin()+i);
        //cardsColour.erase (cardsColour.begin()+i);
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

void CardPiles::getDiscardPile(string &value,string &colour,int &i){
    //check if empty and if value/colour size is the same
    
    value = discardPileValue[i];
    colour = discardPileColour[i];
}

void CardPiles::getDrawPile(string &value,string &colour,int &i){
    value = drawPileValue[i];
    colour = drawPileColour[i];
}

void CardPiles::getPlayerPile(string &value,string &colour,int &i){
    value = playerPileValue[i];
    colour = playerPileColour[i];
}

void CardPiles::getComputerPile(string &value,string &colour,int &i){
    value = computerPileValue[i];
    colour = computerPileColour[i];
}

void CardPiles::displayPlayerPile(){
    //check if same as colour if not throw
    cout << playerPileValue.size();
    for(int i = 0; i < playerPileValue.size(); i++){
        cout << i << ") " << endl;
        cout << "******";
        cout << "|"  << playerPileValue[i] << playerPileColour[i] << "|" ;
        cout << "|"  << "|" << endl;
        cout << "*****";
    }
}

long CardPiles::playerPileAmt(){
    //check if same as colour if not throw
    return playerPileValue.size();
}

long CardPiles::computerPileAmt(){
    //check if same as colour if not throw
    return computerPileValue.size();
}

class Game{
private:
    CardPiles *newGame = new CardPiles;
    bool isPlaying = false;
    string topColour,topValue;
    int topIndex = 0;
public:
    Game();
    void playGame();
    void isMatch(string &value,string &colour);
    void computerTurn();
    void playerTurn(int &cardSelect);
    void skip();
    void draw();
    void topCard(string &topColour,string &topValue,int &topIndex);
    void isUno();
};

Game::Game(){}

void Game::playGame(){
    newGame->createPiles();
    
    int playerChoice = 0;
    long skipNumber = newGame->playerPileAmt() + 1;
    
    cout << "LETS PLAY UNO!!" << endl;
    cout << "Press 1 to play" << endl;
    cout << "Press 2 for instructions" << endl;
    cin >> playerChoice;
    //if less than 1 or greater than 2 throw
    try{
        if(playerChoice < 0 || playerChoice > 2){
            throw("Incorrect value");
        }
    }catch(const char *e){
        cout << e;
    }
    
    //instructions press 1 to play
    if(playerChoice == 2){
    cout << "You and the computer get 7 cards each. You have to match the card on top of the draw   pile by number,colour, or action/symbol."
        <<
        "TOP CARD: 8 RED"
        <<
        "You will need either an 8 card or red card to match above"
        <<
        "There are two action cards 'Skip', 'Draw Two'. If the player pulls a:"
        <<
        "'Skip'       -  current player can play again"
        <<
        "'Draw two'   -  next player has to draw two card"
        <<
        "If the player does not have a match or chooses to skip the player has to draw one card"
        <<
        "The player with one card left wins."
    << endl;
    cout << "Press 1 to play" << endl;
    cin >> playerChoice;
    }
    
    try{
        if(playerChoice < 1){
            throw("Incorrect value");
        }
    }catch(const char *e){
        cout << e;
    }
    
    cout << "Your hand:" << endl;
    newGame->displayPlayerPile();
    
    cout << "Top of discard pile:";
    topCard(topColour, topValue,topIndex);
    cout << topColour << topValue;
    
    cout << "Select a card or choose" << skipNumber << " to skip";
    //if choice less than 1 or more than user pile throw error
    try{
        if(playerChoice < 1 || skipNumber > playerChoice){
            throw("Incorrect value");
        }
    }catch(const char *e){
        cout << e;
    }
    
    //select who goes first;
    
    //player turn
    playerTurn(playerChoice);
    
    //computer turn
    computerTurn();
    
    //delete newGame
}

void Game::topCard(string &topColour,string &topValue,int &topIndex){
    newGame->getDiscardPile(topColour,topValue,topIndex);
}

void Game::isMatch(string &value, string &colour){
    
    //does card match top discard if so remove if not throw error
   
    topCard(topColour,topValue,topIndex);
    
    if(topColour == colour || topValue == value){
        
    }
    
    newGame->removePlayerPile(cardSelect);
    
    isUno();
}

void Game::isUno(){
    long userCards = newGame->playerPileAmt();
    long compCards = newGame->computerPileAmt();
    
    //if computer or user has one card left stop the game
    if(userCards == 1 || compCards == 1){
        //isPlaying = false;
    }
    
    //message based on who won
    if(userCards == 1){
        cout << "YOU WIN!!!";
    }else{
        cout << "YOU LOSE!!!";
    }
}

void Game::computerTurn(){
    //run through all cards. if multiple matches put in pile select random. Delete from card pile check if uno
    string computerValue,computerColour;
    vector<int> matchPile;
    int matchCount = 0;
    int computerChoice = 0;
    topCard(topColour,topValue,topIndex);
    
    for (int i = 0; i < newGame->computerPileAmt(); i++){
        newGame->getComputerPile(computerValue,computerColour,i);
        if (topValue == computerValue || topColour == computerColour) {
            matchPile.push_back(i);
            matchCount++;
        }
    }
    
    if(matchPile.size() == 0){
        //skip if no matches
        skip();
    }else{
        //random computer choice
        computerChoice = rand();
        newGame->getComputerPile(computerValue,computerColour,matchPile[computerChoice]);
        isMatch(computerValue,computerColour);
    }
}

void Game::playerTurn(int &playerChoice){
    string playerValue,playerColour;
    long skipNumber = newGame->playerPileAmt() + 1;
    
    //if chooses to skip
    if(skipNumber == playerChoice){
        skip();
    }
    
    newGame->getPlayerPile(playerValue, playerColour,playerChoice);
    isMatch(playerValue, playerColour);
}


int main()
{
    Game uno;
    uno.playGame();
    return 0;
}
