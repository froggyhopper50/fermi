#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <cmath>


using namespace std;

int main() 
{

  // Generate Random Numbers
  
  srand(time(NULL)); 

  // Declared Variables

  double random_integerX;
  double random_integerY;
  double radius;
  double count = 0;
  unsigned long int i;

  // For Loop

  for(i = 0; i< 100000 ; i++){

    //Selects Random Numbers for X and Y
    
    random_integerX = (rand()%1000)/(1000.0);
    random_integerY = (rand()%1000)/(1000.0);

    //Computes Radius of Circle

    radius = sqrt(pow(random_integerX,2.0) + pow(random_integerY,2.0));

    // Counts the times in which computer selects a place within the circle

    if (radius <= 1.0)
      count += 1.0;
  }
  
  cout << "Count = " << count << " i = " << i << endl;

  // Approximates Pi
  double one_fourth_pi = (double) count / i;
  double approx_pi = one_fourth_pi * 4.0;

  cout << "Approximation of Pi = " << approx_pi << endl;
}
