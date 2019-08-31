#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stdio.h>
#include "element_functions.hpp"

using namespace std;

namespace periodic_elements{
    
    template <class T>
    element<T>::element(){
        
        cout << "+ node\n";
        
        header = NULL;
        current = NULL;
        temp = NULL;
        
    }
    
    template <class T>
    element<T>::~element(){
        
        cout << "- node\n";
        
    }
    
    template <class T>
    void element<T>::set_symbol(T user_data, string user_symbol){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->atom == user_data){
                    
                    cout << "node " << current->atom << endl;
                    cout << "changed from " << current->symbol << " to " << user_symbol << endl;
                    current->symbol = user_symbol;
                    
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
            }
            
            if(current == NULL){
                
                cout << "list end reached.\n";
                
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
    }
    
    template <class T>
    void element<T>::set_name(T user_data, string user_name){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->atom == user_data){
                    
                    cout << "node " << current->atom << endl;
                    cout << "changed from " << current->name << " to " << user_name << endl;
                    current->name = user_name;
                    
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
                
            }
            
            if(current == NULL){
                
                cout << "list end reached.\n";
                
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
    }
    
    template <class T>
    void element<T>::set_mass(T user_data, float user_mass){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->atom == user_data){
                    
                    cout << "node " << current->atom << endl;
                    cout << "changed from " << current->mass << " to " << user_mass << endl;
                    current->mass = user_mass;
                    
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
                
            }
            
            if(current == NULL){
                
                cout << "list end reached.\n";
                
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
    }
    
    template <class T>
    void element<T>::set_matter(T user_data, string user_matter){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->atom == user_data){
                    
                    cout << "node " << current->atom << endl;
                    cout << "changed from " << current->matter << " to " << user_matter << endl;
                    current->matter = user_matter;
                    
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
                
            }
            
            if(current == NULL){
                
                cout << "list end reached.\n";
                
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
    }
    
    template <class T>
    void element<T>::set_category(T user_data, string user_category){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->atom == user_data){
                    
                    cout << "node " << current->atom << endl;
                    cout << "changed from " << current->category << " to " << user_category << endl;
                    current->category = user_category;
                    
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
                
            }
            
            if(current == NULL){
                
                cout << "list end reached.\n";
                
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
    }
    
    template <class T>
    void element<T>::set_family(T user_data, T user_family){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->atom == user_data){
                    
                    cout << "node " << current->atom << endl;
                    cout << "changed from " << current->family << " to " << user_family << endl;
                    current->family = user_family;
                    
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
                
            }
            
            if(current == NULL){
                
                cout << "list end reached.\n";
                
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
    }
    
    template <class T>
    void element<T>::add(T user_data, string user_symbol, string user_name, float user_mass, string user_matter, string user_category, T user_family){
        
        bool passed_header(false);
        node<T>* n = new node<T>;
        
        n->atom = user_data;
        n->symbol = user_symbol;
        n->name = user_name;
        n->mass = user_mass;
        n->matter = user_matter;
        n->category = user_category;
        n->family = user_family;
        
        if(header != NULL){
            
            temp = header;
            current = header;
            
            while(current->next != NULL){
                
                if(n->atom < current->atom){
                    
                    if(passed_header != true){
                        
                        header = n;
                        n->next = current;
                        break;
                        
                    }else{
                        
                        temp->next = n;
                        n->next = current;
                        break;
                        
                    }
                    
                }else{
                    
                    temp = current;
                    current = current->next;
                    passed_header = true;
                    
                }
            }
            
            if(current->next == NULL){
                
                if(n->atom < current->atom){
                    
                    if(passed_header != true){
                        
                        header = n;
                        n->next = current;
                        
                    }else{
                        
                        temp->next = n;
                        n->next = current;
                        
                    }
                    
                }else{
                    
                    current->next = n;
                    n->next = NULL;
                    
                }
            }
            
        }else{
            
            header = n;
            n->next = NULL;
            
        }
        
        cout << "node added.\n";
        
    }
    
    template <class T>
    void element<T>::delete_node(T user_data){
        
        node<T>* delete_node = new node<T>;
        
        if(header != NULL){
            
            current = header;
            temp = header;
            
            if(header->atom != user_data){
                
                while(current != NULL){
                    
                    if(current->atom == user_data){
                        
                        if(current->next == NULL){
                            
                            delete_node = current;
                            temp->next = NULL;
                            cout << "node " << current->atom << " deleted.\n";
                            delete delete_node;
                            break;
                            
                        }else{
                            
                            delete_node = current;
                            current = current->next;
                            temp->next = current;
                            cout << "node " << current->atom << " deleted.\n";
                            delete delete_node;
                            break;
                            
                        }
                        
                    }else{
                        
                        temp = current;
                        current = current->next;
                        
                    }
                }
                
            }else{
                
                delete_node = current;
                current = current->next;
                temp = current;
                header = current;
                cout << "node " << delete_node->atom << " deleted\n";
                delete delete_node;
                
            }
            
        }else{
            
            cout << "list empty.\n";
            
        }
    }
    
