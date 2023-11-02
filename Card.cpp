#include "Card.hpp"

~Card(){} 

Card(const Card& rhs){ 
    instruction_ = "";
    bitmap_ = nullptr;
    drawn = false;
}

Card& operator=(const Card& rhs){

}

Card(Card&& rhs){

}

Card& operator=(Card&& rhs){

}

Card(Card&& rhs){

}

Card& operator=(Card&& rhs){

}

Card(){
    instruction_ = "";
    bitmap_ = nullptr;
    drawn = false;
}

std::string getType() const{
    return cardType_;
}

void setType(const CardType& type){
    this.cardType_ = type;
}

const std::string& getInstruction() const{
    return instruction_;
}

void setInstruction(const std::string& instruction){
    this.instruction_ = instruction;
}

const int* getImageData() const{
    return bitmap_;
}

void setImageData(int* data){
    bitmap_ = data*;
}

bool getDrawn() const{
    return drawn_;
}

void setDrawn(const bool& drawn){
    this.drawn_ = drawn
}