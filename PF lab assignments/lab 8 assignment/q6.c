#include <stdio.h>

#define rate 50 // global variable
static int totalvehicles = 0; // static makes the initialisation only once when the function is first called
static int totalrevenue = 0;

void processVehicle(char vehicleType[]){
    totalrevenue += rate;
    totalvehicles += 1;
}

int main(){
    processVehicle("Car");
    processVehicle("Motorcycle");
    processVehicle("Truck");
    processVehicle("Bus");
    processVehicle("Car");

    printf("Total Vehicles passed: %d\n", totalvehicles);
    printf("Total revenue: %d\n", totalrevenue);

    return 0;
}