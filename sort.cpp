#include <iostream>
    using std::cout;
    using std::endl;
    using std::cin;
    
#include <ctime>

#include "functions.h"

int main()
{
    int menu = 9;                   // setting the first menu choice.
    int size = 20;                  // setting up the size of the test array
    srand(time(nullptr));           // setting up the srand for random number generation
                                    // This is for changing between the two quick sorts to prevent unneeded code.
    bool quickCheck = false; 
    
    cout << "\n\n\n\n";
    
                                    //setting up a testing array for building sorts.
    int test [20] = {2, 1, 3, 5, 4, 20, 10, 12, 6, 7, 13,
                     8, 14, 9, 19, 15, 17, 16, 11, 18};
                     
    cout << "\n\nThe unsorted array is....\n\n";
                     
                                    // viewing the array before any sort is applied.
    display(size,test);             // made into funcition, as it will have a lot of use.

    
    cout << "\n\n\n";
     
    
    do                              // first do while to allow for the user to keep picking a new sort if they wish.
    {
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
        
        do                          // second do while to make sure good numeric input.
        {                           // NEED TO ADD CHECK IF INPUT IS NOT A NUMBER. dont remember how atm but got examples to view. 
            cout << "\n\nSort::  ";
            cin >> menu;
            
            if(menu < 0 || menu > 8) // check for numeric menu check
            {
                cout << "\n\nThe choices to choose are numerical between 0 - 8\n";
            }
        }
        while(menu < 0 || menu > 8); // second do while end.
        
        if(menu == 1)               // start of the sort menu, takes in user given input.
        {                           //each sort should be stated via the first cout statment.
            cout << "\nYou have chosen to use the selection sort\n";
            selectionSort(size, test);
        }
        
        if(menu == 2)
        {
            cout << "\nYou have chosen to use the bubble sort\n";
            bubbleSort(size, test);
        }
        
        if(menu == 3)
        {
            cout << "\nYou have chosen to use the insertion sort\n";
            insertionSort(size, test);
        }

        if(menu == 4)
        {
            cout << "\nYou have chosen to use the modified insertion sort\n";
            insertionSortMod(size, test);
        }
        
        if(menu == 5)
        {
            cout << "\nYou have chosen to use the merge sort\n";
            mergeSort(size, test);
        }
        
        if(menu == 6)
        {
            cout << "\nYou have chosen to use the quick sort(last element is pivot)\n";
            quicksort(size, test, quickCheck);
        }
        
        if(menu == 7)
        {
            cout << "\nYou have chosen to use the quick sort(random pivot)\n";
            quickCheck = true;
            quicksort(size, test, quickCheck);
            quickCheck = false;
        }
        
        if(menu == 8)
        {
            cout << "\nYou have chosen to use the heap sort\n";
            //sort.(test);
        }
        
        if(menu >= 0 && menu <= 8)
        {
            display(size,test);
            destory(size,test);
            
            cout << "Back to be broken...";
            display(size,test);
        }
        
        if(menu == 0)
        {
            cout << "\nYou have chosen to exit";
            cout << "\nThank you and have a good day!\n\n";
            exit(0);
        }
        
    }
    while(menu >= 0 && menu <= 8); // end of first do while.
    
    
    
    cout << "\n\n\n\n\n";
    
    return 0;
}