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
    bar.closeBill(1,50);
    bar.showInfoOfTable(1);
    bar.daySummery();
    }
    catch(std::overflow_error& err)
    {
        std::cout<<err.what()<<std::endl;
    }
    catch(std::exception& err)
    {
        std::cout<<err.what()<<std::endl;
    }
   
}
// void TEST6(){
//     Bar bar(10);
//     try{
//         bar.openNewTable(11);
        
//     }
//     // catch(TableAlreadyOpen& err)
//     // {
//     //     std::cout<<err.what();
//     // }
//     catch(std::exception& err)
//     {
//         std::cout<<err.what();
//     }
    

// }
void Test1(){
    Bar bar(10);
    try{
        bar.openNewTable(1);
        bar.openNewTable(2);
        bar.addItemToTable(1,0);
       bar.addItemToTable(1,1);
       bar.addItemToTable(1,2);
       bar.addItemToTable(1,4);
       bar.showInfoOfTable(1);
       bar.closeBill(1,25);
       bar.showInfoOfTable(1);
       bar.showInfoOfTable(2);
       bar.daySummery();
    }
    catch(std::exception& err){
        std::cout<<err.what() << std::endl;
    }
        
    
}
void system(){
    Bar bar(10);
    int funcnum;
    do{

    std::cout<<"    WELCOME PAGE-MAIN PAGE    "<<std::endl;
    std::cout<<"1 - Open New Table"<<std::endl<< "2 - Create New Order"<<std::endl <<"3 - Remove Item from Table"<<std::endl;
    std::cout<<"4 - Close Bill" <<std::endl;
    std::cout<<"5 - Show Information about table"<<std::endl;
    std::cout<<"6 - Day Summery "<<std::endl;
    std::cout<<"7 - Close Table"<<std::endl;
    std::cout<< "-1 - exit" <<std::endl;
    std::cout<<"Which operation would you like to do ? "<<std::endl;
    std::cin>>funcnum;
    switch (funcnum)
    {
        case (1):
         std::cout<<"        OPEN NEW TABLE SECTION          "<<std::endl;
         std::cout<<"Which Table whould you like to sit ? ";
         int num;
        std::cin>>num;
        try{
        bar.openNewTable(num);
        }
        catch(std::exception& err){
            std::cout<<err.what()<<std::endl;
            std::cout<<" your order was canceld , try again !";
        }
        break;
    
        case (2):
             std::cout<<"       ADD ITEM TO TABLE SECTION          "<<std::endl;
            std::cout<<"for Which Table you are order ? " <<std::endl;
            int num2;
            int item;
            std::cin>>num2;
            do{
            std::cout<<"which item from the menu? ,press -1 for done " << std::endl;
            std::cin>>item;
            try{
                bar.addItemToTable(num2,item);
            }
            catch(std::exception& err){
            std::cout<<err.what()<<std::endl;
            std::cout<<" your order was canceld , try again !";
        }
            }while(item!=-1);
        break;
        case (3):
          //  removeElementFromTable();
            /* code */
            break;
        case (4):
            std::cout<<"        CLOSE BILL SECTION          "<<std::endl;
            int num_table;
            std::cout<<"Which Table you sit ? "<<std::endl;
            std::cin>>num_table ;
            std::cout<<"How much do you want to pay ?" << std::endl;
            int amount; std::cin>>amount;
            try{
                bar.closeBill(num_table,amount);
            }
            catch(std::exception& err){
            std::cout<<err.what()<<std::endl;
            std::cout<<" your order was canceld , try again !";
            break;
            }
         break;
         case (5):
             std::cout<<"       INFORMATION ABOUT TABLE SECTION         "<<std::endl;  
             int num_table5;
             std::cout<<"Which Table you sit ? "<<std::endl;
             std::cin>>num_table5 ;
             try{
             bar.showInfoOfTable(num_table5);
             }
             catch(std::exception& err){
            std::cout<<err.what()<<std::endl;
            std::cout<<" your order was canceld , try again !";
            break;
        }
             
        break;
        case(6):
            bar.daySummery();
            break;
        case(7):
            std::cout<<"       CLEAR TABLE SECTION         "<<std::endl;  
             int num_table7;
             std::cout<<"Which Table you sit ? "<<std::endl;
             std::cin>>num_table7 ;
             try{
             bar.closeTable(num_table7);
             }
             catch(std::exception& err){
            std::cout<<err.what()<<std::endl;
            std::cout<<" your order was canceld , try again !";
            break;
             }

    }
    }while(funcnum!=-1);
        
    
    
}
int main()
{
  system();
  std::cout<<"good day !"<<std::endl;
}