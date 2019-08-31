#ifndef main_functions_hpp
#define main_functions_hpp

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

void input_atom(int &user_atom);
void input_symbol(int user_atom, string &user_symbol);
void input_name(int user_atom, string &user_name);
void input_mass(float &user_mass);
void input_matter(int user_atom, string &user_matter);
void input_category(int user_atom, string &user_category);
void input_family(int &user_family);
void validate_string(string &user_input);
int validate_int(string &user_input);
float validate_float(string &user_input);
int validate_atomnumber(string &user_data);
int validate_family(string user_data);
void verify_symbol(int user_data, string &user_symbol, bool &data_valid);
void verify_name(int user_data, string &user_name, bool &data_valid);
void verify_matter(int user_data, string user_matter, bool &data_valid);
void verify_category(int user_data, string user_category, bool &data_valid);
#endif

