#include "PointCard.hpp"

PointCard::PointCard(){
    setType(POINT_CARD);
    setInstruction("");
    setImageData(nullptr);
    setDrawn(false);
}

bool PointCard::isPlayable(){
    std::string instro = getInstruction();
    for(char x : instro){ //iterate through an instruction and test if it is a number
       if (!(x != '1' || x!= '2' || x!='3'||x!='4'||x!='5'||x!='6'||x!='7'||x!='8'||x!='9'||x!='0')){
        return false;
       }
    }   
    return (getDrawn()); //valid instruction is implied so all is left is to check draw state
}

void PointCard::Print() const{
    std::cout << "Type: " << getType() << std::endl;
    std::cout <<"Points: "<< getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;
    if(getImageData() == nullptr){
        std::cout << "No image data" <<std::endl;
    }else{
        std::cout << getImageData() <<std::endl;
    }
}