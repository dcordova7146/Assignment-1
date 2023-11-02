#include "ActionCard.hpp"

ActionCard(){

}

bool isPlayable() override{
    if(this.drawn_/* and valid instruction */){
        return true;
    } return false;
}

void Print() const override{
    /**
         * @post: Print the ActionCard in the following format:
         * Type: [CardType]
         * Instruction: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
         
}