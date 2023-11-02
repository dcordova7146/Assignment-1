#include "PointCard.hpp"

PointCard(){

}

bool isPlayable() override{
    return (this.drawn_ && std::stoi(this.instruction_)); //check stoi function 
}

void Print() const override{
    std::cout <<
    /**
         * @post: Print the Point Card in the following format:
         * Type: [CardType]
         * Points: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
}