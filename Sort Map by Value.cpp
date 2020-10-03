//https://www.educative.io/edpresso/how-to-sort-a-map-by-value-in-cpp

// METHOD1---using vector--------------------
#include <iostream>
#include <map>
#include <vector>
#include <algorithm> // for sort function

using namespace std;

// utility comparator function to pass to the sort() module
bool sortByVal(const pair<string, int> &a, 
               const pair<string, int> &b) 
{ 
    return (a.second < b.second); 
} 

int main()
{
  // create the map
	map<string, int> mymap = {
		{"coconut", 10}, {"apple", 5}, {"peach", 30}, {"mango", 8}
	};

  cout << "The map, sorted by keys, is: " << endl;
  map<string, int> :: iterator it;
  for (it=mymap.begin(); it!=mymap.end(); it++) 
  { 
    cout << it->first << ": " << it->second << endl;
  }
  cout << endl;
 
	// create a empty vector of pairs
	vector<pair<string, int>> vec;

	// copy key-value pairs from the map to the vector
  map<string, int> :: iterator it2;
  for (it2=mymap.begin(); it2!=mymap.end(); it2++) 
  {
    vec.push_back(make_pair(it2->first, it2->second));
  }

	// // sort the vector by increasing order of its pair's second value
  sort(vec.begin(), vec.end(), sortByVal); 

	// print the vector
	cout << "The map, sorted by value is: " << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first << ": " << vec[i].second << endl;
	}
	return 0;
}

// METHOD2---using multimap--------------------
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

// Function to convert a map<key,value> to a multimap<value,key>
multimap<int, string> invert(map<string, int> & mymap)
{
	multimap<int, string> multiMap;

	map<string, int> :: iterator it;
	for (it=mymap.begin(); it!=mymap.end(); it++) 
	{
		multiMap.insert(make_pair(it->second, it->first));
	}

	return multiMap;
}

int main()
{
	// make the map
	map<string, int> mymap = {
		{"coconut", 10}, {"apple", 5}, {"peach", 30}, {"mango", 8}
	};
	cout << "The map, sorted by keys, is: " << endl;
	map<string, int> :: iterator it;
	for (it=mymap.begin(); it!=mymap.end(); it++) 
	{ 
		cout << it->first << ": " << it->second << endl;
	}
	cout << endl;

	// invert mymap using the invert function created above
	multimap<int, string> newmap = invert(mymap);

	// print the multimap
	cout << "The map, sorted by value is: " << endl;
 	multimap<int, string> :: iterator iter;
	for (iter=newmap.begin(); iter!=newmap.end(); iter++) 
	{
		// printing the second value first because the 
		// order of (key,value) is reversed in the multimap
		cout << iter->second << ": " << iter->first << endl; 
	}

	return 0;
}
