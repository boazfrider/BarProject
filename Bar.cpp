#include "Bar.h"
#include<iostream>
#include<assert.h>
#include<fstream>
#include<vector>
#include<map>
#include<string>
//THIS IS A TEST FOR CHANGE AND UPLOAD TO GITHUB. 





std::map<int , Item> Bar::setMenu(){
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
        // std::cout<<item_number <<"-"<<item.getName() << "-"<<item.getPrice()<<std::endl;
        menu.insert({item_number,item});
        item_number++;
    }
    return menu;
}
std::map<int , Item> Bar::getMenu(){
    return menu;
}


Bar::Bar(){
   
    for(int i=0 ; i<20 ; i++)
    {
        Table* table=new Table(i+1);
        tables.push_back(table);
    }
    //insert the menu from file to map.
    total_income=0;
    total_open_income=0;
    total_seated_table=0;
    menu=setMenu();
}

Bar::Bar(int num_of_tables_to_open){

    for(int i = 0 ; i<num_of_tables_to_open ; i++){
        Table* table=new Table(i+1);
        tables.push_back(table);
    }
    total_income=0;
    total_open_income=0;
    total_seated_table=0;
    menu=setMenu();
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
Table* Bar::GetTable(int table_number){
    if(table_number<0 || table_number>=tables.size())
    {
        throw IlleglArgument("Table number dosent exist");
    }
    return tables[table_number-1];
}

void Bar::checkValidTableNum(int num_of_table){
    if(num_of_table<=0 || num_of_table>tables.size())
         throw InvalidNumOfTable("The number of table dosent exist");
}
void Bar::checkTableIsOpen(int num_of_table){
    if( tables[num_of_table-1]->GetTableIsOpen()==false)
        throw TableAlreadyOpen("The table is not open");
}
void Bar::addTototalIncome(int amount_to_add){
    total_income+=amount_to_add;
}
void Bar::addOpenIncome(int amount_to_add){
    total_open_income+=amount_to_add;
}

void Bar::openNewTable(int num_of_table){

    checkValidTableNum(num_of_table);
   //checkTableIsOpen(num_of_table);
   if(tables.at(num_of_table-1)->GetTableIsOpen()==true)
   {
       throw TableAlreadyOpen("The table Already open !");
   }
    
    tables[num_of_table-1]->setTableCondition(true);
    total_seated_table++;
}

void Bar::addItemToTable(int num_of_table,int item_index){
    checkValidTableNum(num_of_table);
    checkTableIsOpen(num_of_table);
    tables[num_of_table-1]->AddItem(&menu[item_index]);
    addOpenIncome(menu[item_index].getPrice());
    addTototalIncome(menu[item_index].getPrice());
}
void Bar::removeElementFromTable(){

}



void Bar::closeBill(int table_number , int amount){
    checkValidTableNum(table_number);

    Table* table = GetTable(table_number);
    if(amount > table->getOpenBill())
    {
        throw IlleglArgument("amount bigger then current bill");
        
    }


    tables[table_number-1]->SubOpenBill(amount);
    addOpenIncome(-amount);
    if( tables[table_number-1]->getOpenBill()==0){
        std::ofstream history;
        history.open("history.txt", std::ios::out | std::ios::app);
        history << *tables[table_number-1];
        history.close();
    }
    
   
}
void Bar::showInfoOfTable(int table_number){

    checkValidTableNum(table_number);
    std::cout << *tables[table_number-1];

}

void Bar::daySummery(){
    time_t now=time(0);
    std::string date=ctime(&now);
        std::ofstream day_summary;
        day_summary.open("daySummery.txt", std::ios::out | std::ios::app);
        day_summary <<date <<std::endl;
        day_summary <<"Total seated tables : " << total_seated_table <<std::endl;
        day_summary <<"Total Income : " << total_income << std::endl;
        day_summary <<"Total Open Income " << total_open_income << std::endl;
        day_summary <<"******************************************" << std::endl;
        day_summary.close();
}