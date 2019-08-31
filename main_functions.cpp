#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stdio.h>
#include "main_functions.hpp"

using namespace std;

void input_atom(int &user_atom){
    
    string string_atom;
    
    cout << "enter atom number: ";
    cin >> string_atom;
    
    user_atom = validate_atomnumber(string_atom);
    
}

void input_symbol(int user_atom, string &user_symbol){
    
    bool data_valid(false);
    
    cout << "enter symbol: ";
    cin >> user_symbol;
    
    verify_symbol(user_atom, user_symbol, data_valid);
    
    while(data_valid != true){
        
        cout << "invalid input. enter again.\n";
        cin >> user_symbol;
        
        verify_symbol(user_atom, user_symbol, data_valid);
        
    }
}

void input_name(int user_atom, string &user_name){
    
    bool data_valid(false);
    
    cout << "enter name: ";
    cin >> user_name;
    
    verify_name(user_atom, user_name, data_valid);
    
    while(data_valid != true){
        
        cout << "invalid input. enter again.\n";
        cin >> user_name;
        
        verify_name(user_atom, user_name, data_valid);
        
    }
}

void input_mass(float &user_mass){
    
    string string_mass;
    
    cout << "enter mass: ";
    cin >> string_mass;
    
    user_mass = validate_float(string_mass);
    
}

void input_matter(int user_atom, string &user_matter){
    
    bool data_valid(false);
    
    cout << "enter state of matter\n";
    cout << "(solid, liquid, gas, or unknown)\n";
    cin >> user_matter;
    
    verify_matter(user_atom, user_matter, data_valid);
    
    while(data_valid != true){
        
        cout << "invalid input. enter again.\n";
        cout << "(solid, liquid, gas, or unknown)\n";
        cin >> user_matter;
        
        verify_matter(user_atom, user_matter, data_valid);
        
    }
}

void input_category(int user_atom, string &user_category){
    
    bool data_valid(false);
    
    cout << "enter category\n";
    cout << "(alkali metal, alkali earth metal, lanthanoid, actinoid, transition metal" << endl;
    cout << "post transition metal, metalloid, other non metal, noble gas, unknown)" << endl;
    cin.ignore();
    getline(cin, user_category);
    
    verify_category(user_atom, user_category, data_valid);
    
    while(data_valid != true){
        
        cout << "invalid input. enter again.\n";
        cout << "(alkali metal, alkali earth metal, lanthanoid, actinoid, transition metal" << endl;
        cout << "post transition metal, metalloid, other non metal, noble gas, unknown)" << endl;
        cin.clear();
        getline(cin, user_category);
        
        verify_category(user_atom, user_category, data_valid);
        
    }
}

void input_family(int &user_family){
    
    string string_family;
    
    cout << "enter family: ";
    cin >> string_family;
    
    user_family = validate_family(string_family);
    
}

void validate_string(string &user_input){
    
    bool valid_input(true);
    
    for(unsigned int a(0); a<user_input.length(); a++){
        
        if(isalpha(user_input[a])||user_input[a] == ' '){
            
            continue;
            
        }else{
            
            valid_input = false;
            
        }
    }
    
    while(valid_input != true){
        
        cout << "invalid input. enter again.\n";
        cin >> user_input;
        
        valid_input = true;
        
        for(unsigned int a(0); a<user_input.length(); a++){
            
            if(isalpha(user_input[a])){
                
                continue;
                
            }else{
                
                valid_input = false;
                
            }
        }
    }
}

int validate_int(string &user_input){
    
    char value_convert[10];
    bool valid_input(true);
    int counter(0);
    
    for(unsigned int a(0); a<user_input.length(); a++){
        
        if(isdigit(user_input[a])){
            
            continue;
            
        }else{
            
            valid_input = false;
            
        }
    }
    
    while(valid_input != true){
        
        cout << "invalid input. enter again.\n";
        cin >> user_input;
        
        valid_input = true;
        
        for(unsigned int a(0); a<user_input.length(); a++){
            
            if(isdigit(user_input[a])){
                
                continue;
                
            }else{
                
                valid_input = false;
                
            }
        }
    }
    
    for(unsigned int b(0); b<user_input.length(); b++){
        
        value_convert[b] = user_input[b];
        counter = b;
        
    }
    
    value_convert[counter+1] = '\0';
    
    return atoi(value_convert);
    
}

float validate_float(string &user_input){
    
    int counter(0);
    bool valid_input(true);
    float final_value;
    char value_convert[10];
    
    for(unsigned int a(0); a<user_input.length(); a++){
        
        if(isdigit(user_input[a])||user_input[a] == '.'){
            
            continue;
            
        }else{
            
            valid_input = false;
            
        }
    }
    
    while(valid_input != true){
        
        cout << "invalid input. enter again.\n";
        cin >> user_input;
        
        valid_input = true;
        
        for(unsigned int a(0); a<user_input.length(); a++){
            
            if(isdigit(user_input[a])||user_input[a] == '.'){
                
                continue;
                
            }else{
                
                valid_input = false;
                
            }
        }
    }
    
    for(unsigned int b(0); b<user_input.length(); b++){
        
        value_convert[b] = user_input[b];
        counter = b;
    }
    
    value_convert[counter+1] = '\0';
    
    final_value = atof(value_convert);
    
    return final_value;
    
}

