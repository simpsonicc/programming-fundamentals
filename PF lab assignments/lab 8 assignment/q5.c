#include <stdio.h>

typedef struct PatientInfo{ // inner struct
    int id;
    char name[50];
    char disease[50];
}p;

typedef struct HospitalRecord{ // outer struct
    int room_no;
    float bill;
    p patient_record;
}h;

int main(){
    h record1 = {90, 45000.9, {5, "Omer", "OCD"}};
    h *ptr = &record1; // pointer to a record

    printf("Room No: %d\n", ptr->room_no);
    printf("Bill Amount: %.2f\n",ptr->bill);
    printf("Patient ID: %d\n", ptr->patient_record.id);
    printf("Patient Name: %s\n", ptr->patient_record.name);
    printf("Disease: %s\n", ptr->patient_record.disease);

    return 0;
}