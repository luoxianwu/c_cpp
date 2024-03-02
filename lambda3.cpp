#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template<class InputString, class OutputInt>
bool unhexlify(const InputString& input, OutputInt& output)
{
    for_each( input.begin(), input.end(), [&output](char c) { 
        output *= 16;
        output += c >= '0' && c<= '9' ? c - '0' :
                 c >= 'A' && c<= 'F' ? c - 'A' + 10 :
                 c >= 'a' && c<= 'f' ? c - 'a' + 10 :
              -1;
    });
    return true;
}


int main(){
    int  out;
    string  in ;

    cout << "please input a hex value: ";
    cin >> in;
    cout << "\n";
 
    unhexlify( in, out );
    cout << out;

    return 0;
}