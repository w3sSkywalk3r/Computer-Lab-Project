//
//   COPYRIGHT (C) wec16@zips.uakron.edu>, 2021  All rights reserved.
//   Student Wesley Cunningham
//   Purpose: To simulate a computer lab
//
#include <cassert>
#include <iosfwd>
#include <iostream>
#include <iomanip>
#include <limits>
#include<time.h>



using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::right;

static int uChoose = 0;

 // Global Constants
// Number of computer labs
const int NUMLABS = 8;
// Number of computers in each lab
const int LABSIZES[NUMLABS] = {10, 15, 20, 25, 20, 15, 10, 5};

// Names of university of each lab
const std::string UNIVERSITYNAMES[NUMLABS] = {"The University of Michigan", "The University of Pittsburgh", "Stanford University",
"Arizona State University", "North Texas State University", "The University of Alabama, Huntsville", "Princeton University", "Duquesne University"};



void
introMessage();

int
mainMenu();

void
simLogIn(int *userID[], std::string *userName[], int *userTime[]);

void
simLogOff(int *userID[], std::string *userName[], int *userTime[]);

void
simSearch(int *userID[], std::string *userName[], int *userTime[]);

void
displayLab(int *userID[], std::string *userName[], int *userTime[]);

 bool
 validateInput(int, int, int, std::string);

 bool
 validateTime(int, std::string);

struct Test_myCode
{
  void
  default_beg(int *userID[], std::string *userName[], int *userTime[])
  {
    uChoose = mainMenu();
    assert(!(std::cin.fail()));
    std::cout << " Your choice: " << uChoose << std::endl;
  }
  void
  whatAction(int *userID[], std::string *userName[], int *userTime[])
  {
    switch (uChoose)
    {
      case (1):
        simLogIn(userID, userName, userTime);
        break;
      case (2):
        simLogOff(userID, userName, userTime);
        break;
      case (3):
        simSearch(userID, userName, userTime);
        break;
      case (4):
        displayLab(userID, userName, userTime);
        break;
      case (5):
      cout << "End of program";
      exit(0);


      default:
        cout << "no case";
    }
  }


  void
  run(int *userID[], std::string *userName[], int *userTime[])
  {
    default_beg(userID, userName, userTime);
    whatAction(userID, userName, userTime);
  }

};


int
main()
{
    int *userID[NUMLABS];
    std::string *userName[NUMLABS];
    int *userTime[NUMLABS];
    //Array for userID
    for (auto i = 0; i < NUMLABS; ++i)
    {
        userID[i] = new int[LABSIZES[i]];
        for(auto j = 0; j < LABSIZES[i]; ++j)
        {
            userID[i][j] = -1;
        }

    }
    //Array for userName
    for (auto i = 0; i < NUMLABS; ++i)
    {
        userName[i] = new std::string[LABSIZES[i]];
        for(auto j = 0; j < LABSIZES[i]; ++j)
        {
            userName[i][j] = " ";
        }
    }
    //Array for userTime
    for (auto i = 0; i < NUMLABS; ++i)
    {
        userTime[i] = new int[LABSIZES[i]];
        for(auto j = 0; j < LABSIZES[i]; ++j)
        {
            userTime[i][j] = -1;
        }
    }
    srand(time(NULL)); //Seeds the rand function, placed here so clock would keep getting called
    //so then random IDs are not close numbers.
    cout << "      Welcome- here is our list of available labs" << endl;
    cout << "Lab #1 for The University of Michigan" << endl;
    cout << "Lab #2 for The University of Pittsburgh" << endl;
    cout << "Lab #3 for Stanford University" << endl;
    cout << "Lab #4 for Arizona State University" << endl;
    cout << "Lab #5 for North Texas State University" << endl;
    cout << "Lab #6 for The University of Alabama, Huntsville" << endl;
    cout << "Lab #7 for Princeton University" << endl;
    cout << "Lab #8 for Duquesne University" << endl;
    cout << endl;
  Test_myCode test;
  while (true)
  {
    test.run(userID, userName, userTime);
  }

}



int
mainMenu()
{
  //Setup similar to the way the assignments were constructed
   cout << endl;
  cout << setw(68) << "__________________________________________________________________ " << endl;
  cout << setw(68) << "|------------------------------------------------------------------|" << endl;
  cout << setw(68) << "|                Wesley Cunningham Incorporated                    |" << endl;
  cout << setw(68) << "|                    Computer Lab System                           |" << endl;
  cout << setw(68) << "|__________________________________________________________________|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "   MAIN MENU"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "1) Simulate Login"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "2) Simulate Logoff"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "3) Search      "
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "4) Display a Lab"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "5) Quit "
       << right << setw(2) << "|" << endl;
  cout << setw(68) << "|__________________________________________________________________|" << endl;
  cout << endl;
  int userChoice = 0;

  cout << "Enter the code that you wish to generate, or quit to exit: ";
  cin >> userChoice;
  return userChoice;
}

