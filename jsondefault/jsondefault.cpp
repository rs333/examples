#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using namespace std;

nlohmann::json out_json = nlohmann::json::parse(R"(
  {
    "val_injson": 42
  }
)");

void generateJsonFile(const string &filename, const nlohmann::json &json_data ){
    ofstream fout(filename);
    fout << json_data;
    fout.close();
}

void readJsonFile(const string &filename, nlohmann::json &json_data){
    ifstream fin(filename);
    json_data = nlohmann::json::parse(fin);
};

int main(int argc, char*argv[]){
    generateJsonFile("jsondefault.json", out_json);
    nlohmann::json in_json;
    readJsonFile("jsondefault.json", in_json);       
    // assign defaults
    float val_injson=in_json.value("val_injson",1);
    float val_default=in_json.value("val_default",1776);
    // read from json file
    assert( val_injson==42 );
    assert( val_default==1776 );
    cout << " val_injson=" << val_injson 
         << " val_default=" << val_default 
         << "\n";
    return 0;
}