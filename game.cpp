#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

#include "game.h"

Game::Game(){
    //Divy up cards
    newGame->createPiles();
    
    //Get top of discard pile
    //topCard(topValue,topColour,topIndex);
}

Game::~Game(){
    cout << "destroying";
    delete newGame;
}

void Game::setupGame(){
    int playerChoice = 0;
    
    cout << "LETS PLAY UNO!!" << endl;
    cout << "Press 1 to play" << endl;
    cout << "Press 2 for instructions" << endl;
    cin >> playerChoice;
    
    //if less than 1 or greater than 2 throw
    if(playerChoice < 0 || playerChoice > 2){
        throw("Player choice out of bounds");
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
    
    if(playerChoice < 1){
        throw("Player choice out of bounds");
    }
}

//checked
void Game::topCard(string &topValue,string &topColour,int &topIndex){
    newGame->getDiscardPile(topValue,topColour,topIndex);
}

//checked
void Game::isMatch(string &value, string &colour,int &index){
    //does card match top discard if so remove if not throw error
    if(topColour == colour || topValue == value){
        if(isPlayer){
            newGame->removePlayerPile(index);
        }else{
            newGame->removeComputerPile(index);
        }
    }else{
        throw("Player choice does not match");
    }
    
    //check if is uno if not draw
    if(!isUno()){
        draw();
    }
}

//checked
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
    }else if(compCards == 1){
        cout << "YOU LOSE!!!";
    }
    
    return (isPlaying) ? false : true;
}

//checked
void Game::draw(){
    string drawValue,drawColour;
    int index = 0;
    
    //get top of draw pile;
    newGame->getDrawPile(drawValue,drawColour,index);
    
    if(isPlayer){
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

//checked
void Game::playerTurn(int &playerChoice){
    isPlayer = true;
    
    string playerValue,playerColour;
    long skipNumber = newGame->playerPileAmt() + 1;
    
    cout << "Your hand:" << endl;
    newGame->displayPlayerPile();
    
    cout << "\n\n TOP OF DISCARD PILE:" << endl;
    cout << setw(13) << setfill('*') << "\n";
    cout << topValue << " " << topColour << endl;
    cout << setw(13) << setfill('*') << "\n";
    
    cout << "\n\n Select a card or choose " << skipNumber << " to skip" << endl;
    cin >> playerChoice;
    
    //if choice less than 1 or more than user pile throw error
    if(playerChoice < 1 || playerChoice > skipNumber ){
            throw("Incorrect value");
    }
    
    playerChoice = playerChoice - 1; //remove one to match index values in vector
    
    //if chooses to skip -- subtracting 1 to match index values
    if((skipNumber - 1) == playerChoice){
        draw();
    }else{
        newGame->getPlayerPile(playerValue, playerColour,playerChoice);
        isMatch(playerValue, playerColour,playerChoice);
    }
}

void Game::gameLogo(){
    cout << "#" << setw(4) << "#" << setw(4) <<  right << "#" << setw(3) << right << "#####" << setw(7) << right << "#####" << '\n';
    cout << "#" << setw(4) << "#" << setw(4) << right << "#" << setw(5) << right << "#" << setw(3) << right << "#" << setw(4) << right << "#" <<'\n';
    cout << "#" << setw(4) << "#" << setw(4) << right << "#" << setw(5) << right << "#" << setw(3) << right << "#" << setw(4) << right << "#" <<'\n';
    cout << setw(8) << left << "#####" << setw(1) << right << "#" << setw(5) << right << "#" << setw(7) << right << "#####" << '\n';
    cout << endl;
}

void Game::playGame(){
    try{
        setupGame();
    }catch(const char *e){
        cout << e << endl;
    }
}
