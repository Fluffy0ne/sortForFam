#include <iostream>
    using std::cout;
    using std::endl;
    using std::cin;
#include <iomanip>
	using std::setw;
	using std::right;
	using std::left;
	using std::setprecision;
	using std::fixed;
#include <string>
	using std::string;
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
    int nCompared = 0; // used to calculate comparison while AUTO RUN
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
            cout << "\nPlease select the sort you would like: ";
            cin >> menu;
			
			if(menu != 0){
				cout << "\nPlease enter an array length between 2 and 100: ";
				cin >> lengthCheck;
			}
            
            if(menu < 0 || menu > 8) // check for numeric menu check
            {
                cout << "\n\nThe choices to choose are numerical between 0 - 8\n";
            }
			if(lengthCheck > 100 || lengthCheck < 2){
				cout << "\n\nLength must be between 2 and 100\n";
			}
        }
        while((menu < 0 || menu > 8) || (lengthCheck > 100 || lengthCheck < 2)); // second do while end.
		
        length = lengthCheck;
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
			selectionSort(length, ran, nCompared);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			selectionSort(length, inc, nCompared);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			selectionSort(length, dec, nCompared);
            cout << "\nDecreasing Array after it is sorted.\n";
			display(length, dec);
        }
        
        if(menu == 2)
        {
            cout << "\nYou have chosen to use the bubble sort\n";
            cout << "\nRandom Array before it is sorted.\n";
            display(length, ran);
			bubbleSort(length, ran, nCompared);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			bubbleSort(length, inc, nCompared);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			bubbleSort(length, dec, nCompared);
            cout << "\nDecreasing Array after it is sorted.\n";
			display(length, dec);
        }
        
        if(menu == 3)
        {
            cout << "\nYou have chosen to use the insertion sort\n";
            cout << "\nRandom Array before it is sorted.\n";
            display(length, ran);
			insertionSort(length, ran, nCompared);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			insertionSort(length, inc, nCompared);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			insertionSort(length, dec, nCompared);
            cout << "\nDecreasing Array after it is sorted.\n";
			display(length, dec);
        }

        if(menu == 4)
        {
            cout << "\nYou have chosen to use the modified insertion sort\n";
            cout << "\nRandom Array before it is sorted.\n";
            display(length, ran);
			insertionSortMod(length, ran, nCompared);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			insertionSortMod(length, inc, nCompared);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			insertionSortMod(length, dec, nCompared);
            cout << "\nDecreasing Array after it is sorted.\n";
			display(length, dec);
        }
        
        if(menu == 5)
        {
            cout << "\nYou have chosen to use the merge sort\n";
            cout << "\nRandom Array before it is sorted.\n";
            display(length, ran);
			mergeSort(length, ran, nCompared);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			mergeSort(length, inc, nCompared);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			mergeSort(length, dec, nCompared);
            cout << "\nDecreasing Array after it is sorted.\n";
			display(length, dec);
        }
        
        if(menu == 6)
        {
            cout << "\nYou have chosen to use the quick sort(last element is pivot)\n";
            quickCheck = false;
			cout << "\nRandom Array before it is sorted.\n";
            display(length, ran);
			quickSort(length, ran, quickCheck, nCompared);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			quickSort(length, inc, quickCheck, nCompared);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			quickSort(length, dec, quickCheck, nCompared);
            cout << "\nDecreasing Array after it is sorted.\n";
			display(length, dec);
        }
        
        if(menu == 7)
        {
            cout << "\nYou have chosen to use the quick sort(random pivot)\n";
            quickCheck = true;
			cout << "\nRandom Array before it is sorted.\n";
            display(length, ran);
			quickSort(length, ran, quickCheck, nCompared);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			quickSort(length, inc, quickCheck, nCompared);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			quickSort(length, dec, quickCheck, nCompared);
            cout << "\nDecreasing Array after it is sorted.\n";
			display(length, dec);
        }
        
        if(menu == 8)
        {
            cout << "\nYou have chosen to use the heap sort\n";
			
            cout << "\nRandom Array before it is sorted.\n";
            display(length, ran);
			heapSort(ran, length, nCompared);
            cout << "\nRandom Array after it is sorted.\n";
			display(length, ran);
			
			
			cout << "\nIncreasing Array before it is sorted.\n";
            display(length, inc);
			heapSort(inc, length, nCompared);
            cout << "\nIncreasing Array after it is sorted.\n";
			display(length, inc);
			
			
			cout << "\nDecreasing Array before it is sorted.\n";
            display(length, dec);
			heapSort(dec, length, nCompared);
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
	string sorts[8] = {"Selection","Bubble","Insertion","Mod Insertion",
						"Merge","Quick Ran","Quick Last","Heap"};
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
	
	string arrayTypes[3] = {"ran", "inc", "dec"};
    
    //number of comparisons in each sort ***************
    int position1 = 0;               // keeps track of the position in the array (amount of data)
    int position2 = 0;               // keeps track of the position in the array (ran, inc Dec)
    int position3 = 0;               // keeps track of the position in the array (type of sort)
    int numberOfCommarison[4][3][8] = {0};
    nCompared = 0;
    // number of comparisons in each sort *************
	
	for(int k = 0; k < 4; k++){
		sortUp = 0;
		lengthUp = k;
		length = arraySize[k];
		ran = new int[length];
		inc = new int[length];
		dec = new int[length];
		arraySetups(ran, inc, dec, length);
        
        position1 = k;
        position2 = 0;
        position3 = 0;
        
		//Selection Sort
		
		begin = std::chrono::high_resolution_clock::now();
        selectionSort(length, ran, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		
		begin = std::chrono::high_resolution_clock::now();
        selectionSort(length, inc, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		
		begin = std::chrono::high_resolution_clock::now();
        selectionSort(length, dec, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2 = 0;
        position3++;
        
		
		//Bubble Sort
		
        arraySetups(ran, inc, dec, length);
		typeUp = 0;
		sortUp++;
		arraySetups(ran, inc, dec, length);
		begin = std::chrono::high_resolution_clock::now();
        bubbleSort(length, ran, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		
		begin = std::chrono::high_resolution_clock::now();
        bubbleSort(length, inc, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		
		begin = std::chrono::high_resolution_clock::now();
        bubbleSort(length, dec, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2 = 0;
        position3++;
		
		//Insertion Sort
		
        arraySetups(ran, inc, dec, length);
		typeUp = 0;
		sortUp++;
		arraySetups(ran, inc, dec, length);
		begin = std::chrono::high_resolution_clock::now();
        insertionSort(length, ran, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		
		begin = std::chrono::high_resolution_clock::now();
        insertionSort(length, inc, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		
		begin = std::chrono::high_resolution_clock::now();
        insertionSort(length, dec, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2 = 0;
        position3++;
        
		
		//Insertion Sort Mod
		
        arraySetups(ran, inc, dec, length);
		typeUp = 0;
		sortUp++;
		arraySetups(ran, inc, dec, length);
		begin = std::chrono::high_resolution_clock::now();
        insertionSortMod(length, ran, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		
		begin = std::chrono::high_resolution_clock::now();
        insertionSortMod(length, inc, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		
		begin = std::chrono::high_resolution_clock::now();
        insertionSortMod(length, dec, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2 = 0;
        position3++;
        
		
		//Merge Sort
		
        arraySetups(ran, inc, dec, length);
		typeUp = 0;
		sortUp++;
		arraySetups(ran, inc, dec, length);
		begin = std::chrono::high_resolution_clock::now();
        mergeSort(length, ran, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		
		begin = std::chrono::high_resolution_clock::now();
        mergeSort(length, inc, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
        
		begin = std::chrono::high_resolution_clock::now();
        mergeSort(length, dec, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2 = 0;
        position3++;
        
        
		//Quick Last Sort
		
        quickCheck = false;
        arraySetups(ran, inc, dec, length);
		typeUp = 0;
		sortUp++;
		arraySetups(ran, inc, dec, length);
		begin = std::chrono::high_resolution_clock::now();
        quickSort(length, ran, quickCheck, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		
		begin = std::chrono::high_resolution_clock::now();
        quickSort(length, inc, quickCheck, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		
		begin = std::chrono::high_resolution_clock::now();
        quickSort(length, dec, quickCheck, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2 = 0;
        position3++;
        
		
		//Quick Random Sort
		
        quickCheck = true;
        arraySetups(ran, inc, dec, length);
		typeUp = 0;
		sortUp++;
		arraySetups(ran, inc, dec, length);
		begin = std::chrono::high_resolution_clock::now();
        quickSort(length, ran, quickCheck, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		
		begin = std::chrono::high_resolution_clock::now();
        quickSort(length, inc, quickCheck, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		
		begin = std::chrono::high_resolution_clock::now();
        quickSort(length, ran, quickCheck, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2 = 0;
        position3++;
        
		
		//Heap Sort
		
        arraySetups(ran, inc, dec, length);
		typeUp = 0;
		sortUp++;
		arraySetups(ran, inc, dec, length);
		begin = std::chrono::high_resolution_clock::now();
        heapSort(ran, length, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		
		begin = std::chrono::high_resolution_clock::now();
        heapSort(inc, length, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		
		begin = std::chrono::high_resolution_clock::now();
        heapSort(dec, length, nCompared);;
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2 = 0;
        position3 = 0;
        
	}
	
	
	cout <<"\n\nFINISHED AUTOMATIC SORTS\n\n";
	
	cout << setw(20) << "\nArray Size   "
		 << setw(11) << right << "100"
		 << setw(34) << right << "1000"
		 << setw(34) << right << "10000"
		 << setw(33) << right << "30000";
	
	cout << setw(20) << right << "\nArray Type   ";
	for(int asdf = 0; asdf < 4; asdf++){
		cout << setw(11) << right << "ran"
			 << setw(11) << right << "inc"
			 << setw(11) << right << "dec";
	}
	cout << endl;
	
	for(int sort = 0; sort < 8; sort++){
		cout << setw(17) << left << sorts[sort];
		for(int arrLength = 0; arrLength < 4; arrLength++){
			for(int arrType = 0; arrType < 3; arrType++){
				cout << setw(11) << right << setprecision(5)
					 << fixed << timeLists[sort][arrLength][arrType];
			}
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << "     ";
	for(int b = 0; b < 8; b++){
		cout << setw(17) << right << fixed << sorts[b];
	}
	cout << endl;
	for(int j = 0; j < 4; j++){
		for(int k = 0; k < 3; k++){
			cout << setw(5) << right << fixed << arrayTypes[k];
			for(int l = 0; l < 8; l++){
				cout << setw(17) << right << fixed << numberOfCommarison[j][k][l];
			}
			cout << endl;
		}
		cout << endl;
	}

    delete[] ran;
	delete[] inc;
	delete[] dec;
    
    cout << "\n\n";
    
    return 0;
}
