//
//  SSNSet.cpp
//  Homework1
//
//  Created by Chet MacArthur on 1/17/19.
//  Copyright © 2019 Chet MacArthur. All rights reserved.
//

#include "SSNSet.h"
using namespace std;

SSNSet::SSNSet(){
    
}

bool SSNSet:: add(unsigned long ssn){
    // Add an SSN to the SSNSet.  Return true if and only if the SSN
    // was actually added.
    return m_Set.insert(ssn);
}

int SSNSet:: size() const{
    // Return the number of SSNs in the SSNSet.
    return m_Set.size();
}

void SSNSet:: print() const{
    for( int i = 0; i < m_Set.size(); i++)
    {
        ItemType ssNum;
        m_Set.get(i, ssNum);
        cout << ssNum << endl;
    }
}


