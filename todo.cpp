/*
 *  Purpose for program
 *  This programming project generates to do list
 *
 *  Programmer: Pranav Rao
 *  Date: Jan 30 2020
 *
 *  Honor Code: I have neither given nor received any unauthorized assistance with this program.
 */
#include "todo.hpp"
//TA implementation
TodoCl::TodoCl() //Constructor for Todo Class
{
    fin = ' ';
    txt = "";
    prom = 5;
    out_file = "todo.txt";
}

TodoCl::~TodoCl() //Destructor For Todo Class
{}

void TodoCl::listTasks(int index) //This function displays the list tasks
{
    if(prom > 10)
    {
        prom = prom - 10;
    }
    std::ofstream out(out_file);
    std::cout << index <<":[" << fin << "]" << "[" << prom << "] " << getTxt() << std::endl;
}

void TodoCl::setTxt(std::string task) //Setting the task
{
    txt = task;
}

int TodoCl::getProm() //get the right character
{
    return prom;
}

std::string TodoCl::getTxt() //get the text
{
    return txt;
}

int TodoCl::getPromVal() //get right character
{
    return prom;
}

void TodoCl::finishT() //Finish the text
{
    fin = 'x'; //setting the right value
    prom = prom + 10; //since it's till 10
}

void TodoCl::setProm(int priority) //set the right character
{
    prom = priority;
}

bool TodoCl::getFin() //Finish text
{
    return(fin == 'x');
}

//void TodoCl::setDelete(string x) //to delete the string
//{
//    deleteT = x;
//}
//
//string TodoCl::getDelete()
//{
//    return deleteT;
//}

bool TodoCl::operator==(TodoCl rhs) const //Operator Constructor
{
    TodoCl lhs = *this;
    return(lhs.fin == rhs.fin && lhs.txt == rhs.txt && lhs.prom == rhs.prom);
}

bool TodoCl::operator>(TodoCl rhs) const //operator for least importance
{
    TodoCl lhs = *this;
    
    return(lhs.prom>rhs.prom);
}
