#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stdio.h>
#include "element_functions.hpp"
#include "element_functions.cpp"
#include "main_functions.hpp"

using namespace std;
using namespace periodic_elements;
using namespace gas_elements;

int main(){
    
    element<int> user_element;
    gas_element<int> exam_element;
    
    int option(0), edit_option(0), user_atom(0), user_family(0);
    float user_float(0);
    string user_symbol, user_name, user_matter, user_category;
    bool program_end(false), already_exists(false);
    
    while(program_end != true){
        
        bool add_gas(false), gas_exist(false);
        
        cout << "----------------" << endl;
        cout << "1 - add" << endl;
        cout << "2 - delete" << endl;
        cout << "3 - find" << endl;
        cout << "4 - display all" << endl;
        cout << "5 - display all gas elements" << endl;
        cout << "6 - modify element info" << endl;
        cout << "7 - display sum of group (family)" << endl;
        cout << "8 - exit" << endl;
        cout << "----------------" << endl;
        cout << "input: ";
        
        cin >> option;
        
        switch(option){
                
            case 1:
                
                input_atom(user_atom);
                user_element.check_atomexists(user_atom, already_exists);
                
                while(already_exists != false){
                    
                    cout << "invalid input. already exists. enter again.\n";
                    
                    input_atom(user_atom);
                    user_element.check_atomexists(user_atom, already_exists);
                    
                }
                
                already_exists = false;
                
                input_symbol(user_atom, user_symbol);
                user_element.check_symbolexists(user_symbol, already_exists);
                
                while(already_exists != false){
                    
                    cout << "invalid input. already exists. enter again.\n";
                    
                    input_symbol(user_atom, user_symbol);
                    user_element.check_symbolexists(user_symbol, already_exists);
                    
                }
                
                already_exists = false;
                
                input_name(user_atom, user_name);
                user_element.check_namexists(user_name, already_exists);
                
                while(already_exists != false){
                    
                    cout << "invalid input. already exists. enter again.\n";
                    
                    input_name(user_atom, user_name);
                    user_element.check_namexists(user_name, already_exists);
                    
                }
                
                input_mass(user_float);
                
                input_matter(user_atom, user_matter);
                
                if(user_matter == "Gas" || user_matter == "gas" || user_matter == "G" || user_matter == "g"){
                    
                    add_gas = true;
                    
                }
                
                input_category(user_atom, user_category);
                
                input_family(user_family);
                
                user_element.add(user_atom, user_symbol, user_name, user_float, user_matter, user_category, user_family);
                
                if(add_gas == true){
                    
                    exam_element.add(user_atom, user_symbol, user_name, user_float, user_matter, user_category, user_family);
                    
                }
                
                break;
                
            case 2:
                
                cout << "enter atom number: ";
                cin >> user_atom;
                
                user_element.has_gas(user_atom, gas_exist);
                
                user_element.delete_node(user_atom);
                
                if(gas_exist == true){
                    
                    exam_element.delete_node(user_atom);
                    
                }
                
                break;
                
            case 3:
                
                cout << "enter atom number: ";
                cin >> user_atom;
                
                user_element.find(user_atom);
                
                break;
                
            case 4:
                
                cout << "displaying all nodes in list.\n";
                
                user_element.display();
                
                break;
                
            case 5:
                
                cout << "dislaying all gas elements.\n";
                
                exam_element.display();
                
                break;
                
            case 6:
                
                cout << "enter atom numer: ";
                cin >> user_atom;
                user_element.has_gas(user_atom, gas_exist);
                cout << "which info to edit?" << endl;
                cout << "----------------" << endl;
                cout << "1 - symbol" << endl;
                cout << "2 - name" << endl;
                cout << "3 - mass" << endl;
                cout << "4 - state of matter" << endl;
                cout << "5 - category" << endl;
                cout << "6 - family" << endl;
                cout << "----------------" << endl;
                cout << "input: ";
                cin >> edit_option;
                
                switch (edit_option){
                        
                    case 1:
                        
                        already_exists = false;
                        
                        input_symbol(user_atom, user_symbol);
                        
                        user_element.set_symbol(user_atom, user_symbol);
                        
                        if(gas_exist == true){
                            
                            exam_element.set_symbol(user_atom, user_symbol);
                            
                        }
                        
                        break;
                        
                    case 2:
                        
                        already_exists = false;
                        
                        input_name(user_atom, user_name);
                        
                        user_element.set_name(user_atom, user_name);
                        
                        if(gas_exist == true){
                            
                            exam_element.set_name(user_atom, user_name);
                            
                        }
                        
                        break;
                        
                    case 3:
                        
                        input_mass(user_float);
                        
                        user_element.set_mass(user_atom, user_float);
                        
                        if(gas_exist == true){
                            
                            exam_element.set_mass(user_atom, user_float);
                            
                        }

                        break;
                        
                    case 4:
                        
                        input_matter(user_atom, user_matter);
                        
                        user_element.set_matter(user_atom, user_matter);
                        
                        if(gas_exist == true){
                            
                            exam_element.set_matter(user_atom, user_matter);
                            
                        }

                        break;
                        
                    case 5:
                        
                        input_category(user_atom, user_category);
                        
                        user_element.set_category(user_atom, user_category);
                        
                        if(gas_exist == true){
                            
                            exam_element.set_category(user_atom, user_category);
                            
                        }

                        break;
                        
                    case 6:
                        
                        input_family(user_family);
                        
                        user_element.set_family(user_atom, user_family);
                        
                        if(gas_exist == true){
                            
                            exam_element.set_family(user_atom, user_family);
                            
                        }

                        break;
                        
                    default:
                        
                        cout << "invalid input.\n";
                        
                        break;
                }
                
                break;
                
            case 7:
                
                input_family(user_family);
                
                user_element.sum_group(user_family);
                
                break;
                
            case 8:
                
                cout << "exiting program.\n";
                program_end = true;
                
            default:
                
                cout << "invalid input.\n";
                
                break;
        }
    }
    
    return 0;
    
}
