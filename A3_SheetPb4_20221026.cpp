// File name: A3_SheetPb4_20221026.cpp
// Purpose: writing a template-based class that implements a set of items.and its functions like (add,remove,return size,find item)
// Author: Amany Mohamed Hussien Mohamed
// ID: 20221026
// Section: S1,S2
// Date: 6/12/2023
// Version: version1
#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
template <typename T>
class Set
{
    private:
    vector<T> items;
    public:
    Set(){} //default constructor
   
    bool Contains(const T& item) const 
   {
    if (items.empty()) {
       
        return false;
    }
    
    auto it = find(items.begin(), items.end(), item); //Determine if an item is a member of the set
    if (it != items.end()) {
    
        return true;
    } else {
        
        return false;
    }
   }
    void Add (const T & item) //Add a new item to the set
    {
        if (!Contains (item))
        {
            items.push_back(item);
        }

    }
    int Size() //Return the number of items in the set.
    {
        return items.size();
    }
    
    void Remove(const T& item)// Remove an item from the set.
    {
        items.erase(remove(items.begin(), items.end(), item), items.end());
    }
     T* ToArray() const
    {
        vector<T> sortedItems = items;  // Create a copy of items
        sort(sortedItems.begin(), sortedItems.end());  // Sort the copy vector
        T* arr = new T[sortedItems.size()]; //create a pointer from arr to return the items of vector
        copy(sortedItems.begin(), sortedItems.end(), arr);
        return arr;
    }
   bool operator==(const Set<T>& other)const  { //overload operator == to check if two sets equal or not
        if (items.size() != other.items.size()) {
           return false;
        }

        for (const T& item : items) {
            if (!other.Contains(item)) {
               
               return false;
            }
        }

        return true;
    }
    bool operator!=(const Set<T>& other) const {
        return !(*this == other);//returns the negation of the equality comparison
    }
};
int main() {
    Set<int> intSet1;
    intSet1.Add(2);
    intSet1.Add(1);
    intSet1.Add(3);
    intSet1.Add(5);
    intSet1.Add(4);
    intSet1.Add(2);
    intSet1.Remove(5);
    int* intArray = intSet1.ToArray();
    for (int i = 0; i < intSet1.Size(); i++) {
    
       cout << intArray[i] << " ";
    }
    delete[] intArray;
    cout << endl;
    cout << "Number of items of intSet: " << intSet1.Size()<<endl;
    if(intSet1.Contains(4))
    {
        cout<<"Yes,The Set contains this element"<< endl;
    }
    else
    {
          cout<<"No,The Set doesn't contain this element"<<endl;
    }
    Set<int> intSet2;
    intSet2.Add(2);
    intSet2.Add(3);
    intSet2.Add(1);
    intSet2.Add(4);
    if (intSet1 == intSet2) {
        cout << "The sets are equal." << endl;
    } 
    else if (intSet1 != intSet2) {
        cout << "The sets are not equal." << endl;
    } 
    cout<<"---------------------------------------------------"<<endl;
    Set<string> stringSet;
    stringSet.Add("Apple");
    stringSet.Add("Banana");
    stringSet.Add("Mango");
    stringSet.Add("Orange");
    stringSet.Add("Banana");
    stringSet.Remove("Apple");
    string* stringArray = stringSet.ToArray();
    for (int i = 0; i < stringSet.Size(); i++) {
     cout << stringArray[i] << " ";
    }
    delete[] stringArray;
  cout << endl;
  cout << "Number of items in stringSet: " << stringSet.Size() << endl;
    if (stringSet.Contains("Peach"))
    {
        cout<<"Yes,The stringSet contains this element"<<endl;
    }
    else
    {
          cout<<"No,The stringSet doesn't contain this element"<<endl;
    }
Set<string> stringSet2;
    stringSet2.Add("Banana");
    stringSet2.Add("Mango");
    stringSet2.Add("Kiwi");
    if (stringSet == stringSet2) {
        cout << "The sets are equal." << endl;
    } 
    else if ( stringSet!= stringSet2) {
        cout << "The sets are not equal." << endl;
    } 
    return 0;
}
