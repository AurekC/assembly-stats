nclude<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;
class genome
{

 string id;
 string seq;
}ob[10];

void getid(char buffer,int count)
{
for(int q=0;buffer[q]!=' '|| buffer[q]!='/n',q++)
  strcpy(ob[count].id,buffer);

}
int getseq(char buffer, int count,  int index)
  {
  for(int m=index;buffer[m]!=' '|| buffer[m]!='/n',m++)
    strcpy(ob[count].seq,buffer);
   return m;
  }


}

int main()
{ char buffer[80]; int i=0,n=0,q=0;
   int count=0,index=0;

 char array[10000];
ifstream fin("plantgenome.txt");
while(!fin.eof())
{
    getline(buffer,80);
    if( buffer[0]=='<')
      getid(buffer,count);count++;index=0;
    else 
      { 
    index=getseq(buffer,count,index);
     
      }



}


return 0;

}


