#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "func.h"

#define TRUE 0
#define FALSE 1
#define ELEMENTS 1000

#define MAX_NAME 51
#define MAX_TRIES 3
#define MIN_SALARY 1000
#define MAX_SALARY 9000
#define MIN_SECTOR 1
#define MAX_SECTOR 10


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(sEmployee* list, int len)
{
    int returnInt;

    if(list!=NULL && len==ELEMENTS)
    {
        int i;
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=TRUE;
            returnInt = 0;
        }

    }else{
        returnInt = -1;
    }

    return returnInt;
}





/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \param empty place int index to use
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */

int addEmployee(sEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector, int emptyPlace)
{

   if(list!=NULL && len==ELEMENTS)
    {

       strcpy( list[emptyPlace].lastName , lastName );
       strcpy( list[emptyPlace].name, name );
       list[emptyPlace].salary=salary;
       list[emptyPlace].sector=sector;
       list[emptyPlace].id=id;

       list[emptyPlace].isEmpty=FALSE;

     return 0;
    }


    return -1;

}





/** \brief hardcoding of employees to check results
 *
 * \param list[] sEmployee list of employees
 * \param len int array length
 * \return void
 *
 */
void hardcodeofEmployees(sEmployee list[], int len)
{

    int id[]={1,2,3};
    char name[] [51]={"John","Aichael","Mary"};
    char lastName[] [51]={"Aitchell","Citchell","Citchell"};
    float salary[]={900,300,850};
    int sector[]={11,12,30};
    int isEmpty[]={1,1,1};

    int i;

    for(i=0;i<len;i++)
    {
        list[i].id=id[i];
        strcpy( list[i].name, name[i]);
        strcpy(list[i].lastName,lastName[i]);
        list[i].salary=salary[i];
        list[i].sector=sector[i];
        list[i].isEmpty=isEmpty[i];
    }

}










/** \brief finds an empty index
 *
 * \param list Employee the structure list
 * \param int array length
 * \return int the index found or -1 if there is none
 *
 */
int findEmptyPlace (sEmployee* list, int len)
{
    int i;
    int emptyPlaceValid=0;
    int indexFound;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            indexFound=i;
            emptyPlaceValid=1;
            break;
        }else if(list[i].isEmpty== '\0' && emptyPlaceValid==0)
        {
            indexFound=-1;
        }

    }

    return indexFound;
}






/** \brief print the content of employees array
*
* \param list Employee*
* \param len int array length
* \return int 0 if ok -1 if error (list is null or invalid lenght)
*
*/
int printEmployees(sEmployee* list, int len)
{
    if(list!=NULL && len==ELEMENTS)
    {
        int i;
        printf("\n\n 1. List of employees \n\n");
        printf("\n");
        printf("\t  Id  \t  Last Name  \t  Name  \t  Salary  \t  Sector  \t");
        printf("\n");
        printf("\n");
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==FALSE)
            {
                printf("\n");
                printf("\t  %02d  \t  %10s  \t  %10s  \t  %.2f  \t  %02d  \t",list[i].id, list[i].lastName,list[i].name,list[i].salary,list[i].sector);
                printf("\n");
            }
           //printf("\t %s \t \n",list[i].lastName);
        }


        return 0;
    }

    return -1;
}



/** \brief find an Employee by Id and returns the index position in array.
*
* \param list Employee*
* \param len int array length
* \param id int the id to search
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(sEmployee* list, int len,int id)
{
    int i;
    //scanf("%d",&id);

    if(list!=NULL && len==ELEMENTS)
    {
        for(i=0;i<len;i++)
        {
            if(id == list[i].id)
            {
                return i;
            }
        }
    }


    return -1;
}





/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee* the list of employees
* \param len int array lenght
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(sEmployee* list, int len, int order)
{
   int i;
   int j;
   sEmployee auxEmployee;

   if(list!=NULL && len==ELEMENTS)
   {
       /**order Up**/ //ascendente
       if(order==1)
       {
           for(i=0;i<len-1;i++)
           {
               for(j=i+1;j<len;j++)
               {
                  if (( strcmp(list[i].lastName, list[j].lastName)  > 0 ) || (list[i].sector > list[j].sector))
                  {
                      auxEmployee = list[i];
                      list[i] = list[j];
                      list[j] = auxEmployee;
                  }//if (( strcmp(list[i].lastName, list[j].lastName)  > 0 ) || (list[i].sector > list[j].sector))
                }//for(j=i+1;j<len;j++)
           }//for(i=0;i<len-1;i++)
        }// if(order==1)



        /**order Down**/ //descendente
        if(order==0)
       {
           for(i=0;i<len-1;i++)
           {
               for(j=i+1;j<len;j++)
               {
                  if ( ( strcmp(list[i].lastName, list[j].lastName)  < 0 ) || (list[i].sector < list[j].sector) )
                  {
                      auxEmployee = list[i];
                      list[i] = list[j];
                      list[j] = auxEmployee;
                  }//if ( ( strcmp(list[i].lastName, list[j].lastName)  < 0 ) || (list[i].sector < list[j].sector) )
                }//for(j=i+1;j<len;j++)
           }//for(i=0;i<len-1;i++)
        }//if(order==0)

    }//if validation
    return 0;
}