int validate_atomnumber(string &user_data){
    
    int valid_data = validate_int(user_data);
    bool already_exists(false);
    
    while(valid_data > 118 || valid_data <= 0 || already_exists != false){
        
        if(already_exists == true){
            
            cout << "invalid input. already exists. enter again.\n";
            
        }else{
            
            cout << "invalid input. enter again.\n";
            
        }
        
        cin >> user_data;
        
        already_exists = false;
        
        valid_data  = validate_int(user_data);
        
    }
    
    return valid_data;
    
}

int validate_family(string user_data){
    
    int valid_family = validate_int(user_data);
    
    while(valid_family > 18 || valid_family < 0){
        
        cout << "invalid input. enter again.\n";
        cin >> user_data;
        
        valid_family = validate_int(user_data);
        
    }
    
    return valid_family;
    
}

void verify_symbol(int user_data, string &user_symbol, bool &data_valid){
    
    string symbol_list[118] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg",
        "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr",
        "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br",
        "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd",
        "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La",
        "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er",
        "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pr", "Au",
        "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
        "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
        "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn",
        "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
    
    validate_string(user_symbol);
    
    if(user_symbol == symbol_list[user_data-1]){
        
        data_valid = true;
        
    }else{
        
        data_valid = false;
        
    }
}

void verify_name(int user_data, string &user_name, bool &data_valid){
    
    string name_list[118] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen",
        "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur",
        "Chlorine", "Argon", "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium",
        "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium", "Germanium", "Arsenic",
        "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium",
        "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium",
        "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium",
        "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium",
        "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium", "Tantalum",
        "Tungsten", "Rhenium" "Osmium", "Iridium", "Platinum", "Gold", "Mercury", "Thallium", "Lead",
        "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium", "Protactinium",
        "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium",
        "Fermium", "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium",
        "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium",
        "Moscovium", "Livermorium", "Tennessine", "Oganesson"};
    
    validate_string(user_name);
    
    if(user_name == name_list[user_data-1]){
        
        data_valid = true;
        
    }else{
        
        data_valid = false;
        
    }
}

void verify_matter(int user_data, string user_matter, bool &data_valid){
    
    validate_string(user_matter);
    
    for(unsigned int a(0); a<user_matter.length(); a++){
        
        tolower(user_matter[a]);
        
    }
    
    if(user_matter == "Liquid" || user_matter == "liquid" || user_matter == "L" || user_matter == "l"){
        
        if(user_data == 35 || user_data == 80){
            
            data_valid = true;
            
        }else{
            
            data_valid = false;
            
        }
        
    }else if(user_matter == "Gas" || user_matter == "gas" || user_matter == "G" || user_matter == "g"){
        
        if((user_data == 1)||(user_data == 2)||(user_data == 7)||(user_data == 8)||(user_data == 9)||
           (user_data == 10)||(user_data == 17)||(user_data == 18)||(user_data == 36)||(user_data == 54)||(user_data == 86)){
            
            data_valid = true;
            
        }else{
            
            data_valid = false;
            
        }
        
    }else if(user_matter == "Unknown" || user_matter == "unknown" || user_matter == "U" || user_matter == "u"){
        
        if((user_data == 104)||(user_data == 105)||(user_data == 106)||(user_data == 107)||(user_data == 108)){
            
            data_valid = true;
            
        }else{
            
            data_valid = false;
            
        }
        
        
    }else if(user_matter == "Solid" || user_matter == "solid" || user_matter == "S" || user_matter == "s"){
        
        if((user_data == 35)||(user_data == 80)||(user_data == 1)||(user_data == 2)||(user_data == 7)||(user_data == 8)||(user_data == 9)||(user_data == 10)||(user_data == 17)||(user_data == 18)||(user_data == 36)||(user_data == 54)||(user_data == 86)||(user_data == 104)||(user_data == 105)||(user_data == 106)||(user_data == 107)||(user_data == 108)){
            
            data_valid = false;
            
        }else{
            
            data_valid = true;
            
        }
    }
}

