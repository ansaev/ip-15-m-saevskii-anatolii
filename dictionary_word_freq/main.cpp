#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <cstring>
using namespace std;

void delchar(string &, char);

class CountWorlder{
private:
    string separator = "!@#$%^&*()_{}[]:;'\|,<.>?/—-";
public:
    CountWorlder(){
    }
    bool clean_str(string &str){
        bool found = false;
        for(int i=0;i<this->separator.length();i++){
            size_t pos = str.find(separator[i]);
            if (pos != std::string::npos) {
                str = str.erase(pos, 1);
                found = true;
            }
        }
        return found;
    }
    bool countWords(string input_file_path, string output_file_path){
        ifstream input_file;
        map<string, int> dictionary;
        try {
            setlocale(LC_ALL, "eng");
            ifstream input_file(input_file_path);
            string str;
            cout <<input_file.is_open()<< endl;

            while(!(input_file.eof())){
                str = "";
                input_file >> str;
                boost::algorithm::to_lower(str);
                while(this->clean_str(str)){}
                auto iter = dictionary.find(str);
                if(iter!= dictionary.end()){
                    iter->second++;
                } else{
                    dictionary.insert(pair<string, int>(str,1));
                }
            }
        }catch(std::ifstream::failure &readErr){
            cout<<"cannot read input file:"<<input_file_path<<endl;
            return false;
        }
        try {
            ofstream fout(output_file_path);
            for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
            {
                fout << it->first << " : " << it->second << "\n";
            }
        }catch(std::ofstream::failure &writeErr){
            cout<<"cannot write output file:"<<output_file_path<<endl;
            return false;
        }
        return true;
    }

};

int main(int argc, char* argv[])
{
    CountWorlder counnter = CountWorlder();
    bool done = counnter.countWords("/home/ansaev/repos/ip-15-m-saevskii-anatolii/dictionary_word_freq/text", "/home/ansaev/repos/ip-15-m-saevskii-anatolii/dictionary_word_freq/out");
    if(done){
        cout<<"everythig is ok!";
    } else{
        cout<<"something goes wrong! We are sorry!";
    }

    return 0;
}
