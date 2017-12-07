#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>

using namespace std;

//const CARDS_IN_HAND = 7;

class Cards
{
private:
public:
    map<int,map<string, string>> cards;
    map<string, string> cardsData;
    map<int,map <string, string>> :: iterator itr;
    map<string, string>::iterator itr2;
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
    
    typedef std::map< std::string, std::string > inner_t;
    typedef std::map< int, inner_t >     outer_t;
    typedef outer_t::iterator                    outer_iter_t;
    typedef inner_t::iterator                    inner_iter_t;
    
    outer_t tree;
    inner_t f;
    int count = 0;
    while (!f2.eof())
    {
        getline(f2, str);
        stringstream strStream(str);
        //strStream >> value;
     
        while (!strStream.eof())
        {
            strStream >> value >> colour;
            cout << colour << endl;
            //f.emplace(value, colour);
        }
        
        //tree.emplace(count,f);
        count++;
    }
    for( outer_iter_t o = tree.begin(); o != tree.end(); ++o )
        for( inner_iter_t i = o->second.begin(); i != o->second.end(); ++i )
            //std::cout << i->first << " == " << i->second << std::endl;
    f2.close();
}

class CardPiles: public Cards
{
private:
    map <string, string> pdiscardPile;
    map<int,map <string, string>> pdrawPile;
    map<int,map <string, string>> pplayerPile;
    map<int,map <string, string>> pcomputerPile();
public:
    CardPiles();
    void addDiscardPile(string value,string type);
    void addDrawPile(string value,string type);
    void addPlayerPile(string value,string type);
    void addComputerPile(string value,string type);
    void removeDiscardPile(string key);
    void removeDrawPile(string key);
    void removePlayerPile(string key);
    void removeComputerPile(string key);
    void getDiscardPile();
    void getDrawPile();
    void getPlayerPile();
    void getComputerPile();
    void createPiles();
};

CardPiles::CardPiles(){
}

void CardPiles::createPiles(){
    int hand, count = 0;
    for (this->itr = this->cards.begin(); this->itr != this->cards.end(); ++this->itr)
    {
        for (this->itr2 = this->cardsData.begin(); this->itr2 != this->cardsData.end(); ++this->itr2)
        {
            cout << itr2->first;
        //if(count < PLAYER_CARD_AMNT && PLAYERS > hand){
            //push to correct map and remove ones added from card;
        //}
        }
        
        //put one in discard
        //rest in draw
    }
    cout << endl;
}

void CardPiles::addDiscardPile(string value,string type){
    //cards.insert(pair <string, string> (value,type));
}

void CardPiles::addDrawPile(string value,string type){
   // cards.insert(pair <string, string> (value,type));
}

void CardPiles::addPlayerPile(string value,string type){
    //cards.insert(pair <string, string> (value,type));
}

void CardPiles::addComputerPile(string value,string type){
    //cards.insert(pair <string, string> (value,type));
}

void CardPiles::removeDiscardPile(string key){
    
}

void CardPiles::removeDrawPile(string key){
    
}

void CardPiles::removePlayerPile(string key){
}

void CardPiles::removeComputerPile(string key){
}

void CardPiles::getDiscardPile(){}
void CardPiles::getDrawPile(){}
void CardPiles::getPlayerPile(){}
void CardPiles::getComputerPile(){}


int main()
{
    
    Cards cards;
    CardPiles divyUp;
    cards.getCards();
    

    return 0;
}
