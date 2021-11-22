#include "Bar.h"
//THIS IS A TEST FOR CHANGE AND UPLOAD TO GITHUB. 
Bar::Bar(){
    tables.resize(20);
    for(int i=0 ; i<20 ; i++)
    {
        Table* table=new Table(i-1);
        tables.push_back(table);
    }
}

void Bar::openNewTable(int num_of_tabel)
{
    if ( tables[num_of_tabel-1]->GetTabelIsOpen())
    {
        //need to throw the table is catch
        throw TableIsClose();
        
    }
    tables[num_of_tabel-1]->setTabelCondition(true);
}
bool Bar::checkTableIsOpen(int num_of_table)
{
    
    return  tables[num_of_table-1]->GetTabelIsOpen();
}
void Bar::subBillFromTable(int num_of_table, int amount_to_sub)
{
    tables[num_of_table-1]->SubOpenBill(amount_to_sub);
}