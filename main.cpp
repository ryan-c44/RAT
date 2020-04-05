#include <iostream>
#include <vector>
#include "header.h"
using namespace std;

int main(int argc, char *argv[]) {
    vector<Customer> customers;
    vector<Builder> builders;
    vector<Part> parts;

    printCustomerDetails(argv[1], customers);
    printBuilderDetails(argv[2], builders);
    printPartDetails(argv[3], parts);
   
    buildRobot(customers, builders, parts, argv[4]);
    
}