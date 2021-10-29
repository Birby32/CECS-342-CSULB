#include <stdio.h>
#include <stdlib.h>

struct Employee {
    void **vtable;
    int age;
};
struct HourlyEmployee {
    void **vtable;
    int age;
    double hourly_rate;
    double hours;
};
struct CommissionEmployee {
    void** vtable;
    int age;
    double sales_amount;
};
struct SeniorSalesman {
    void** vtable;
    int age;
    double sales_amount;
};
void Speak_Hourly(struct Employee *employee) {
    struct HourlyEmployee *hourlyEmployee = (struct HourlyEmployee *) employee;
    //Display hourly rate
    printf("I work for %.2lf dollars per hour :(\n", hourlyEmployee->hourly_rate);
}
void Speak_Commission(struct Employee *employee) {
    struct CommissionEmployee *commissionEmployee = (struct CommissionEmployee *) employee;
    //Display sales amount
    printf("I made commission on %.2lf dollars from sales!\n", commissionEmployee->sales_amount);
}
double GetPay_Hourly(struct Employee *employee) {
    struct HourlyEmployee *hourlyEmployee = (struct HourlyEmployee *) employee;
    double total =  hourlyEmployee->hourly_rate * hourlyEmployee->hours;
    return total;
}
double GetPay_Commission(struct Employee *employee) {
    struct CommissionEmployee *commissionEmployee = (struct CommissionEmployee *) employee;
    double total =  commissionEmployee->sales_amount * 0.1 + 40000 ;
    return total;
}
double GetPay_Senior(struct Employee *employee) {
    struct SeniorSalesman *seniorSalesman = (struct SeniorSalesman *) employee;
    double total =  seniorSalesman->sales_amount * 0.2 + 50000;
    if(seniorSalesman->age >=40){
        total += seniorSalesman->sales_amount *0.05;
    }
    return total;
}
void *Vtable_HourlyEmployee[2] = {Speak_Hourly, GetPay_Hourly};
void *Vtable_CommissionEmployee[2] = {Speak_Commission, GetPay_Commission};
void *Vtable_SeniorSalesman[2] = {Speak_Commission, GetPay_Senior};

struct HourlyEmployee Construct_Hourly(struct HourlyEmployee *hourlyEmployee) {
    hourlyEmployee->vtable = Vtable_HourlyEmployee;
    hourlyEmployee->age = 0;
    hourlyEmployee->hourly_rate = 0;
    hourlyEmployee->hours = 0;
    return *hourlyEmployee;
}
struct CommissionEmployee Construct_Commission(struct CommissionEmployee *commissionEmployee) {
    commissionEmployee->vtable = Vtable_CommissionEmployee;
    commissionEmployee->age = 0;
    commissionEmployee->sales_amount = 0;
    return *commissionEmployee;
}
struct SeniorSalesman Construct_Senior(struct SeniorSalesman *seniorSalesman) {
    seniorSalesman->vtable = Vtable_SeniorSalesman;
    seniorSalesman->age = 0;
    seniorSalesman->sales_amount = 0;
    return *seniorSalesman;
}

int main() {
    struct Employee *employee;
    int choice, age;

    printf("1. Hourly Employee\n");
    printf("2. Commission Employee\n");
    printf("3. Senior Employee\n");
    scanf("%d", &choice);
    while(choice != 1 && choice != 2 && choice !=3){
        printf("Enter number 1-3 only");
        scanf("%d", &choice);
    }

    printf("Input age\n");
    scanf("%d", &age);
    if (choice == 1){

        struct HourlyEmployee *pHourlyEmployee = (struct HourlyEmployee *) malloc(sizeof(struct HourlyEmployee));
        Construct_Hourly(pHourlyEmployee);
        printf("Input pay rate\n");
        scanf("%lf", &(pHourlyEmployee->hourly_rate));
        printf("Input hours\n");
        scanf("%lf", &(pHourlyEmployee->hours));
        employee = (struct Employee *) pHourlyEmployee;
        employee->age = age;
        printf("Total Earned: %f\n", GetPay_Hourly(employee));

    }else if(choice ==2){

        struct CommissionEmployee *pCommissionEmployee = (struct CommissionEmployee *) malloc(sizeof(struct CommissionEmployee));
        Construct_Commission(pCommissionEmployee);
        printf("Input sales amount\n");
        scanf("%lf", &(pCommissionEmployee->sales_amount));
        employee = (struct Employee *) pCommissionEmployee;
        employee->age = age;
        printf("Total Earned: %f\n", GetPay_Commission(employee));

    }else if (choice == 3){

        struct SeniorSalesman *pSeniorSalesman = (struct SeniorSalesman *) malloc(sizeof(struct SeniorSalesman));
        Construct_Senior(pSeniorSalesman);
        printf("Input sales amount\n");
        scanf("%lf", &(pSeniorSalesman->sales_amount));
        employee = (struct Employee *) pSeniorSalesman;
        employee->age = age;
        printf("Total Earned: %f\n", GetPay_Senior(employee));

    }
    ((void (*)(struct Employee *)) employee->vtable[0])((struct Employee *) employee);

    return 0;

}
