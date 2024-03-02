// ------ function template ----------
#include <iostream>
using namespace std;

template <class T>
T GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return (result);
}
// ------ function template ----------

//++++++ class template +++++++++
template <class T> 
class mypair {
    T a, b;
  public:
    mypair (T first, T second)
      {a=first; b=second;}
    T getmax ();
    T getmax (T t1, T t2);
};

template <class T>
T mypair<T>::getmax ()
{
  return a>b? a : b;
}

template <class T>
T mypair<T>::getmax (T t1, T t2)
{
  return (t1 > t2 ? t1 : t2);
}
//+++++++++++++++++++++++++++++

int main () {
  int i=5, j=6, k;
  long l=10, m=5, n;
  float f1 = 1.5, f2 = 3.3, f3;
  k=GetMax<int>(i,j);
  n=GetMax<long>(l,m);
  f3 = GetMax<float>(f1, f2);
  cout << k << endl;
  cout << n << endl;
  cout << f3 << endl;

  // class template test
  mypair<float> myobj(1.3, 5.5 );
  cout << myobj.getmax() << endl;
  cout << myobj.getmax( 2, 3) << endl;
  return 0;
}