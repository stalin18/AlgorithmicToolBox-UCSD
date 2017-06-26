#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

/* make b as small number */
void arrange_min(int &a, int &b){
    int temp;
    
    if(a<b){
        temp = b;
        b = a;
        a = temp;
    }
}

int gcd_fast(int a, int b) {
    if(b == 0){
        return a;
    }
    
    arrange_min(a, b);
    return gcd_fast(b, a%b);
}

long long lcm_fast(int a, int b) {
    int gcd;
    long long lcm;
    
    gcd = gcd_fast(a, b);
    
    lcm = ((long long)a*b) / gcd;
    
    return lcm;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
