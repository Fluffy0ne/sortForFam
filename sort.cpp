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
	//std::chrono::high_resolution_clock::time_point begin, end;
    //std::chrono::duration<double> elapsed_time;
    int menu = 9;		// setting the first menu choice.
    srand(time(NULL));	// setting up the srand for random number generation
	// This is for changing between the two quick sorts to prevent unneeded code.
    bool quickCheck = false; 
    cout << "\n\n";
    
    int lengthCheck = 100;
	int length = 100;
    //int *ran, *inc, *dec;
	
	
    do // first do while to allow for the user to keep picking a new sort if they wish.
    {
		do
		{
			cout << "\nWhich sort do you wish to use:: ";
			cout << "\n\nSelection(1)\n";
			cout << "Bubble(2)\n";
			cout << "Insertion(3)\n";
			cout << "Modified Insertion(4)\n";
			cout << "Merge(5)\n";
			cout << "Quick-Last element as pivot(6)\n";
			cout << "Quick-Random element as pivot(7)\n";
			cout << "Heap(8)\n";
			cout << "Exit(0)\n";
			
			// NEED TO ADD CHECK IF INPUT IS NOT A NUMBER. dont remember how atm but got examples to view. 
            cout << "\nPlease enter an array length between 2 and 100:";
			cin >> lengthCheck;
			cout << "\nPlease select the sort you would like:";
            cin >> menu;
            
            if(menu < 0 || menu > 8) // check for numeric menu check
            {
                cout << "\n\nThe choices to choose are numerical between 0 - 8\n";
            }
			if(lengthCheck > 100 || lengthCheck < 2){
				cout << "\n\nLength must be between 2 and 100\n";
			}
            length = lengthCheck;
        }
        while((menu < 0 || menu > 8) || (lengthCheck > 100 || lengthCheck < 2)); // second do while end.
		
        
        int *ran, *inc, *dec;
		ran = new int[length];
		inc = new int[length];
		dec = new int[length];
		arraySetups(ran, inc, dec, length);
		
        if(menu == 1)               // start of the sort menu, takes in user given input.
        {                           //each sort should be stated via the first cout statment.
            cout << "\nYou have chosen to use the selection sort\n";
            cout << "\nRandom Array before it is sorted.\n";
            display(length, ran);
			selectionSort(length, ran);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			selectionSort(length, inc);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			selectionSort(length, dec);
            cout << "\nDecreasing Array after it is sorted.\n";
			display(length, dec);
        }
        
        if(menu == 2)
        {
            cout << "\nYou have chosen to use the bubble sort\n";
            cout << "\nRandom Array before it is sorted.\n";
            display(length, ran);
			bubbleSort(length, ran);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			bubbleSort(length, inc);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			bubbleSort(length, dec);
            cout << "\nDecreasing Array after it is sorted.\n";
			display(length, dec);
        }
        
        if(menu == 3)
        {
            cout << "\nYou have chosen to use the insertion sort\n";
            cout << "\nRandom Array before it is sorted.\n";
            display(length, ran);
			insertionSort(length, ran);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			insertionSort(length, inc);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			insertionSort(length, dec);
            cout << "\nDecreasing Array after it is sorted.\n";
			display(length, dec);
        }

        if(menu == 4)
        {
            cout << "\nYou have chosen to use the modified insertion sort\n";
            cout << "\nRandom Array before it is sorted.\n";
            display(length, ran);
			insertionSortMod(length, ran);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			insertionSortMod(length, inc);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			insertionSortMod(length, dec);
            cout << "\nDecreasing Array after it is sorted.\n";
			display(length, dec);
        }
        
        if(menu == 5)
        {
            cout << "\nYou have chosen to use the merge sort\n";
            cout << "\nRandom Array before it is sorted.\n";
            display(length, ran);
			mergeSort(length, ran);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			mergeSort(length, inc);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			mergeSort(length, dec);
            cout << "\nDecreasing Array after it is sorted.\n";
			display(length, dec);
        }
        
        if(menu == 6)
        {
            cout << "\nYou have chosen to use the quick sort(last element is pivot)\n";
            quickCheck = false;
			cout << "\nRandom Array before it is sorted.\n";
            display(length, ran);
			quickSort(length, ran, quickCheck);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			quickSort(length, inc, quickCheck);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			quickSort(length, dec, quickCheck);
            cout << "\nDecreasing Array after it is sorted.\n";
			display(length, dec);
        }
        
        if(menu == 7)
        {
            cout << "\nYou have chosen to use the quick sort(random pivot)\n";
            quickCheck = true;
			cout << "\nRandom Array before it is sorted.\n";
            display(length, ran);
			quickSort(length, ran, quickCheck);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			quickSort(length, inc, quickCheck);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			quickSort(length, dec, quickCheck);
            cout << "\nDecreasing Array after it is sorted.\n";
			display(length, dec);
        }
        
        if(menu == 8)
        {
            cout << "\nYou have chosen to use the heap sort\n";
			
            cout << "\nRandom Array before it is sorted.\n";
            display(length, ran);
			heapSort(ran, length);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			heapSort(inc, length);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			heapSort(dec, length);
            cout << "\nDecreasing Array after it is sorted.\n";
			display(length, dec);
        }
        
        if(menu >= 0 && menu <= 8)
        {
            
        }
        
        if(menu == 0)
        {
            cout << "\nYou have chosen to exit";
            cout << "\nThank you and have a good day!\n\n";
            //exit(0);
        }
        
		quickCheck = false;
		delete[] ran;
		delete[] inc;
		delete[] dec;
    }
    while(menu > 0 && menu <= 8); // end of first do while.
    
	
	/*************************************************************************/
	
    cout << "\n\nSTARTING AUTOMATIC SORTS\n\n";
    
	//AUTOMATIC SORT TIMING BELOW
	//Selection 0
	//Bubble 1
	//Insertion 2
	//Mod Insertion 3
	//Merge 4
	//Quick Last 5
	//Quick Random 6
	//Heap 7
	int *ran, *inc, *dec;
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
		
        arraySetups(ran, inc, dec, length);
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
		
        arraySetups(ran, inc, dec, length);
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
		
        arraySetups(ran, inc, dec, length);
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
		
        arraySetups(ran, inc, dec, length);
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
		
        arraySetups(ran, inc, dec, length);
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
		
        arraySetups(ran, inc, dec, length);
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
		
        arraySetups(ran, inc, dec, length);
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
	
	
	cout <<"\n\nFINISHED AUTOMATIC SORTS\n\n";
	

    delete[] ran;
	delete[] inc;
	delete[] dec;
    
    cout << "\n\n";
    
    return 0;
}