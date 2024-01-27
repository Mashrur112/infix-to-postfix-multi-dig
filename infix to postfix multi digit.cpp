#include<bits/stdc++.h>
using namespace std;
stack<float >s1;
int prec(char c)
{
    if(c=='^')
    return 100;
    else if(c=='*' || c=='/')
    return 50;
    else if(c=='+' || c=='-')
    return 10;
    else 
    return 0;

}
void calc(string s[], int n)
{
    for(int i=0;i<=n;i++)
    {
        string sym=s[i];
        if(sym[0]>='0' && sym[0]<='9')
        {
            s1.push(stof(sym));
        }
        else
        {
            float a=s1.top();
            s1.pop();
            float b=s1.top();
            s1.pop();
            float c;
            if(sym[0]=='*')
                c=b*a;
            else if(sym[0]=='/')
                c=b/a;
            else if(sym[0]=='^')
                c=pow(b,a);
            else if(sym[0]=='+')
                c=b+a;
            else if(sym[0]=='-')
                c=b-a;
            s1.push(c);

        }
    }
    cout<<s1.top()<<endl;

}
int main()
{
   string in;
   int j=0;
   
   
   getline(cin,in);
   string post[in.size()];
   for(int i=0;i<in.size();i++)
   post[i]="";
   stack<char >s;
   for(int i=0;i<in.size();i++)
   {
        char sym=in[i];
        if(sym>='0' && sym<='9')
        {
            post[j]=post[j]+sym;
        }
        else if(sym=='(')
        {
            
            
            s.push(sym);
        }
        else if(sym==')')
        {
           //j++;
            
            while(!s.empty() && s.top()!='(')
            {
                j++;
                post[j]=s.top();
                
                s.pop();
            }
            s.pop();
        }
        else
        {
           
            while(!s.empty() && prec(sym)<=prec(s.top()))
            {
                j++;
                post[j]=s.top();
                
                s.pop();
            }
            s.push(sym);
            j++;

        }
   }
   while(!s.empty())
   {
    post[j]=s.top();
    j++;
    s.pop();
   }
  // j--;
   for(int i=0;i<=j;i++)
   cout<<post[i]<<" ";
   cout<< endl;
  //cout<<(post[7]);

   
calc(post,j);
}
//(66+8/2*(7+34)-4)