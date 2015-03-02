#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define PI 3.14159265

int main() {
	
	int a, b, s, m, n;
	cin >> a >> b >> s >> m >> n;
	
	while (a != 0 && b != 0 && s != 0 && m != 0 && n != 0) {
		
		double angle = atan(((double)(b * n)) / ((double)(a * m))) * 180 / PI;
		
		double dist     = sqrt((((double)a * (double)m) * ((double)a * (double)m)) + (((double)b * (double)n) * ((double)b * (double)n)));
		double veloc = dist / s;
		
		cout << fixed << setprecision(2) << angle << " " << veloc << endl;
		
		cin >> a >> b >> s >> m >> n;
	}
	
    return 0;
}
