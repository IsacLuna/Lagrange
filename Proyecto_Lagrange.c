#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingDatos(int numPO, float paresX[], float paresY[]);
void lagrangemetod(int numPO, float paresX[], float paresY[], float numSolPar[]);


int main(int argc, char const *argv[]){
    int numPO = 0;
    int val = 0, i;
    do{
        printf("\t\t\t\t----------------INTERPOLACI%cN DE LAGRANGE----------------\n\n", 224);
        printf("\t\tEste programa nos ayudar%c a interpolar.\n", 160);
        printf("\n\t\tReglas:");
        printf("\n\t\tPara llevar a cabo la ejecuci%cn del programa, se debe tener en cuenta lo siguiente:", 162);
        printf("\n\t\t\t1.- Se deber%c de ingresar solo n%cmeros.", 160, 163);
		printf("\n\t\t\t2.- El n%cmero de pares ingresados tiene que ser mayor o igual a 2.\n\n\n", 163);
        while(1){
	        printf("\tIngrese el n%cmero de pares ordenados: ", 163);
	        fflush(stdin);
	        int aux = scanf("%d", &numPO);
	        if(aux != 0 && numPO > 0)
	            break;
	        if(aux == 0)
	            printf("\n\t\tIngrese un n%cmero.\n", 163);
	        else  
	            printf("\t\tIngrese un n%cmero mayor a 0.\n", 163);
        }
        float paresOX[numPO];
        float paresOY[numPO];
        ingDatos(numPO, paresOX, paresOY);


        for(i = 0; i < numPO; i++){
            printf("\n\t\tPar Ordenado %d\t\t", i + 1);
	        printf("X = %4.2f\t\tY = %4.2f", paresOX[i], paresOY[i]);
        }
        printf("\n\n");
        float numSolPar[numPO];

        lagrangemetod(numPO, paresOX, paresOY, numSolPar);
        float sumaResultante = 0;
        for(i = 0; i < numPO; i ++){
            printf("\t\t%d\t\t\t%4.5f\n", i + 1, numSolPar[i]);
            sumaResultante = sumaResultante + numSolPar[i];
        }
        printf("\t\t\t\t    --------------\n");
        printf("\t\t          Y(x)=         %4.5f\n", sumaResultante);

        while(1){
            printf("\n\t%cDesea ingresar otra ecuaci%cn%c\n", 168, 162, 63);
            printf("\t\tDigite 1 para S%c.\n\t\tDigite 2 para No.\n\t\t-- ", 161);
            fflush(stdin);
            int aux1 = scanf("%d", &val);
            if(aux1 != 0 && aux1 == 1 || aux1 == 2) 
                break;
            printf("\t\t\tIngrese un n%cmero correcto.\n", 163);
        }
        system("cls");
    }while(val == 1);
    return 0;
}

void ingDatos(int numPO, float paresX[], float paresY[]){
    float parO;
    int i;
    for(i = 0; i < numPO; i++){
        printf("\n\t\t\tPAR ORDENADO N%cMERO %d\n", 233, i + 1);
        while(1){
            printf("\tIngrese el par ordenado x = ");
            int aux = scanf("%f", &parO);
            fflush(stdin);
            if(aux != 0)
                break;
            printf("\t\tIngrese un n%cmero.\n", 163);
        }
        paresX[i] = parO;
        parO = 0;
        while(1){
            printf("\tIngrese el par ordenado y = ");
            int aux = scanf("%f", &parO);
            fflush(stdin);
            if(aux != 0)
                break;
            printf("\t\tIngrese un n%cmero.\n", 163);
        }
        paresY[i] = parO;
    }
}

void lagrangemetod(int numPO, float paresX[], float paresY[], float numSolPar[]){
    float x = 0;
    int i, j;
    while(1){
        printf("\tIngrese el valor de x para encontrar su y: ");
        int aux = scanf("%f", &x);
        fflush(stdin);
        if(aux != 0)
            break;
        printf("\t\tIngrese un n%cmero.\n", 163);
    }

    for(i = 0; i < numPO; i++){
        float aux = 0, aux1 = 0, aux3 = 1, aux2 = 1; 
        for(j = 0; j < numPO; j++){
            
            if(i != j){
                aux = x -paresX[j];
                aux1 = paresX[i] - paresX[j];
                aux3 = aux3 * aux;
                aux2 = aux2 * aux1;

            }
        }
        numSolPar[i] = paresY[i]*(aux3/aux2);
    }
}