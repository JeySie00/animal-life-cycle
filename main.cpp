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



 //Рандомизация пола
string gender_rand()
{
    int s = rand() % 2;
    if (s == 1) return "Male";
    else return "Female";
}


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
    srand(time(NULL));
    int number_of_food = atoi(argv[1]);
    int inventory_renewal = atoi(argv[2]);
    int number_of_years = atoi(argv[3]);
    const string file_name(argv[4]);


    int year = 0;
    int count_n = 3;


    //Изначальные данные об особях
    vector <individual> individuals;
    
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


    //int number_of_food = 5;
    //int inventory_renewal = 2;
    //int number_of_years = 5;
    
    for (int i=0;i<number_of_years;i++)
    { 
        year++;
        cout<<"Year: " << year <<endl;

        //Константы
        const int const_born = 50; //вероятность воспроизведения потомства (%)
        const int const_eat = 1; //потребление пищи за год
        const int const_die = 50; //вероятность смерти (%)
        vector<string>die;
        vector<string>born;

        
        srand(time(NULL));
        
        //Вымирание 
        for (int i = 0; i < individuals.size(); i++)
        {   
            int tmp = rand() % 101;
            if (const_die>=tmp)
            { 
                if (individuals[i].age >=10) {
                die.push_back(individuals[i].name); 
                individuals.erase(individuals.begin() + i);
                }

            }
            if (individuals[i].age>=15){ 
                individuals.erase(individuals.begin() + i);
                die.push_back(individuals[i].name); 
                }

        }

        
        //Кормление
        int sum_food=number_of_food + inventory_renewal;
        cout<<"Amount of food: "<<sum_food<<endl;
        int sum_food_for=0;
        for (int i = 0; i < individuals.size(); i++)
        {  
            if (individuals[i].age>=1) 
                sum_food_for+=const_eat;
        }
        cout<<"Needed for feeding: "<<sum_food_for<<endl;
        while (sum_food_for>sum_food)
        {
            sum_food_for -= const_eat;
            int pop=rand()%individuals.size();
            die.push_back(individuals[pop].name);
            individuals.erase(individuals.begin() + pop);
        }
        sum_food-=const_eat*individuals.size();
        number_of_food=sum_food;
        cout<<"Leftover food: "<<sum_food<<endl;
        


        //Скрещивание и рождение
        int male_count = 0, female_count = 0;
        for (int i = 0; i < individuals.size(); i++)
        {   
            if (individuals[i].genders == string("Male")) {
                if ((individuals[i].age>=1) & (individuals[i].age<=13)) {
                    male_count++;
                }
            }
            if (individuals[i].genders == string("Female")) {
                if ((individuals[i].age>=1) & (individuals[i].age<=13)) {
                    female_count++;
                }
            }
        }
        cout << "M: " << male_count << endl;
        cout << "F: " << female_count << endl;
        int born_count = 0;
        int count = 0;
        if (max(male_count, female_count) != 0) {
            born_count = min(male_count, female_count);
            count = born_count;
            cout << "born_count: " << born_count << endl;
            int tmp;
            for (int i = 0; i < born_count; i++){
                tmp = rand() % 101;
                cout << "tmp: " << tmp << endl;
                if (tmp <= const_born){
                    count--;
                }

            }

        }
    
        while (count)
        {
            //Создается малышок
            string slovo = "animal_"+to_string(count_n);
            individual new_animal;
            new_animal.name= slovo;
            new_animal.age= 0;
            new_animal.genders=gender_rand();
            individuals.push_back(new_animal);
            born.push_back(new_animal.name);
            count--;
            count_n++;
            cout << "Born: " << new_animal.name << endl;
        }
        for (int i=0;i<die.size();i++)
        {
            cout<<"Die: " << die[i] <<endl;
        }
        
        //Дни рождения
        for (int i = 0; i < individuals.size(); i++){
            individuals[i].age++;
        }
        cout << endl;
        write_individuals(file_name, individuals, year);
    }

    return 0;
}