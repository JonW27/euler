#include <stdio.h>
#include <math.h>
typedef enum {false, true} bool;

int smaller(int num, int num2){
  return num > num2 ? num2 : num;
}

int greater(int num, int num2){
  return num > num2 ? num : num2;
}

void formArray(int num, int arr[], int length){
  int i;
  for(i = 0; i < length; i++){
    int digit = num % 10;
    arr[i] = digit;
    num = floor(num / 10);
  }
}

bool isPalindromeHelper(int arr[], int length){
  for(int i = 0; i < floor(length / 2); i++){
    if(arr[i] != arr[length-1-i]){
      return false;
    }
  }
  return true;
}

bool isPalindrome(num){
  int arr[6]; // you can change this if you want higher numbers
  int length = floor(log10(abs(num)))+1; // theres no length function!
  formArray(num, arr, length);
  return isPalindromeHelper(arr, length);
}

int LargestPalindromeProduct(int num, int num2){
  int highest = -1;
  int rotary = 0;
  int rotary2 = 0;
  int smallr = smaller(num,num2);
  int largr = greater(num,num2);
  while(rotary < smallr || rotary2 < largr){
    if(rotary < smallr){
      rotary++;
    }
    if(rotary2 < largr){
      rotary2++;
    }
    if(rotary * rotary2 > highest && isPalindrome(rotary * rotary2)){
      highest = rotary * rotary2;
    }
  }
  return highest;
}

int multiOfThreeAndFive(int number){
  int i;
  int sum = 0;
  for(i = 0; i < number; i++){
    if(i % 3 == 0 || i % 5 == 0){
      sum += i;
    }
  }
  return sum;
}

int main(){
  int num;
  int num2;
  printf("Enter first number:");
  scanf("%d", &num);
  printf("Enter second number:");
  scanf("%d", &num2);
  printf("%d, %d\n", num, num2);
  printf("Largest Palindrome Product is %d\n", LargestPalindromeProduct(num, num2));
  printf("Sum of Multiples of Three and Five for first number: %d\n", multiOfThreeAndFive(num)); 
}
