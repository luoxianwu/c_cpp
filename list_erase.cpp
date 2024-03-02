// erasing from list
#include <iostream>
#include <list>
using namespace std;

class T{
    public:
    string nm;
    int    tel;

    T( string n, int t ) :nm(n), tel(t) {}
    void show() { cout << nm << "," << tel << endl; }
};

T t[] = { T("A", 1), T("B", 2), T("c", 3), T("D", 4), T("E", 5), T("F", 6) };

int main ()
{
  list<class T> mylist;
  
  // set some values:
  for (int i=0; i<6; ++i) mylist.push_back(t[i]);

  for( auto t : mylist ){
    t.show();
   }

   cout << "erase a element name==\"E\"" << endl;

    list<class T>::iterator it = mylist.begin();

    for( it; it != mylist.end(); it++ )
        if( it->nm == "E")
            break;

    mylist.erase(it);

    for( auto t : mylist ){
    t.show();
   }  

  return 0;
}