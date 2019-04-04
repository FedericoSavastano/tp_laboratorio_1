#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**
*\brief se crea una funcion para mostrar el menu y si estan cargados los numeros ingresados los muestre por pantalla
*\param las variables de chequeo, o flags, para ver cual dato se ha ingresado
*\param los numeros ingresados que se mostraran por pantalla
*\return mostrar menu por pantalla, 0 para saber que no hay error
*/

int menu (int numeroUnoIngresadoRevision, int numeroDosIngresadoRevision, int numeroIngresadoUno, int numeroIngresadoDos)
{
    if(numeroUnoIngresadoRevision==0 && numeroDosIngresadoRevision==0)
    {
        printf(" \n 1_ Ingresar 1er operando ( A = x )\n 2_ Ingresar el 2do operando ( B = y ) \n 3_ Calcular la Suma ( A + B ) \n 4_ Calcular la Resta ( A - B ) \n 5_ Calcular la Division ( A / B ) \n 6_ Calcular la Multiplicacion ( A * B ) \n 7_ Calcular el Factorial ( A! ) \n 8_ Calcular todas las operaciones \n 9_ Salir \n");
    }
    else if(numeroUnoIngresadoRevision==1 && numeroDosIngresadoRevision==0)
    {
        printf(" \n 1_ Ingresar 1er operando ( A = %d )\n 2_ Ingresar el 2do operando ( B = y ) \n 3_ Calcular la Suma ( A + B ) \n 4_ Calcular la Resta ( A - B ) \n 5_ Calcular la Division ( A / B ) \n 6_ Calcular la Multiplicacion ( A * B ) \n 7_ Calcular el Factorial ( A! ) \n 8_ Calcular todas las operaciones \n 9_ Salir \n", numeroIngresadoUno);
    }
    else if (numeroUnoIngresadoRevision==0 && numeroDosIngresadoRevision==1)
    {
        printf(" \n 1_ Ingresar 1er operando ( A = x )\n 2_ Ingresar el 2do operando ( B = %d ) \n 3_ Calcular la Suma ( A + B ) \n 4_ Calcular la Resta ( A - B ) \n 5_ Calcular la Division ( A / B ) \n 6_ Calcular la Multiplicacion ( A * B ) \n 7_ Calcular el Factorial ( A! ) \n 8_ Calcular todas las operaciones \n 9_ Salir \n", numeroIngresadoDos);
    }
    else if(numeroUnoIngresadoRevision==1 && numeroDosIngresadoRevision==1)
    {
        printf(" \n 1_ Ingresar 1er operando ( A = %d )\n 2_ Ingresar el 2do operando ( B = %d ) \n 3_ Calcular la Suma ( A + B ) \n 4_ Calcular la Resta ( A - B ) \n 5_ Calcular la Division ( A / B ) \n 6_ Calcular la Multiplicacion ( A * B ) \n 7_ Calcular el Factorial ( A! ) \n 8_ Calcular todas las operaciones \n 9_ Salir \n",numeroIngresadoUno ,numeroIngresadoDos);
    }

    return 0;
}






/** \brief Creamos la funcion para obtener enteros, sera usada para obtener los dos operandos y
*          la eleccion de las opciones que haga el usuario
*\param el mensaje a mostrar
*\return el numero entero solicitado
*/

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

/**
*\brief calculamos la suma
*\param los dos numeros ingresados
*\return los dos numeros ingresados sumados
*/

int calcularSuma ( int numeroIngresadoUno, int numeroIngresadoDos)
{
    int suma= numeroIngresadoUno + numeroIngresadoDos;
    return suma;
}

/**
*\brief calculamos la resta
*\param los dos numeros ingresados
*\return los dos numeros ingresados restados
*/

int calcularResta ( int numeroIngresadoUno, int numeroIngresadoDos)
{
    int resta= numeroIngresadoUno - numeroIngresadoDos;
    return resta;
}

/**
*\brief calculamos la multiplicacion
*\param los dos numeros ingresados
*\return los dos numeros ingresados multiplicados
*/

int calcularMultiplicacion ( int numeroIngresadoUno, int numeroIngresadoDos)
{
    int multiplicacion= numeroIngresadoUno * numeroIngresadoDos;
    return multiplicacion;
}

/**
*\brief calculamos la division
*\param los dos numeros ingresados
*\return los dos numeros ingresados dividios
*/

int calcularDivision ( int numeroIngresadoUno, int numeroIngresadoDos)
{
    int division= numeroIngresadoUno / numeroIngresadoDos;
    return division;
}



/**
*\brief calculamos el factorial, se hace una funcion para cada numero
*\param el numero ingresado
*\return el factorial de cada numero
*/

int calcularFactorialUno ( int numeroIngresadoUno )
{
    int factorialNumeroUno;
    if(numeroIngresadoUno<=1)
    {
        factorialNumeroUno= 1;
    }else
    {
        factorialNumeroUno= numeroIngresadoUno* calcularFactorialUno(numeroIngresadoUno - 1);
    }
    return factorialNumeroUno;
}

int calcularFactorialDos (int numeroIngresadoDos)
{
    int factorialNumeroDos;
    if(numeroIngresadoDos<=1)
    {
        factorialNumeroDos= 1;
    }else
    {
        factorialNumeroDos= numeroIngresadoDos* calcularFactorialDos(numeroIngresadoDos - 1);
    }
    return factorialNumeroDos;
}