/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee* the list of employees
* \param len int array length
* \param id int  the id of the employee to modify
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(sEmployee* list, int len, int id)
{

    int i;
    //scanf("%d",&id);

    if(list!=NULL && len==ELEMENTS)
    {
        for(i=0;i<len;i++)
        {
            if(id == list[i].id)
            {
                list[i].isEmpty=TRUE;
                return 0;
            }
        }
    }

    return -1;

}




/** \brief gives and prints the total an the average of salaries
 *
 * \param list Employee the list of employees
 * \param int len array length
 * \return Return (-1) if Error [Invalid length or NULL pointer ] - (0) if Ok
 *
 */
int totalAndAverageSalary (sEmployee* list, int len)
{
    int i;
    float acumulatorSalary;
    float averageSalary;
    int counterEmployeeAboveSalary;
    int counterEmployees;

    acumulatorSalary=0;
    averageSalary=0;
    counterEmployeeAboveSalary=0;
    counterEmployees=0;

    if(list!=NULL && len==ELEMENTS)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==FALSE)
            {
                counterEmployees++;
                acumulatorSalary=list[i].salary + acumulatorSalary;



            }//if(list[i].isEmpty==FALSE)
        }//for(i=0;i<len;i++)





        averageSalary=acumulatorSalary/(float)counterEmployees;

        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==FALSE)
            {
                if(list[i].salary>averageSalary)
                {
                    counterEmployeeAboveSalary++;
                }//if(list[i].salary>averageSalary)
            }//if(list[i].isEmpty==FALSE)
        }//for(i=0;i<len;i++)




        printf("\n\n 2. Total and average salary \n\n ");

        printf("\n");
        printf(" The total of salaries is : %.2f \n", acumulatorSalary);
        printf(" The average of salaries is : %.2f \n", averageSalary);
        printf(" There are %d employees above the average salary \n", counterEmployeeAboveSalary);
        printf("\n");
        printf("\n");

        return 0;
    }//if(list!=NULL && len==ELEMENTS)

    return -1;


}




/** \brief modifies the selected variable in the structure
 *
 * \param list Employee the list of employees
 * \param int index to modify
 * \return int 0 if succesfull , -1 if list is null or index surpases elements
 *
 */

int modifyEmployee (sEmployee list[], int index)
{


    if(list!=NULL && index<ELEMENTS)
    {

        int option;

        char auxName [51];
        char auxLastName [51];
        float auxSalary;
        int auxSector;
        //int auxID;

        int validLastName;
        int validName;
        int validSalary;
        int validSector;


        printf("\n\n Choose what you want to modify \n\n");
        printf("\n");
        printf("\n 1. Name \n 2. Last Name \n 3. Salary \n 4. Sector \n 5. Exit \n\n");
        printf("\n");
        printf("\n");
        scanf("%d",&option);
        while(option!=5)
        {


            switch(option)
            {
                case 1:
                    validName=getValidString("Enter name : ","name not valid","name too long ",auxName,51,3);
                    if(validName==0)
                    {
                        strcpy( list[index].name, auxName );
                        printf("\n");
                        printf("Name modified successfully \n");
                        printf("\n");
                        break;
                    }else{
                        printf("\n");
                        printf("Couldn't modify name, try again ");
                        printf("\n");
                        break;
                    }

                case 2:
                    validLastName=getValidString("Enter last name : ","last name not valid","last name too long ",auxLastName,51,3);
                    if(validLastName==0)
                    {
                        strcpy( list[index].lastName, auxLastName );
                        printf("\n");
                        printf("Last name modified successfully \n");
                        printf("\n");
                        break;
                    }else{
                        printf("\n");
                        printf("Couldn't modify last name, try again \n");
                        printf("\n");
                        break;
                    }
                case 3:
                    validSalary=getValidFloat("Enter salary ","salary not valid",&auxSalary,0,2000,3);
                    if(validSalary==0)
                    {
                        list[index].salary=auxSalary;
                        printf("\n");
                        printf("Salary modified successfully \n");
                        printf("\n");
                        break;
                    }else{
                        printf("\n");
                        printf("Couldn't modify salary, try again \n");
                        printf("\n");
                        break;
                    }
                case 4:
                    validSector=getValidInt("Enter sector : ","sector not valid",&auxSector,1,10,3);
                    if(validSector==0)
                    {
                        list[index].sector=auxSector;
                        printf("\n");
                        printf("Sector modified successfully \n");
                        printf("\n");
                        break;
                    }else{
                        printf("\n");
                        printf("Couldn't modify sector, try again \n");
                        printf("\n");
                        break;
                    }


            }//switch(option)

            printf("\n\n Choose what you want to modify \n\n");
            printf("\n");
            printf("\n 1. Name \n 2. Last Name \n 3. Salary \n 4. Sector \n 5. Exit \n\n");
            printf("\n");
            printf("\n");
            scanf("%d",&option);


        }//while(option!=5)

        return 0;

    }//if(list!=NULL && index<ELEMENTS)

    return -1;
}




/** \brief shows menu to choose an option
 *
 * \return void
 *
 */
void showMenu ()
{
    printf("\n\n ** EMPLOYEES LIST ** \n\n");
    printf("What do you want to do : \n\n ");
    printf("\n");
    printf("1. Add Employee\n");
    printf("2. Modify Employee \n");
    printf("3. Remove Employee \n");
    printf("4. Inform \n");
    printf("5. Exit \n");
    printf("\n");
    printf("\n");
}
