#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib> 
#include <ctime>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using namespace std;


#include "game.h"


const int PLAYER_CARDS_AMT = 7;

class Test{
private:
    Cards *testCards = new Cards;
    CardPiles *testPiles = new CardPiles;
    Game *testGame = new Game;
public:
    Test();
    ~Test();
    void testUno();
};
