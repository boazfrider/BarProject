#ifndef _TABLE_H
#define _TABEL_H

#include<iostream>
#include<string>
#include<vector>
class Table{
    private:
        int table_number;
        int total_bill;
        int open_bill;
        bool table_catch;
        std::vector<std::string> items;
        std::vector<int> prices ;

    public:
    Table(int table_number);
    ~Table();
    int getTabelNumber();
    int getTotalBill();
    int getOpenBill(); 
    bool GetTableIsOpen();
    void addToTotalBill(int amount_to_add);
    void addToOpenBill(int amount_to_add);
    void setTableCondition(bool cond);
    void SubOpenBill(int paid_amount);
    void AddItem(std::string item,int price);
    

    friend std::ostream& operator<<(std::ostream& os , const Table* table);
};

#endif