#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<double> heights = { 3.5,5.2,20.0,8.1,12.3,9.9,10.0 };
	for (double h : heights) {
		cout << h << " ";
	}
	cout << endl;
   auto new_end = std::remove_if(heights.begin(), heights.end(), [](double h) { return h < 10.0; });
   heights.erase(new_end, heights.end());

   for (double h : heights) {
	   cout << h << " ";
   }
   cout << endl;
   system("pause");
   return 0;
}
