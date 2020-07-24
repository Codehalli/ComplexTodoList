/*
 *  Purpose for program
 *  This programming project generates to do list
 *
 *  Programmer: Pranav Rao
 *  Date: Jan 30 2020
 *
 *  Honor Code: I have neither given nor received any unauthorized assistance with this program.
 */

//main functions
#include "sorted_list.hpp" //includes
#include "todo.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
//Main through the command line
void add(TodoCl todo, SortedList<TodoCl>* todoL);
void getL(string getFile, SortedList<TodoCl>* todoL);
void sendL(ofstream &out, SortedList<TodoCl>* mylist);

void add(TodoCl todo, SortedList<TodoCl>* todoL) //This is the add funciton
{
    todoL->insertSorted(todo);
}

void getL(string getFile, SortedList<TodoCl>* todoL) //This is the get Line funciton
{
    
    ifstream input;
    input.open(getFile);
    int prior;
    
    string prio; //These are the variables
    string mark;
    string text;
    
    if(!input.fail())
    {
        getline(input,mark,',');
        getline(input,prio, ',');
        
        prior = atoi(prio.c_str());
        getline(input,text, '\n'); //get line
    }
    
    while(!input.fail())
    {
        TodoCl temporaryDo;
        temporaryDo.setProm(prior);
        temporaryDo.setTxt(text);
        
        if(mark == "x") //symbol for mark x
        {
            temporaryDo.finishT();
        }
        add(temporaryDo, todoL);
        
        getline(input,mark,',');
        getline(input,prio, ',');
        prior = atoi(prio.c_str());
        getline(input,text);
    }
    
    input.close(); //input close
}

void sendL(ofstream &out,  SortedList<TodoCl>*  mylist) //Send List
{
    for(int k = 1; k <=  mylist->getLength(); k++)
    {
        if( mylist->getEntry(k).getFin()) //get my list
        {
            out << "x" << "," <<  mylist->getEntry(k).getProm() - 10  << "," <<  mylist->getEntry(k).getTxt()<<endl;
        }
        else
        {
            out << "n" << "," <<  mylist->getEntry(k).getProm() << "," <<  mylist->getEntry(k).getTxt() << endl;
        }
    }
}

int main(int argc, char *argv[])
{
    SortedList<TodoCl> todoL;
    
    string inputFile = "note.txt"; //file name for the input
    getL(inputFile, &todoL);
    
    ofstream outputFile; //output file
    outputFile.open("note.txt" , std::ofstream::out | std::ofstream::trunc);
    
    string enter = argv[1];
    
    if(enter == "add") //add function
    {
        string text;
        string phrase;
        
        for(int k = 2 ; k < argc; k++)
        {
            phrase = argv[k];
            text.append(phrase);
            text.append(" ");
        }
        
        TodoCl todo;
        todo.setProm(5);
        todo.setTxt(text);
        add(todo, &todoL);
    }
    
    if(enter == "-p") ///conditon for the priority
    {
        int prio = atoi(argv[2]);
        string aComment = argv[3];
        string text;
        string phrase;
        
        for (int k = 4; k < argc; k++)
        {
            phrase = argv[k];
            text.append(phrase);
            text.append(" ");
        }
        
        TodoCl todo;
        if(prio <=  10 && prio >= 1)
        {
            todo.setProm(prio);
        }
        todo.setTxt(text);
        add(todo, &todoL);
    }
    if(enter == "-f") //condtion  for finished
    {
        string sFile  = argv[2];
        outputFile.open(sFile);
    }
    if(enter == "mark") //make the it complete
    {
        std::size_t subenter;
        subenter = atoi(argv[2]);
        TodoCl done;
        
        done.setTxt(todoL.getEntry(subenter).getTxt());
        done.setProm(todoL.getEntry(subenter).getProm());
        done.finishT();
        
        todoL.remove(subenter);
        add(done, &todoL);
    }
    if(enter == "list") //create the list
    {
        for(size_t k = 1; k <= todoL.getLength();k++)
        {
            todoL.getEntry(k).listTasks(k);
        }
    }
    
    sendL(outputFile, &todoL);
}
//This is end of the main


