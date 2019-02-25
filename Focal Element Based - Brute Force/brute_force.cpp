#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
  vector<int> t, a, a_bar, mass, bel, a_barstrad;
  vector<double> cond;
  int a_ptr = 0, a_bar_ptr = 0, nlz = 0, rounds = 0;
  bool ck = true;
  clock_t cond_begin, cond_end;
  double total_time = 0;
  for (int fod = 2; fod <= 14; fod = fod + 2)
  {
    rounds = 0;
    total_time = 0;
    t.clear();
    mass.clear();
    nlz = 0;
    for (int i = 1; i <= fod; i++)
    {
      t.push_back(i);
      mass.push_back(pow(2,i - 1));
      nlz += pow(2, i - 1);
    }
    for (int i = 1; i <= fod; i++)
    {
      for (int r = 0; r < 10000; r++)
      {
        rounds++;
        a.clear();
        a_bar.clear();
        bel.clear();
        a_barstrad.clear();
        cond.clear();
        bel.push_back(0);
        a_barstrad.push_back(0);
        cond.push_back(0);


        for (int j = 1; j <= i; j++)
        {
          a.push_back(j);
          bel.push_back(0);
          a_barstrad.push_back(0);
          cond.push_back(0);
        }
        for (int j = i + 1; j <= fod; j++)
          a_bar.push_back(j);
        // for (int j = 0; j < t.size(); j++)
          // cout << t[j] << " ";
        // cout << endl;
        // for (int j = 0; j < mass.size(); j++)
          // cout << mass[j] << " ";
        // cout << endl;
        // for (int j = 0; j < a.size(); j++)
          // cout << a[j] << " ";
        // cout << endl;
        // for (int j = 0; j < a_bar.size(); j++)
          // cout << a_bar[j] << " ";
        // cout << endl;
        // reading vals from array
        cond_begin = clock();
        for (int l = 0; l < pow(2, a.size()); l++)
        {
          a_ptr = 0;
          int ran;
          for (int k = 0; k < fod; k++)
          {
            if (a_ptr < a.size() && a[a_ptr] == t[k])
              a_ptr++;
            ran += mass[k];
          }
        }
        cond_end = clock();
         // for (int j = 0; j < cond.size(); j++)
           // cout << cond[j] << " ";
         // cout << endl << endl;
        total_time += (double)(cond_end - cond_begin);
      }

    }
    // cout << "FH conditional beliefs, rounds :" << rounds << " average time (microsecs) :  " << total_time / rounds << endl << endl;
    cout << "Brute force, FoD : " << fod << " average time (microsecs) :  " << total_time / rounds << endl << endl;
  }
  return 0;
}
