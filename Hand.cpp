#include "Hand.hpp"

Hand::Hand(){

}
Hand::~Hand(){

}

Hand::Hand(const Hand& other){

}

Hand& Hand::operator=(const Hand& other){

}

Hand::Hand(Hand&& other){

}

Hand& Hand::operator=(Hand&& other){

}

const std::deque<PointCard>& Hand::getCards() const{

}

void Hand::addCard(PointCard&& card){

}

bool Hand::isEmpty() const{

}

void Hand::Reverse(){

}

int Hand::PlayCard(){
    
}