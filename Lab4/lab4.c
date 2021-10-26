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
    void **vtable;
    int age;
    double sales_amount;
};

struct SeniorSalesman {
    void **vtable;
    int age;
    double sales_amount;
};

void Speak_Hourly(struct Employee *employee) {
    struct HourlyEmployee *hourlyEmployee = (struct HourlyEmployee *) employee;
    //Display hourly rate
    printf("I work for %.2lf dollars per hour :(\n", hourlyEmployee->hourly_rate);
}

double GetPay_Hourly(struct Employee *employee) {
    struct HourlyEmployee *hourlyEmployee = (struct HourlyEmployee *) employee;
    return hourlyEmployee->hourly_rate;
}

void Speak_Commission(struct Employee *employee) {
    struct CommissionEmployee *commissionEmployee = (struct CommissionEmployee *) employee;
    ///Display sales amount
    printf("I made commission on %.2lf dollars from sales!\n", commissionEmployee->sales_amount);
} 

double GetPay_Commission(struct Employee *employee) {
    struct CommissionEmployee *commissionEmployee = (struct CommissionEmployee *) employee;
    commissionEmployee->sales_amount;
}

double GetPay_Senior(struct Employee *employee) {
    struct SeniorSalesman *seniorsalesman = (struct SeniorSalesman *) employee;
    double age_bonus = 0;
    if(seniorsalesman->age > 40)
        age_bonus = seniorsalesman->sales_amount*0.05;
    
    return (seniorsalesman->sales_amount*0.2 + 50000 + age_bonus);
}

void *Vtable_HourlyEmployee[2] = {Speak_Hourly, GetPay_Hourly};
void *Vtable_CommisionEmployee[2] = {Speak_Commission,GetPay_Commission};
void *Vtable_SeniorSalesman[2] = {Speak_Commission,GetPay_Senior};

struct HourlyEmployee Construct_Hourly(struct HourlyEmployee *hourlyEmployee) {
    hourlyEmployee->vtable = Vtable_HourlyEmployee;
    hourlyEmployee->age = 0;
    hourlyEmployee->hourly_rate = 0;
    hourlyEmployee->hours = 0;
}

struct CommissionEmployee Construct_Commission(struct CommissionEmployee *commissionEmployee) {
    commissionEmployee->vtable = Vtable_CommisionEmployee;
    commissionEmployee->age = 0;
    commissionEmployee->sales_amount = 0;
}

struct SeniorSalesman Construct_Senior(struct SeniorSalesman *seniorSalesman) {
    seniorSalesman->vtable = Vtable_SeniorSalesman;
    seniorSalesman->age;
    seniorSalesman->sales_amount = 0;
}

int main() {
    struct Employee *employee;
    // Display the selections. Validate the selection/

    // Input age
    int age; 
    //For hourly employee
    struct HourlyEmployee *pHourlyEmployee = (struct HourlyEmployee *) malloc(sizeof(struct HourlyEmployee));
    //Consturct pHourlyEmployee
    //Input hourly rate and hours

    employee = (struct Employee *) pHourlyEmployee;
    //Do the same for other employee types
    employee->age = age;
    ((void (*)(struct Employee *)) employee->vtable[0])((struct Employee *) employee);
    //  ………………………………………………….
    return 0;
}
// TODO: Not sure why this is here
// ( (void *) (struct Employee *)) employee->vtable[0] ( (struct Employee *) employee)