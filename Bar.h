#ifndef _BAR_H
#define _BAR_H
#include "Table.h"
//more change
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include"Item.h"

class Bar{
    private:
        int total_income=0;
        int total_open_income;
        int total_seated_table;
        std::vector<Table*> tables;
        std::map<int , Item> menu;

       


    public:
    Bar(); 
    Bar(int num_of_tables_to_open);
    ~Bar();

    //Getters and Setters 
    int getTotalIncome();
    int getOpenIncome();
    int getTotalSeatedTables();
    void addSeatedTable();
    Table* askAndGetTable();
    std::map<int , Item> getMenu();

    //static function - only function for inside use.
    bool checkTableIsOpen(int num_of_table);
    void addTototalIncome(int amount_to_add);
    void addOpenIncome(int amount_to_add); 
    
    //System Functions.
    void welcomePage();
    void openNewTable(int num_of_table);
    //void openNewTable();
    void createOrder();
    void removeElementFromTable();
    void closeBill();
    void showInfoOfTable();
    void daySummery();
    void endDay();    
    void showMenu();
}; 
 
#endif