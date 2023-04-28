#include <iostream>
#include "testlib.h";
using namespace std;

int main(int argc, char *argv[]) 
{
    registerGen(argc, argv, 1);
    cout << rnd.next(5, 10) << " " << rnd.next(11, 20) << endl; //random number gen from 5 to 10 and between 11 to 20
    // cout << rnd.next(100) << " " << rnd.next(100) << endl;//random number gen from 0 to 100 
    return 0;
}

//save script: gen 1 > $ 
                // gen 2> $
                // or
                /*Loop: 
                <#list 1..99 as g>
                 gen ${g} > $
                 </#list>
                */