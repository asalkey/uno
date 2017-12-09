CardPiles::CardPiles(){}

CardPiles::~CardPiles(){}

void CardPiles::createPiles(){
    getCards();
    
    int player = 1,playerCards = 1,count = 0;
    
    for (int i = 0; i < cardsValue.size(); i++ )
    {
        if(PLAYER_CARDS_AMT >= count){
            if(player == 1){
                addPlayerPile(cardsValue[i],cardsColour[i]);
            }else{
                addComputerPile(cardsValue[i],cardsColour[i]);
            }
            deleteCards(i);
            
            playerCards++;
        }
        
        if(playerCards == PLAYER_CARDS_AMT && player < 2){
            player++;
            count = 0;
        }
        
        count++;
        
        addDiscardPile(cardsValue[i],cardsColour[i]);
        deleteCards(i);
    }

    
    //drawPileValue.push_back();
    cout << computerPileValue.size();
    cout << playerPileValue.size();
    //cout << cardsValue.size();
}

void CardPiles::addDiscardPile(string &value,string &colour){
    discardPileValue.push_back(value);
    discardPileColour.push_back(colour);
}

void CardPiles::addDrawPile(string &value,string &colour){
    drawPileValue.push_back(value);
    drawPileColour.push_back(colour);
}

void CardPiles::addPlayerPile(string &value,string &colour){
    playerPileValue.push_back(value);
    discardPileColour.push_back(colour);
}

void CardPiles::addComputerPile(string &value,string &colour){
    computerPileValue.push_back(value);
    computerPileColour.push_back(colour);
}

//not needed since it's a discard pile remove this
void CardPiles::removeDiscardPile(int &index){
    //check if exists if not throw error
    discardPileValue.erase(discardPileValue.begin()+index);
    discardPileColour.erase(discardPileColour.begin()+index);
}

void CardPiles::removeDrawPile(int &index){
    drawPileValue.erase(drawPileValue.begin()+index);
    drawPileColour.erase(drawPileColour.begin()+index);
}

void CardPiles::removePlayerPile(int &index){
    //check if exists if not throw error
    playerPileValue.erase(playerPileValue.begin()+index);
    playerPileColour.erase(playerPileColour.begin()+index);
}

void CardPiles::removeComputerPile(int &index){
    //check if exists if not throw error
    computerPileValue.erase(playerPileValue.begin()+index);
    computerPileColour.erase(playerPileColour.begin()+index);
}

void CardPiles::getDiscardPile(string &value,string &colour,int &i){
    //check if empty and if value/colour size is the same
    
    value = discardPileValue[i];
    colour = discardPileColour[i];
}

void CardPiles::getDrawPile(string &value,string &colour,int &i){
    //check if exists if not throw error
    value = drawPileValue[i];
    colour = drawPileColour[i];
}

void CardPiles::getPlayerPile(string &value,string &colour,int &i){
    //check if exists if not throw error
    value = playerPileValue[i];
    colour = playerPileColour[i];
}

void CardPiles::getComputerPile(string &value,string &colour,int &i){
    //check if exists if not throw error
    value = computerPileValue[i];
    colour = computerPileColour[i];
}

void CardPiles::displayPlayerPile(){
    //check if same as colour if not throw
    cout << playerPileValue.size();
    for(int i = 0; i < playerPileValue.size(); i++){
        cout << i << ") " << endl;
        cout << "******";
        cout << "|"  << playerPileValue[i] << playerPileColour[i] << "|" ;
        cout << "|"  << "|" << endl;
        cout << "*****";
    }
}

long CardPiles::playerPileAmt(){
    //check if same as colour if not throw
    return playerPileValue.size();
}

long CardPiles::computerPileAmt(){
    //check if same as colour if not throw
    return computerPileValue.size();
}