    template <class T>
    void element<T>::find(T user_data){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->atom == user_data){
                    
                    cout << "node found.\n";
                    cout << "----------------" << endl;
                    cout << "atom: " << current->atom << endl;
                    cout << "symbol: " << current->symbol << endl;
                    cout << "name: " <<  current->name << endl;
                    cout << "mass: " <<  current->mass << endl;
                    cout << "matter: " << current->matter << endl;
                    cout << "category: " << current->category << endl;
                    cout << "family: " << current->family << endl;
                    
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
            }
            
            if(current == NULL){
                
                cout << "list end reached. node not found.\n";
                
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
    }
    
    template <class T>
    void element<T>::display(){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                cout << "----------------" << endl;
                cout << "atom: " << current->atom << endl;
                cout << "symbol: " << current->symbol << endl;
                cout << "name: " <<  current->name << endl;
                cout << "mass: " <<  current->mass << endl;
                cout << "matter: " << current->matter << endl;
                cout << "category: " << current->category << endl;
                cout << "family: " << current->family << endl;
                cout << "----------------" << endl;
                
                if(current->next != NULL){
                    
                    cout << "LINKED TO >>>>>\n";
                    
                }
                
                current = current->next;
                
            }
            
            if(current == NULL){
                
                cout << "list end reached.\n";
                
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
    }
    
    template <class T>
    void element<T>::check_atomexists(T user_data, bool &already_exists){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->atom == user_data){
                    
                    already_exists = true;
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
            }
            
            if(current == NULL){
                
                already_exists = false;
                
            }
            
        }else{
            
            already_exists = false;
            
        }
    }
    
    template <class T>
    void element<T>::check_symbolexists(string user_symbol, bool &already_exists){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->symbol == user_symbol){
                    
                    already_exists = true;
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
            }
            
            if(current == NULL){
                
                already_exists = false;
                
            }
            
        }else{
            
            already_exists = false;
            
        }
    }
    
    template <class T>
    void element<T>::check_namexists(string user_name, bool &already_exists){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->name == user_name){
                    
                    already_exists = true;
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
            }
            
            if(current == NULL){
                
                already_exists = false;
                
            }
            
        }else{
            
            already_exists = false;
            
        }
    }
    
    template <class T>
    void element<T>::has_gas(T user_data, bool &gas_exist){
     
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->atom == user_data){
                    
                    if(current->matter == "Gas" || current->matter == "gas" || current->matter == "G" || current->matter == "g"){
                        
                        gas_exist = true;
                        cout << "gas found!\n";
                        
                        break;
                        
                    }else{
                        
                        cout << ". . ." << endl;
                        
                        break;
                        
                    }
                    
                }else{
                    
                    current = current->next;
                    
                }
            }
        }
    }
    
    template <class T>
    void element<T>::sum_group(T user_family){
        
        float total_mass(0);
        bool found_node(false);
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->family == user_family){
                    
                    total_mass += current->mass;
                    found_node = true;
                    
                    current = current->next;
                    
                }else{
                    
                    current = current->next;
                    
                }
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
        
        if(found_node != true){
            
            cout << "family not found. sum of mass not available.\n";
            
        }else{
            
            cout << "sum of mass for group " << user_family << " is: " << total_mass << endl;
            
        }
    }
}

//exam linked lists functions
namespace gas_elements{
    
    template <class T>
    gas_element<T>::gas_element(){
        
        cout << "+ node\n";
        
        header = NULL;
        current = NULL;
        temp = NULL;
        
    }
    
    template <class T>
    gas_element<T>::~gas_element(){
        
        cout << "- node\n";
        
    }
    
    template <class T>
    void gas_element<T>::set_symbol(T user_data, string user_symbol){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->atom == user_data){
                    
                    cout << "node " << current->atom << endl;
                    cout << "changed from " << current->symbol << " to " << user_symbol << endl;
                    current->symbol = user_symbol;
                    
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
            }
            
            if(current == NULL){
                
                cout << "list end reached.\n";
                
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
    }
    
    template <class T>
    void gas_element<T>::set_name(T user_data, string user_name){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->atom == user_data){
                    
                    cout << "node " << current->atom << endl;
                    cout << "changed from " << current->name << " to " << user_name << endl;
                    current->name = user_name;
                    
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
                
            }
            
            if(current == NULL){
                
                cout << "list end reached.\n";
                
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
    }
    
