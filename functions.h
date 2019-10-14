/**
 * @file    functions.h
 * @brief   This is a helper function file to the main file of sort.cpp.
 * With this file holding the primary sorts and a few helper functions.
 *
 *This file holds the eight sorts of selection, bubble, insertion, modified
 *insertion, merge, random quick, last pivot quick, and finally heap sort.
 *Along with all of the sorts it also includes most of the common helper
 *funcitons needed in general and for each specific sort.
 *
 * 
 * @author  Daniel Woodard
 *          Brody Modglin
 *          Rachael Hawthrone
 *          Abhijit Dutta
 *          
 * @date    Monday, September 11th
 */


#ifndef FUNCTIONS_H
#define FUNCTIONS_H


/**
 * @brief       This is a simple helper function to swap two values in a
 *              clean and clear manner in other funcitons
 *
 * @param[out]   a   Simply stands in for a value to be swtiched for another.
 * @param[out]   b   Simply stands in for a value to be swtiched for another.
 *
 * @return  no return as it is a void funciton.
**/

void swap (int& a, int& b) // helper function for sorting
{
  int temp = a;
  a = b;
  b = temp;
}


/**
 * @brief      This is selection sort, and is one of the simpler sorts. This
 *             sort is better for smaller amounts of data. It should suffer
 *             on larger data sets.
 *
 * @param        size         This is the size of the current array to be
 *                            worked on.
 * @param        data         This is the current array being worked on.
 * @param[out]   nCompared    This is the loop counter for gathering infomation
 *
 * @return  no return as it is a void funciton.
**/

void selectionSort(int size, int data[], int &nCompared) // first sort. 
{
  int count = 0; // simple variables to upkeep increments
  int place = 0;
  bool check = false; // simple on/off boolean check
  
  while(count < (size))
  {
    int min = data[count];
    for(int i = count; i < (size); i++)   // each position in Array
    {// find smallest value in subsequent positions
      nCompared++;// nCompared for number of comaprisons
      if(min > data[i])
      {
        min = data[i];
        place = i;
        check = true;
      }
    }// swap smallest with current position in Array
    
    if(check == true)
    {
      swap(data[count], data[place]);
      place = 0;
    }
    
    count = count + 1;
    check = false;
  }
}


/**
 * @brief      This is bubble sort, and is one of the simpler sorts. This
 *             sort is better for smaller amounts of data. It should suffer
 *             on larger data sets. This is named thus since the data
 *             seems to bubble up.
 *
 * @param        size         This is the size of the current array to be
 *                            worked on.
 * @param        data         This is the current array being worked on.
 * @param[out]   nCompared    This is the loop counter for gathering infomation
 *
 * @return  no return as it is a void funciton.
**/

void bubbleSort(int size, int data[], int &nCompared) // The second sort
{
  bool check = false; // in this case check allows for an early stop if
  int shrink = 1;     // a swap is never made.
  do
  {
    check = false;
	// each pair of elements in an ever-shrinking list
    for(int i = 0; i < (size - shrink); i++) 
    {
      nCompared++;// nCompared for number of comparisons
      if(data[i] > data[i + 1])
      { // swap data, since greater
        swap(data[i],data[i + 1]);
        check = true;
      }
    }
    shrink++;
  } // end do-while
  while(check == true); // a swap occurred this pass
}  


/**
 * @brief      This is insertion sort, and is one of the simpler sorts. This
 *             sort is better for smaller amounts of data. It should suffer
 *             on larger data sets.
 *
 * @param        size         This is the size of the current array to be
 *                            worked on.
 * @param        data         This is the current array being worked on.
 * @param[out]   nCompared    This is the loop counter for gathering infomation
 *
 * @return  no return as it is a void funciton.
**/

void insertionSort(int size, int data[], int &nCompared) // the third sort
{
  int j;
  int temp = 0;
  for(int i = 1; i < size; i++) // each element after the first
  {
    temp = data[i];// save this number
    j = i - 1; // Different incrementer to keep up with both positions
	  // previous elements are bigger than saved element
    while(data[j] > temp && j >= 0) 
    {
      data[j + 1] = data[j];// move previous element forward one positions
      j--;
      nCompared++; // nCompared for number of comparisons
    }
    data[j + 1] = temp; // insert saved element in open hole
    nCompared++; // nCompared for number of comparisons
  } // end for     
}


