// Application main program for rantioal number class with overloaded operators. 
#include <iostream>
//#include <iomanip>
#include <cstdlib> 
#include <cmath>
#include "rational_overloading.h"

using namespace std;

// Maximum function of rational numbers.
Rational max(const Rational x, const Rational y) {
  if (x >= y) return x;
  else return y;
}

// Minimum function of rational numbers.
Rational min(const Rational x, const Rational y) {
  if (x >= y) return y;
  else return x;
}

int main() {
  Rational a, b, c; // Declare three rational variables.
  int d, e, f; // Declare three integer variables.
  
  cout << "Enter rational number a (in the form of: p/q): ";
  cin >> a;
  cout << "**** Value of a: " << a << endl;  
  cout << "Enter rational number b (in the form of: p/q): ";
  cin >> b;
  cout << "**** Value of b: " << b << endl;  
  cout << "Enter rational number c (in the form of: p/q): ";
  cin >> c;
  cout << "**** Value of c: " << c << endl;  
  cout << "Enter integer number d: ";
  cin >> d;
  cout << "**** Value of d: " << d << endl;
  cout << "Enter integer numbere: ";
  cin >> e;
  cout << "**** Value of e: " << e << endl;
  cout << "Enter integer number f: ";
  cin >> f;
  cout << "**** Value of f: " << f << endl;
  cout << "=====================================" << endl;
  
  cout << "**** Expression -a = " << -a << endl;  
  cout << "**** Expression a+b = " << a+b << endl;  
  cout << "**** Expression |a+b| = " << (a+b).rabs() << endl;  
  cout << "**** Expression a+d = " << a+d << endl;
  cout << "**** Expression d+a = " << d+a << endl;  
  cout << "**** Expression a-b = " << a-b << endl;  
  cout << "**** Expression |a-b| = " << (a-b).rabs() << endl;
  cout << "**** Expression a-d = " << a-d << endl;
  cout << "**** Expression d-a = " << d-a << endl;
  cout << "**** Expression a*b = " << a*b << endl;  
  cout << "**** Expression |a*b| = " << (a*b).rabs() << endl;
  cout << "**** Expression a*d = " << a*d << endl;
  cout << "**** Expression d*a = " << d*a << endl;
  cout << "**** Expression a/b = " << a/b << endl;  
  cout << "**** Expression |a/b| = " << (a/b).rabs() << endl;
  cout << "**** Expression a/d = " << a/d << endl;
  cout << "**** Expression d/a = " << d/a << endl;
  cout << "=====================================" << endl;
  
  bool flag;
  flag = a==b;
  cout << "**** Relation a==b is " << boolalpha << flag << "." << endl;
  flag = a==e;
  cout << "**** Relation a==e is " << boolalpha << flag << "." << endl;
  flag = f==c;
  cout << "**** Relation f==c is " << boolalpha << flag << "." << endl;
  flag = a!=b;
  cout << "**** Relation a!=b is " << boolalpha << flag << "." << endl;
  flag = a!=e;
  cout << "**** Relation a!=e is " << boolalpha << flag << "." << endl;
  flag = f!=c;
  cout << "**** Relation f!=c is " << boolalpha << flag << "." << endl;
  flag = a<b;
  cout << "**** Relation a<b  is " << boolalpha << flag << "." << endl;
  flag = a<e;
  cout << "**** Relation a<e  is " << boolalpha << flag << "." << endl;
  flag = f<c;
  cout << "**** Relation f<c is " << boolalpha << flag << "." << endl;
  flag = a<=b;
  cout << "**** Relation a<=b is " << boolalpha << flag << "." << endl;
  flag = a<=e;
  cout << "**** Relation a<=e is " << boolalpha << flag << "." << endl; 
  flag = f<=c;
  cout << "**** Relation f<=c is " << boolalpha << flag << "." << endl;
  flag = a>b;
  cout << "**** Relation a>b  is " << boolalpha << flag << "." << endl;
  flag = a>e;
  cout << "**** Relation a>e  is " << boolalpha << flag << "." << endl;
  flag = f>c;
  cout << "**** Relation f>c is " << boolalpha << flag << "." << endl;
  flag = a>=b;
  cout << "**** Relation a>=b is " << boolalpha << flag << "." << endl;
  flag = a>=e;
  cout << "**** Relation a>=e is " << boolalpha << flag << "." << endl;
  flag = f>=c;
  cout << "**** Relation f>=c is " << boolalpha << flag << "." << endl;
  cout << "=====================================" << endl;
  
  cout << "**** Expression a*c/d+e*b-d/b-a = " << a*c/d+e*b-d/b-a << endl;
  cout << "**** Expression a*c/(d+e*b)-d/(b-a) = " << a*c/(d+e*b)-d/(b-a) << endl;
  cout << "**** Expression a*((c/(d+e)*b)-d/b)-a = " << a*((c/(d+e)*b)-d/b)-a << endl;
  cout << "=====================================" << endl;
  
  Rational g;
  
  cout << "Statement: if (a>=b) then g=(d+e)*f else g=(d-e)/f;" << endl;
  if (a>=b) g = g=(d+e)*f; else g = g=(d-e)*f;
  cout << "**** The new value of object g: " << g << endl;
  cout << "=====================================" << endl;
  
  cout << "Statement: if (c*d==b*e) then g*=b/d+c/e else g/=b*d+c*e;" << endl;
  if (c*d==b*e) g *= b/d+c/e;
  else g /= b*d+c*e;
  cout << "**** The new value of object g: " << g << endl;
  cout << "=====================================" << endl;
  
  cout << "**** Expression max(f-a/b, c+e*b)-min(a+c/e, b*d) = " << max(f-a/b, c+e*b)-min(a+c/e, b*d) << endl;
  cout << "=====================================" << endl;

  return(0);
}