    template <class T>
    void gas_element<T>::set_mass(T user_data, float user_mass){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->atom == user_data){
                    
                    cout << "node " << current->atom << endl;
                    cout << "changed from " << current->mass << " to " << user_mass << endl;
                    current->mass = user_mass;
                    
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
                
            }
            
            if(current == NULL){
                
                cout << "list end reached.\n";
                
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
    }
    
    template <class T>
    void gas_element<T>::set_matter(T user_data, string user_matter){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->atom == user_data){
                    
                    cout << "node " << current->atom << endl;
                    cout << "changed from " << current->matter << " to " << user_matter << endl;
                    current->matter = user_matter;
                    
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
                
            }
            
            if(current == NULL){
                
                cout << "list end reached.\n";
                
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
    }
    
    template <class T>
    void gas_element<T>::set_category(T user_data, string user_category){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->atom == user_data){
                    
                    cout << "node " << current->atom << endl;
                    cout << "changed from " << current->category << " to " << user_category << endl;
                    current->category = user_category;
                    
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
                
            }
            
            if(current == NULL){
                
                cout << "list end reached.\n";
                
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
    }
    
    template <class T>
    void gas_element<T>::set_family(T user_data, T user_family){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                if(current->atom == user_data){
                    
                    cout << "node " << current->atom << endl;
                    cout << "changed from " << current->family << " to " << user_family << endl;
                    current->family = user_family;
                    
                    break;
                    
                }else{
                    
                    current = current->next;
                    
                }
                
            }
            
            if(current == NULL){
                
                cout << "list end reached.\n";
                
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
    }
    
    template <class T>
    void gas_element<T>::add(T user_data, string user_symbol, string user_name, float user_mass, string user_matter, string user_category, T user_family){
        
        bool passed_header(false);
        node<T>* n = new node<T>;
        
        n->atom = user_data;
        n->symbol = user_symbol;
        n->name = user_name;
        n->mass = user_mass;
        n->matter = user_matter;
        n->category = user_category;
        n->family = user_family;
        
        if(header != NULL){
            
            temp = header;
            current = header;
            
            while(current->next != NULL){
                
                if(n->atom < current->atom){
                    
                    if(passed_header != true){
                        
                        header = n;
                        n->next = current;
                        break;
                        
                    }else{
                        
                        temp->next = n;
                        n->next = current;
                        break;
                        
                    }
                    
                }else{
                    
                    temp = current;
                    current = current->next;
                    passed_header = true;
                    
                }
            }
            
            if(current->next == NULL){
                
                if(n->atom < current->atom){
                    
                    if(passed_header != true){
                        
                        header = n;
                        n->next = current;
                        
                    }else{
                        
                        temp->next = n;
                        n->next = current;
                        
                    }
                    
                }else{
                    
                    current->next = n;
                    n->next = NULL;
                    
                }
            }
            
        }else{
            
            header = n;
            n->next = NULL;
            
        }
        
        cout << "node added to gas.\n";
        
    }
    
    template <class T>
    void gas_element<T>::delete_node(T user_data){
        
        node<T>* delete_node = new node<T>;
        
        if(header != NULL){
            
            current = header;
            temp = header;
            
            if(header->atom != user_data){
                
                while(current != NULL){
                    
                    if(current->atom == user_data){
                        
                        if(current->next == NULL){
                            
                            delete_node = current;
                            temp->next = NULL;
                            cout << "node " << current->atom << " deleted.\n";
                            delete delete_node;
                            break;
                            
                        }else{
                            
                            delete_node = current;
                            current = current->next;
                            temp->next = current;
                            cout << "node " << current->atom << " deleted.\n";
                            delete delete_node;
                            break;
                            
                        }
                        
                    }else{
                        
                        temp = current;
                        current = current->next;
                        
                    }
                }
                
            }else{
                
                delete_node = current;
                current = current->next;
                temp = current;
                header = current;
                cout << "node " << delete_node->atom << " deleted\n";
                delete delete_node;
                
            }
            
        }else{
            
            cout << "list empty.\n";
            
        }
    }
    
    template <class T>
    void gas_element<T>::display(){
        
        if(header != NULL){
            
            current = header;
            
            while(current != NULL){
                
                cout << "----------------" << endl;
                cout << "atom: " << current->atom << endl;
                cout << "symbol: " << current->symbol << endl;
                cout << "name: " <<  current->name << endl;
                cout << "mass: " <<  current->mass << endl;
                cout << "matter: " << current->matter << endl;
                cout << "category: " << current->category << endl;
                cout << "family: " << current->family << endl;
                cout << "----------------" << endl;
                
                if(current->next != NULL){
                    
                    cout << "LINKED TO >>>>>\n";
                    
                }
                
                current = current->next;
                
            }
            
            if(current == NULL){
                
                cout << "list end reached.\n";
                
            }
            
        }else{
            
            cout << "list is empty.\n";
            
        }
    }
}

