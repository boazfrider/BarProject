#include"Table.h"

Table::Table(int table_number):table_number(table_number){
    total_bill=0;
    open_bill=0;
    table_catch=false;
}
Table::~Table(){

}

int Table::getTabelNumber(){ 
    return table_number;
}
int Table::getTotalBill(){
    return total_bill;
}
int Table::getOpenBill()
{
    return open_bill;
}
bool Table::GetTableIsOpen(){
    return table_catch;

}
void Table::addToTotalBill(int amount_to_add){
    total_bill+=amount_to_add;
}
void Table::addToOpenBill(int amount_to_add){
    open_bill+=amount_to_add;
}
void Table::setTableCondition(bool cond){
    table_catch=cond;
}
void Table::SubOpenBill(int paid_amount){
    open_bill-=paid_amount;
}
void Table::AddItem(Item* item){

    items.push_back(item);
    addToOpenBill(item->getPrice());
    addToTotalBill(item->getPrice());
    
}

std::ostream& operator<<(std::ostream& os , const Table& table){
    os<<"in";
    os << "Table number : "<<table.table_number <<std::endl;
    os << "Total Bill :" <<table.total_bill <<std::endl;
    os<< "Open Bill : "<<table.open_bill << std::endl;
    os<<"Items"<<std::endl;
    for(int i=0 ; i < table.items.size() ; i++)
    {
        os<<table.items[i]->getName()<<"-"<<table.items[i]->getPrice()<<std::endl;
    }
    return os;
}
