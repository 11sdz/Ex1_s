#include<math.h>

typedef enum bool {
	True=1,
	False=0
	}bool;

	int isArmstrong (int number){
		if (number==0){
			return False;
		}
		if ((number<=10) || ((number%10==0) && (number<=100))){
			return True;
		}
		int absNumber= (int)fabs(number);
		number=absNumber;
		int power=(int) floor(log10(absNumber))+1;
		int sum=0,
		    lastDigit=-1;
		for(;absNumber>0;absNumber=absNumber/10){
			lastDigit=absNumber%10;
			sum=(int)pow(lastDigit,power);
		}
		if (sum==number){
			return True;
		}
		return False;
}

	int isPalindrome (int number){
		if(number<=9){
			return True;
		}
		if((number<100)){
			if(number%11==0){
				return True;
			}else{
				return False;
			}
		}
		int absNumber= (int)fabs(number);
		int len=(int) floor(log10(absNumber))+1;
		int digitsArr[len];
		int i=0,j=len-1;
		for(;absNumber>0;absNumber=absNumber/10,i=i+1){
			digitsArr[i]=absNumber%10;
		}
		i=0;
		for(;i<j;i=i+1,j=j-1){
			if(digitsArr[i]!=digitsArr[j]){
				return False;
			}
		}
	return True;
	
	}
