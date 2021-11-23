#ifndef _BAR_H
#define _BAR_H
#include "Table.h"
//more change
#include<iostream>
#include<fstream>
#include<vector>
#include<map>

class Bar{
    private:
        int total_income=0;
        int total_open_income;
        int total_seated_table;
        std::vector<Table*> tables;
        std::map<std::string, int> menu;
    public:
    Bar(); 
    Bar(int num_of_tables_to_open);
    ~Bar();

    //Getters and Setters 
    int getTotalIncome();
    int getOpenIncome();
    
    int getTotalSeatedTables();
    void addSeatedTable(); //increase by 1 .
    static Table* askAndGetTable();
    static  std::map<std::string, int> getMenu();

    //System Functions.
    void welcomePage();
    void openNewTable(int num_of_tabel);
    void openNewTable();
    void createOrder();
    void removeElementFromTable();
    void showMenu();
    void closeBill();
    void showInfoOfTable();
    void daySummery();
    void endDay();    

    //static function - only function for inside use.
    static bool checkTableIsOpen(int num_of_table);
    static int addTototalIncome(int amount_to_add);
    static int addOpenIncome(int amount_to_add);
};
#endif