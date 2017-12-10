#include "cards.h"

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
    void removeDrawPile(int &index);
    void removePlayerPile(int &index);
    void removeComputerPile(int &index);
    void getDiscardPile(string &value,string &colour,int &i);
    void getPlayerPile(string &value,string &colour,int &i);
    void getDrawPile(string &value,string &colour,int &i);
    void getComputerPile(string &value,string &colour,int &i);
    void displayPlayerPile();
    long playerPileAmt();
    long computerPileAmt();
    long drawPileAmt();
    long discardPileAmt();
};
