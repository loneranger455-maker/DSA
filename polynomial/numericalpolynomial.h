#include<iostream>
using namespace std;
string num_poly(string func){
    string temp;
    bool checker=true;
    
    if(func[0]=='-'||func[0]!='+'){
            temp.push_back('+');
        }
    for (int i=0;i<func.size();i++){
       temp.push_back(func[i]);
       if (func[i]=='+'||func[i]=='-')
           checker=false;       
       if ((func[i]=='x'||func[i]=='X'))
       {
           checker=true;
           if(func[i+1]!='^'){
           temp.push_back('^');
           temp.push_back('1');}
       }}
    if (checker==false)
    {
        temp.push_back('x');
        temp.push_back('^');
        temp.push_back('0');
    }
    
    return(temp);
}
