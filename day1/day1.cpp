#include <bits/stdc++.h>

int solvePartA()
{
   int amounts = 0;
   int total = 0;
   int maxi = 0;

   while (std::cin >> amounts)
   {
      total += amounts;

      if (std::cin.get() == '\n' || std::cin.eof())
      {
         if (std::cin.get() == '\n' || std::cin.eof())
         {
            maxi = std::max(maxi, total);
            total = 0;
         }
         else
         {
            std::cin.unget();
         }
      }
   }

   return maxi;
}

int solvePartB()
{
   int amounts = 0;
   int total = 0;

   std::multiset<int, std::greater<int>> st;

   while (std::cin >> amounts)
   {
      total += amounts;

      if (std::cin.get() == '\n' || std::cin.eof())
      {
         if (std::cin.get() == '\n' || std::cin.eof())
         {
            st.insert(total);
            total = 0;
         }
         else
         {
            std::cin.unget();
         }
      }
   }

   int ans = 0;
   std::multiset<int>::iterator it(st.begin());

   for (int i = 0; i < 3; i++)
   {
      ans += *it;
      std::advance(it, 1);
   }

   return ans;
}

int main()
{
   std::cout << solvePartB();
   return 0;
}
