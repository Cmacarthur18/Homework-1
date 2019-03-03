//
//  Set.cpp
//  Homework1
//
//  Created by Chet MacArthur on 1/16/19.
//  Copyright © 2019 Chet MacArthur. All rights reserved.
//

#include "Set.h"
using namespace std;
Set::Set(){
    m_items = 0;
}

bool Set:: empty() const {
    if( m_items == 0)
        return true;
    return false; 
}

int Set:: size() const{
    return m_items;
}

bool Set::insert(const ItemType& value){
    
    //bool contains = false;
    if(size() >= DEFAULT_MAX_ITEMS) // check to see if there already is enough items
        return false;
    
    int i = 0;
    for( ; i <size(); i++){ // Check to see if the value is in the array already
        if(m_arr[i] == value)
            return false;
    }
    m_arr[i] = value;
    m_items++;
    return true;
    
}

bool Set::erase(const ItemType& value){
    bool removed = false;
    for(int i = 0; i <size(); i++){
        if (m_arr[i] == value) {
            for(int m = i; m < size()-1 ; m++){
                m_arr[m] = m_arr[m+1];
            }
            m_items--;
            removed = true;
        }
    }
    if(removed)
        return true;
    
    return false;
}

bool Set:: contains(const ItemType& value) const{
    
    for(int i = 0 ; i < size(); i++){
        if( m_arr[i] == value){
           
          // std::cout << "Contains" << std::endl;
            return true;
        }
        
    }
    return false;
}

bool Set::get(int i, ItemType& value) const{
    
    //cout << "entered get" << endl;
    ItemType temp;
    if( i >= 0 && i < size()){
        //cout << "entered if" << endl;
        ItemType newArr[DEFAULT_MAX_ITEMS]; // make a new array identical to the old one
        for(int m = 0; m < size() ; m++ ){
            newArr[m] = m_arr[m];
        }
        
        for( int j = 0 ; j < size() ; j++){
            for (int k = j+1 ;  k < size() ; k++)
            {
                if(newArr[k] < newArr[j])
                {
                    temp = newArr[j];
                    newArr[j] = newArr[k];
                    newArr[k] = temp;
                }
            }
        }
        value = newArr[i];
        return true;
    }
    return false;
}

void Set:: swap(Set& other){
    int temp = other.m_items;
    other.m_items = this->m_items;
    this->m_items = temp;
    
    for( int i = 0; i < DEFAULT_MAX_ITEMS ; i++){
        ItemType  temp1 = other.m_arr[i];
        other.m_arr[i] = m_arr[i];
        m_arr[i] =temp1;
        //cout << other.m_arr[i] << endl;
    }
}
