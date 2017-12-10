#include "test.h"

Test::Test(){}

Test::~Test(){
    cout << "destroying";
    delete testCards;
    delete testPiles;
    delete testGame;
}

void Test::testUno(){
    try{
        cout << "Divy up cards into piles" << endl;
        testPiles->createPiles();
    
        cout << "Player cards: 7" << endl;
        cout <<testPiles->playerPileAmt() << endl;
    
        cout << "Computer cards: 7" << endl;
        cout << testPiles->computerPileAmt() << endl;
    
        cout << "Discard cards: 1" << endl;
        cout << testPiles->discardPileAmt() << endl;
    
        cout << "Draw cards: 77" << endl;
        cout << testPiles->drawPileAmt() << endl;
        
        cout << "Cards left: 0" << endl;
        cout << testCards->cardsAmt() << endl;
    
    
        srand(time(0));
        int whoseTurn = rand() % 2 + 1;
    
        if(whoseTurn == 1){
            int index = rand() % testPiles->playerPileAmt();
            
            cout << "Player turn - choice " << index << endl;
            cout << testPiles->discardPileAmt() << endl;
            testGame->playerTurn(index);
        }else if(whoseTurn == 2){
            cout << "Computer turn" << endl;
            
            testGame->computerTurn();
        }
    }catch(const char *e){
        cout << e << endl;
    }
}
