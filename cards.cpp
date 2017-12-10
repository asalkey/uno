#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

#include "cards.h"

Cards::Cards(){}

Cards::~Cards(){}

void Cards::getCards(){
    string str, value,colour;
    ifstream f2;
    f2.open("/Users/andy/Desktop/c++/ffff/ffff/cards.txt");
    
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
        
        while (!strStream.eof())
        {
            strStream >> value >> colour;
            
            cardsColour.push_back(colour);
            cardsValue.push_back(value);
        }
        
        count++;
    }
}

//shuffle cards func

long Cards::cardsAmt(){
    //check if same as colour if not throw
    if(cardsValue.size() != cardsColour.size()){
        throw("Value and colour not the same size");
    }
    
    return cardsValue.size();
}

void Cards::deleteCards(int &index){
    cardsValue.erase (cardsValue.begin()+index);
    cardsColour.erase (cardsColour.begin()+index);
}
