#include "iostream"
#include "fstream"

int main()
{
  std::ofstream outfile("numbs");
  
  for(int i = 1; i <= 100; i++)
  	outfile << i << '\n';

  outfile.close();

  return 0;
}
