#include <stdio.h>

int temp1 = 1, temp2 = 1, sum = 1, temp = 2, flag = 0, num;

int Fib(int a){
  	if(a == 0){
    	return 0;
    }
  	if(flag == 0){
    	flag = 1;
      	num = a;
    } 
	if(num > temp){
        temp += 1;
    	sum = temp1 + temp2;
        temp1 = temp2;
        temp2 = sum;
        return Fib(a - 1);
    }
    else{
        return sum;
    }
}

int main(){
    printf("%d\n", Fib(9));
}