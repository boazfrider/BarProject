// #include "Tabel.h"
#include"Bar.h"
#include "Item.h"
#include<iostream>
#include<assert.h>
#include<fstream>
#include<vector>
#include<map>
#include<string>

// void Bar::welcomePage(){
//     std::cout<<"    WELCOME PAGE-MAIN PAGE    "<<std::endl;
//     std::cout<<"1 - Open New Table"<<std::endl<< "2 - Create New Order"<<std::endl <<"3 - Remove Item from Table"<<std::endl;
//     std::cout<<"4 - Close Bill" <<std::endl;
//     std::cout<<"5 - Show Information about table"<<std::endl;
//     int funcnum;
//     std::cout<<"Which operation would you like to do ? "<<std::endl;
//     std::cin>>funcnum;
//     switch (funcnum)
//     {
//         case (1):
//         openNewTable();
//         break;
    
//         case (2):
//         createOrder();
//         /* code */
//         break;
//         case (3):
//         removeElementFromTable();
//         /* code */
//         break;
//         case (4):
//         closeBill();
//         /* code */
//         break;
//         case (5):
//         showInfoOfTable();
//         /* code */
//         break;
//     }

// }

void TEST5(){
    Bar bar(10);
    try{
    bar.openNewTable(1);
    bar.addItemToTable(1,1); //1-Half hoegaarden = 25 sehkel.
    bar.addItemToTable(1,2);
    bar.addItemToTable(1,7);
    bar.showInfoOfTable(1);
    bar.closeBill(1,350);
    bar.showInfoOfTable(1);
    }
    catch(std::overflow_error& err)
    {
        std::cout<<err.what()<<std::endl;
    }
    
   
}
int main()
{
   // TEST1();
    //    TEST2();
    //    TEST3();
    
 //  TEST2();
 TEST5();

   std::cout<<("all test pass");
}