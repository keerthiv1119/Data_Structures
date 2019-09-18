/*
Author Name : Keerthi
ID : N!51119
Date : 18-09-2019
*/


void quicksort(int arr[25],int L_Bound,int U_Bound){

   int start, end, pivot, temp;

   if(L_Bound < U_Bound)
   {
      pivot = L_Bound;
      start = L_Bound;
      end = U_Bound;

      while(start < end)
      {
         while(arr[start] <= arr[pivot] && start < U_Bound)
            start++;
         while(arr[end] > arr[pivot])
            end--;
         if(start < end)
         {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
         }
      }
      //swapping of the elements if the starting index crosses the ending index
      temp = arr[pivot];
      arr[pivot] = arr[end];
      arr[end] = temp;
      quicksort(arr,L_Bound,pivot-1);//sorting of the elements left to the pivot
      quicksort(arr,pivot+1,U_Bound);//sorting of the elements right to the pivot
   }
 }

#include<stdio.h>
int main()
{
  int i,array_size;
  printf("Enter the size of the array : ");
  scanf("%d",&array_size);
  int array[array_size];
  printf("Enter the array elements : \n");
  for(i = 0;i < array_size;i++)
  {
    scanf("%d",&array[i]);
  }
  for(i = 0;i < array_size;i++)
  {
    printf("%d\t",array[i]);
  }
  quicksort(array , 0, array_size - 1);
  printf("\n Sorted elements are: \n");
  for(i = 0 ; i < array_size ; i++)
  {
      printf("%d \t",array[i]);
  }
  return 0;
}
