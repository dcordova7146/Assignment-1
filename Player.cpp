#include "Player.hpp"

Player::Player(){
    score_ = 0;
    opponent_ = nullptr;
    actiondeck_ = nullptr;
    pointdeck_ = nullptr;
}

Player::~Player(){
    delete opponent_;
    opponent_ = nullptr;
    delete actiondeck_;
    actiondeck_= nullptr;
    delete pointdeck_;
    pointdeck_ = nullptr;
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
    //Print out the instruction
    std::cout<< "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
    std::string instro = card.getInstruction();
    int x = 0; //number of cards to be drawn/played
    
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

    //Instructions being done
    if(instro == "REVERSE HAND"){
        hand_.Reverse();
    }
    else if(instro == "SWAP HAND WITH OPPONENT"){
        Hand temp = hand_;
        hand_ = opponent_->getHand();
        opponent_->setHand(temp);
    }
    else if(words[0] == "DRAW"){
            x = std::stoi(words[1]);
            while(x != 0){//draw would check the empty
                drawPointCard();
                x --;
            }
    }
    else if(words[0] == "PLAY"){
            x = std::stoi(words[1]);
            while(x != 0){
                playPointCard();
                x--;
            }
     }

}

void Player::drawPointCard(){
    if(pointdeck_ != nullptr){
        hand_.addCard(pointdeck_->Draw());
    }
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