////////////////////////////////////////////////////////////////////////////////////////////
// C O M E   B A C K   T O   T H I S.
int binarySearch(int a[], int target, int bottom, int top){
	if(top <= bottom)
  {
		if(target > a[bottom])
    {
			return (bottom + 1);
		}
    else
    {
			return (bottom);
		}
	}
	
	int middle = (bottom + top) / 2;
	
	if(target == a[middle])
  {
		return (middle + 1);
	}
	
	if(target > a[middle])
  {
    return binarySearch(a, target, middle + 1, top);
	}
	
	return binarySearch(a, target, bottom, middle - 1);
}


/**
 * @brief      This is insertion sort, and is one of the simpler sorts.
 *             However, this is a modified insertion sort to allow for
 *             more data to be done at readily speedily times. As it has
 *             been changed to allow for a more binary approach. To decrease
 *             search time for previous elements.
 *
 * @param        size         This is the size of the current array to be
 *                            worked on.
 * @param        data         This is the current array being worked on.
 * @param[out]   nCompared    This is the loop counter for gathering infomation
 *
 * @return  no return as it is a void funciton.
**/

void insertionSortMod(int size, int data[], int &nCompared) // The fourth sort.
{
  int j;
  int temp = 0;
  for(int i = 1; i < size; i++) // each element after the first
  {
    j = i - 1; // different incrementer to keep up with both positions
	  temp = data[i];// save this number
	
    int spot = binarySearch(data, temp, 0, j); // The modifed part of insertion.
    
    while(j >= spot)
    {
      data[j+1] = data[j];
      j--;
      nCompared++; // nCompared for number of comparisons
    }
    data[j+1] = temp; // insert saved element in open hole
    nCompared++; // nCompared for number of comparions
  } // end for     
}


/**
 * @brief      This is merge, it is a part of the merge sort functions. This
 *             funcitons main purpose is taking in various parts of the array
 *             along with the data to sort and merge the array data into.
 *
 * @param        left         This is the number of the left index.
 * @param        middle       This is the number of the middle index
 * @param        right        This is the number of the right index
 * @param        data         This is the array itself being brought in.
 * @param[out]   nCompared    This is counting the amount of times a loop is
 *                            done for later data comparison.
 *
 * @return  no return as it is a void funciton.
**/

void merge (int left, int middle, int right, int data[], int &nCompared) 
{
   int leftSize = middle - left + 1; // left side of the merge sort array
   
   int rightSize = right - middle; // right side of the merge sort array
   
   int* leftArray = new int[leftSize]; // comparable array - left
   int* rightArray = new int[rightSize]; // comparable array - right
   
   int leftIndex = 0; // for moving through the left part
   // right part, doing this so I can shift through them separately.
   int rightIndex = 0; 
   int arrayIndex = 0; // for the array index
   
   for(int i = 0; i < leftSize; i++) // putting values into left array
   {
      leftArray[i] = data[left + i]; // plus i to shift the index of array.
   }
   for(int i = 0; i < rightSize; i++) // putting values into right array
   {
     rightArray[i] = data[middle + i + 1];
     
   }
   
   while(leftIndex < leftSize && rightIndex < rightSize)
   { // will compare only if both comparable have an active value to check.
      if(leftArray[leftIndex] < rightArray[rightIndex])
      {
        data[left + arrayIndex] = leftArray[leftIndex];
        arrayIndex = arrayIndex + 1; 
        leftIndex = leftIndex + 1;
      }
      else // right was smaller
      {
        data[left + arrayIndex] = rightArray[rightIndex];
        arrayIndex = arrayIndex + 1;
        rightIndex = rightIndex + 1;
      }
      nCompared++;
   } // could still have something in either array left over, 
	 //uneven ls/rs, or uneven shifting
   
   // while loop before, should make only one of these true
	while(leftIndex < leftSize) 
   { // left already ordered, if it is only one left just throw it in.
      data[left + arrayIndex] = leftArray[leftIndex];
      arrayIndex = arrayIndex + 1; 
      leftIndex = leftIndex + 1;  
   }
   
   while(rightIndex < rightSize) // if not left, right
   {// right already ordered, if it is only one left just throw it in.
      data[left + arrayIndex] = rightArray[rightIndex];
      arrayIndex = arrayIndex + 1;
      rightIndex = rightIndex + 1;
   }
     
  delete [] leftArray; // taking care of memory
  delete [] rightArray;
}


/**
 * @brief      This is a helper function by the same name of the main
 *             merge sort. This is the recursive call that will call
 *             upon itself until completion.
 *
 * @param        left         This is the number of the left index.
 * @param        right        This is the number of the right index
 * @param        data         This is the array itself being brought in.
 * @param[out]   nCompared    This is counting the amount of times a loop is
 *                            done for later data comparison.
 * @return  no return as it is a void funciton.
**/

