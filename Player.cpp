#include "Player.hpp"

Player::Player(){
    score_ = 0;
    opponent_ = nullptr;
    actiondeck_ = nullptr;
    pointdeck_ = nullptr;
}

Player::~Player(){
    delete opponent_;
    delete actiondeck_;
    delete pointdeck_;
}

const Hand& Player::getHand() const{
    return hand_;
}

void Player::setHand(const Hand& hand){
    hand_ = hand;
}

int Player::getScore() const{
    return score_;
}

void Player::setScore(const int& score){
    score_ = score;
}

void Player::play(ActionCard&& card){
    int count;
    //Print out the instruction
    std::cout<< "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
    std::string instro = card.getInstruction();
    if(instro == "REVERSE HAND"){
        hand_.Reverse();

    }
    else if(instro == "SWAP HAND WITH OPPONENT"){//should be fine
        Hand temp = hand_;
        hand_ = opponent_->getHand();
        opponent_->setHand(temp);
        //std:swap
    }
    else{

    //tokenize the instruction
    std::string tempWord = "";
    std::vector<std::string> words;
    for(int i = 0;i<instro.length();i++){
        if(instro[i] != ' '){
            tempWord.push_back(instro[i]);
        }else{
            words.push_back(tempWord);
            tempWord = "";
        }
    }
    if (!tempWord.empty()) {  // Check for the last word
        words.push_back(tempWord);
    }

    if(words[0] == "DRAW"){
        count = std::stoi(words[1]);
        while(count != 0 && !(pointdeck_->IsEmpty())){//draw would check the empty
            drawPointCard();
            count --;
        }
    }
    else if(words[0] == "PLAY"){
        count = std::stoi(words[1]);
        while(count != 0 && !(hand_.isEmpty())){
            playPointCard();
            count--;
        }
    }
    }
}

void Player::drawPointCard(){
    hand_.addCard(pointdeck_->Draw());
}

void Player::playPointCard(){
    hand_.PlayCard();
}

void Player::setOpponent(Player* opponent){
    opponent_ = opponent;
}

Player* Player::getOpponent(){
    return opponent_;
}

void Player::setActionDeck(Deck<ActionCard>* actiondeck){
    actiondeck_ = actiondeck;
}

Deck<ActionCard>* Player::getActionDeck(){
    return actiondeck_;
}

void Player::setPointDeck(Deck<PointCard>* pointdeck){
    pointdeck_  = pointdeck;
}

Deck<PointCard>* Player::getPointDeck(){
    return pointdeck_;
}