// #include "Tabel.h"
// #include"Bar.h"
#include<iostream>
#include<assert.h>
#include<fstream>
#include<vector>
#include<map>
#include<string>
// void TEST1(){
//     Table table1(1);
//     assert(table1.getTotalBill()==0);
//     assert(table1.getTabelNumber()==1);
//     assert(table1.GetTabelIsOpen()==false);
//     assert(table1.getOpenBill()==0);
// }
// void TEST2(){
//     Table table1(1);
//     assert(table1.getTotalBill()==0);
//     assert(table1.getTabelNumber()==1);
//     assert(table1.GetTabelIsOpen()==false);
//     assert(table1.getOpenBill()==0);
//     table1.AddBill(100);
//     assert(table1.getTotalBill()==100);
//     assert(table1.getOpenBill()==100);
//     table1.SubOpenBill(50);
//     assert(table1.getOpenBill()==50);
// }
// void TEST3(){
//     Bar bar;
//  //   assert(bar.tabels[0]->getTotalBill()==0);
//     bar.openNewTabel(3);
//     bar.openNewTabel(4);
//     assert(bar.checkTableIsOpen(3)==true);
//     assert(bar.checkTableIsOpen(4)==true);
//     try{
//         bar.openNewTabel(3);
//     }
//     catch(Bar::TableIsClose& err)
//     {
//         std::cout<<"error catch";
//     }
// }
std::map<std::string, int> getmenu(){
    std::ifstream menu_file("menu.txt");
    std::map<std::string, int> menu;
    std::string menu_line;
    std::string price;
    
    if(!menu_file){
        std::cerr<<"cannot open file "<<"menu.txt"<<std::endl;
    }
     while(std::getline(menu_file,menu_line))
    {
        std::getline(menu_file,price);
        int priceint=stoi(price);
        menu.insert({menu_line,priceint});
    }
    return menu;
}
void TEST1(){
    std::ifstream menu_file("menu.txt");
    std::map<std::string, int> menue;
    menue=getmenu();
    for (auto itr = menue.begin(); itr != menue.end(); ++itr) {
        std::cout << itr->first
             << '\t' << itr->second << '\n';
    }
    
}
int main()
{
    TEST1();
    //    TEST2();
    //    TEST3();
   std::cout<<("all test pass");
}