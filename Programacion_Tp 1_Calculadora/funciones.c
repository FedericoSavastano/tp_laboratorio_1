#include <stdio.h>
#include <stdlib.h>


/** \brief  Obtiene un numero entero elegido por el usuario
 *
 * \param mensaje para mostrar
 * \return devuelve el numero flotante elegido por el usuario
 *
 */
int obtenerNumeroEntero (char mensaje[])
{
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);
    return numero;
}


/** \brief Obtiene un numero flotante elegido por el usuario
 *
 * \param mensaje para mostrar
 * \return devuelve el numero flotante elegido por el usuario
 *
 */
float obtenerNumeroFlotante (char mensaje[])
{
    float numero;
    printf("%s",mensaje);
    scanf("%f",&numero);
    return numero;
}


/** \brief Suma dos numeros
 *
 * \param numeroUno float el primer numero obtenido
 * \param numeroDos float el segundo numero obtenido
 * \return float devuelve la suma de los dos numeros obtenidos
 *
 */
float sumarNumeros(float numeroUno, float numeroDos)
{
    float suma;
    suma=numeroUno+numeroDos;
    return suma;
}

/** \brief Resta dos numeros
 *
 * \param numeroUno float el primer numero obtenido
 * \param numeroDos float el segundo numero obtenido
 * \return float devuelve la resta de los dos numeros obtenidos
 *
 */
float restarNumeros(float numeroUno, float numeroDos)
{
    float resta;
    resta=numeroUno-numeroDos;
    return resta;
}

/** \brief multiplica dos numeros
 *
 * \param numeroUno float el primer numero obtenido
 * \param numeroDos float el segundo numero obtenido
 * \return float devuelve la multiplicacion de los dos numeros obtenidos
 *
 */
float multiplicarNumeros(float numeroUno, float numeroDos)
{
    float multiplicar;
    multiplicar=numeroUno*numeroDos;
    return multiplicar;
}

/** \brief divide dos numeros
 *
 * \param numeroUno float el primer numero obtenido
 * \param numeroDos float el segundo numero obtenido
 * \return float devuelve la division de los dos numeros obtenidos
 *
 */
float dividirNumeros(float numeroUno, float numeroDos)
{
    float division;
    division=numeroUno/numeroDos;
    return division;

}

 /** \brief obtiene el factorial de un numero
  *
  * \param numero float el numero obtenido al cual hay que calcularle factorial
  * \return float el factorial del numero obtenido
  *
  */
 float factorial(float numero)
 {
   /**
   opcion sin funcion autoreferencial

    float facto=1;
    int calculador;
    for(calculador=1;calculador<=numero;calculador++)
        facto=facto*calculador;

    return facto;
    **/


    float resultado;

    if(numero<=1)
    {
        resultado=1;
    }
    else
    {
        resultado= numero * factorial( numero - 1);
    }

    return resultado;
 }





 /** \brief Muestra el menu con los casilleros de los operandos en blanco, marcados con una A y B. Obtiene la opcion elegida del menu.
  *
  * \return int regresa la opción elegida del menu
  *
  */
 int menuPrimero()
 {
    int opcion;
        printf(" 1. Ingrese 1er operando ( A )  \n 2. Ingrese 2do operando ( B ) \n 3. Calcular todas las operaciones \n 4. Informar resultados \n 5. Salir \n\n\n");
        printf("Ingrese su eleccion: ");
        scanf("%d",&opcion);

        return opcion;
 }


 /** \brief Muestra el menu con los casilleros de los operadores mostrando los dos numeros legidos. devuelve el numero de opcion elegido del menu.
  *
  * \param numeroUno float el primer numero elegido por el usuario
  * \param numeroDos float el segundo numero elegido por el usuario
  * \return int devuelve el numero de la opcion elegida por el usuario
  *
  */
 int menuConOperadores( float numeroUno, float numeroDos)
 {
        int opcion;
            printf("\n 1. Ingrese 1er operando ( %.2f )  \n 2. Ingrese 2do operando ( %.2f ) \n 3. Calcular todas las operaciones \n 4. Informar resultados \n 5. Salir \n\n\n",numeroUno,numeroDos);
            printf("Ingrese su eleccion: ");
            scanf("%d",&opcion);

            return opcion;
 }

  /** \brief Muestra el menu con el casillero del 1er operador mostrando el numero legido y el segundo con una B. devuelve el numero de opcion elegido del menu.
   *
   * \param numeroUno float el primer numero elegido por el usuario
   * \return int  devuelve el numero de la opcion elegida por el usuario
   *
   */
  int menuConOperadorUno( float numeroUno)
 {
        int opcion;
            printf("\n 1. Ingrese 1er operando ( %.2f )  \n 2. Ingrese 2do operando ( B ) \n 3. Calcular todas las operaciones \n 4. Informar resultados \n 5. Salir \n\n\n",numeroUno);
            printf("Ingrese su eleccion: ");
            scanf("%d",&opcion);

            return opcion;
 }


  /** \brief Muestra el menu con el casillero del 1er operador mostrando una A y en el segundo el numero elegido. devuelve el numero de opcion elegido del menu.
   *
   * \param numeroDos float el segundo numero elegido por el usuario
   * \return int  devuelve el numero de la opcion elegida por el usuario
   *
   */
  int menuConOperadorDos( float numeroDos)
 {
        int opcion;
            printf("\n 1. Ingrese 1er operando ( A )  \n 2. Ingrese 2do operando ( %.2f ) \n 3. Calcular todas las operaciones \n 4. Informar resultados \n 5. Salir \n\n\n",numeroDos);
            printf("Ingrese su eleccion: ");
            scanf("%d",&opcion);

            return opcion;
 }

