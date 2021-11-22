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
    ~Table();
    int getTabelNumber();
    int getTotalBill();
    int addToTotalBill(int amount_to_add);
    int getOpenBill();
    int addToOpenBill(int amount_to_add);
    bool GetTabelIsOpen();
    void setTabelCondition(bool cond);
    void SubOpenBill(int paid_amount);
    void AddItem(std::string item);
    void AddPrices(int price);

    friend std::ostream& operator<<(std::ostream& os , const Table* table);
};

#endif