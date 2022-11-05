#include <stdio.h>
#include <unistd.h>
int error;

int mode(int array[], int lenght){
	int moda;
	int record = -1;
	int counter;
	error = 0;
	
	for(int i = 0; i<lenght; i++){
		
		counter = 0;
		
		
		if(array[i] != moda){
			
			for(int j=0; j<lenght; j++)
				if(array[j] == array[i])
					counter++;
				
			if(counter > record){
					record = counter;
					moda = array[i];
					error = 0;
			}
			
			else if(counter == record){
				error = 1;
			}	
		}
		
	}
	
	if(error == 1)
		printf("\nModa non calcolabile: Sono presenti piu' valori con la stessa frequenza");
	
	
	return moda;
}

void input(int array[], int lenght){
	printf("\nInserisci i valori: \n");
	for(int i = 0; i<lenght; i++){
		printf("[%d]: ", i);
		scanf("%d", &array[i]);
	}
}




int main(){
	printf("CALCOLO DELLA MODA");
	printf("\nQuesto programma e' in grado di calcolare la moda di una serie di valori interi!\n\n");
	
	int exit = 0;
	
	int nValues;
	do{
		
		printf("Numero di valori da inserire: ");
		scanf("%d", &nValues);
		
		int data[nValues];
		input(data, nValues);
		
		int moda = mode(data, nValues);
		
		if(error == 0)
			printf("\nLa moda equivale a: %d", moda);
		
		
		printf("\n\nVuoi calcolare un'altra moda?[1]: ");
		
		scanf("%d", &exit);
		
		if(exit == 1){
			system("cls");
		}
		
			
			
	}while(exit == 1);
	
	
	
	
}


