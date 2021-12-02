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
        // std::cout<<item_number <<"-"<<item.getName() << "-"<<item.getPrice()<<std::endl;
        menu.insert({item_number,item});
        item_number++;
    }
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
    menu=getMenu();
}

Bar::Bar(int num_of_tables_to_open){

    for(int i = 0 ; i<num_of_tables_to_open ; i++){
        Table* table=new Table(i+1);
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
   if(tables.at(num-1)->GetTableIsOpen()==false)
   {
      std::cout<<"The table is close. Whould you like to open this table? Y/N"<<std::endl;
        char ch;
        std::cin >> ch;
        if(ch=='Y')
        {
            openNewTable();
            return tables.at(num-1);
        }
        else{
            std::cout<<"return to start"<<std::endl;
            throw std::overflow_error("Not the right table");
        }
   }
    
    return tables.at(num-1);
}

bool Bar::checkTableIsOpen(int num_of_table){
    return tables[num_of_table-1]->GetTableIsOpen();
}
void Bar::addTototalIncome(int amount_to_add){
    total_income+=amount_to_add;
}
void Bar::addOpenIncome(int amount_to_add){
    total_open_income+=amount_to_add;
}
void Bar::welcomePage(){
    std::cout<<"    WELCOME PAGE-MAIN PAGE    "<<std::endl;
    std::cout<<"1 - Open New Table"<<std::endl<< "2 - Create New Order"<<std::endl <<"3 - Remove Item from Table"<<std::endl;
    std::cout<<"4 - Close Bill" <<std::endl;
    std::cout<<"5 - Show Information about table"<<std::endl;
    int funcnum;
    std::cout<<"Which operation would you like to do ? "<<std::endl;
    std::cin>>funcnum;
    switch (funcnum)
    {
        case (1):
        openNewTable();
        break;
    
        case (2):
        createOrder();
        /* code */
        break;
        case (3):
        removeElementFromTable();
        /* code */
        break;
        case (4):
        closeBill();
        /* code */
        break;
        case (5):
        showInfoOfTable();
        /* code */
        break;
    }

}

void Bar::openNewTable(){
    int num_of_table;
    std::cout<<"Which Table to open ? ";
    std::cin>>num_of_table;
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
    welcomePage();
}
void Bar::createOrder(){
    std::cout<<"    CREATE ORDER SECTION    " <<std::endl;
    Table* table;
try{
    table=askAndGetTable();
}
catch(std::overflow_error& err){
    return;
}
    
  
    std::cout<<"enter -1 to end the order";
    showMenu();
    int index;
    std::cout<<"Enter the number of the item"<<std::endl;
    std::cin>>index;
    while(index!=-1)
    {
        table->AddItem(&menu[index]);
        std::cin>>index;
    }
    std::cout<<"THE ITEMS ADDED TO THE TABLE !";
    welcomePage();

   
    
}
void Bar::removeElementFromTable(){

}
void Bar::closeBill(){
    again1: std::cout<<"    CLOSE BILL SECTION    " <<std::endl;
    Table* table ;
    
    table= askAndGetTable();    
    int amount=0;
    again: std::cout<<"pay amount ?" <<std::endl;
    std::cin>>amount;
    try{
            
            table->SubOpenBill(amount);

    }
    catch(std::overflow_error& err)
    {
        goto again;
    }
    
    if(table->getOpenBill()==0){
        std::ofstream history;
        history.open("history.txt", std::ios::out | std::ios::app);
        history << *table;
        history.close();
    }
    welcomePage();
}
void Bar::showInfoOfTable(){
    Table* table = askAndGetTable();
    std::cout << *table;
    welcomePage();
}
void Bar::showMenu(){
    for(auto& t : menu){
        std::cout<<t.first <<"-"<<t.second.getName() << "-"<<t.second.getPrice()<<std::endl;
    }
}