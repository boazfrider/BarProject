#ifndef _Item_H
#define _Item_H

#include<iostream>

class Item{
    private:
        std::string name;
        int price;
    public:
        Item()=default;
        Item(std::string name,int price);
        Item(const Item& item)=default;
        Item& operator=(const Item& item)=default;
        ~Item()=default;

        std::string getName();
        int getPrice();
        void setPrice(int new_price);
        void setName(std::string newname);


};
#endif