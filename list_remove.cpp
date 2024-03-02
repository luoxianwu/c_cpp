/*In the code below we are inserting elements to the list and 
then we will try to remove the elements from the list using their values. */
#include <bits/stdc++.h>
using namespace std;
int main(){
   //create a list
   list<int> myList;
   //insert elements to the List
   myList.push_back(1);
   myList.push_back(1);
   myList.push_back(3);
   myList.push_back(2);
   myList.push_back(5);
   myList.push_back(1);
   //my list before removing elements
   cout<<"List before removing elements: ";
   for (auto i = myList.begin(); i!=myList.end(); i++){
      cout << *i << " ";
   }
   //deleting 1 2 and 3 from the list
   myList.remove(1);
   myList.remove(2);
   myList.remove(3);
   // List after removing elements
   cout << "\nList after removing elements: ";
   for (auto i = myList.begin(); i!= myList.end(); i++){
      cout << *i << " ";
   }

    cout << endl;

    list<string> myList2;
    myList2.push_back("abc");
    myList2.push_back("123");
    myList2.push_back("xyzz");
    myList2.push_back("123");

    cout<<"List before removing elements: ";
    for (auto i = myList2.begin(); i!=myList2.end(); i++){
        cout << *i << " ";
    }

    myList2.remove("123");
    cout<<"\nList after removing elements: ";
    for (auto i = myList2.begin(); i!=myList2.end(); i++){
        cout << *i << " ";
    }

    cout << endl;
    
    return 0;
}