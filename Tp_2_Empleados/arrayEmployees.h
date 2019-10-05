#define TRUE 0
#define FALSE 1
#define ELEMENTS 1000

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty; //*CERO PARA CIERTO, 1 PARA FALSO

}sEmployee;


int initEmployees(sEmployee* list, int len);

int findEmptyPlace (sEmployee* list, int len);

void hardcodeofEmployees(sEmployee list[], int len);
int printEmployees(sEmployee* list, int length);

int findEmployeeById(sEmployee* list, int len,int id);
int sortEmployees(sEmployee* list, int len, int order);
int removeEmployee(sEmployee* list, int len, int id);

int totalAndAverageSalary (sEmployee* list, int len);


int addEmployee(sEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector, int emptyPlace);

int modifyEmployee (sEmployee list[], int index);

void showMenu ();
