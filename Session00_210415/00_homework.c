#include <stdio.h>

long senselessModuloFunc(long *a, long *b){
    //input parameter sind Pointer (Adressen)
    //Hier drin werden sie dereferenziert um sie zu verrechnen
    long result = *a % *b;
    return result;
}

void print_array(int *arr, int length) {
  for (int i=0; i<length; i++) {
	printf("\n*arr+%d = %d", i, *arr++);
  }
}

int main(){

// 07: What is '985824 % 23471'?
int modulo = 985824 % 23471;
printf("985824 Modulo 23471 = %d \n", modulo);

/* 08: Read about "call by value" and "call by reference" in your favorite C programming book and explain the difference!

*/

// 09: Write a function that takes two pointers to a long number as parameter and returns a long result after a modulo operation!
long c = 5555;
long d = 1000;
long e = senselessModuloFunc(&c, &d);
printf("senseless result: %ld", e);

/* 
10: Rewrite the func 'print_array(int *arr, int length)' using ptr instead of arr[i]
Tip: You can step forward with ptr++.

int arr[] = [10, 20, 30, 40];
print_array(arr, 4); */
}

