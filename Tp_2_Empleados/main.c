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

/******************************************

    Trabajo Practico nro 2

    programacion 1 - laboratorio 1

    Federico Savastano 1ero B


*****************************************/



int main()
{
    int idNumberAcumulator=0;
    sEmployee employeesList[ELEMENTS];
    int validateInit;
    int option;
    int emptyPlace;
    int validateEmployeeAdded=0;

    int idToModify;
    int indexToModify;
    int idToRemove;



    validateInit=initEmployees(employeesList,ELEMENTS);

    if(validateInit==0)
    {
        showMenu();
        option=getInt("Choose an option : ");
        while(option!=5)
        {
            switch(option)
            {

            case 1:
                emptyPlace=findEmptyPlace(employeesList,ELEMENTS);
                if(emptyPlace>-1)
                {
                    char auxName [MAX_NAME];
                    char auxLastName [MAX_NAME];
                    float auxSalary;
                    int auxSector;
                    int auxID;

                    int validLastName;
                    int validName;
                    int validSalary;
                    int validSector;

                    int validEmployee;

                    printf("\n");
                    printf("\n");
                    printf("Adding a new employee ");
                    printf("\n");
                    printf("\n");
                    validLastName=getValidString("Enter last name : ", "last name not valid ","last name too long ",auxLastName,MAX_NAME,MAX_TRIES);
                    validName=getValidString("Enter name : ","name not valid","name too long ",auxName,MAX_NAME,MAX_TRIES);
                    validSalary=getValidFloat("Enter salary : ","salary not valid",&auxSalary,MIN_SALARY,MAX_SALARY,MAX_TRIES);
                    validSector=getValidInt("Enter sector : ","sector not valid",&auxSector,MIN_SECTOR,MAX_SECTOR,MAX_TRIES);


                        if( validLastName==0 && validName==0 && validSalary==0 && validSector==0   )
                        {
                            auxID=incrementarID(&idNumberAcumulator);


                            validEmployee=addEmployee(employeesList,ELEMENTS,auxID,auxName,auxLastName,auxSalary,auxSector,emptyPlace);
                            if(validEmployee==0)
                            {
                                validateEmployeeAdded=1;
                                printf("\n");
                                printf("\n\n Employee added successfully \n\n");
                                printf("\n");
                                 break;
                            }
                        }else{
                            printf("\n");
                            printf("\n\n An error ocurred. Unable to add employee. Try again \n\n");
                            printf("\n");
                            break;
                        }

                }else{
                    printf("There is no more space to add employees\n");

                    break;
                }



            case 2:
                if(validateEmployeeAdded==1)
                {
                    printf("\n");
                    printf("\n");
                    printf("Modifying an employee ");
                    printf("\n");

                    if(printEmployees(employeesList,ELEMENTS)==0)
                    {
                        if(getValidInt("\n Write the id of the employee you want to modify : "," Not a valid ID ", &idToModify,0,ELEMENTS,MAX_TRIES)==0)
                        {
                            indexToModify=findEmployeeById(employeesList,ELEMENTS,idToModify);
                            if(modifyEmployee(employeesList,indexToModify)==0)
                            {
                                printf("\n");
                                printf("\n");
                                printf(" \n Modification successful \n ");
                                printf("\n");
                                printf("\n");

                                break;
                            }else{

                                printf("\n");
                                printf("\n");
                                printf(" \n Modification failed. try again \n");
                                printf("\n");
                                printf("\n");
                                break;
                            }
                        }
                    }//if(printEmployees(employeesList,ELEMENTS))

                }else{
                    printf("\n");
                    printf("\n\n You must first add an employee \n\n");
                    printf("\n");
                    break;
                }

                break;


            case 3:
                if(validateEmployeeAdded==1)
                {
                    printf("\n");
                    printf("\n");
                    printf("Removing an employee ");
                    printf("\n");

                    if(printEmployees(employeesList,ELEMENTS)==0)
                    {
                        if(getValidInt("\n Write the id of the employee you want to remove : "," Not a valid ID ", &idToRemove,0,ELEMENTS,MAX_TRIES)==0)
                        {
                            if(removeEmployee(employeesList,ELEMENTS,idToRemove)==0)
                            {
                                printf("\n");
                                printf("\n");
                                printf("\n Removal done successfully \n");
                                printf("\n");
                                printf("\n");
                                break;
                            }else{
                                printf("\n");
                                printf("\n");
                                printf(" \n Removal failed. try again \n ");
                                printf("\n");
                                printf("\n");
                                break;
                            }
                        }
                    }//if(printEmployees(employeesList,ELEMENTS)==0)

                }else{
                    printf("\n");
                    printf("\n\n You must first add an employee \n\n");
                    printf("\n");
                    break;
                }
                break;


            case 4:
                if(validateEmployeeAdded==1)
                {
                    int order;
                    if(getValidInt("Choose the order to show employees [1] for Up , [0] for down ","invalid order",&order,0,1,MAX_TRIES)==0)
                    {
                        if(sortEmployees(employeesList,ELEMENTS,order)==0)
                        {

                            if((printEmployees(employeesList,ELEMENTS)==0) && (totalAndAverageSalary(employeesList,ELEMENTS)==0))
                            {
                                 printf("\n");


                                 break;
                            }else{
                                printf("\nAn error ocurred, unable to inform. Try again\n\n");
                                 break;
                            }

                        }
                    }

                }else{

                    printf("\n\n You must first add an employee \n\n");
                    break;
                }


            }//switch(option)

        system("pause");
        system("cls");


        showMenu();
        option=getInt("Choose an option : ");
    }//while(option!=5)

    }//if(validateInit==0)

    return 0;
}
