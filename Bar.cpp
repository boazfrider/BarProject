#include "Bar.h"
#include<iostream>
#include<assert.h>
#include<fstream>
#include<vector>
#include<map>
#include<string>
//THIS IS A TEST FOR CHANGE AND UPLOAD TO GITHUB. 





std::map<std::string, int> Bar::getMenu(){
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
        //std::cout<<menu_line<<" "<<priceint<<std::endl;
        menu.insert({menu_line,priceint});
    }
    return menu;
}


Bar::Bar(){
   
    for(int i=0 ; i<20 ; i++)
    {
        Table* table=new Table(i);
        tables.push_back(table);
    }
    //insert the menu from file to map.
    total_income=0;
    total_open_income=0;
    total_seated_table=0;
    menu=getMenu();
}

Bar::Bar(int num_of_tables_to_open){

    for(int i = 0 ; i<num_of_tables_to_open ; i++){
        Table* table=new Table(i);
        tables.push_back(table);
    }
    total_income=0;
    total_open_income=0;
    total_seated_table=0;
    menu=getMenu();
}

