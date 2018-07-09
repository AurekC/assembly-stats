#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;
class genome
{

 string id;
 string seq;
};


int main()
{ char buffer; int i=0,n=0,q=0;

genome ob[10];
 char array[10000];
ifstream fin("plantgenome.txt");
while(!fin.eof())
{
    fin<<buffer;
   a[i]=buffer;i++;
     
}
int l=strlen(array);

for(i=0;i<l;i++)
{
   if( isdigit(a[i]) && a[i-1]=='<' )
    {  int m=0,j=i;
        char temp[10];
       while(a[j]!=' ' | a[j]!='/n'|a[j]!='\t')
        {  
           temp[m]=a[j];
            m++;
        }

       strcpy(genome ob[q].id,temp);q++;
    }

   if( isaplha(a[i]) && a[i-1]=='/n')
     {   
            
       int m1=0,j1=i;
        char temp1[1000];
       while(a[j1]!=' ' | a[j1]!='/n'|a[j1]!='\t')
        {  
           temp[m1]=a[j1];
            m1++;
        }

       strcpy(genome ob[n].seq,temp1);n++;
     }

}

return 0;

}


