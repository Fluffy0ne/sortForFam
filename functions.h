/*
	Group Members: 
		Daniel Woodard
		Abhijit Dutta
		Rachael Hawthrone
		Brody Modglin
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void swap (int& a, int& b) // helper function for sorting
{
  int temp = a;
  a = b;
  b = temp;
}

////////////////////////////////////////////////////////////////////////////////////////////

int binarySearch(int a[], int target, int bottom, int top){
	if(top <= bottom){
		if(target > a[bottom]){
			return (bottom + 1);
		}else{
			return (bottom);
		}
	}
	
	int middle = (bottom + top)/2;
	
	if(target == a[middle]){
		return (middle + 1);
	}
	
	if(target > a[middle]){
		return binarySearch(a, target, middle+1, top);
	}
	
	return binarySearch(a, target, bottom, middle-1);
}

/////////////////////////////////////////////////////////////////////////////////////////////

void selectionSort(int size,int data[], int &nCompared) // first sort. // nCompared for number of comaprisons
{
  int count = 0;
  int place = 0;
  bool check = false;
  
  while(count < (size))
  {
    int min = data[count];
    for(int i = count; i < (size); i++)   // each position in Array
    {                                   // find smallest value in subsequent positions
      nCompared++;
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

/////////////////////////////////////////////////////////////////////////////////////////////

void bubbleSort(int size, int data[], int &nCompared) //One of the simpler sorts, and number 2 // nCompared for number of comparisons
{
  bool check = false;
  int shrink = 1;
  do
  {
    check = false;
	// each pair of elements in an ever-shrinking list
    for(int i = 0; i < (size - shrink); i++) 
    {
      nCompared++;
      if(data[i] > data[i + 1])
      { // swap data[pairIndx] and data[pairIndx+1]
        swap(data[i],data[i + 1]);
        check = true;
      }
    }
    shrink++;
  } // end do-while
  while(check == true); // a swap occurred this pass
}  

/////////////////////////////////////////////////////////////////////////////////////////////

void insertionSort(int size, int data[], int &nCompared) // Number 3. // nCompared for number of comparisons
{
  int j;
  int temp = 0;
  for(int i = 1; i < size; i++) // each element after the first
  {
    temp = data[i];// save this number
    j = i - 1;
	// previous elements are bigger than saved element
    while(data[j] > temp && j >= 0) 
    {
      data[j + 1] = data[j];// move previous element forward one position
      j--;
      nCompared++;
    }
    data[j + 1] = temp; // insert saved element in open hole
    nCompared++;
  } // end for     
}

/////////////////////////////////////////////////////////////////////////////////////////////

void insertionSortMod(int size, int data[], int &nCompared) // Number 4.
{
  int j;
  int temp = 0;
  for(int i = 1; i < size; i++) // each element after the first
  {
    j = i - 1;
	temp = data[i];// save this number
	
	int spot = binarySearch(data, temp, 0, j);
	
	while(j >= spot){
		data[j+1] = data[j];
		j--;
		nCompared++;
	}
	data[j+1] = temp;
	nCompared++;
  } // end for     
}

/////////////////////////////////////////////////////////////////////////////////////////////

// The merge part of merge sort.
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
   
   return;
}

/////////////////////////////////////////////////////////////////////////////////////////////

// building the recursion of merge sort.
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

/////////////////////////////////////////////////////////////////////////////////////////////

//the sort called in main, sort 5 in this case.
void mergeSort (int n, int data[], int &nCompared) 
{
   mergeSort (0, n - 1, data, nCompared);
}

/////////////////////////////////////////////////////////////////////////////////////////////

int random_pivot(int left, int right) // helper function pivot for quick sort
{// This is the random pivot.
    int random = rand() % (right - left + 1) + left;  
    
    return random;
}

/////////////////////////////////////////////////////////////////////////////////////////////

int right_pivot(int right) // helper function pivot for quick sort
{// This is the last element as pivot
    return right;
}

/////////////////////////////////////////////////////////////////////////////////////////////

// partition for quick sort, helper function.
int partition(int left, int right, int data[], bool quickCheck, int &nCompared) // nCpmpared for number of comparisons
{
    int pivot_index = 0;
  
    if(quickCheck == true)
    {
      pivot_index = random_pivot(left, right); //choosing pivot
    }
    else
    {
      pivot_index = right_pivot(right);
    }
    
    int pivot_value = data[pivot_index];
    // pivot value for easy reference
    swap(data[pivot_index], data[right]);
    // move pivot to end (out of the way)
    pivot_index = left;
    // start looking for "correct" location
    //for each i from left_index to right_index-1:
    for(int i = left; i < (right); i++)
    {// by scanning the entire array
        if(data[i] < pivot_value)
        {// if value smaller than pivot is found
            swap(data[i], data[pivot_index]);
            // swap it into left partition
            pivot_index++;
        }    // and move the dividing point
        nCompared++;
    }      
    swap(data[pivot_index], data[right]);
    // swap pivot into its correct location
    return pivot_index;
    // and return the location of the split
}

/////////////////////////////////////////////////////////////////////////////////////////////

// helper function for recursion and partition.
void quickSort(int left, int right, int data[], bool quickCheck, int &nCompared) 
{
    int division = 0;
    
    if (left < right)// being "unsorted" requires 2 or more values...
    {
        division = partition(left, right, data, quickCheck, nCompared);
        // smaller values to left of division, larger to right
        quickSort(left, (division - 1), data, quickCheck, nCompared);
        // now quicksort everything left of division
        quickSort((division + 1), right, data, quickCheck, nCompared);
        // and everything right of division
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////

// what is actually called in main, sort 6.
void quickSort(int size, int data[], bool quickCheck, int &nCompared) 
{
    quickSort(0, (size - 1), data, quickCheck, nCompared);
}

/////////////////////////////////////////////////////////////////////////////////////////////

void display(int size, int data[]) // simple display function.
{
    cout << "\n";
    for(int i = 0; i < size; i++)
    {
        cout << data[i] << ", ";
        
        if(((i+1)%10) == 0)
        {
            cout << data[i + 1] << endl;
            i++;
        }
		else if((i + 1) == (size - 1)){
			cout << data[i + 1] << endl;
			i++;
		}
    }
    cout << "\n\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////

void destory(int size, int data[])
{
    int test [20] = {2, 1, 3, 5, 4, 20, 10, 12, 6, 7, 13,
                     8, 14, 9, 19, 15, 17, 16, 11, 18};
                     
    for(int i = 0; i< size; i++)
    {
        data[i] = test[i];
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////

//void destroyO(int size, int data[]){
//	for(int i = 0; i < size; i++) { data[i] = random();}}

/////////////////////////////////////////////////////////////////////////////////////////////

void destroyA(int size, int data[]){
	for(int i = 0; i < size; i++) { data[i] = i;}}

/////////////////////////////////////////////////////////////////////////////////////////////


void destroyD(int size, int data[]){
	for(int i = 0; i < size; i++) { data[i] = size - i;}}

/////////////////////////////////////////////////////////////////////////////////////////////

void heapify(int arr[], int arrSize, int node, int &nCompared){
	int root = node;
	int leftChild = 2*node +1;
	int rightChild = 2*node + 2;
	
	if(leftChild < arrSize && arr[leftChild] > arr[root]){
		root = leftChild;
    nCompared++;
	}
	
	if(rightChild < arrSize && arr[rightChild] > arr[root]){
		root = rightChild;
    nCompared++;
	}
	
	if(root != node){
		swap(arr[node], arr[root]);
		heapify(arr, arrSize, root, nCompared);
	}
}


void heapSort(int arr[], int arrSize, int &nCompared){
	for(int i = arrSize / 2 - 1; i >= 0; i--){
		heapify(arr, arrSize, i, nCompared);
	}
	
	for(int i = arrSize - 1; i >= 0; i--){
		swap(arr[0], arr[i]);
		
		heapify(arr, i, 0, nCompared);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

int randoml()
{
  return rand() % 10000;
}

/////////////////////////////////////////////////////////////////////////////////////////////

void arraySetups(int ran[], int inc[], int dec[], int size){
	//ran = new int[size];
	//inc = new int[size];
	//dec = new int[size];
	for(int i = 0; i < size; i++)
    {
       ran[i] = rand() % 10000 + 0;
	   inc[i] = i;
	   dec[size - i - 1] = i;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
#endif
