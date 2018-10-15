
// Ryan Engebretsen
// Mastermind game

#include <iostream>
#include <vector>
#include <stdlib.h> // rand()
#include <time.h>

#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

enum Color {Red, Orange, Yellow, Green, Blue, Indigo, Violet};
Color Colors[7] = {Red, Orange, Yellow, Green, Blue, Indigo, Violet};

Color ColorRandom();

class Series {
    public:
        Color Colors[4];
    
        Series(Color a, Color b, Color c, Color d) {
            Colors[0] = a; Colors[1] = b; Colors[2] = c; Colors[3] = d;
        }
    
        Series() {
        
        }
        //int operator==() {
            
            
        //}
    private:
    
};

void UniqueSeries(Series &a);

void DrawGameboard(Series &gb, int l);


int main() {
    srand(time(NULL));
    
    cout << "Master Mind game\n";
    cout << "Valid colors: Red, Orange, Yellow, Green, Blue Indigo, Violet.\n\n";
    
    

    int length;
    
    Series GameboardA[9] = {}; // this is a bit of a hack to bypass variable sized array errors
    Series GameboardB[11] = {};
    Series GameboardC[13] = {};
    
    Series* Gameboard; // depending on the size we point to one of our gameboard arrays
    
    
    cout << "Enter game length, 8, 10, or 12:";
    cin >> length;
    (length == 8 || length == 10 || length == 12) ? length = length : length = 12;
    
    switch (length) {
        case 8: {
            Gameboard = GameboardA;
            //delete GameboardB;
            //delete GameboardC;
        }
        case 10: {
            Gameboard = GameboardB;
            //delete GameboardA;
            //delete GameboardC;
        }
        case 12: {
            Gameboard = GameboardC;
            //delete GameboardA;
            //delete GameboardB;
        }
    }
    
    
    Series SecretCode;
    UniqueSeries(SecretCode);
    
    
    cout << "unique series is: " << SecretCode.Colors[0] << ", " << SecretCode.Colors[1] << ", " << SecretCode.Colors[2] << ", " << SecretCode.Colors[3] << "\n\n\n";
    

    
    
}



Color ColorRandom() {
    
    return Colors[rand()%7];
}

void UniqueSeries(Series &a) {
    vector<Color> FreeColors;
    for (int i = 0; i <= 6; ++i) {
        FreeColors.push_back(Colors[i]);
    }

    unsigned rseed = chrono::system_clock::now().time_since_epoch().count();
    shuffle (FreeColors.begin(), FreeColors.end(), default_random_engine(rseed));


    a.Colors[0] = FreeColors[0];
    a.Colors[1] = FreeColors[1];
    a.Colors[2] = FreeColors[2];
    a.Colors[3] = FreeColors[3];
}

void DrawGameboard(Series &gb, int l) {
    cout << "\n\nSTARTING DRAW\n";
    for (int i = (l-1); i < (l-1); ++i) {
        cout << i << ": ";
        
        //if(gb[i] =
        
        
    }
    
}




