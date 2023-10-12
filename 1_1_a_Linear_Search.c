 #include <stdio.h>

int main()

{
   int arr[100], key, i, num, count = 0;
   printf("Enter number of elements : ");
   scanf("%d", &num);

   printf("Enter %d numbers\n", num);
   for (i= 0; i < num; i++)
      scanf("%d", &arr[i]);  

   printf("Enter a number that you would like to search: ");
   scanf("%d", &key);  

   for (i = 0; i < num; i++) 
   {
      if (arr[i] == key) 
      {
         count++;
         break;
      }

   }

   if (count == 0)
      printf("%d key is not present in the array.\n", key);

   else
      printf("%d is present at position %d.\n", key, i+1);    

   return 0;

}
