#include "Bar.h"
#include<iostream>
#include<assert.h>
#include<fstream>
#include<vector>
#include<map>
#include<string>
//THIS IS A TEST FOR CHANGE AND UPLOAD TO GITHUB. 








Bar::Bar(){
   
    for(int i=0 ; i<20 ; i++)
    {
        Table* table=new Table(i-1);
        tables.push_back(table);
    }
    //insert the menue from file to map.
    total_income=0;
    total_open_income=0;
    total_seated_table=0;
    std::ifstream menu_file("menue.txt");
    
    std::string menue_line;
    std::string price;
    int price;
    if(!menu_file){
        std::cerr<<"cannot open file "<<"menue.txt"<<std::endl;
    }
     while(std::getline(menu_file,menue_line))
    {
        std::getline(menu_file,price);
        int priceint=stoi(price);
        std::cout<<menue_line<<" "<<priceint<<std::endl;
        menue.insert({menue_line,priceint});
    }

}

