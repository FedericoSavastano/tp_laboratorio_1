#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int menu (int numeroUnoIngresadoRevision, int numeroDosIngresadoRevision, int numeroIngresadoUno, int numeroIngresadoDos);


int main()
{

    char seguir='s';
    int opcion=0;
    int numeroIngresadoUno;
    int numeroIngresadoDos;
    int numeroUnoIngresadoRevision=0;
    int numeroDosIngresadoRevision=0;



    while(seguir=='s')
    {

        menu(numeroUnoIngresadoRevision,numeroDosIngresadoRevision,numeroIngresadoUno, numeroIngresadoDos);
        opcion=getInt("Elija una opcion");

        switch(opcion)
        {
            case 1:
                numeroIngresadoUno=getInt("Ingrese el primer operando",&numeroIngresadoUno);
                numeroUnoIngresadoRevision=1;
                break;
            case 2:
                numeroIngresadoDos=getInt("Ingrese el segundo operando",&numeroIngresadoDos);
                numeroDosIngresadoRevision=1;
                break;
            case 3:
                if(numeroUnoIngresadoRevision==0 || numeroDosIngresadoRevision==0)
                {
                    printf("Ingresa los numeros primero \n");
                }
                else if (numeroUnoIngresadoRevision==1 && numeroDosIngresadoRevision==1)
                {
                    printf("El resultado de la suma es  %d \n",calcularSuma(numeroIngresadoUno,numeroIngresadoDos));
                }

                break;
            case 4:
                if(numeroUnoIngresadoRevision==0 || numeroDosIngresadoRevision==0)
                {
                    printf("Ingresa los numeros primero \n");
                }
                else if (numeroUnoIngresadoRevision==1 && numeroDosIngresadoRevision==1)
                {
                    printf("El resultado de la resta es %d \n",calcularResta(numeroIngresadoUno,numeroIngresadoDos));
                }

                break;
            case 5:
                if(numeroUnoIngresadoRevision==0 || numeroDosIngresadoRevision==0)
                {
                    printf("Ingresa los numeros primero \n");
                }
                else if (numeroUnoIngresadoRevision==1 && numeroDosIngresadoRevision==1)
                {
                    if(numeroIngresadoDos==0)
                    {
                        printf("No se puede dividir entre cero");
                    }else
                    {
                        printf("El resultado de la division es %d \n",calcularDivision(numeroIngresadoUno,numeroIngresadoDos));
                    }
                }

                break;
            case 6:

                if(numeroUnoIngresadoRevision==0 || numeroDosIngresadoRevision==0)
                {
                    printf("Ingresa los numeros primero \n");
                }
                else if (numeroUnoIngresadoRevision==1 && numeroDosIngresadoRevision==1)
                {
                    printf("El resultado de la multiplicacion es %d \n",calcularMultiplicacion(numeroIngresadoUno,numeroIngresadoDos));
                }

                break;
            case 7:
                if(numeroUnoIngresadoRevision==0 || numeroDosIngresadoRevision==0)
                {
                    printf("Ingresa los numeros primero \n");
                }
                else if (numeroUnoIngresadoRevision==1 && numeroDosIngresadoRevision==1)
                {
                    printf("El resultado del factorial del primer numero es %d \n", calcularFactorialUno(numeroIngresadoUno));
                    printf("El resultado del factorial del segundo numero es %d \n", calcularFactorialDos(numeroIngresadoDos));
                }

                break;
            case 8:
                if(numeroUnoIngresadoRevision==0 || numeroDosIngresadoRevision==0)
                {
                    printf("Ingresa los numeros primero \n");
                }
                else if (numeroUnoIngresadoRevision==1 && numeroDosIngresadoRevision==1)
                {
                    printf("El resultado de la suma es  %d \n",calcularSuma(numeroIngresadoUno,numeroIngresadoDos));
                    printf("El resultado de la resta es %d \n",calcularResta(numeroIngresadoUno,numeroIngresadoDos));
                    if(numeroIngresadoDos==0)
                    {
                        printf("No se puede dividir entre cero \n");
                    }else
                    {
                        printf("El resultado de la division es %d \n",calcularDivision(numeroIngresadoUno,numeroIngresadoDos));
                    }
                    printf("El resultado de la multiplicacion es %d \n",calcularMultiplicacion(numeroIngresadoUno,numeroIngresadoDos));
                    printf("El resultado del factorial del primer numero es %d \n", calcularFactorialUno(numeroIngresadoUno));
                    printf("El resultado del factorial del segundo numero es %d \n", calcularFactorialDos(numeroIngresadoDos));

                }

                break;
            case 9:
                seguir = 'n';

                break;
        }


    }

    return 0;
}
