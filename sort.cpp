#include <iostream>
    using std::cout;
    using std::endl;
    using std::cin;

#include <cstdlib>
#include <ctime>
#include <chrono>

#include "functions.h"

int main()
{
	srand(time(0));
	std::chrono::high_resolution_clock::time_point begin, end;
    std::chrono::duration<double> elapsed_time;
    int menu = 9;                   // setting the first menu choice.
    int size = 20;                  // setting up the size of the test array
    //srand(time(NULL));           // setting up the srand for random number generation
                                    // This is for changing between the two quick sorts to prevent unneeded code.
    bool quickCheck = false; 
    int test[20];
    cout << "\n\n\n\n";
    
    int length = 1000;               //setting up a testing array for building sorts.
    int *ran, *inc, *dec;
	//ran = new int[length];
	//inc = new int[length];
	//dec = new int[length];
    //arraySetups(ran, inc, dec, length);
	/*for(int i = 0; i < length; i++)
    {
       ran[i] = randoml();
	   inc[i] = i;
	   dec[size - i] = i;
    }*/
    
	
    //cout << "\n\nThe unsorted array is....\n\n";
                     
                                    // viewing the array before any sort is applied.
    //display(size,test);             // made into funcition, as it will have a lot of use.

    /*
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
            cout << "\nArray before it is sorted.\n";
            display(length, ran);
			heapSort(ran, length);
            cout << "\nArray after it is sorted.\n";
			display(length, ran);
        }
        
        if(menu >= 0 && menu <= 8)
        {
            //display(size,test);
            //destory(size,test);
            
            cout << "Back to be broken...";
            //display(size,test);
        }
        
        if(menu == 0)
        {
            cout << "\nYou have chosen to exit";
            cout << "\nThank you and have a good day!\n\n";
            //exit(0);
        }
        
    }
    while(menu > 0 && menu <= 8); // end of first do while.
    */
	
	/*************************************************************************/
	
	//AUTOMATIC SORT TIMING BELOW
	//Selection 0
	//Bubble 1
	//Insertion 2
	//Mod Insertion 3
	//Merge 4
	//Quick Last 5
	//Quick Random 6
	//Heap 7
	
	int arraySize[4] = {100,1000,10000,30000};
	std::chrono::high_resolution_clock::time_point begin, end;
    std::chrono::duration<double> elapsed_time;
	double timeLists[8][4][3];
	//First number is sort
	//Second number is array length
	//Third number is type of array, ran, inc, or dec
	int sortUp;
	int lengthUp;
	int typeUp = 0;
	
	for(int k = 0; k < 4; k++){
		sortUp = 0;
		lengthUp = k;
		length = arraySize[k];
		ran = new int[length];
		inc = new int[length];
		dec = new int[length];
		arraySetups(ran, inc, dec, length);
		
		//Selection Sort
		
		begin = std::chrono::high_resolution_clock::now();
        selectionSort(length, ran);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        selectionSort(length, inc);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        selectionSort(length, dec);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		
		//Bubble Sort
		
		typeUp = 0;
		sortUp++;
		arraySetups(ran, inc, dec, length);
		begin = std::chrono::high_resolution_clock::now();
        bubbleSort(length, ran);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        bubbleSort(length, inc);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        bubbleSort(length, dec);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		
		//Insertion Sort
		
		typeUp = 0;
		sortUp++;
		arraySetups(ran, inc, dec, length);
		begin = std::chrono::high_resolution_clock::now();
        insertionSort(length, ran);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        insertionSort(length, inc);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        insertionSort(length, dec);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		
		//Insertion Sort Mod
		
		typeUp = 0;
		sortUp++;
		arraySetups(ran, inc, dec, length);
		begin = std::chrono::high_resolution_clock::now();
        insertionSortMod(length, ran);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        insertionSortMod(length, inc);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        insertionSortMod(length, dec);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		
		//Merge Sort
		
		typeUp = 0;
		sortUp++;
		arraySetups(ran, inc, dec, length);
		begin = std::chrono::high_resolution_clock::now();
        mergeSort(length, ran);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        mergeSort(length, inc);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        mergeSort(length, dec);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		
		//Quick Last Sort
		
		typeUp = 0;
		sortUp++;
		arraySetups(ran, inc, dec, length);
		begin = std::chrono::high_resolution_clock::now();
        bubbleSort(length, ran);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        bubbleSort(length, inc);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        bubbleSort(length, dec);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		
		//Quick Random Sort
		
		typeUp = 0;
		sortUp++;
		arraySetups(ran, inc, dec, length);
		begin = std::chrono::high_resolution_clock::now();
        bubbleSort(length, ran);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        bubbleSort(length, inc);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        bubbleSort(length, dec);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		
		//Heap Sort
		
		typeUp = 0;
		sortUp++;
		arraySetups(ran, inc, dec, length);
		begin = std::chrono::high_resolution_clock::now();
        heapSort(ran, length);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        heapSort(inc, length);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
		
		begin = std::chrono::high_resolution_clock::now();
        heapSort(dec, length);;
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
	}
	
	
	
	

    delete[] ran;
	delete[] inc;
	delete[] dec;
    
    cout << "\n\n\n\n\n";
    
    return 0;
}