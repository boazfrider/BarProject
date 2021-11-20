#include "Bar.h"
//THIS IS A TEST FOR CHANGE AND UPLOAD TO GITHUB. 
Bar::Bar(){
    tables.resize(20);
    for(int i=0 ; i<20 ; i++)
    {
        tables[i]=new Table(i+1);
    }
}

void Bar::openNewTabel(int num_of_tabel)
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