#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>

using std::cout;
using std::string;
using std::ifstream;
using std::vector;

class genome
{
public:
  genome(void) : _id(""), _seq("") {}
  genome(std::string& i, std::string& s) : _id(i), _seq(s) {}
  std::string& id(void) {return _id;}
  std::string& seq(void) {return _seq;}
private:
  string _id;
  string _seq;
};

class stats
{
public:
  string to_string() {
    std::stringstream ss;
    ss << "N Sequences\t" << nos << '\n'
       << "A\t" << noa << '\n' << "T\t" << not1 << '\n' << "G\t" << nog << '\n' << " C\t" << noc 
<<'\n' << "N\t" << non <<'\n'<< "N contigs\t" << nocon << '\n' << "total\t" << total << '\n';
    return ss.str();
  }
  uint64_t nos = 0;
  uint64_t noa = 0;
  uint64_t not1 = 0;
  uint64_t nog = 0;
  uint64_t noc = 0;
  uint64_t non = 0;
  uint64_t nocon = 0;
  double a_percent = 0.0;
  double t_percent = 0.0;
  double g_percent = 0.0;
  double c_percent = 0.0;
  double n_percent = 0.0;
  uint64_t total = 0;
};

int main(const int argc, const char ** argv)
{
  ifstream fin("plantgenome.txt");

  vector<genome> genome_vec;

  stats ob2;
  
  string line;
  string current_id = "";
  string current_seq = "";
  while(std::getline(fin, line))
    {
      // Get ID and sequence for the current record
      if (line.front() == '>')
        {
          current_id = line;
          current_seq = "";
        }
      else
        {
          current_seq += line;
        }
      // We check of the next line starts a new record
      if (fin.peek() == EOF || fin.peek() == '>')
        {
          genome curr_g(current_id, current_seq);
          genome_vec.push_back(curr_g);
        }
    }

  for (genome& record : genome_vec)
    {
      for (char& nuc : record.seq())
        {
          if (nuc == 'A')
            ob2.noa++;
          if (nuc == 'T')
            ob2.not1++;
          if (nuc == 'G')
            ob2.nog++;
          if (nuc == 'C')
            ob2.noc++;
          if (nuc == 'N')
            ob2.non++;
        }
    }

ob2.total = ob2.noa + ob2.not1 + ob2.nog + ob2.noc + ob2.non;
ob2.a_percent = (ob2.noa / ob2.total) * 100;
ob2.t_percent = (ob2.not1 / ob2.total) * 100;
ob2.g_percent = (ob2.nog / ob2.total) * 100;
ob2.c_percent = (ob2.noc / ob2.total) * 100;
ob2.n_percent = (ob2.non / ob2.total) * 100;

int q=0,x=0;int flag=0;
for (genome& record: genome_vec) 
  {
 for (char& nuc : record.seq())
      {  
       if (nuc=='N')
           q++;
      } 
      if(q>=25)
       { 
         x++;q=0;flag=1;
       }
      if(flag ==1)
      ob2.nocon=x+1;
      else 
       ob2.nocon=0;
}


cout<<ob2.to_string(); 



return 0;
}


