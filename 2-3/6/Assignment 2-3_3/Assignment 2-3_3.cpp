#include "my_string.h"
#include <iostream>

using namespace std;
using namespace my_oopstd;

int main()
{
    // assign을 사용하는 예
    my_string a;
    a.my_assign("HI");
    cout << "Test my_assign : " << a.my_c_str() << endl;

    // at을 사용하는 예
    my_string b("Hello World");
    cout << "Test my_at : " << b.my_at(2) << endl;
    
    // c_str을 사용하는 예
    cout << "Test my_c_str : " << b.my_c_str() << endl;

    // clear를 사용하는 예
    cout << "Test my_clear : ";
    b.my_clear();

    // push_back을 사용하는 예
    b.my_assign("Hello World");
    b.my_push_back('b');
    cout << "Test my_push_back : " << b.my_c_str() << endl;

    // compare를 사용하는 예
    my_string example("Hello Worlds");
    cout << "Test my_compare : " << b.my_compare(&example) << endl;

    // replace를 사용하는 예
    my_string example2("Hi");
    my_string d = example.my_replace(0, 5, &example2);
    cout << "Test my_replace : " << d.my_c_str() << endl;

    // substr을 사용하는 예
    my_string e = b.my_substr(5, 5);
    cout << "Test my_substr : " << e.my_c_str() << endl;
    
    // find를 사용하는 예
    cout << "Test my_find : " << b.my_find("World", 0) << endl;
    
    // stoi, stof를 사용하는 예
    my_string num("10bus");
    size_t sz1 = 0;
    int number = my_stoi(num, &sz1, 10);
    cout << "Test my_stoi : " << number << endl;
    cout << "Size : " << sz1 << endl;
    
    my_string floatstr("1.5abc");
    size_t sz2 = 0;
    float float_num = my_stof(floatstr, &sz2);
    cout << "Test my_stof : " << float_num << endl;
    cout << "Size : " << sz2 << endl;
    
    // to_string을 사용하는 예
    my_string intstr = my_to_string(10);
    cout << "Test my_to_string(int val) : " << intstr.my_c_str() << endl;
    
    my_string float_to_str = my_to_string(1.5f);
    cout << "Test my_to_string(float val) : " << float_to_str.my_c_str() << endl;
    
    return 0;
}
