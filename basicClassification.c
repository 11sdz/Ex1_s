#include<math.h>
typedef enum bool {
	True=1,
	False=0
	}bool;

int isPrime (int number){
	if (number==2) {
		return True;
	}
	if (number==3) {
		return True;
	}
	if (number % 2==0){
		return False;
	}
	if (number % 3==0){
		return False;
	}
	int p=5;
	for(;p*p<=number;p=p+2){
		if (number % p==0)
		{
			return False;
		}
	}
	return True;
}

int isStrong (int number){
	if(number==0){
		return False;
	}
	int temp=number,
		 lastdigit=-1,
		 sum=0;	
	int factorials[10]={1,1,2,6,24,120,720,5040,40320,362880};

	for(;temp>0;temp=temp/10){
		lastdigit=temp%10;
		sum=sum+factorials[lastdigit];
	}

	if(sum==number){
		return True;
	}

	return False;
}
