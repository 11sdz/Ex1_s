#include<math.h>
#include<stdio.h>
typedef enum bool {
	True=1,
	False=0
	}bool;
int isArmstrongRec (int number, int power);
int firstDigit (int number);

int isArmstrong (int number){
	if(number<=10){
		return True;
	}
	int power = (int) floor(log10(number))+1;
	int sum=isArmstrongRec(number , power);
	if(sum==number){
	return True;
	}
	return False;
}

int isArmstrongRec (int number, int power){
	if(number==0){
		return 0;
	}
	int lastDigit= number % 10;
	int sum = (int) pow(lastDigit,power); 
	number=number/10;
	sum=isArmstrongRec(number,power)+sum;
	return sum;
}

int isPalindromeRec (int number,int power){
	int newPower = (int) log10(number)+1;
	int left=0,right=0;
	if((power<2) && (newPower<2)){
		return True;
	}
	else{
		if(power>newPower){
			left=0;
		}else{
			left=firstDigit(number);
		}
		right=number % 10;
		if(right!=left){
			return False;
		}
		number=(int) number-(left * (pow(10,power-1)));
		number=number/10;
		int answer=isPalindromeRec(number,power-2);
		return answer;
	}
}

int isPalindrome (int number){
	int power = (int) log10(number)+1;
	return isPalindromeRec(number,power);
}

int firstDigit (int number){
	int power = (int) log10(number);
	int mod = (int) pow(10,power); 
	int firstDigit = number/mod;
	return firstDigit;
}