void verify_category(int user_data, string user_category, bool &data_valid){
    
    int temp_ans(0);
    int case1[6] = {3, 11, 19, 37, 55, 87};
    int case2[6] = {4, 12, 20, 38, 56, 88};
    int case3[15] = {57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71};
    int case4[15] = {89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103};
    int case5[18] = {21, 22, 39, 40, 72, 104, 23, 41, 73, 105, 24, 42, 74, 106, 25, 43, 75, 107};
    int case6[9] = {13, 31, 49, 50, 81, 82, 83, 84, 114};
    int case7[7] = {5, 14, 32, 33, 51, 52, 85};
    int case8[9] = {1, 6, 7, 15, 16, 17, 34, 35, 53};
    int case9[6] = {2, 10, 18, 36, 54, 86};
    int case10[8] = {109, 110, 111, 113, 115, 116, 117, 118};
    bool found_number(false);
    
    validate_string(user_category);
        
    if(user_category == "alkali metal"){
        
        temp_ans = 1;
        
    }else if(user_category == "alkali earth metal"){
        
        temp_ans = 2;
        
    }else if(user_category == "lanthanoid"){
        
        temp_ans = 3;
        
    }else if(user_category == "actinoid"){
        
        temp_ans = 4;
        
    }else if(user_category == "transition metal"){
        
        temp_ans = 5;
        
    }else if(user_category == "post transition metal"){
        
        temp_ans = 6;
        
    }else if(user_category == "metalloid"){
        
        temp_ans = 7;
        
    }else if(user_category == "other non metal"){
        
        temp_ans = 8;
        
    }else if(user_category == "noble gas"){
        
        temp_ans = 9;
        
    }else if(user_category == "unknown"){
        
        temp_ans = 10;
    }
    
    switch(temp_ans){
            
        case 1:
            
            found_number = false;
            
            for(unsigned int a(0); a<6; a++){
                
                if(user_data == case1[a]){
                    
                    found_number = true;
                    data_valid = true;
                    
                }else{
                    
                    continue;
                    
                }
            }
            
            if(found_number != true){
                
                data_valid = false;
                
            }
            
            break;
            
        case 2:
            
            found_number = false;
            
            for(unsigned int a(0); a<6; a++){
                
                if(user_data == case2[a]){
                    
                    found_number = true;
                    data_valid = true;
                    
                }else{
                    
                    continue;
                    
                }
            }
            
            if(found_number != true){
                
                data_valid = false;
                
            }
            
            break;
            
        case 3:
            
            found_number = false;
            
            for(unsigned int a(0); a<15; a++){
                
                if(user_data == case3[a]){
                    
                    found_number = true;
                    data_valid = true;
                    
                }else{
                    
                    continue;
                    
                }
            }
            
            if(found_number != true){
                
                data_valid = false;
                
            }
            
            break;
            
        case 4:
            
            found_number = false;
            
            for(unsigned int a(0); a<15; a++){
                
                if(user_data == case4[a]){
                    
                    found_number = true;
                    data_valid = true;
                    
                }else{
                    
                    continue;
                    
                }
            }
            
            if(found_number != true){
                
                data_valid = false;
                
            }
            
            break;
            
        case 5:
            
            found_number = false;
            
            for(unsigned int a(0); a<18; a++){
                
                if(user_data == case5[a]){
                    
                    found_number = true;
                    data_valid = true;
                    
                }else{
                    
                    continue;
                    
                }
            }
            
            if(found_number != true){
                
                data_valid = false;
                
            }
            
            break;
            
        case 6:
            
            found_number = false;
            
            for(unsigned int a(0); a<9; a++){
                
                if(user_data == case6[a]){
                    
                    found_number = true;
                    data_valid = true;
                    
                }else{
                    
                    continue;
                    
                }
            }
            
            if(found_number != true){
                
                data_valid = false;
                
            }
            
            break;
            
        case 7:
            
            found_number = false;
            
            for(unsigned int a(0); a<7; a++){
                
                if(user_data == case7[a]){
                    
                    found_number = true;
                    data_valid = true;
                    
                }else{
                    
                    continue;
                    
                }
            }
            
            if(found_number != true){
                
                data_valid = false;
                
            }
            
            break;
            
        case 8:
            
            found_number = false;
            
            for(unsigned int a(0); a<9; a++){
                
                if(user_data == case8[a]){
                    
                    found_number = true;
                    data_valid = true;
                    
                }else{
                    
                    continue;
                    
                }
            }
            
            if(found_number != true){
                
                data_valid = false;
                
            }
            
            break;
            
        case 9:
            
            found_number = false;
            
            for(unsigned int a(0); a<6; a++){
                
                if(user_data == case9[a]){
                    
                    found_number = true;
                    data_valid = true;
                    
                }else{
                    
                    continue;
                    
                }
            }
            
            if(found_number != true){
                
                data_valid = false;
                
            }
            
            break;
            
        case 10:
            
            found_number = false;
            
            for(unsigned int a(0); a<8; a++){
                
                if(user_data == case10[a]){
                    
                    found_number = true;
                    data_valid = true;
                    
                }else{
                    
                    continue;
                    
                }
            }
            
            if(found_number != true){
                
                data_valid = false;
                
            }
            
            break;
            
        default:
            
            data_valid = false;
            break;
            
    }
}
