#include <iostream>
    using std::cout;
    using std::endl;
    
//(a) selection
//(b) bubble
//(c) insertion
//(d) modified insertion (implement the algorithm described in the problem 2.3-6 on the page 37)
//(e) merge
//(f) quick (with the last array element as the pivot point)
//(g) randomized quick
//(h) heap sort. 
    
    
int main()
{
    cout << "\n\n\n\n";
    
    int menu = 9;
    
    cout << "Which sort do you wish to use:: ";
    cout << "\n\nSelection(1)\n";
    cout << "Bubble(2)\n";
    cout << "Insertion(3)\n";
    cout << "Modified Insertion(4)\n";
    cout << "Merge(5)\n";
    cout << "Quick-Last element as pivot(6)\n";
    cout << "Quick-Random element as pivot(7)\n";
    cout << "Heap(8)\n";
    cout << "Exit(0)\n";
    
    
    do
    {
        
    }
    while(menu >= 0 && menu <= 8);
    
    cout << "\n\n\n\n\n";
    
    return 0;
}