#include <iostream>
#include <cstring>
#include <time.h>
#include <vector>
#include <fstream>

using namespace std;

struct individual {
    string name;
    int age;
    string genders;
};

 //Рандомизация пола
string gender_rand()
{
    srand(time(NULL));
    int s = rand() % 2;
    if (s == 1) return "Male";
    else return "Female";
}

//Запись данных об особях в текстовый файл
void write_individuals(string file_name, vector <individual> individuals, int year) {
    ofstream file(file_name, ofstream::app);
    int size = individuals.size();
    file << "____________________" << endl;
    file << "Year:" << year << endl << endl;
    for (int i = 0; i < size; i++){
        file << "Name: " << individuals[i].name << endl;
        file << "Age: " << individuals[i].age << endl;
        file << "Gender: " << individuals[i].genders << endl << endl;
    }
    file.close();
}

int main(int argc, char* argv[]){
    //Вводимые переменные с клавиатуры

    int number_of_food = atoi(argv[1]);
    int inventory_renewal = atoi(argv[2]);
    int number_of_years = atoi(argv[3]);
    const string file_name(argv[4]);

    int year = 0;
    int count_n = 3;

    vector <individual> individuals;

    //Изначальные данные об особях
    
    individual animal_1;
    animal_1.name="animal_1";
    animal_1.age =1;
    animal_1.genders="Male";
    individuals.push_back(animal_1);

    individual animal_2;
    animal_2.name="animal_2";
    animal_2.age =1;
    animal_2.genders="Female";
    individuals.push_back(animal_2);

    write_individuals(file_name, individuals, year);

    return 0;
}