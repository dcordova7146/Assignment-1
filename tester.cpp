#include "Player.cpp"
#include "Deck.hpp"
#include "Hand.cpp"
#include "ActionCard.cpp"
#include "PointCard.cpp"
#include "Card.cpp"

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
