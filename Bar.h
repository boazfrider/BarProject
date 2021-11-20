#ifndef _BAR_H
#define _BAR_H
#include "Table.h"

#include<iostream>
#include<vector>

class Bar{
    private:
    
    int total_income=0;
    std::vector<Table*> tables;
    public:
   
    Bar();
    ~Bar()=default;
    void openNewTabel(int num_of_tabel);
    bool checkTableIsOpen(int num_of_table);
    class TableIsClose : std::exception{};
};
#endif