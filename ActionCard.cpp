#include "ActionCard.hpp"

ActionCard::ActionCard(){
    setInstruction("");
    setImageData(nullptr);
    setDrawn(false);
    setType(ACTION_CARD);
}

bool ActionCard::isPlayable(){
    return (getDrawn() && validInstro(getInstruction())); // check draw state and validate instruction useing helper method
}

bool ActionCard::validInstro(std::string instro){
    if(instro.empty()){ // first check if the instruction is empty
        return false;
    }
    if(instro == "REVERSE HAND" || instro == "SWAP HAND WITH OPPONENT"){
        return true;
    }
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

    if(words[0] != "PLAY" && words[0] != "DRAW"){
        return false;       
    }

    for(char x : words[1]){ //checking for valid integer value
       if (!(x != '1' || x!= '2' || x!='3'||x!='4'||x!='5'||x!='6'||x!='7'||x!='8'||x!='9'||x!='0')){
        return false;
       }  
    }

    if(words[2] != "CARD" && words[2] != "CARD(S)"){    
        return false;
    }

    return true;
    

}

void ActionCard::Print() const{
    std::cout << "Type: " << getType() << "\nInstruction: ";
    std::cout << getInstruction() + "\nCard: \n";
    if(getImageData() == nullptr){
        std::cout << "No image data\n";
    }else{
        std::cout << getImageData() <<  "\n";
    }
        
}