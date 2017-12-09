class Cards
{
private:
public:
    vector<string> cardsColour;
    vector<string> cardsValue;
    Cards();
    ~Cards();
    void getCards();
    void deleteCards(int &index);
};