void simLogIn(int *userID[], std::string *userName[], int *userTime[])
{
    bool loopFlag = false;
    int labNum = 0;
    int statNum = 0;
    do
    {
      cout << "Enter the lab number the user is logging in from (1-8): ";
      cin >> labNum;
      if(validateInput(labNum,1,8, "Please enter a number within the given range."))
       {
         loopFlag = true;
       }
      else
      {
          loopFlag = false;
      }

    }while(loopFlag);
     int ktr = 0;
    for(auto i = 0; i < LABSIZES[labNum - 1]; ++i)
    {
        if(userID[labNum - 1][i] != -1)
        {
           ++ktr;
        }
    }

    if(ktr == LABSIZES[labNum - 1])
    {
     cout << "Sorry lab " << labNum << " is full, please try a different lab." << endl;
    }
   else
    {
    loopFlag = false;

    do
    {
    cout << "Enter computer station number the user is logging in to (1-" << LABSIZES[labNum - 1]   << "):";
    cin >> statNum;
    if(validateInput(statNum, 1, LABSIZES[labNum - 1], "Please enter a number within the given range."))
    {
        loopFlag = true;
    }
    else
    {
        loopFlag = false;
    }
    if(userID[labNum - 1][statNum - 1] != -1)
    {
        cout << "Sorry, this lab station is already taken." << endl;
        loopFlag = true;
    }
    else
    {
        loopFlag = false;
    }
    }while(loopFlag);

    cout << endl;

    int userNum = 0;
    userNum = rand()% 99999;
    cout << "User ID: " << setw(5) << std::setfill('0') << userNum << endl;
    cout << setw(0) << std::setfill(' ') << endl;
    userID[labNum-1][statNum-1] = userNum;
   // cin.clear();
   // cin.ignore(999, '\n');

  std::string nameStr = " ";
    do
    {
    cout << "Please enter the name of this user: " << endl;
    getline(cin, nameStr);
    if((nameStr.size() > 35) || nameStr == "")
    {
        loopFlag = true;
        cout << "Please enter a valid name." << endl;
    }
    else
    {
        loopFlag = false;
    }
    cout << endl;
    }while(loopFlag);
    userName[labNum-1][statNum-1] = nameStr;

    int timeInt = 0;
    do
    {
    cout << "Please enter the minutes of use for the work station (15/30/45/60):" << endl;
    cin >> timeInt;
    if(validateTime(timeInt, "Please select a valid time option"))
    {
        loopFlag = true;
    }
    else
    {
        loopFlag = false;
    }
    //cin.clear();
    //cin.ignore(999, '\n');
    }while(loopFlag);
    userTime[labNum-1][statNum-1] = timeInt;
        std::cout << endl;
    }
}



void simLogOff(int *userID[], std::string *userName[], int *userTime[])
{
    int labNum = 0;
    int statNum = 0;
    bool loopFlag = false;
    do
    {
      cout << "Please enter the lab number that the user is logging off (1-8): ";
      cin >> labNum;
    if(validateInput(labNum, 1, 8, "Please enter a number within the given range."))
    {
        loopFlag = true;
    }
    else
    {
        loopFlag = false;
    }
    }while(loopFlag);
    cout << endl << endl;
    do
    {
      cout << "Please enter the lab station the user was working from (1-" << LABSIZES[labNum - 1] << "): " ;
      cin >> statNum;
      if(validateInput(statNum, 1, LABSIZES[labNum - 1], "Please enter a number within the given range."))
      {
          loopFlag = true;
      }
      else
      {
          loopFlag = false;
      }

    }while(loopFlag);


    userID[labNum - 1][statNum - 1] = -1;
    userName[labNum - 1][statNum - 1] = " ";
    userTime[labNum - 1][statNum - 1] = -1;

    cout << "User successfully logged out" << endl;
}

void simSearch(int *userID[], std::string *userName[], int *userTime[])
{
    cout << "Enter the 5 digit ID number of the user to find:" << endl;
    int userNum = 0;
    cin >> userNum;

    for(auto i = 0; i < NUMLABS; ++i)
    {
        for(auto j = 0; j < LABSIZES[i]; ++j)
        {
            if(userID[i][j] == userNum)
            {
              cout << setw(5) << std::setfill('0') << userNum;
              cout << setw(0) << std::setfill(' ') << ": " << userName[i][j] << " is in lab " << i + 1 << " at computer " << j + 1;
              cout << " for " << userTime[i][j] << " minutes.";
              return;
            }
            else
            {
                continue;
            }

        }
    }
    cout << "Sorry this user is not logged in" << endl;

}

void displayLab(int *userID[], std::string *userName[], int *userTime[])
{
    cout << "Please enter the lab to display: ";
    int labNum = 0;
    cin >> labNum;
    cout << endl;

    cout << "LAB STATUS" << endl;
    cout << "Lab # " << labNum << " for " << UNIVERSITYNAMES[labNum-1] << endl;
    cout << "Computer Stations" << endl;
    for(auto i = 0; i <= LABSIZES[labNum-1]; ++i)
    {
        if(userID[labNum-1][i] == -1)
        {
            cout <<  " empty ";
        }
        else
        {
            cout << setw(5) << std::setfill('0') << userID[labNum-1][i] << setw(0) << std::setfill(' ') <<  " ";
            cout << setw(0) << std::setfill(' ');
        }
    }

}


bool validateInput(int userChoice, int range1, int range2, std::string message)
{
  bool goodOrNot = false;
  if ((cin.fail()) || ((userChoice < range1) || (userChoice > range2)))
  {
 	cout << message << endl;
    goodOrNot = true;
  }
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return goodOrNot;
}


bool validateTime(int userChoice, std::string message)
{
    bool goodOrNot = false;
    if (userChoice == 15 || userChoice == 30 || userChoice == 45 || userChoice == 60)
    {
        return goodOrNot;
    }
    else
    {
        cout << message << endl;
        goodOrNot = true;
    }
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return goodOrNot;
}
