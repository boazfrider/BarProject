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
        bool tabel_open;
        std::vector<std::string> items;
        std::vector<int> prices ;

    public:
    Table(int tabel_number);
    ~Table()=default;
    int getTabelNumber();
    int getTotalBill();
    int getOpenBill();
    bool GetTabelIsOpen();
    void setTabelCondition(bool cond);
    void AddBill(int adding_price);
    void SubOpenBill(int paid_amount);
    void AddItem(std::string item);
    void AddPrices(int price);
};

#endif