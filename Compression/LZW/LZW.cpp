#include <bits/stdc++.h>
using namespace std;

vector<int> encode(string text){
    map<string, int> table;
    
    //reserve our table with the first 255 ascii values
    for(int i = 0; i <= 255; i++){
        string ch = "";
        ch += char(i);
        table[ch] = i;
    }


    string p = "";
    string c = "";
    //set p = to the first letter of our text
    p += text[0];
    //default the starting code to 256 since 1-255 are reserved
    int code = 256;
    //this holds our output codes
    vector<int> output_code;
    cout << "String\tOutput_Code\tAddition\n";
    for(int i = 0; i < text.length(); i++){
        //if not at the last letter in text
        if(i != text.length() - 1){
            //add the next letter to c
            c += text[i+1];
        }

        //if the p + c is not at the end of our table/map
        if(table.find(p + c) != table.end()){
            //add c to p, then reset c to continue loop
            p = p + c;
        }
        else{
            //if we are at the end of our table
            cout << p << "\t" << table[p] << "\t\t"
                << p + c << "\t" << code << endl;
            //push 
            output_code.push_back(table[p]);
            //set combination = whatever code is
            table[p+c] = code;
            //increment code
            code++;
            //set p = c
            p = c;
        }
        //reset c
        c = "";
    }

    //handle last letter case
    cout << p << "\t" << table[p] << endl;
    output_code.push_back(table[p]);
    return output_code;
}

void decode(vector<int> op)
{
    cout << "\nDecoding\n";
    map<int, string> table;

    //init and reserver 1-255 ascii values
    for(int i = 0; i <= 255; i++){
        string ch = "";
        ch += char(i);
        table[i] = ch;
    }

    //setting this to the first code
    int old = op[0];
    int n;
    string s = table[old];
    string c = "";
    c += s[0];
    cout << s;
    int count = 256;
    for(int i = 0; i < op.size() - 1; i ++){
        n = op[i + 1];
        if(table.find(n) == table.end()){
            s = table[old];
            s = s + c;
        }
        else{
            s = table[n];
        }
        cout << s;
        c = "";
        c += s[0];
        table[count] = table[old] + c;
        count++;
        old = n;
    }
}

int main(){

    string s = "WYS*WYGWYS*WYSWYSG";
    vector<int> output_code = encode(s);
    cout << "Output code are: ";
    for(int i = 0; i < output_code.size(); i++){
        cout << output_code[i] << " ";
    }
    cout << endl;
    decode(output_code);
    cout << endl;
    return 0;
}