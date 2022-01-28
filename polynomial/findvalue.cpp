#include<iostream>
#include "numericalpolynomial.h"
#include "stack_linkedlist.h"
using namespace std;
class polynomial{
stack<string> * ptr=new(stack<string>);
string func;

public:
polynomial(string str){
    func=num_poly(str);
}
void extract(){
    string temp;
    for (int i = 0; i < func.size(); i++)
    {
         if (func[i]=='x'||func[i]=='X'||func[i]=='+'||func[i]=='-')
       {
           ptr->push(temp);
           temp.clear();
           
       }
       if(func[i]!='x'&& func[i]!='X'&& func[i]!='^' &&func[i]!='+'){       
          
           temp.push_back(func[i]);}
      
       
    }
    ptr->push(temp);
   
    
}
int power(int a,int b){
    int ans=1;
    if(b==0)
    return 1;
    for (int i = 0; i < b; i++)
    {
        ans=ans*a;
    }
    return ans;
    
}
string strip(string str){
string temp;
for (auto i = str.begin(); i < str.end(); i++)
{
    if(*i!='-'){
        temp.push_back(*i);
    }
}
return(temp);


}
int string_to_int(string str){
    int ans=0;
    bool check=false;
    if(str[0]=='-'){
        str=strip(str);
        check=true;
    }
    for (int i = 0; i < str.length(); i++)
    {
        ans=ans+((int)str[str.length()-1-i]-48)*power(10,i);
    }
    if (check)
    {
       return(0-ans);
    }
    
    return ans;
    
}

int calculate(int value){
 int ans=0;
 this->extract();
 while (true)
 {
     if(ptr->is_empty())
     break;
     int pop1=string_to_int(ptr->pop());
     ans=ans+string_to_int(ptr->pop())*power(value,pop1);}
 return(ans);
 
}

};
int main(){
    polynomial puj("5x^2+9x-7");
   
    cout<<puj.calculate(1)<<endl;


}