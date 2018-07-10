#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using std::cout;
using std::string;
using std::ifstream;
class genome
{
 public:
 string id;
 string seq;
}ob[10];

class stats
{ public:
 int nos;
 int noa;
 int not1;
 int nog;
 int noc;
 int non;
 float a_percent;
 float t_percent;
 float g_percent;
 float c_percent;
 float n_percent;
 int total;
}ob2;

void getid(char buffer[81],int count)
{
  ob[count].id+=buffer;

}
void getseq(char buffer[81], int count)
  {

    ob[count].seq+=buffer;

  }

int main()
{ char buffer[81]; int i=0,n=0,q=0;
   int count=0;

 char array[10000];
ifstream fin("plantgenome.txt");
while(!fin.eof())
{
    fin.getline(buffer,81);
    if( buffer[0]=='<')
     {
         getid(buffer,count);count++;
     }
    else
      getseq(buffer,count);

}
--count;
ob2.nos=count;
for(int i=0;i<count;i++)
{
    for(int j=0;j<ob[i].seq.length();j++)
    {
        if (ob[i].seq[j]=='A')
            ob2.noa++;
        if (ob[i].seq[j]=='T')
            ob2.not1++;
        if (ob[i].seq[j]=='G')
            ob2.nog++;
        if (ob[i].seq[j]=='C')
            ob2.noc++;
        if (ob[i].seq[j]=='N')
            ob2.non++;
    }
}
ob2.total=ob2.noa+ob2.not1+ob2.nog+ob2.c_percent+ob2.n_percent;
ob2.a_percent=(ob2.noa/ob2.total)*100;
ob2.t_percent=(ob2.not1/ob2.total)*100;
ob2.g_percent=(ob2.nog/ob2.total)*100;
ob2.c_percent=(ob2.noc/ob2.total)*100;
ob2.n_percent=(ob2.non/ob2.total)*100;




return 0;

}


