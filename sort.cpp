/**
 *******************************************************************************
 * @file    sort.cpp
 * @brief   This file is the main file for the Analysis of Algorithms project
 * Assignment. The main file is mainly for testing the driver code and building
 * the arrays for holding the data.
 *
 *This file should hold eight sorts and should build the run time of the sorts
 *from the created arrays of random numbers, increasing order array, and
 *sequence of elements arranged in decreasing order. It should compile this
 *data into two seperate tables to allow easy view and understanding. Along,
 *with the different automatic sorts should be a menu based sorting to allow
 *for certain sorts to be used with an array of 2 to 100 size.
 *
 * @remarks
 *      Course:        Analysis of Algorithms 4713, Fall 2019
 *      Due Date:      Monday, October 12th
 *      Instructor:    Dr. Xiuzhen Huang
 *
 *          Name           -- ID        --  name+last4ID+class number -- class#
 * @author  Daniel Woodard -- 50436100	--	Daniel6100u14 -- u14
 *          Brody Modglin -- 50523177 -- Brody3177u07 -- u07
 *          Rachael Hawthrone -- 50374766 -- Rachael4766g09 -- g09
 *          Abhijit Dutta -- 50511365 -- Abhijit1365 --
 *          
 * @date    Monday, September 9th
 *******************************************************************************
**/


#include <iostream> // for basic needed statements.
    using std::cout;
    using std::endl;
    using std::cin;
#include <iomanip> // for formatting the tables
	using std::setw;
	using std::right;
	using std::left;
	using std::setprecision;
	using std::fixed;
#include <string> // for use of strings.
	using std::string;
    
#include <cstdlib>
#include <ctime> // This is for the timing of the sorts
#include <chrono> // This is also for the timing of the sorts.

//This is the other half of the Project file.
#include "functions.h" // This holds most of the sorts and helper functions.

