/* ------------------------------------------------------
Final Project Milestone 5
Module: Car and Motorcycle
Filename: main.cpp
Version 1.0
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
-----------------------------------------------------------*/
/*
C,1,ASD123,Honda Civic,0
M,2,AS12,Honda 125,1
C,3,QWE123,BMW 320,1
M,5,ZXC123,Suzuki 750,0
C,6,ASDASD,Ford F150,0
M,7,ZXC,Ninja 650,0
M,8,QWE,Ninja H2,0
C,9,GVAA123,Tesla Model 3,1
C,10,QWEASD,Cadilac XT5,0
*/
#include <fstream>
#include <iostream>
#include <ctype.h>
#include "Parking.h"
using namespace std;
using namespace sdds;
void runParking();
void Datafile(bool restore = false);
int main() {
   runParking();
   Datafile(true);
   return 0;
}
void runParking() {
   Parking P("ParkingData.csv", 10);
   P.run();
}
void Datafile(bool restore) {
   char ch;
   ifstream file("ParkingData.csv");
   cout << endl << "Content of ParkingData.csv after the program exits" << endl;
   cout << "-----------------------------------------------------------" << endl;
   while(file.get(ch)) {
      cout << char(tolower(ch));
   }
   cout << "-----------------------------------------------------------" << endl;
   if(restore) {
      cout << "Restore data file to original values? (y)es/(n)o: ";
      file.close();
      if(cin.get() == 'y') {
         char ch;
         file.open("ParkingData.csv.bak");
         ofstream fout("ParkingData.csv");
         while(file) {
            ch = file.get();
            if(file) fout.put(ch);
         }
         file.close();
         fout.close();
         cout << "Data file restored to orginal values." << endl;
      } else {
         cout << "Restoration aborted!" << endl;
      }
   }
}

