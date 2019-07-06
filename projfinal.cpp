#include<bits/stdc++.h> //Header file that include every standard library.
#define pb push_back    //push_back can be replaced by pb in our program now.
using namespace std;


int temp = 0; //To check if path is avaiable or not.
vector < string > final; //for storing the final itinerary.

class touristMap { //Class touristMap consists of all the methods used.
 
  map < string, list < pair < string, int > > > m; //Container of STL where first argument is Place and Pair consists of connected Place and its Distance.

  public:

    void addPath(string u, string v, int distance) { //addPath for adding new places.
      //Assuming Bidirectional Way
      m[u].pb(make_pair(v, distance));
      m[v].pb(make_pair(u, distance));
    }

  void printAdjList() { //For printing all the connected Places from a particular place.

    for (auto j: m) {
      cout << j.first << "-->";
      for (auto vertex: j.second) {
        cout << "(" << vertex.first << "," << vertex.second << ")";
      }
      cout << endl << endl;
    }
  }

  void printMap() { //printMap for printing the map manually according to the data entered.

    cout << "TRAVELER'S ITINERARY PLANNER" << endl << endl;

    cout << "MAP:";
    cout << endl;
    cout << "*********************************************************************************" << endl;
    cout << "*                                        /|                                     * " << endl;
    cout << "*                                       / |                                     * " << endl;
    cout << "*                                      '--|                        /|           * " << endl;
    cout << "*                                         |                       '-|           * " << endl;
    cout << "*    ______/|_____________6hr_______.-----|-----.             .----|-----.      * " << endl;
    cout << "*    |    / |++++++++++.            |           |             |{HauzKhas}|      * " << endl;
    cout << "*    |____| {AppuGhar} |___ 4hr____ |  {RedFort}|             .----------.      * " << endl;
    cout << "*     ____|            |            |           |_____6hr _____________|___     * " << endl;
    cout << "*     |   **************            .+++++++++++.       /              |        * " << endl;
    cout << "*     |                                                 5hr            |        * " << endl;
    cout << "*     |                                                /               |        * " << endl;
    cout << "*     2hr                    .-++-----++--.        .^^^^^^^^^^^^.     3hr       * " << endl;
    cout << "*     |                   __ |{ DaryaGanj}|________|{ IndiaGate}|      |        * " << endl;
    cout << "*     |                  /   |            |   1hr  |            |      |        * " << endl;
    cout << "*     |____.*********. 1hr   '--+++++++++-.        .^^^^^^^^/^^^^.     |        * " << endl;
    cout << "*          |{Chandani| /                                   3hr         |        * " << endl;
    cout << "*          |  Chowk} |/              /|----------.        /            |        * " << endl;
    cout << "*          |         |              / |          |      <<<<           >>>>     * " << endl;
    cout << "*     _____.---------.            ./--|----------|       {{ LotusTemple }}      * " << endl;
    cout << "*     |                           |              |        {{{{       }}}}       * " << endl;
    cout << "*     2hr                         |{JantarMantar}|          {{{    }}}          * " << endl;
    cout << "*     |____.---------. _____3hr __|              |----6hr-----////////          * " << endl;
    cout << "*          | {Jama   |            .--------------.               |              * " << endl;
    cout << "*          |  Masjid}|                                           |              * " << endl;
    cout << "*          |         |                                         -----            * " << endl;
    cout << "*          .---------.                                             |            * " << endl;
    cout << "*                |------------------------3hr----------------------|            * " << endl;
    cout << "*                                                                               * " << endl;
    cout << "*                                                                               * " << endl;
    cout << "*                                                                               * " << endl;
    cout << "********************************************************************************";
    cout << endl;

  }

  //Backtricking Algorithm Block

  void paths(string source, string destination, int time, int currTime, vector < string > v, map < string, bool > marked) {

    if (currTime > time) { //Backtrack if Time exceeds.
      return;
    }

    if (source == destination) {
      //v.pb(destination);
      for (int it = 0; it != v.size(); it++) {
        cout << v[it] << "-->";
      }
      temp = 1; //Confirming Path is Possible.
      cout << destination << endl;
      cout << " " << "No. of places Visited :" << v.size();
      cout << endl;
      cout << endl;
      if (v.size() > final.size()) { //Altering the Final vector if a more optimal path is found.
        final.clear();
        for (int it = 0; it < v.size(); it++) {
          final.pb(v[it]);
        }
      }
      return;
    }
    if (marked[source]) {
      return;
    }

    v.pb(source);
    marked[source] = true;
    for (auto neighbour: m[source]) {

      paths(neighbour.first, destination, time, currTime + neighbour.second, v, marked); //Recursion Part 
    }
  }
};

int main() {
  system("color 1E"); //it changes the background color to blue.
  touristMap ourMap; 
  // Adding paths to our Map.
  ourMap.addPath("AppuGhar", "RedFort", 4); 
  ourMap.addPath("AppuGhar", "ChandaniChowk", 2);
  ourMap.addPath("RedFort", "AppuGhar", 6);
  ourMap.addPath("RedFort", "HauzKhas", 6);
  ourMap.addPath("HauzKhas", "IndiaGate", 5);
  ourMap.addPath("HauzKhas", "LotusTemple", 3);
  ourMap.addPath("IndiaGate", "DaryaGanj", 1);
  ourMap.addPath("IndiaGate", "LotusTemple", 3);
  ourMap.addPath("DaryaGanj", "ChandaniChowk", 1);
  ourMap.addPath("ChandaniChowk", "JamaMasjid", 2);
  ourMap.addPath("JamaMasjid", "JantarMantar", 3);
  ourMap.addPath("JantarMantar", "LotusTemple", 6);
  ourMap.addPath("JamaMasjid", "LotusTemple", 3);
                        
  // Printing all the Connections.
  ourMap.printAdjList();
  //Printing the Map. 
  ourMap.printMap();

  string source, destination;
  int time;

  cout << "Enter your Source and Destination" << endl;
  cout << "Source :" << " ";
  cin >> source;

  cout << "Destination:" << " ";
  cin >> destination;

  cout << "Enter how much time do you have in hours?";
  cout << endl;
  cin >> time;

  vector < string > v;
  map < string, bool > marked; //For checking out if the place is visited before.

  ///passing source,destination and time in our backtracking algorithm..
  ourMap.paths(source, destination, time, 0, v, marked);

  if (temp == 0) {
    cout << "Sorry,no path is possible" << endl;
  } 
  else {
    cout << "Best way to go is ";
    cout << endl;
    for (int i = 0; i < final.size(); ++i) {
      cout << final[i] << "-->";
    }
    cout << destination;
    cout << endl << endl;
    cout << "Wohoo we will visit " << " " << final.size() << " places and reach our Destination on Time" << endl;
  }
  return 0;
}