#include "Deck.hpp"
#include "Hand.cpp"
//#include "Player.cpp"
#include "Card.cpp"
#include "ActionCard.cpp"
#include "PointCard.cpp"

int main(){
    ActionCard aCard;
    aCard.setDrawn(false);
    aCard.setInstruction("REVERSE HAND");
    PointCard pCard;
    pCard.setDrawn(false);
    pCard.setInstruction("5");

    Deck<ActionCard> myADeck;
    Deck<PointCard> myPDeck;

    myADeck.AddCard(aCard);
    myPDeck.AddCard(pCard);
    
    aCard.Print();
    return 0;

}
