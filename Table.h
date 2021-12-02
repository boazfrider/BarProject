#ifndef _TABLE_H
#define _TABEL_H
#include "Item.h"
#include <iostream>
#include <string>
#include <vector>
#include<ctime>
class Table{
    private:
        int table_number;
        int total_bill;
        int open_bill;
        bool table_catch;
        std::vector<Item*> items;
        

    public:
    Table(int table_number);
    ~Table();
    int getTabelNumber();
    int getTotalBill();
    int getOpenBill(); 
    bool GetTableIsOpen(); //true=catch ! false=empty table
    void addToTotalBill(int amount_to_add);
    void addToOpenBill(int amount_to_add);
    void setTableCondition(bool cond);
    void SubOpenBill(int paid_amount);
    void AddItem(Item* item);

    friend std::ostream& operator<<(std::ostream& os , const Table& table);
};

#endif