# Computer-Lab-Project
/*
This simulates a series of University Labs
The labs are organized using jagged arrays

When the program is run a menu will appear that asks the user to pick an option

1) Simulate Login
   This will login a user to 1 of the 8 labs, then they can pick a lab station as well
   Once the lab station is chosen a random user ID will be assigned
   Then the name of the user will be prompted for entry
   Next the amount of time the user is logging in for will be recorded
   
2) Simulate Logoff
   This will prompt the user for the lab number and lab station
   Once entered the data in the array will be reset
   
3) Search
  This will prompt the user for a user ID, it will then search through the arrays
  Once the number is found it will display the user's name, lab number, lab station, and time
  If the user ID number is not found it will display "Sorry this user is not logged in"
  
4) Display A Lab
  This will prompt the user for a lab to display, this will then display all the user ID's logged in at each lab station
  If a user is not logged in the lab station will display as "empty"
  
5) Quit
  This will terminate the program
