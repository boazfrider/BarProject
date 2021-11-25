#include "Item.h"

Item::Item(std::string name,int price) : name(name),price(price) {}
std::string Item::getName(){return name;}
int Item::getPrice(){return price;}
void Item::setPrice(int new_price){
    price=new_price;
}
void Item::setName(std::string newname){
    name=newname;
}