#include "Player.cpp"
#include "Deck.hpp"
#include "Hand.cpp"
#include "ActionCard.cpp"
#include "PointCard.cpp"
#include "Card.cpp"

int main(){
    /*
    Hand hand1;
    Hand hand2;
    Deck<PointCard> deck1;

    PointCard p1;
    p1.setInstruction("2");
    p1.getInstruction();
    PointCard p2;
    p2.setInstruction("4");
    p2.getInstruction();
    PointCard p3;
    p3.setInstruction("6");
    p3.getInstruction();
    PointCard p4;
    p4.setInstruction("7");
    p4.getInstruction();

    deck1.AddCard(p1);
    deck1.AddCard(p2);
    deck1.AddCard(p3);
    deck1.AddCard(p4);

    ActionCard action1;
    action1.setInstruction("PLAY 1 CARD(S)");
    action1.getInstruction();
    ActionCard action2;
    action2.setInstruction("DRAW 2 CARD(S)");
    action2.getInstruction();
    ActionCard action3;
    action3.setInstruction("SWAP HAND WITH OPPONENT");
    action3.getInstruction();
    ActionCard action4;
    action4.setInstruction("REVERSE HAND");
    action4.getInstruction();

    Deck<ActionCard> action_deck;
    
    Player play1;
    Player play2;
    play1.setHand(hand1);
    play2.setHand(hand2);
    play1.setOpponent(&play2);
    play1.setPointDeck(&deck1);
    play1.setActionDeck(&action_deck);

    play1.play(std::move(action2)); //draw 2 cards

    play1.play(std::move(action1));
    play1.play(std::move(action3));
    play1.play(std::move(action4));

    return 0;
    */

    // Create two players
    Player player1;
    Player player2;
    std::cout<<"Got to here"<<std::endl;
    // Set opponents
    player1.setOpponent(&player2);
    player2.setOpponent(&player1);
    std::cout<<"Got to here 2"<<std::endl;
    // Create decks for action and point cards
    Deck<ActionCard> actionDeck;
    Deck<PointCard> pointDeck;
    std::cout<<"Got to here 3"<<std::endl;

    // Fill the decks with cards (example, you will need to implement this according to your Card classes)
    
    ActionCard a1;
    ActionCard a2;
    ActionCard a3;
    ActionCard a4;
    ActionCard a5;
    ActionCard a6;

    PointCard p1;
    PointCard p2;
    PointCard p3;
    PointCard p4;
    PointCard p5;
    PointCard p6;

    actionDeck.AddCard(a1);
    //std::cout << a1.getDrawn() << std::endl;
    pointDeck.AddCard(p1);
    actionDeck.AddCard(a2);
    pointDeck.AddCard(p2);
    actionDeck.AddCard(a3);
    pointDeck.AddCard(p3);
    actionDeck.AddCard(a4);
    pointDeck.AddCard(p4);
    actionDeck.AddCard(a5);
    pointDeck.AddCard(p5);
    actionDeck.AddCard(a6);
    pointDeck.AddCard(p6);

    p1.setInstruction("1");
    p2.setInstruction("2");
    p3.setInstruction("4");
    p4.setInstruction("20");
    p5.setInstruction("3");
    p6.setInstruction("13");
    a1.setInstruction("SWAP HAND WITH OPPONENT");
    a2.setInstruction("DRAW 2 CARD(S)");
    a3.setInstruction("PLAY 2 CARD(S)");
    a4.setInstruction("DRAW 3 CARD(S)");
    a5.setInstruction("PLAY 2 CARD(S)");
    a5.setInstruction("REVERSE HAND");



    std::cout<<"Got to here 4"<<std::endl;
    // Assign the decks to the players
    player1.setActionDeck(&actionDeck);
    player1.setPointDeck(&pointDeck);
    std::cout<<"Got to here 5"<<std::endl;
    player2.setActionDeck(&actionDeck);
    player2.setPointDeck(&pointDeck);
    std::cout<<"Got to here 6"<<std::endl;

    // Shuffle the decks
    actionDeck.Shuffle();
    pointDeck.Shuffle();
    std::cout << "Got to here 6.5" <<std::endl;
    std::cout << "Size: " <<actionDeck.getSize() << std::endl;
    
    std::cout << actionDeck.getDeck()[1].getDrawn() << std::endl;

    for(int i = 0; i < actionDeck.getSize(); i++){
        std::cout << actionDeck.getDeck()[i].getDrawn() << " : " << i+1 << ", ";
    }
    std::cout << std::endl;
    std::cout<<" Got to here 7"<<std::endl;
    // Players draw point cards
    player1.drawPointCard();
    std::cout<<" Got to here 7.5"<<std::endl;
    player2.drawPointCard();
    std::cout<<" Got to here 8"<<std::endl;
    // Players draw action cards and play them
    ActionCard actionCard1 = player1.getActionDeck()->Draw();
    ActionCard actionCard2 = player2.getActionDeck()->Draw();
    std::cout<<" Got to here 9"<<std::endl;
    // Players play point cards
    player1.playPointCard();
    player2.playPointCard();
    std::cout<<" Got to here 10"<<std::endl;
    // Output scores
    std::cout << "Player 1 score: " << player1.getScore() << std::endl;
    std::cout << "Player 2 score: " << player2.getScore() << std::endl;
    std::cout<<" Got to here 11"<<std::endl;
    // Check and print hands and opponents

    std::cout << "Player 1's opponent is Player 2: " << (player1.getOpponent() == &player2) << std::endl;
    std::cout << "Player 2's opponent is Player 1: " << (player2.getOpponent() == &player1) << std::endl;
    std::cout<<" Got to here 12"<<std::endl;

    return 0;
}
