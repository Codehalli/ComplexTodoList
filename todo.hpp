/*
 *  Purpose for program
 *  This programming project generates to do list
 *
 *  Programmer: Pranav Rao
 *  Date: Jan 30 2020
 *
 *  Honor Code: I have neither given nor received any unauthorized assistance with this program.
 */
#include <string> //includes
#include <vector>
#include <fstream>
#include <iostream>
#include "sorted_list.hpp"

class TodoCl //creation a to do class
{
private: //private variables
    char fin; //completed
    std::string txt; //text message
    int  prom; //important
    std::string out_file;//declaring the output file nMW
    //string deleteT; //to delete the strings
public:
    
    TodoCl(); //Constructor for Todo Class
    ~TodoCl(); //Destructor For Todo Class
    
    void finishT(); //finish the text
    void setProm(int priority); //Based on the 1-10 priority
    void setTxt(std::string task); //Setting the task
    void setPromVal();//set the right character
    void setFile(std::string out_file); //seting the proper file
   // void setDelete(string x); //deleting the file
    

    bool getFin();//Finisht text
    int getProm();//get right character
    std::string getTxt();
    int getPromVal(); //get right character
    //string getDelete(); //get function to delete the string
    
    bool operator==(TodoCl rhs) const; //bool operators =
    bool operator>(TodoCl rhs) const; //bool operator greater
    
    void listTasks(int index);
    
};
