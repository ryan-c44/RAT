#include <string>
#include <vector>

struct Customer {
    std::string customer_name;
    std::string project_name;
    std::string parts;
};

struct Builder {
    std::string builder_name;
    int ability;
    int variability;
};

struct Part {
    std::string part_code;
    std::string part_name;
    int maximum;
    int minimum;
    int complexity;
};

struct Project {
    std::string customer_name;
    std::string project_name;
    std::string builder_name;
    int complexity;
    int variability;
};

void printCustomerDetails(char customer_file[], std::vector<Customer> &customers);
void printBuilderDetails(char builder_file[], std::vector<Builder> &builder);
void printPartDetails(char parts_file[], std::vector<Part> &parts);
void writeReport(char output_file[]);
void buildRobot(std::vector<Customer> &customers, std::vector<Builder> &builders, std::vector<Part> &parts, char output_file[]);