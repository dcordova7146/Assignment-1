#include "Hand.hpp"

Hand::Hand(){
}
Hand::~Hand(){
    cards_.clear();
}

Hand::Hand(const Hand& other){ //copy constructor
    cards_ = other.cards_;
}

Hand& Hand::operator=(const Hand& other){  //copy assignment
    if(this != &other){
        cards_ = other.cards_;
    }
    return *this;
}

Hand::Hand(Hand&& other){ //move constructor
    other.cards_.clear();
}

Hand& Hand::operator=(Hand&& other){ //move assignment
    std::swap(cards_, other.cards_);
    return *this;
}

const std::deque<PointCard>& Hand::getCards() const{
    return cards_;
}

void Hand::addCard(PointCard&& card){
    PointCard newCard = card;
    cards_.push_back(newCard);
}

bool Hand::isEmpty() const{
    return(cards_.empty());
}

void Hand::Reverse(){
    std::reverse(cards_.begin(), cards_.end());
}

int Hand::PlayCard(){
    if(isEmpty()){
        std::runtime_error("Hand is Empty.\n");
        return 0;
    }
    if(!(cards_.front().isPlayable())){
        std::runtime_error("Card Not playable.\n");
        cards_.pop_front();
        return 0;
    }
    cards_.pop_front();
    return std::stoi(cards_.front().getInstruction());
}