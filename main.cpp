#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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
    ~Cards();
    void getCards();
    void deleteCards(int &index);
};

Cards::Cards(){}

Cards::~Cards(){}

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

void Cards::deleteCards(int &index){
    cardsValue.erase (cardsValue.begin()+index);
    cardsColour.erase (cardsColour.begin()+index);
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
    ~CardPiles();
    void createPiles();
    void addDiscardPile(string &value,string &type);
    void addDrawPile(string &value,string &type);
    void addPlayerPile(string &value,string &type);
    void addComputerPile(string &value,string &type);
    void removeDiscardPile(int &index);
    void removeDrawPile(int &index);
    void removePlayerPile(int &index);
    void removeComputerPile(int &index);
    void getDiscardPile(string &value,string &colour,int &i);
    void getPlayerPile(string &value,string &colour,int &i);
    void getDrawPile(string &value,string &colour,int &i);
    void getComputerPile(string &value,string &colour,int &i);
    void displayPlayerPile();
    long  playerPileAmt();
    long  computerPileAmt();
};

CardPiles::CardPiles(){}

CardPiles::~CardPiles(){}

void CardPiles::createPiles(){
    getCards();
    
    int player = 1,playerCards = 1,count = 0;
    
    for (int i = 0; i < cardsValue.size(); i++ )
    {
        if(PLAYER_CARDS_AMT >= count){
            if(player == 1){
                addPlayerPile(cardsValue[i],cardsColour[i]);
            }else{
                addComputerPile(cardsValue[i],cardsColour[i]);
            }
            deleteCards(i);
            
            playerCards++;
        }
        
        if(playerCards == PLAYER_CARDS_AMT && player < 2){
            player++;
            count = 0;
        }
        
        count++;
        
        addDiscardPile(cardsValue[i],cardsColour[i]);
        deleteCards(i);
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

//not needed since it's a discard pile remove this
void CardPiles::removeDiscardPile(int &index){
    //check if exists if not throw error
    discardPileValue.erase(discardPileValue.begin()+index);
    discardPileColour.erase(discardPileColour.begin()+index);
}

void CardPiles::removeDrawPile(int &index){
    drawPileValue.erase(drawPileValue.begin()+index);
    drawPileColour.erase(drawPileColour.begin()+index);
}

void CardPiles::removePlayerPile(int &index){
    //check if exists if not throw error
    playerPileValue.erase(playerPileValue.begin()+index);
    playerPileColour.erase(playerPileColour.begin()+index);
}

void CardPiles::removeComputerPile(int &index){
    //check if exists if not throw error
    computerPileValue.erase(playerPileValue.begin()+index);
    computerPileColour.erase(playerPileColour.begin()+index);
}

void CardPiles::getDiscardPile(string &value,string &colour,int &i){
    //check if empty and if value/colour size is the same
    
    value = discardPileValue[i];
    colour = discardPileColour[i];
}

void CardPiles::getDrawPile(string &value,string &colour,int &i){
    //check if exists if not throw error
    value = drawPileValue[i];
    colour = drawPileColour[i];
}

void CardPiles::getPlayerPile(string &value,string &colour,int &i){
    //check if exists if not throw error
    value = playerPileValue[i];
    colour = playerPileColour[i];
}

void CardPiles::getComputerPile(string &value,string &colour,int &i){
    //check if exists if not throw error
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
    bool isPlaying = true;
    bool isPlayer = false;
    string topColour,topValue;
    int topIndex = 0;
public:
    Game();
    ~Game();
    void playGame();
    void isMatch(string &value,string &colour,int &index);
    void computerTurn();
    void playerTurn(int &cardSelect);
    void draw();
    void topCard(string &topColour,string &topValue,int &topIndex);
    bool isUno();
};

Game::Game(){}

Game::~Game(){
    cout << "destroying";
    delete newGame;
}

void Game::playGame(){
    newGame->createPiles();
    
    int playerChoice = 0;
    
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
    
    if (playerChoice == 1) {
        //player turn
        playerTurn(playerChoice);
    }else if (playerChoice == 2) {
        //computer turn
        computerTurn();
    }else{
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
}

void Game::topCard(string &topColour,string &topValue,int &topIndex){
    newGame->getDiscardPile(topColour,topValue,topIndex);
}

void Game::isMatch(string &value, string &colour,int &index){
    
    //does card match top discard if so remove if not throw error
   
    topCard(topColour,topValue,topIndex);
    
    if(topColour == colour || topValue == value){
        newGame->removePlayerPile(index);
        newGame->removeComputerPile(index);
    }else{
        throw("not a match");
    }
    
    //check if is uno if not draw
    if(isUno()){
        draw();
    }
}

bool Game::isUno(){
    long userCards = newGame->playerPileAmt();
    long compCards = newGame->computerPileAmt();
    
    //if computer or user has one card left stop the game
    if(userCards == 1 || compCards == 1){
        isPlaying = false;
    }
    
    //message based on who won
    if(userCards == 1){
        cout << "YOU WIN!!!";
    }else{
        cout << "YOU LOSE!!!";
    }
    
    return isPlaying;
}

void Game::draw(){
    string drawValue,drawColour;
    int index = 0;
    
    //get top of draw pile;
    newGame->getDrawPile(drawValue,drawColour,index);
    
    if(isPlayer){
        //add it to player pile
        newGame->addPlayerPile(drawValue,drawColour);
    }else{
        //add it to computer pile
        newGame->addComputerPile(drawValue,drawColour);
    }
    
    //remove it from pile
    newGame->removeDrawPile(index);
}

void Game::computerTurn(){
    isPlayer = false;
    
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
        //draw if no matches
        draw();
    }else{
        //random computer choice
        computerChoice = rand();
        newGame->getComputerPile(computerValue,computerColour,matchPile[computerChoice]);
        isMatch(computerValue,computerColour,matchPile[computerChoice]);
    }
}

void Game::playerTurn(int &playerChoice){
    isPlayer = true;
    
    string playerValue,playerColour;
    long skipNumber = newGame->playerPileAmt() + 1;
    
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
    
    //if chooses to skip
    if(skipNumber == playerChoice){
        draw();
    }else{
        newGame->getPlayerPile(playerValue, playerColour,playerChoice);
        isMatch(playerValue, playerColour,playerChoice);
    }
}


int main()
{
    //make dynamic
    Game uno;
    uno.playGame();
    return 0;
}
