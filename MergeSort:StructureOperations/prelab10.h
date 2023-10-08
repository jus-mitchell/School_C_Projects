
typedef struct Employee {
    char * name;
    int SSN, ID, salary;
} Employee;

typedef struct EmpDatabase {
    Employee ** empArraySortedByID, ** empArraySortedBySSN;
    int ec, size;
} EmpDatabase;

EmpDatabase createSearchableEmployeeDB(Employee ** inputArray, int n);

Employee * findEmpBySSN(int SSN, EmpDatabase inputDatabase);

Employee * findEmpByID(int ID, EmpDatabase inputDatabase);

void freeEmpDatabase(EmpDatabase inputDatabase);

int getErrorCode(EmpDatabase inputDatabase);

int countEmpsInSalaryRange(int min, int max, EmpDatabase inputDatabase);