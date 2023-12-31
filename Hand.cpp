#include "Hand.hpp"
#include <stack>

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

Hand::Hand(Hand&& other):cards_(std::move(other.cards_)){ 

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
    newCard.setDrawn(true);
    cards_.push_back(newCard);
}

bool Hand::isEmpty() const{
    return(cards_.empty());
}

void Hand::Reverse(){
    std::stack <PointCard> stack;
    while(!cards_.empty()){
        stack.push(cards_.back());
        cards_.pop_back();
    }
    while(!stack.empty()){
        cards_.push_front((stack.top()));
        stack.pop();
    }
}

int Hand::PlayCard(){
    if(isEmpty()){
        throw std::runtime_error("Hand is Empty.\n");
    }
    PointCard pCard = cards_.front();
    pCard.Print();
    if(!(pCard.isPlayable())){
        cards_.pop_front();
        throw std::runtime_error("Card Not playable.\n");
    }
    cards_.pop_front();
    std::cout << "pre stoi in the play card functinon" <<std::endl;
    return std::stoi(pCard.getInstruction());
}