void mergeSort (int left, int right, int data[], int &nCompared) 
{
   if (right - left > 0)
   {
       int middle = (left + right) / 2;
       mergeSort (left, middle, data, nCompared);
       mergeSort (middle + 1, right, data, nCompared);
       merge (left, middle, right, data, nCompared);
   }
}


/**
 * @brief      This is the main merge sort call that would be called in
 *             main. The function itelf will call a helper funciton to
 *             create a recursive stack to complete the sort. This sort
 *             is typically good at doing larger sets of data but can
 *             be over kill to set up for small amounts of data.
 *
 * @param        left         This is the number of the left index.
 * @param        right        This is the number of the right index
 * @param        data         This is the array itself being brought in.
 * @param[out]   nCompared    This is counting the amount of times a loop is
 *                            done for later data comparison.
 * @return  no return as it is a void funciton.
**/

void mergeSort (int n, int data[], int &nCompared)  // The fifth sort
{
   mergeSort (0, n - 1, data, nCompared);
}


/**
 * @brief       This is a simple helper function for quick sort. This is the
 *              random pivot creation aspect. Taking in the left and right
 *              bounds it will give back a random index for the limits.
 *
 * @param     left    left bound of the array
 * @param     right   right bound of the array
 *
 * @return  should return a random value between the two bounds for random
 *          pivot to be used for quick sort.
**/

int random_pivot(int left, int right)
{// This is the random pivot.
    int random = rand() % (right - left + 1) + left;  
    
    return random;
}


/**
 * @brief       This is a simple helper function for quick sort. This is the
 *              return right pivot creation aspect. Taking in the right bound
 *              and it will give back a the right bound. This helper function
 *              helps creates differentiation between the two needed pivots
 *              within the quicksort calls.
 *
 * @param     right   right bound of the array
 *
 * @return  should return back the right bound of the array to be used as the
 *          pivot.
**/

int right_pivot(int right)
{// This is the last element as pivot
    return right;
}

/**
 * @brief       This is a simple helper function for quick sort. This helper
 *              function goal is to build the partitions of the arrays. In
 *              simple terms it decides which pivot index is used as the
 *              partioned middle ground value to be checked against the
 *              other values.
 *
 * @param     left          left bound of the array
 * @param     right         right bound of the array
 * @param     data          the array itself
 * @param     quickCheck    a simple check to decide if the random pivot
 *                          or the right pivot should be used in this
 *                          iteration of the quick sort.
 * @param     nCompared     Keeps up with the amount of times the partition
 *                          loops for use later in the data comparison.
 *
 * @return  should return the pivot index to be used in the comparison of
 *          different values for quick sort.
**/

int partition(int left, int right, int data[], bool quickCheck, int &nCompared)
{
    int pivot_index = 0;
  
    if(quickCheck == true)
    {
      pivot_index = random_pivot(left, right); //choosing pivot, random
    }
    else
    {
      pivot_index = right_pivot(right); // choosing pivot, right
    }
    
    int pivot_value = data[pivot_index];
    // pivot value for easy reference
    swap(data[pivot_index], data[right]);
    // move pivot to end (out of the way)
    pivot_index = left;
    // start looking for "correct" location

    for(int i = left; i < (right); i++)
    {// by scanning the entire array
        if(data[i] < pivot_value) // if value smaller than pivot is found
        {// swap it into left partition
            swap(data[i], data[pivot_index]);
         // and move the dividing point
            pivot_index++;
        } 
        nCompared++; // nCpmpared for number of comparisons
    }
    // swap pivot into its correct location
    swap(data[pivot_index], data[right]);
    // and return the location of the split
    return pivot_index;
}


/**
 * @brief      This is a helper function by the same name of the main
 *             quick sort. This is the recursive call that will call
 *             upon itself until completion.
 *
 * @param        left         This is the number of the left index.
 * @param        right        This is the number of the right index
 * @param        data         This is the array itself being brought in.
 * @param        quickCheck   This is a check to see if the right pivot or
 *                            random pivot should be used in this quick sort.
 * @param[out]   nCompared    This is counting the amount of times a loop is
 *                            done for later data comparison.
 * @return  no return as it is a void funciton.
**/

void quickSort(int left, int right, int data[], bool quickCheck, int &nCompared) 
{
    int division = 0;
    
    if (left < right)
    {   // smaller values to left of division, larger to right
        division = partition(left, right, data, quickCheck, nCompared);
        // now quicksort everything left of division
        quickSort(left, (division - 1), data, quickCheck, nCompared);
         // and everything right of division
        quickSort((division + 1), right, data, quickCheck, nCompared);
    }
}


