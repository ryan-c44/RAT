#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include "header.h"
using namespace std;

/* 
    TODAYS GOAL: 

    read each file into their respective struct array. For example there is a constant
    of 4 customers, read each file and place all data of each customer into array so it can be used
    in buildRobot() where we can loop through each customer and randomise what builder is assigned.

    Complete:
        - Successfully read in all data objects in correct format
        - Reported to standard out of all these objects
        - Error opening each file is completed.
        - Structs for each data type
        - Reading in each object to struct array

    Incomplete:
        - Invalid data checks to cerr (e.g formatting)
        - buildRobot() function
            - Reporting success of each build to output_file.
            - Looping through customers and assigning builders
            - Converting strings to their respective data type (e.g stoi, stof, string to char etc)
            - Implementing given algorithms to calculate success or failure of robot
*/

void printCustomerDetails(char customer_file[], vector<Customer> &customers) {
    ifstream inFile; 
    Customer customer;
    string customerDetails;
    string customer_name;
    string project_name;
    string parts;

    inFile.open(customer_file);
    
    cout << "\nCustomer Details: \n" << endl;

    if(!inFile) {
        cerr << "Error opening: " << customer_file << endl;
        abort();
    }

    while(!inFile.eof()) {

        getline(inFile, customerDetails);
        stringstream ss(customerDetails);

        getline(ss, customer_name, ':');
        getline(ss, project_name, ':');
        getline(ss, parts, ':');

        customer.customer_name = customer_name;
        customer.project_name = project_name;
        customer.parts = parts;
        customers.push_back(customer);
    
        cout << "Name: " << customer.customer_name;
        cout << ", Project Name: " << customer.project_name;
        cout << ", Parts: " << customer.parts << "\n";
    }

    inFile.close();
}

void printBuilderDetails(char builder_file[], vector<Builder> &builders) {
    //standard out all data in correct format
    Builder builder;
    string builder_name;
    string ability;
    string variability;
    string builderDetails;
    ifstream inFile; 

    inFile.open(builder_file);
    
    cout << "\nBuilder Details: \n" << endl;

    if(!inFile) {
        cerr << "Error opening: " << builder_file << endl;
        abort();
    }

    //Invalid data check

    //While loop to read each line to the end of line and print each builder detail.
    while(!inFile.eof()) {

        getline(inFile, builderDetails);
        stringstream ss(builderDetails);

        getline(ss, builder_name, ':');
        getline(ss, ability, ':');
        getline(ss, variability, ':');

        builder.builder_name = builder_name;
        builder.ability = stoi(ability);
        builder.variability = stoi(variability);

        builders.push_back(builder);

        cout << "Name: " + builder.builder_name;
        cout << ", Ability: " << builder.ability;
        cout <<  ", Variability: " << builder.variability << endl; 
        
    }
    inFile.close();
}

void printPartDetails(char parts_file[], vector<Part> &parts) {
    string partDetails;
    string part_code;
    string part_name;
    string minimum;
    string maximum;
    string complexity;
    Part part;
    ifstream inFile;

    inFile.open(parts_file);

    cout << "\nPart Details: \n" << endl;

    if(!inFile) {
        cerr << "Error opening: " << parts_file << endl;
        abort();
    }

    //Invalid data check

    //Read data in from file, partition each line and place into struct array.
    while(!inFile.eof()) {

        getline(inFile, partDetails);
        stringstream ss(partDetails);

        getline(ss, part_code, ':');
        getline(ss, part_name, ':');
        getline(ss, minimum, ':');
        getline(ss, maximum, ':');
        getline(ss, complexity, ':');

        part.part_code = part_code;
        part.part_name = part_name;
        part.maximum = stoi(maximum);
        part.minimum = stoi(minimum);
        part.complexity = stoi(complexity);

        parts.push_back(part);

        cout << "Part Code: " << part.part_code;
        cout << ", Part Name: " << part.part_name;
        cout << ", Minimum: " << part.minimum;
        cout << ", Maximum: " << part.maximum;
        cout << ", Complexity: " << part.complexity << endl;
        
    }

    inFile.close();
}


void buildRobot(vector<Customer> &customers, vector<Builder> &builders, vector<Part> &parts, char output_file[]) {
    //each customer orders a build
    //randomly allocate array of builders read in from file to each customer
    //robot is built with series of randomly allocated values to determine success
    //if successful moves to next customer, else re-attempts up to two times, print status
    vector<Project> projects;
    ofstream outFile;
    Project project;
    uniform_int_distribution<unsigned> uniform(0, 3);
    default_random_engine randEng;
    char part_letter;

    int attempts = 0;
    bool isBuilt;

    //Allocating a builder to each customer using a project struct.
    for(int i = 0; i < customers.size(); i++) {
        Builder builder = builders[uniform(randEng)];

        project.builder_name = builder.builder_name;
        project.customer_name = customers[i].customer_name;
        project.project_name = customers[i].project_name;
        project.variability = builder.variability;

        projects.push_back(project);
    }

    outFile.open(output_file);

    for(Project project : projects) {
        outFile << "Customer name: " << project.customer_name;
        outFile << ", Project name: " << project.project_name;
        outFile << ", Builder name: " << project.builder_name;
        outFile << ", Distribution paramaters: " << project.variability;
        outFile << part_letter << endl;
    }


    do {
        //Build robot

        attempts++;
    } while(attempts <= 3); //Do this until either successful or attempts = 3;
    
}

void writeReport(char output_file[]){
    //write to output-file whether the build was successful

}



/*

 for(Customer customer : customers) {
    string part = customer.parts; 
    int n = part.length();
    char char_array[n + 1];

    strcpy(char_array, part.c_str());

    for (int i = 0; i < n; i++) {
        part_letter = char_array[i];
    }
}

*/