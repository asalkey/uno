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
    
    shuffleCards();
}

//shuffle cards func
void Cards::shuffleCards(){
    srand(time(0)); //seed
    int *indexArray;
    int cardIndex;
    long limit;
    indexArray = new int[cardsAmt()];
    limit = cardsAmt() - 1; //reduce so the index does not go out of bounds
    
    //check that we have space for array
    if (!indexArray){
        exit(-1);
    }
    
    //Get a random array of indices
    for(int i = 0; i < cardsAmt(); i++){
        indexArray[i] = rand() % limit;
    }
    
    for(int i = 0; i < cardsAmt(); i++){
        cardIndex = indexArray[i];
        
        //put the value in the back of vector
        cardsColour.push_back(cardsColour[cardIndex]);
        cardsValue.push_back(cardsValue[cardIndex]);
        
        //delete those values so no duplicates
        cardsColour.erase(cardsColour.begin() + cardIndex);
        cardsValue.erase(cardsValue.begin() + cardIndex);
    }
    
    //delete array
    delete [] indexArray;
}

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