/**
 * @brief      This is the quick sort call that would be called in main.
 *             upon being called it will call its help function counter part
 *             in which, it will begin the recurrence stack to be built
 *             and allowing quicksort to be completed.
 *
 * @param        data         This is the array itself being brought in.
 * @param        quickCheck   This is a check to see if the right pivot or
 *                            random pivot should be used in this quick sort.
 * @param[out]   nCompared    This is counting the amount of times a loop is
 *                            done for later data comparison.
 *                            
 * @return  no return as it is a void funciton.
**/

void quickSort(int size, int data[], bool quickCheck, int &nCompared)
{ // The sixth and seventh sort, as this sort contains both the right pivot,
    quickSort(0, (size - 1), data, quickCheck, nCompared); // and random pivot.
}


/**
 * @brief      This function is very simple in that it takes in the size
 *             of the array and the array itself to display its contents.
 *             This display is mainly for the user menu.
 *
 * @param   size   The size of the data array
 * @param   data   The array of data itself.
 *
 * @return  no return as it is a void funciton.
**/

void display(int size, int data[]) // simple display function.
{
    cout << "\n"; // takes care of its own spacing.
    for(int i = 0; i < size; i++)
    {
      if(((i+1)%10) == 0) 
      { // if even 10, new line.
          cout  << setw(4) << right << data[i] << endl;
      }
      else if((i) == (size - 1))
      { // last value, new line.
        cout  << setw(4) << right << data[i] << endl;
      }
      else
      {// comma for display, no new line
        cout  << setw(4) << right << data[i] << ", ";
      }
    }
    cout << "\n\n"; // takes care of its own spacing.
}


/**
 * @brief      This is a helper function to help the heap function.
 *             This funciton creates the heapify property that is
 *             used to build the heap and maintain the property
 *             when actions are done to disrupt the heap property.
 *
 * @param     data        The array itself being brought in to be used.
 * @param     size        The size of the array brought in.
 * @param     node        The node used, or what is being worked on.
 * @param     nCompared   The comparsion counter to be used to compare
 *                        data later in the program.
 *
 * @return  no return as it is a void funciton.
**/

void heapify(int data[], int size, int node, int &nCompared)
{
	int root = node; // building root of the tree
  
  // both children are created from a mathmatical sequence.
	int leftChild = 2 * node + 1; // building the left child
	int rightChild = 2 * node + 2; // building the right child
	
	if(leftChild < size && data[leftChild] > data[root]){
		root = leftChild; //left side
    nCompared++;
	}
	
	if(rightChild < size && data[rightChild] > data[root]){
		root = rightChild; // right side
    nCompared++;
	}
	
	if(root != node){
		swap(data[node], data[root]);
		heapify(data, size, root, nCompared); // recurring call. 
	}
}


/**
 * @brief      This is a helper function to help the heap function.
 *             This funciton creates the heapify property that is
 *             used to build the heap and maintain the property
 *             when actions are done to disrupt the heap property.
 *
 * @param     data        The array itself being brought in to be used.
 * @param     size        The size of the array brought in.
 * @param     nCompared   The comparsion counter to be used to compare
 *                        data later in the program.
 *
 * @return  no return as it is a void funciton.
**/

void heapSort(int data[], int size, int &nCompared) // The final sort.
{// arrSize / 2 - 1, is a mathmatical form of the parent in heap.
	for(int i = size / 2 - 1; i >= 0; i--){ // so for each parent.
		heapify(data, size, i, nCompared);
	}
	
	for(int i = size - 1; i >= 0; i--){ 
		swap(data[0], data[i]); 
		
		heapify(data, i, 0, nCompared); // reform after popoff.
	}
}


/**
 * @brief       This is a simple helper function to create the different
 *              arrays used in main. Creating the random array, increasing
 *              array, decreasing array, all based on the passed in size.
 *
 * @param   ran    Sending in the random array to be given values.
 * @param   inc    sending in the increasing array to be given vales.
 * @param   dec    sending in the decreasing array to be given values.
 * @param   size   sending in the size that the arrays should match.
 *
 * @return  no return as it is a void funciton.
**/

void arraySetups(int ran[], int inc[], int dec[], int size){
	for(int i = 0; i < size; i++)
    {
      ran[i] = rand() % 10000 + 0;
      inc[i] = i;
      dec[size - i - 1] = i;
    }
}

#endif