#ifndef element_functions_hpp
#define element_functions_hpp

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

namespace periodic_elements{
    
    template<class T>
    struct node{
        
        T atom;
        string symbol;
        string name;
        float mass;
        string matter;
        string category;
        T family;
        node* next;
        
        
    };
    
    template<class T>
    class element{
        
    public:
        
        element();
        ~element();
        
        void set_symbol(T user_data, string user_symbol);
        void set_name(T user_data, string user_name);
        void set_mass(T user_data, float user_mass);
        void set_matter(T user_data, string user_matter);
        void set_category(T user_data, string user_category);
        void set_family(T user_data, T user_family);
        void add(T user_data, string user_symbol, string user_name, float user_mass, string user_matter, string user_category, T user_family);
        void delete_node(T user_data);
        void find(T user_data);
        void display();
        void check_atomexists(T user_data, bool &already_exists);
        void check_symbolexists(string user_symbol, bool &already_exists);
        void check_namexists(string user_name, bool &already_exists);
        void has_gas(T user_data, bool &gas_exist);
        void sum_group(T user_family);

        
    private:
        
        node<T>* current;
        node<T>* temp;
        node<T>* header;
        
    };
}

//exam linked lists
namespace gas_elements{
    
    template<class T>
    struct node{
        
        T atom;
        string symbol;
        string name;
        float mass;
        string matter;
        string category;
        T family;
        node* next;
        
        
    };
    
    template<class T>
    class gas_element{
        
    public:
        
        gas_element();
        ~gas_element();
        
        void set_symbol(T user_data, string user_symbol);
        void set_name(T user_data, string user_name);
        void set_mass(T user_data, float user_mass);
        void set_matter(T user_data, string user_matter);
        void set_category(T user_data, string user_category);
        void set_family(T user_data, T user_family);
        void add(T user_data, string user_symbol, string user_name, float user_mass, string user_matter, string user_category, T user_family);
        void delete_node(T user_data);
        void display();
        
    private:
        
        node<T>* current;
        node<T>* temp;
        node<T>* header;
        
    };
}

#endif
