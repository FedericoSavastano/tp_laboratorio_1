#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion;
    int seguir=1;
    float numeroUno;
    float numeroDos;
    int numeroUnoChequeado=0;
    int numeroDosChequeado=0;


    opcion= menuPrimero();


    while(seguir==1)
    {
        switch(opcion)
        {
        case 1:
            numeroUno=obtenerNumeroFlotante("Tu primer numero sera: ");
            numeroUnoChequeado=1;
            break;
        case 2:
            numeroDos=obtenerNumeroFlotante("Tu segundo numero sera: ");
            numeroDosChequeado=1;
            break;
        case 3:
            if(numeroUnoChequeado==1 && numeroDosChequeado==1)
            {
                printf("\nSe hicieron todos los siguientes calculos \n\na). Calcular la suma ( %.2f + % .2f)\n", numeroUno, numeroDos);
                printf("b). Calcular la resta ( %.2f - %.2f ) \n", numeroUno, numeroDos);
                printf("c). Calcular la division ( %.2f / %.2f ) \n", numeroUno, numeroDos);
                printf("d). Calcular la multiplicación ( %.2f * %.2f )\n", numeroUno, numeroDos);
                printf("e). Calcular el factorial (%.2f ! y %.2f ! )\n\n", numeroUno, numeroDos);
                break;
            }
            else
            {
                printf("\nPrimero ingrese los numeros!\n\n");
                break;
            }

        case 4:
            if(numeroUnoChequeado==1 && numeroDosChequeado==1)
            {
                printf("\n\n\n");
                printf("El resultado de %.2f + %.2f  es : %.2f\n",numeroUno,numeroDos,sumarNumeros(numeroUno,numeroDos));
                printf("El resultado de %.2f - %.2f  es : %.2f\n",numeroUno,numeroDos,restarNumeros(numeroUno,numeroDos));
                if(numeroDos==0)
                {
                    printf("No se puede dividir por cero\n");
                }else{
                printf("El resultado de %.2f / %.2f  es : %.2f\n",numeroUno,numeroDos, dividirNumeros(numeroUno,numeroDos));
                }
                printf("El resultado de %.2f * %.2f  es : %.2f\n", numeroUno, numeroDos, multiplicarNumeros(numeroUno,numeroDos));
                printf("El factorial de %.2f es %.2f y ", numeroUno,factorial(numeroUno));
                printf("El factorial de %.2f es %.2f", numeroDos,factorial(numeroDos));
                printf("\n\n\n");
                break;
            }
            else
            {
                printf("\nPrimero ingrese los numeros!\n\n");
                break;
            }


        case 5:
            seguir= 0;
            continue;
            break;

        default:
            printf("\n\nOpcion no valida!\n\n");
            break;

        }//switch(opcion)

        if(numeroUnoChequeado==0 && numeroDosChequeado==0)
        {
            opcion=menuPrimero();
        }
        else if(numeroUnoChequeado==1 && numeroDosChequeado==1)
        {
            opcion=menuConOperadores( numeroUno,numeroDos);
        }
        else if(numeroUnoChequeado==1 && numeroDosChequeado==0)
        {
            opcion=menuConOperadorUno(numeroUno);
        }
        else if(numeroUnoChequeado==0 && numeroDosChequeado==1)
        {
            opcion=menuConOperadorDos(numeroDos);
        }


    }//while(seguir==1)


    printf("\n\nSaliste del programa\n\n");

    return 0;
}
