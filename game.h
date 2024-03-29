#include "cardpiles.h"

class Game{
private:
    CardPiles *newGame = new CardPiles;
    bool isPlaying = true;
    bool isPlayer = false;
    string topColour,topValue;
    int topIndex = 0;
    void gameLogo();
public:
    Game();
    ~Game();
    void setupGame();
    void playGame();
    void isMatch(string &value,string &colour,int &index);
    void computerTurn();
    void playerTurn(int &cardSelect);
    void draw();
    void topCard(string &topColour,string &topValue,int &topIndex);
    bool isUno();
};
