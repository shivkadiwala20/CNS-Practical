#include<stdio.h>
#include<conio.h>
#include<string.h>

int vinere(char [] ,char[]);
int devinere(char[], char[]);

int main(){

	char pt[]= "ANGER";
	char key[] = "HARSH";
	printf("\nGiven Plaintext : %s",pt);
	printf("\nGiven Key : %s",key);
    vinere(pt , key);
	
	getch();


}

int vinere (char pt[],char key[]){
	char result[10];
	int i;
	for(i=0 ; i<strlen(pt) ;i++){
		//printf("\n Value of %c = %d" , pt[i] , pt[i]);
		result[i] = ((pt[i] + key[i]) %	 26+ 65) ;
		printf("\nThe Encrypt : %c ", result[i]);
	}
	devinere(result, key);

	return 0;
}


int devinere (char result[],char key[]){
	char deresult[10];
	int i;
	printf("\n");
	for(i=0 ; i<strlen(result) ;i++){
		//printf("\n Value of %c = %d" , pt[i] , pt[i]);
		deresult[i] = ((result[i] - key[i] +26 ) %26) +65 ;
		printf("\nThe Decrypt : %c ", deresult[i]);
	}
	return 0;
}
