#include "Bar.h"
#include<iostream>
#include<assert.h>
#include<fstream>
#include<vector>
#include<map>
#include<string>
//THIS IS A TEST FOR CHANGE AND UPLOAD TO GITHUB. 





std::map<int , Item> Bar::getMenu(){
    std::ifstream menu_file("menu.txt");
    std::map<int , Item> menu;
    std::string menu_line;
    std::string price;
    if(!menu_file){
        std::cerr<<"cannot open file "<<"menu.txt"<<std::endl;
    }
    int item_number=0;
     while(std::getline(menu_file,menu_line))
    {
        std::getline(menu_file,price);
        int priceint=stoi(price);
        Item item(menu_line,priceint);
        //std::cout<<menu_line<<" "<<priceint<<std::endl;
        menu.insert({item_number,item});
        item_number++;
    }
    return menu;
}


Bar::Bar(){
   
    for(int i=0 ; i<20 ; i++)
    {
        Table* table=new Table(i);
        tables.push_back(table);
    }
    //insert the menu from file to map.
    total_income=0;
    total_open_income=0;
    total_seated_table=0;
    menu=getMenu();
}

Bar::Bar(int num_of_tables_to_open){

    for(int i = 0 ; i<num_of_tables_to_open ; i++){
        Table* table=new Table(i);
        tables.push_back(table);
    }
    total_income=0;
    total_open_income=0;
    total_seated_table=0;
    menu=getMenu();
}
Bar::~Bar(){

}

int Bar::getTotalIncome(){
    return total_income;
}
int Bar::getOpenIncome(){
    return total_open_income;
}
int Bar::getTotalSeatedTables(){
    return total_seated_table;
}
void Bar::addSeatedTable(){
    total_seated_table++;
}
Table* Bar::askAndGetTable(){
    std::cout<<"Which Table ?"<<std::endl;
    int num;
    std::cin>>num;
    if(num>tables.size()|| num<0)
    {
        std::cerr<<"NUMBER OF TABLE DOESENT EXIST.";
        throw std::overflow_error("number dosent exist.");
        //MAYBE THROW ERROR ?
    }
    return tables.at(num-1);
}

bool Bar::checkTableIsOpen(int num_of_table){
    return tables[num_of_table]->GetTableIsOpen();
}
void Bar::addTototalIncome(int amount_to_add){
    total_income+=amount_to_add;
}
void Bar::addOpenIncome(int amount_to_add){
    total_open_income+=amount_to_add;
}
void Bar::welcomePage(){

}

void Bar::openNewTable(int num_of_table){
    if(num_of_table>tables.size() || num_of_table<0)
    {
        std::cerr<<"NUMBER OF TABLE DOESNT EXIST";
    }
    if(tables[num_of_table-1]->GetTableIsOpen()==true)
    {
        std::cerr<<"table if already taken";
    }
    else
        tables[num_of_table-1]->setTableCondition(true);
}
void Bar::createOrder(){
    Table* table=askAndGetTable();
    std::cout<<"enter -1 to end the order";
    showMenu();
    std::string item;
    int price;

    std::cin
    
}