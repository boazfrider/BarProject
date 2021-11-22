#ifndef _BAR_H
#define _BAR_H
#include "Table.h"
//more change
#include<iostream>
#include<vector>
#include<map>

class Bar{
    private:
        int total_income=0;
        int total_open_income;
        int total_seated_table;
        std::vector<Table*> tables;
        std::map<std::string, int> menue;
    public:
    Bar(); 
    Bar(int num_of_tables_to_open);
    ~Bar();

    //Getters and Setters 
    int getTotalIncome();
    int addTototalIncome(int amount_to_add);
    int getOpenIncome();
    int addOpenIncome(int amount_to_add);
    int getTotalSeatedTables();
    void addSeatedTable(); //increase by 1 .
    Table* getTable(int num_of_table);

    //System Functions.
    void welcomePage();
    void openNewTable(int num_of_tabel);
    void openNewTable();
    void createOrder();
    void removeElementFromTable();
    void showMenue();
    void closeBill();
    void showInfoOfTable();
    void daySummery();
    void endDay();    

    //static function - only function for inside use.
    static bool checkTableIsOpen(int num_of_table);
    static Table* andAndGetTable();
    
};
#endif