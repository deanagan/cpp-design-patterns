

#include "EarningStatusContext.h"
#include <iostream>
#include <memory>

int main()
{
   FrequentFlyers::EarningStatusContext esc;

   FrequentFlyers::Miles miles;

   miles.Level = "Red";
   miles.TotalAccumulatedMiles = 0;

   miles = esc.UpdateMiles(miles, 20); 

   std::cout << miles.TotalAccumulatedMiles << " miles total at " << miles.Level << "status.\n";

   miles = esc.UpdateMiles(miles, 20); 

   std::cout << miles.TotalAccumulatedMiles << " miles total at " << miles.Level << "status.\n";

   miles = esc.UpdateMiles(miles, 200); 
   miles = esc.UpdateMiles(miles, 100); 

   std::cout << miles.TotalAccumulatedMiles << " miles total at " << miles.Level << "status.\n";
}