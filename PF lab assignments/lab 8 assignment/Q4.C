#include <stdio.h>

typedef struct address{
    char city[50];
    int zipcode;
    char state[50];
}a;

typedef struct student{
    int roll_no;
    char name[50];
    float gpa;
    a student_address; // nested struct
}s;

int main(){
    a address1 = {"Karachi", 74700, "Sindh"};
    s student1 = {5, "Omer", 4.0, address1};

    printf("Roll No: %d\n",student1.roll_no);
    printf("Name: %s\n",student1.name);
    printf("GPA: %.1f\n", student1.gpa);
    printf("City: %s\n", student1.student_address.city);
    printf("Zipcode: %d\n", student1.student_address.zipcode);
    printf("State: %s\n", student1.student_address.state);
    
    return 0;
}