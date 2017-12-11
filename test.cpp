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
        cout << testPiles->playerPileAmt() << endl;
    
        cout << "Computer cards: 7" << endl;
        cout << testPiles->computerPileAmt() << endl;
    
        cout << "Discard cards: 1" << endl;
        cout << testPiles->discardPileAmt() << endl;
    
        cout << "Draw cards: 77" << endl;
        cout << testPiles->drawPileAmt() << endl;
        
        cout << "Cards left: 0" << endl;
        cout << testCards->cardsAmt() << endl;
    
    
        srand(time(NULL));
        int whoseTurn = 1; //rand() % 2 + 1;
        int w = static_cast<int>(testPiles->playerPileAmt()) + 1;
        int ranIn = rand() % w;
        
        if(whoseTurn == 1){
            
            cout << "Player turn - choice " << ranIn << endl;
            testGame->playerTurn(ranIn);
        }else if(whoseTurn == 2){
            cout << "Computer turn" << endl;
            
            testGame->computerTurn();
        }
    }catch(const char *e){
        cout << e << endl;
    }
}
