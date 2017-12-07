#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

//const CARDS_IN_HAND = 7;

class Cards
{
private:
public:
    map <string, string> cards;
    map <string, string> :: iterator itr;
    vector<string> test;
    Cards();
    void getCards();
    void computerPile();
};

Cards::Cards(){   }

void Cards::getCards(){
    ifstream f2;
    f2.open("/Users/andy/Desktop/c++/final/final/cards.txt");
    
    if (f2.fail())
    {
        cout << "Can't open file\n";
        exit(-1);
    }
    string str;
    while (!f2.eof())
    {
        getline(f2, str);
        
        cards.insert(pair <string, string> (str,str));
    }
    
    
    f2.close();
}

void Cards::computerPile(){
    cout << test[0];
    for (this->itr = this->cards.begin(); this->itr != this->cards.end(); ++this->itr)
    {
        cout  <<  '\t' << this->itr->first
        <<  '\t' << this->itr->second << '\n';
    }
    cout << endl;
}


class CardPiles: public Cards
{
private:
    map <string, string> pdiscardPile;
    map <string, string> pdrawPile;
    map <string, string> pplayerPile;
    map <string, string> pcomputerPile();
public:
    CardPiles();
    void discardPile();
    void drawPile();
    void playerPile();
    void computerPile();
};

CardPiles::CardPiles(){
    discardPile();
    drawPile();
    playerPile();
    computerPile();
}

void CardPiles::discardPile(){
    
    //cout << "heyo";
}

void CardPiles::drawPile(){
    
    //cout << "meow";
}

void CardPiles::playerPile(){
    
}

void CardPiles::computerPile(){
    for (this->itr = this->cards.begin(); this->itr != this->cards.end(); ++this->itr)
    {
        cout  <<  '\t' << this->itr->first
        <<  '\t' << this->itr->second << '\n';
    }
    cout << endl;
}


int main()
{
    
    Cards cards;
    cards.getCards();
    CardPiles divyUp;
    

    return 0;
}
