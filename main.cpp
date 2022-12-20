#include "lib.hpp"
void clear_f(const string file_name)
    {
        ofstream file(file_name);
        file<<"";
    }
int main(int argc, char* argv[]){
    //Вводимые переменные с клавиатуры
    srand(time(NULL));
    int number_of_food = atoi(argv[1]);
    int inventory_renewal = atoi(argv[2]);
    int number_of_years = atoi(argv[3]);
    const string file_name(argv[4]);
    clear_f(file_name);
    Life_cycle( number_of_years,number_of_food,inventory_renewal,file_name );
}