#include "Card.hpp"

Card::~Card(){ //destructor
    delete bitmap_;
} 

Card::Card(const Card& rhs){ //copy constructor
    instruction_ = rhs.instruction_;
    bitmap_ = new int(*rhs.bitmap_);
    drawn_ = rhs.drawn_;
}

Card& Card::operator=(const Card& rhs){ //copy assignment operator
    if(this != &rhs){
        *bitmap_ = *rhs.bitmap_; 
        instruction_ = rhs.instruction_;
        drawn_ = rhs.drawn_;  
    }
    return *this;
}

Card::Card(Card&& rhs):bitmap_(rhs.bitmap_){ //move constructor
    rhs.bitmap_ = nullptr;

}

Card& Card::operator=(Card&& rhs){ //move assignment operator
    
    std::swap(bitmap_, rhs.bitmap_);
    std::swap(instruction_, rhs.instruction_);
    std::swap(drawn_, rhs.drawn_);
    return *this;

}

Card::Card(){ //default contrusctor
    instruction_ = "";
    bitmap_ = nullptr;
    drawn_ = false;
}

std::string Card::getType() const{
    if(cardType_ == POINT_CARD){
        return "POINT_CARD";
    }
    if(cardType_ == ACTION_CARD){
        return "ACTION_CARD";
    }
    return "";
}

void Card::setType(const CardType& type){
    cardType_ = type;
}

const std::string& Card::getInstruction() const{
    return instruction_;
}

void Card::setInstruction(const std::string& instruction){
    instruction_ = instruction;
}

const int* Card::getImageData() const{
    return bitmap_;
}

void Card::setImageData(int* data){
    bitmap_ = data;
}

bool Card::getDrawn() const{
    return drawn_;
}

void Card:: setDrawn(const bool& drawn){
    drawn_ = drawn;
}