int main()
{
    cout << endl << "Fluffy saintiy check" << endl;
    
    int menu = 9;		// setting the first menu choice.
    srand(time(NULL));	// setting up the srand for random number generation
	// This is for changing between the two quick sorts to prevent unneeded code.
    bool quickCheck = false; 
    cout << "\n\n";
    
    int lengthCheck = 100;
	int length = 100;
    int nCompared = 0; // used to calculate comparison while AUTO RUN
	
	
    do // first do while to allow for the user to keep picking a new sort.
    {
		do // second do while is for checking in input is valid.
		{
            //Displaying to user the options
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
			
			 // geting user input for sort.
            cout << "\nPlease select the sort you would like: ";
            cin >> menu;
			
			if(menu != 0){ // getting user input for size.
				cout << "\nPlease enter an array length between 2 and 100: ";
				cin >> lengthCheck;
			}
            
            if(menu < 0 || menu > 8) // check for numeric menu check
            {
                cout << "\n\n";
                cout << "The choices to choose are numerical between 0 - 8";
                cout << "\n";
            }
			if(lengthCheck > 100 || lengthCheck < 2){
				cout << "\n\nLength must be between 2 and 100\n";
			}
        } // second do while loop ends.
        while((menu < 0 || menu > 8) || (lengthCheck > 100 || lengthCheck < 2));
		
        length = lengthCheck; // assigning the checked/correct length to a use.
        int *ran, *inc, *dec; // building the pointers for arrays
		ran = new int[length]; // new random
		inc = new int[length]; // new increasing order
		dec = new int[length]; // new decreasing order
		arraySetups(ran, inc, dec, length);
		
        if(menu == 1)// start of the sort menu, takes in user given input.
        {//each sort should be stated via the first cout statment.
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
        { // per each sort, copied code, but different sort done.
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
        { // per each sort, copied code, but different sort done.
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
        {// per each sort, copied code, but different sort done.
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
        {// per each sort, copied code, but different sort done.
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
        {// per each sort, copied code, but different sort done.
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
        { // per each sort, copied code, but different sort done.
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
        { // per each sort, copied code, but different sort done.
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
        
        if(menu == 0)
        {
            cout << "\nYou have chosen to exit";
            cout << "\nThank you and have a good day!\n\n";
        }
        
		quickCheck = false; // reseting the quick check
		delete[] ran; // getting rid of the old arrays
		delete[] inc; // so forth,
		delete[] dec; // so forth.
    }
    while(menu > 0 && menu <= 8); // end of first do while.
    
	
	/*************************************************************************/
	
    cout << "\n\nSTARTING AUTOMATIC SORTS\n\n";
    
	string sorts[8] = {"Selection","Bubble","Insertion","Mod Insertion",
						"Merge","Quick Last","Quick Ran","Heap"};
    
    // building a  array of strings with sort names for outpout later.
    
	int *ran, *inc, *dec; // building arrays of, random, increasing, decreasing
	int arraySize[4] = {100,1000,10000,30000};// The sizes needed for arrays
    
    // setting up the clock for run time
	std::chrono::high_resolution_clock::time_point begin, end; // start to end
    std::chrono::duration<double> elapsed_time; // the elapsed time to be kept
    
    //First number is sort
	//Second number is array length
	//Third number is type of array, ran, inc, or dec
	double timeLists[8][4][3];  // triple array to store data

	int sortUp; // simple ints for increments
	int lengthUp;
	int typeUp = 0;
	
	string arrayTypes[3] = {"ran", "inc", "dec"};
    
    //number of comparisons in each sort ***************
    //keeps track of the postion in the array(amount of data)
    int position1 = 0;
    // keeps track of the position in the array (ran, inc Dec)
    int position2 = 0;
    // keeps track of the position in the array (type of sort)
    int position3 = 0; 
    int numberOfCommarison[4][3][8] = {0}; // setting the array values to 0
    // number of comparisons in each sort *************
    nCompared = 0;
	
	for(int k = 0; k < 4; k++){
		sortUp = 0; // reseting per each loop
		lengthUp = k; // assigning new k per loop
		length = arraySize[k];
		ran = new int[length]; // setting arrays the length per loop
		inc = new int[length];
		dec = new int[length];
		arraySetups(ran, inc, dec, length); 
        
        position1 = k;
        position2 = 0;
        position3 = 0;
        
        //This is the timing of the sorts.
        
		//Selection Sort
        //This is the random
		begin = std::chrono::high_resolution_clock::now(); // start
        selectionSort(length, ran, nCompared); // which sort
		end = std::chrono::high_resolution_clock::now(); /// end
        elapsed_time = end - begin; // the time it took
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count(); 
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0; // resetting nCompared
        position2++;
        
		// Timing, but this time it is increasing order.
		begin = std::chrono::high_resolution_clock::now();
        selectionSort(length, inc, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		// Timing, but this time it is decreasing order.
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
		//Random
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
        
		// Increasing
		begin = std::chrono::high_resolution_clock::now();
        bubbleSort(length, inc, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		//Decreasing
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
		// random
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
        
		//increasing
		begin = std::chrono::high_resolution_clock::now();
        insertionSort(length, inc, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		//decreasing
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
		//random
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
        
		//increasing
		begin = std::chrono::high_resolution_clock::now();
        insertionSortMod(length, inc, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		//decreasing
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
		//random
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
        
		//increasing
		begin = std::chrono::high_resolution_clock::now();
        mergeSort(length, inc, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
        //decreasing
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
		//random
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
        
		//increasing
		begin = std::chrono::high_resolution_clock::now();
        quickSort(length, inc, quickCheck, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		//decreasing
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
		//random
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
        
		//increasing
		begin = std::chrono::high_resolution_clock::now();
        quickSort(length, inc, quickCheck, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		//decreasing
		begin = std::chrono::high_resolution_clock::now();
        quickSort(length, dec, quickCheck, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2 = 0;
        position3++;
        
		
		//Heap Sort
		//random
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
        
		//increasing
		begin = std::chrono::high_resolution_clock::now();
        heapSort(inc, length, nCompared);
		end = std::chrono::high_resolution_clock::now();
        elapsed_time = end - begin;
        timeLists[sortUp][lengthUp][typeUp] = elapsed_time.count();
		typeUp++;
        numberOfCommarison[position1][position2][position3] = nCompared;
        nCompared = 0;
        position2++;
        
		//decreasing
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
	// This is for setting up the table in outputting
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
	//using fors for displaying purposes
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
	for(int b = 0; b < 8; b++){ // display for sorts
		cout << setw(17) << right << fixed << sorts[b];
	}
	cout << endl; // display for array types and number of comparisons
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

    delete[] ran; // deleting the arrays for memeory clearance.
	delete[] inc;
	delete[] dec;
    
    cout << "\n\n";
    
    return 0;
}
