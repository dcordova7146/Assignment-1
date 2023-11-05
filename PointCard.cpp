#include "PointCard.hpp"

PointCard::PointCard(){
    setType(POINT_CARD);
    setInstruction("");
    setImageData(nullptr);
    setDrawn(false);
}

bool PointCard::isPlayable(){
    std::string instro = getInstruction();
    for(char x : instro){
       if (!(x != '1' || x!= '2' || x!='3'||x!='4'||x!='5'||x!='6'||x!='7'||x!='8'||x!='9'||x!='0')){
        return false;
       }
    }   
    return (getDrawn()); 
}

void PointCard::Print() const{
    std::cout << "Type: " << getType() << "\nPoints: ";
    std::cout << getInstruction() + "\nCard: \n";
    if(getImageData() == nullptr){
        std::cout << "No image data\n";
    }else{
        std::cout << getImageData() <<  "\n";
    }
}