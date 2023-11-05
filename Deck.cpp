#include "Deck.hpp"

template <typename CardType>
Deck<CardType>::Deck(){
}

template <typename CardType>
Deck<CardType>::~Deck(){
    cards_.clear();
}

template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card){
    cards_.push_back(card);
}

template <typename CardType>
CardType&& Deck<CardType>::Draw(){ 
    if(IsEmpty()){
        std::runtime_error("Deck is Empty");
    }
    CardType dCard = std::move(cards_.back());
    cards_.pop_back();
    dCard.setDrawn(true);
    return std::move(dCard);
}

template <typename CardType>
bool Deck<CardType>::IsEmpty() const{
    return(cards_.empty());
}

template <typename CardType>
void Deck<CardType>::Shuffle(){
    std::mt19937 seed(2028358904);
    std::shuffle(cards_.begin(), cards_.end(), seed);
}

template <typename CardType>
int Deck<CardType>::getSize() const{
    return cards_.size();
}

template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const{
    return cards_;
    
}