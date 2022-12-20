#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;
struct individual {
    string name;
    int age;
    string genders;
};
void Life_cycle(int number_of_years,int number_of_food,int inventory_renewal, const string file_name );