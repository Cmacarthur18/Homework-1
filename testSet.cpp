

#include "Set.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;



void test()
{
    Set uls;
    assert(uls.insert(20));
    assert(uls.insert(10));
    assert(uls.insert(10) == false);
    assert(uls.size() == 2);
    assert(uls.contains(10));
    ItemType x = 30;
    assert(uls.get(0, x)  &&  x == 10);
    assert(uls.get(1, x)  &&  x == 20);
    assert(uls.erase(20) && uls.size()==1);
    
    assert(uls.insert(20));
    assert(uls.insert(30));
    assert(uls.insert(40));
    
    Set uls1;
    assert(uls1.insert(200));
    assert(uls1.insert(300));
    assert(uls1.insert(400));
    assert(uls1.insert(500));
    assert(uls1.insert(600));
    uls1.swap(uls);
    assert(uls.contains(200) == true);
    assert(uls1.contains(200) == false);
    assert(uls.size() == 5 );
    assert(uls.erase(200) && uls.size()==4);
    
}

int main()
{
    test();
       cout << "Passed all tests" << endl;
}
