#include <iostream>
#include "doubly_linked_list.hpp"

int main()
{
	Doubly_linked_list<int> list;
	//add some elements to the list
	list.push_back(1);
	list.push_back(2);
	list.push_front(3);

	//print list
	list.print();

	//print front value of the list
	std::cout<<list.front()<<std::endl;
        
        //print back value of the list	
	std::cout<<list.back()<<std::endl;
        
        //remove the last element of the list	
	list.pop_back();
	list.print();
        
        //reverse the list	
	list.reverse();
	list.print();

	//add some element to the list
	list.insert(0,14);
        list.print();
	return 0;
}
