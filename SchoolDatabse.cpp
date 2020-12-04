/*******************************
 * Andrew Dillon
 * 2382400
 * CPSC 350
 * Assignment 05
 *******************************/

#include "SchoolDatabase.h"

SchoolDatabase :: SchoolDatabase()
{
  string studentFile = "masterStudent";
  string facultyFile = "masterFaculty";


  if(CheckFileNameValid(studentFile) && CheckFileNameValid(facultyFile))
  {
    try
    {
      DeserializeFaculty(facultyFile);
      DeserializeStudents(studentFile);
    }
    catch(const char)
    {
      cout << "Sorry, there was an error reading the file.\n\n";
    }

  }
}
SchoolDatabase :: ~SchoolDatabase()
{

}
void SchoolDatabase :: RunDatabase()
{
  //VARIABLES
  int menuChoice;

  cout << endl << endl;
  cout << "Hello and  welcome to school database." << endl << endl;

  do
  {
    menuChoice = GetMenuInput(MAIN_MENU, NUM_MAIN_MENU_OPTIONS);

    cout << endl << endl;

    switch(menuChoice)
    {
      case 1:
        PrintStudentDatabase();
        break;
      case 2:
        PrintFacultyDatabase();
        break;
      case 3:
        PrintStudentFromID();
        break;
      case 4:
        PrintFacultyFromID();
        break;
      case 5:
        PrintStudentAdvisor();
        break;
      case 6:
        PrintFacultyAdvisees();
        break;
      case 7:
        AddStudent();
        break;
      case 8:
        DeleteStudent();
        break;
      case 9:
        AddFaculty();
        break;
      case 10:
        DeleteFaculty();
        break;
      case 11:
        ChangeStudentAdvisor();
        break;
      case 12:
        RemoveAdviseeFromID();
        break;
      case 13:
        Rollback();
        break;
      default:
        break;
    }
  } while(menuChoice != NUM_MAIN_MENU_OPTIONS);

  SerializeStudents();
  SerializeFaculty();

  cout << "END\n\n";
}
int SchoolDatabase :: GetMenuInput(const string initialMessage, const int numMenuOptions)
{
  bool valid = false;
  int menuChoice = 0;

  do
  {
    cout << initialMessage;
    cin >> menuChoice;
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(100000000, '\n');
      cout << "\nSorry, please enter numeric input.\n\n";

      valid = false;
    }
    else if(menuChoice > 0 && menuChoice <= numMenuOptions)
    {
      valid = true;
    }
    else
    {
      cout << "\nSorry, please enter a value between 1 and " << numMenuOptions << endl << endl;
      valid = false;
    }

  } while(!valid);
}
void SchoolDatabase :: PrintStudentDatabase()
{
  cout << "Current Students\n";

  if(studentTree.IsEmpty())
  {
    cout << "\nStudent Database is Empty\n\n\n";
  }
  else
  {
    studentTree.InOrder();
  }
}
void SchoolDatabase :: PrintFacultyDatabase()
{
  cout << "School Staff\n";
  if(facultyTree.IsEmpty())
  {
    cout << "\nFaculty Database is Empty\n\n\n";
  }
  else
  {
    facultyTree.InOrder();
  }
}
void SchoolDatabase :: PrintStudentFromID()
{
  int studentID;
  //promt user for student ID

  cout << "Please enter the ID number of the student you'd like to find: ";
  cin  >> studentID;
  if(cin.fail())
  {
    cin.clear();
    cin.ignore(100000000, '\n');
    cout << "\nSorry, non numeric input was recieved.\nReturning to main menu...\n\n";

    return;
  }//END if(cin.fail())

  Student searchStudent(studentID);

  TreeNode<Student>* tempStudentNode = studentTree.ReturnPointerToNode(searchStudent);

  if(tempStudentNode != nullptr)
  {
    cout << tempStudentNode  -> key;
  }
  else
  {
    cout << "Sorry, no student was found with the ID number: " << studentID << endl << endl;
  }
}
void SchoolDatabase :: PrintFacultyFromID()
{
  int facultyID;
  //promt user for student ID

  cout << "Please enter the ID number of the facuty member you'd like to find: ";
  cin  >> facultyID;
  if(cin.fail())
  {
    cin.clear();
    cin.ignore(100000000, '\n');
    cout << "\nSorry, non numeric input was recieved.\nReturning to main menu...\n\n";

    return;
  }//END if(cin.fail())

  Faculty searchFaculty(facultyID);

  TreeNode<Faculty>* tempFacultyNode = facultyTree.ReturnPointerToNode(searchFaculty);

  if(tempFacultyNode != nullptr)
  {
    cout << tempFacultyNode  -> key;
  }
  else
  {
    cout << "Sorry, no faculty member was found with the ID number: " << facultyID << endl << endl;
  }
}
void SchoolDatabase :: PrintStudentAdvisor()
{
  int studentID;
  //promt user for student ID

  cout << "Please enter the ID number of the student whose advisor you would like to find: ";
  cin  >> studentID;
  if(cin.fail())
  {
    cin.clear();
    cin.ignore(100000000, '\n');
    cout << "\nSorry, non numeric input was recieved.\nReturning to main menu...\n\n";

    return;
  }//END if(cin.fail())

  Student searchStudent(studentID);

  TreeNode<Student>* tempStudentNode = studentTree.ReturnPointerToNode(searchStudent);

  if(tempStudentNode != nullptr)
  {
    cout << "The adviosr for " << studentID
         << " [" << tempStudentNode  -> key.GetFirstName() << " "
         << tempStudentNode  -> key.GetLastName() << "] is ";

    int advisorID = tempStudentNode  -> key.GetAdvisorID();

    //No advisor
    if(advisorID == 0)
    {
      cout << "unasigned at this time.\n";
      cout << "This can be changed in the main menu\n\n";

    }
    //Advisor is set
    else
    {
      Faculty tempAdvisor(advisorID);

      TreeNode<Faculty>* advisorNode = facultyTree.ReturnPointerToNode(tempAdvisor);

      //Advisor found in database
      if(advisorNode != nullptr)
      {
        cout << ":\n";
        cout << advisorNode -> key;
      }
      //Advisor is NOT found
      else
      {
        cout << "not currently in the database.\n\n";
      }
    }//END else for if(advisorID == 0)
  }//END if(tempStudentNode != nullptr)
  else
  {
    cout << "Sorry, no student was found with the ID number: " << studentID << endl;
    cout << "Returning to the main menu\n\n";
  }//END else for if(tempStudentNode != nullptr)
}
void SchoolDatabase :: PrintFacultyAdvisees()
{
  int facultyToPrintAdviseesOf;
  bool valid = false;

  do
  {
    cout << "Enter the ID of the Faculty Member you'd like to see the advisees of: ";
    cin >> facultyToPrintAdviseesOf;
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(100000000, '\n');
      cout << "\nSorry, please enter a valid numeric Student ID.\n\n";

      valid = false;
    }
    else if(facultyToPrintAdviseesOf > 0)
    {
      valid = true;
    }
    else
    {
      cout << "\nSorry, please enter a positive value.\n\n";
      valid = false;
    }
  } while(!valid);

  Faculty tempFaculty(facultyToPrintAdviseesOf);

  TreeNode<Faculty>* designatedFaculty = facultyTree.ReturnPointerToNode(tempFaculty);

  //Checknig that they do exist (returning if not)
  if(designatedFaculty == nullptr)
  {
    cout << "Sorry, no faculty member was found with the ID number: " << facultyToPrintAdviseesOf << endl;
    cout << "Returning to the main menu\n\n";
    return;
  }

  DoublyLinkedList<int> studentList = designatedFaculty -> key.GetAdviseesIDs();

  for(int i = 0; i < studentList.GetSize(); ++i)
  {
    Student tempStudent(studentList.GetValueAtIndex(i));
    cout << studentTree.ReturnPointerToNode(tempStudent) -> key;
  }
}
void SchoolDatabase :: AddStudent()
{
  bool valid = false;

  int    newID = GenerateStudentID();
  string newFirstName;
  string newLastName;
  string newStudentLevel;
  string newMajor;
  double newGPA;
  int    newAdvisorID;


  cin.ignore(100000000, '\n');

  cout << "Please enter student data:\n";
  cout << "Student's first name: ";
  getline(cin, newFirstName);

  cout << "Student's last name: ";
  getline(cin, newLastName);

  cout << "Student's level: ";
  getline(cin, newStudentLevel);

  cout << "Student's major: ";
  getline(cin, newMajor);

  //Validating GPA
  do
  {
    cout << "Student's GPA: ";
    cin >> newGPA;
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(100000000, '\n');
      cout << "\nSorry, please enter a valid numeric GPA input.\n\n";

      valid = false;
    }
    else if(newGPA >= 0)
    {
      valid = true;
    }
    else
    {
      cout << "\nSorry, please enter a positive value.\n\n";
      valid = false;
    }

  } while(!valid);

  //validating Advisor ID
  do
  {
    cout << "Student's Advosir's ID: ";
    cin >> newAdvisorID;
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(100000000, '\n');
      cout << "\nSorry, please enter a numeric advisor ID.\n\n";

      valid = false;
    }
    else if(newAdvisorID < 0)
    {
      cout << "\nSorry, please enter a positive value.\n\n";
      valid = false;
    }
    else
    {
      Faculty tempFaculty(newAdvisorID);

      cin.ignore(100000000, '\n');
      if(!facultyTree.IfSearchNode(tempFaculty))
      {
        cout << "Sorry, that faculty ID, does not correspond with any current members of our team.\n\n";
        cout << "Enter \"L\" if you would like to see a list of all faculty members.\n"
             << "Enter \"N\" if you would like to enter a new Advisor ID.\n"
             << "Enter \"R\" if you would like to return to the main menu.\n"
             << "Choice: ";
        char choiceChar;
        cin.get(choiceChar);

        cin.ignore(100000000, '\n');

        if(toupper(choiceChar) == 'L')
        {
          PrintFacultyDatabase();
        }
        else if(toupper(choiceChar) != 'N')
        {
          return;
        }

        valid = false;
      }
      else
      {
        valid = true;
      }

    }//END ELSE of if(cin.fail())

  } while(!valid);

  Student newStudent(newID, newFirstName, newLastName, newStudentLevel,
    newMajor, newGPA, newAdvisorID);


  studentTree.InsertNode(newStudent);
  AddStudentIDToFacultyTree(newAdvisorID, newID);

  cout << endl << newFirstName << " " << newLastName << " has been entered into the system and given the ID Number: " << newID << endl << endl;
}
void SchoolDatabase :: DeleteStudent()
{
  bool valid = false;
  int studentIDToDelete;

  do
  {
    cout << "Enter the ID of the Student to remove: ";
    cin >> studentIDToDelete;
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(100000000, '\n');
      cout << "\nSorry, please enter a valid numeric Student ID.\n\n";

      valid = false;
    }
    else if(studentIDToDelete > 0)
    {
      valid = true;
    }
    else
    {
      cout << "\nSorry, please enter a positive value.\n\n";
      valid = false;
    }

  } while(!valid);


  Student tempStudentNode(studentIDToDelete);
  TreeNode<Student>* studentToDelete = studentTree.ReturnPointerToNode(tempStudentNode);

  //Checknig that they do exist (returning if not)
  if(studentToDelete == nullptr)
  {
    cout << "Sorry, no student was found with the ID number: " << studentIDToDelete << endl;
    cout << "Returning to the main menu\n\n";
    return;
  }

  int studentToDeletesAdvisor = studentToDelete -> key.GetAdvisorID();

  //Removing student from advisor's advisee list
  RemoveStudentIDFromFacultyTree(studentToDeletesAdvisor, studentIDToDelete);
  cout << studentIDToDelete << " was removed from the system\n\n";
}
void SchoolDatabase :: AddFaculty()
{
  bool valid = false;;

  int    newID = GenerateFacultyID();
  string newFirstName;
  string newLastName;
  string newFacultyLevel;
  string newDepartment;
  string newAdviseeID;
  DoublyLinkedList<int> newAdviseesIDsList;


  cin.ignore(100000000, '\n');

  cout << "Please enter faculty memeber data:\n";
  cout << "Faculty memeber's first name: ";
  getline(cin, newFirstName);

  cout << "Faculty memeber's last name: ";
  getline(cin, newLastName);

  cout << "Faculty memeber's level: ";
  getline(cin, newFacultyLevel);

  cout << "Faculty memeber's department: ";
  getline(cin, newDepartment);

  Faculty newFaculty(newID, newFirstName, newLastName, newFacultyLevel,
    newDepartment, newAdviseesIDsList);


  facultyTree.InsertNode(newFaculty);

  cout << newFirstName << " " << newLastName << " has been entered into the system and given the ID Number: " << newID << endl << endl;

}
void SchoolDatabase :: DeleteFaculty()
{
  bool valid = false;
  int facultyToDeleteID;

  do
  {
    cout << "Enter the ID of the Faculty member to remove: ";
    cin >> facultyToDeleteID;
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(100000000, '\n');
      cout << "\nSorry, please enter a valid numeric Faculty ID.\n\n";

      valid = false;
    }
    else if(facultyToDeleteID > 0)
    {
      valid = true;
    }
    else
    {
      cout << "\nSorry, please enter a positive value.\n\n";
      valid = false;
    }

  } while(!valid);

  Faculty facultyToDelete(facultyToDeleteID);
  TreeNode<Faculty>* facultyToDeleteNode = facultyTree.ReturnPointerToNode(facultyToDelete);

  if(facultyToDeleteNode == nullptr)
  {
    cout << "Sorry, no faculty member was found with the ID number: " << facultyToDeleteID << endl;
    cout << "Returning to the main menu\n\n";
    return;
  }

  int newFacultyForAdvisees = facultyTree.GetANewIDFacultyMemberID(facultyToDeleteID);

  if(newFacultyForAdvisees == 0)
  {
    cin.ignore(100000000, '\n');
    string prompt = "Making this change will leave students with no advisors, are you sure you'd like to proceed?";
    bool proceed = GetYesOrNoInput(prompt);

    if(!proceed)
    {
      cout << "Returning to main menu\n\n";
      return;
    }

    //SETTING ALL STUDENT ADVISORS TO 0
    DoublyLinkedList<int> listOfAdvisees = facultyToDeleteNode -> key.GetAdviseesIDs();

    for(int i = 0; i < listOfAdvisees.GetSize(); ++i)
    {
      Student tempStudent(listOfAdvisees.GetValueAtIndex(i));
      TreeNode<Student>* studentToAdjustNode = studentTree.ReturnPointerToNode(tempStudent);
      studentToAdjustNode -> key.SetAdvisorID(newFacultyForAdvisees);
    }
    facultyTree.DeleteNode(facultyToDeleteNode -> key);
    cout << facultyToDeleteID << " was removed from the system and their advisees reassigned to " <<  newFacultyForAdvisees << endl << endl;

    return;
  }

  //Assigning students to new advisee
  TreeNode<Faculty>* newFacultyForAdviseesNode = facultyTree.ReturnPointerToNode(newFacultyForAdvisees);
  DoublyLinkedList<int> listOfAdvisees = facultyToDeleteNode -> key.GetAdviseesIDs();

  for(int i = 0; i < listOfAdvisees.GetSize(); ++i)
  {
    newFacultyForAdviseesNode -> key.AddAdvisee(listOfAdvisees.GetValueAtIndex(i));
    Student tempStudent(listOfAdvisees.GetValueAtIndex(i));
    TreeNode<Student>* studentToAdjustNode = studentTree.ReturnPointerToNode(tempStudent);
    studentToAdjustNode -> key.SetAdvisorID(newFacultyForAdvisees);
  }

  facultyTree.DeleteNode(facultyToDeleteNode -> key);
  cout << facultyToDeleteID << " was removed from the system and their advisees reassigned to " <<  newFacultyForAdvisees << endl << endl;


}
void SchoolDatabase :: ChangeStudentAdvisor()
{
  bool valid = false;
  int studentID;
  int newAdvisorID;

  cout << "Please enter the ID number of the student whose advisor you would like to change: ";
  cin  >> studentID;
  if(cin.fail())
  {
    cin.clear();
    cin.ignore(100000000, '\n');
    cout << "\nSorry, non numeric input was recieved.\nReturning to main menu...\n\n";

    return;
  }//END if(cin.fail())

  Student searchStudent(studentID);
  TreeNode<Student>* tempStudentNode = studentTree.ReturnPointerToNode(searchStudent);

  if(tempStudentNode != nullptr)
  {
    do
    {
      cout << "The current advisor for " << studentID << " is " << tempStudentNode -> key.GetAdvisorID() << endl;
      cout << "Please enter the ID number of the student's new advisor: ";
      cin >> newAdvisorID;
      if(cin.fail())
      {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "\nSorry, please enter a numeric advisor ID.\n\n";

        valid = false;
      }
      else if(newAdvisorID < 0)
      {
        cout << "\nSorry, please enter a positive value.\n\n";
        valid = false;
      }
      else
      {
        Faculty tempFaculty(newAdvisorID);
        TreeNode<Faculty>* newAdvisorNode = facultyTree.ReturnPointerToNode(tempFaculty);

        if(newAdvisorNode == nullptr)
        {
          cin.ignore(100000000, '\n');
          cout << "Sorry, that faculty ID, does not correspond with any current members of our team.\n\n";
          cout << "Enter \"L\" if you would like to see a list of all faculty members.\n"
               << "Enter \"N\" if you would like to enter a new Advisor ID.\n"
               << "Enter \"R\" if you would like to return to the main menu.\n"
               << "Choice: ";
          char choiceChar;
          cin.get(choiceChar);

          cin.ignore(100000000, '\n');

          if(toupper(choiceChar) == 'L')
          {
            PrintFacultyDatabase();
          }
          else if(toupper(choiceChar) != 'N')
          {
            return;
          }

          valid = false;
        }
        else
        {
          valid = true;

          //Creating temp node for old advisor
          Faculty tempFaculty2(tempStudentNode -> key.GetAdvisorID());
          TreeNode<Faculty>* oldAdvisorNode = facultyTree.ReturnPointerToNode(tempFaculty2);


          tempStudentNode -> key.SetAdvisorID(newAdvisorID);
          newAdvisorNode -> key.AddAdvisee(studentID);
          oldAdvisorNode -> key.RemoveAdvisee(studentID);

          cout << "Removing " << studentID << " from faculty member " << tempStudentNode -> key.GetAdvisorID() << "\'s list of advisees";
          cout << " and adding them to " << newAdvisorID << "\'s list of advisees\n\n";

        }
      }//END ELSE of if(cin.fail())
    } while(!valid);
  }//END if(tempStudentNode != nullptr)
  else
  {
    cout << "Sorry, no student was found with the ID number: " << studentID << endl;
    cout << "Returning to the main menu\n\n";
  }//END else for if(tempStudentNode != nullptr)
}
void SchoolDatabase :: RemoveAdviseeFromID()
{

  int  facultyToDeleteFrom;
  bool valid = false;
  int  studentToDelete;
  int  newAdvisorID;

  //GETIING FACULTY
  cout << "Please enter the ID number of the faculty memeber you would like to remove an advisee from: ";
  cin  >> facultyToDeleteFrom;
  if(cin.fail())
  {
    cin.clear();
    cin.ignore(100000000, '\n');
    cout << "\nSorry, non numeric input was recieved.\nReturning to main menu...\n\n";

    return;
  }//END if(cin.fail())

  //CREATING FACULTY NODE
  Faculty tempFaculty(facultyToDeleteFrom);
  TreeNode<Faculty>* tempFacultyNode = facultyTree.ReturnPointerToNode(tempFaculty);

  if(tempFacultyNode == nullptr)
  {
    cout << "Sorry, no faculty member was found with the ID number: " << facultyToDeleteFrom << endl;
    cout << "Returning to the main menu\n\n";
    return;
  }

  //FINDING STUDENT TO REMOVE
  do
  {
    cout << tempFacultyNode -> key;
    cout << "Please enter the ID number of the student's you'd like to remove: ";
    cin >> studentToDelete;
    if(cin.fail())
    {
      cin.clear();
      cin.ignore(100000000, '\n');
      cout << "\nSorry, non numeric input was recieved.";

      valid = false;
    }

    DoublyLinkedList<int> adviseesList = tempFacultyNode -> key.GetAdviseesIDs();

    if(!adviseesList.Search(studentToDelete))
    {
      //cin.ignore(100000000, '\n');
      cout << "Sorry, that faculty ID, does not correspond with any of " << facultyToDeleteFrom << "\'s advisees.\n\n";
      cout << "Enter \"N\" if you would like to enter a new Advisor ID.\n"
           << "Enter \"R\" if you would like to return to the main menu.\n"
           << "Choice: ";
      char choiceChar;
      cin.get(choiceChar);

      if(toupper(choiceChar) != 'N')
      {
        return;
      }
      valid = false;
    }
    else
    {
      valid = true;
    }
  } while(!valid);

  Student tempStudent(studentToDelete);
  TreeNode<Student>* studentNode = studentTree.ReturnPointerToNode(tempStudent);

  if(studentNode == nullptr)
  {
    cout << "Sorry, no student was found with the ID number: " << studentToDelete << endl;
    cout << "Returning to the main menu\n\n";
    return;
  }

  newAdvisorID = facultyTree.GetANewIDFacultyMemberID(facultyToDeleteFrom);

  if(newAdvisorID == 0)
  {
    cin.ignore(100000000, '\n');
    string prompt = "Making this change will cause this student to have no advisor, are you sure you'd like to proceed?";
    bool proceed = GetYesOrNoInput(prompt);

    if(!proceed)
    {
      cout << "Returning to main menu\n\n";
      return;
    }
  }


  studentNode -> key.SetAdvisorID(newAdvisorID);
  tempFacultyNode -> key.RemoveAdvisee(studentToDelete);

  cout << "Removing " << studentToDelete << " from faculty member " <<facultyToDeleteFrom << "\'s list of advisees";

  //Setiing new advisor list to include this student
  if(newAdvisorID != 0)
  {
    Faculty tempFaculty2(newAdvisorID);
    TreeNode<Faculty>* tempFacultyNode2 = facultyTree.ReturnPointerToNode(tempFaculty2);

    tempFacultyNode2 -> key.AddAdvisee(studentToDelete);
    cout << " and adding them to " << newAdvisorID << "\'s list of advisees\n\n";
  }
  else
  {
    cout << endl << endl;
  }
}
void SchoolDatabase ::  Rollback()
{
  cerr << "Entering Rollback\n\n";

  Transaction currentTransactionToUndo = rollbackStack.Pop();


  if(currentTransactionToUndo.GetPersonType() == "STUDENT")
  {
    Student* currentStudent = dynamic_cast<Student*>(currentTransactionToUndo.GetPerson());

    //Removing something that was added
    if(currentTransactionToUndo.GetType() == ADDITION)
    {
      studentTree.DeleteNode(*currentStudent);
    }
    //Adding something that was returned
    else
    {
      studentTree.InsertNode(*currentStudent);
    }
  }
  else//faculty member
  {
    Faculty* currentFaculty = dynamic_cast<Faculty*>(currentTransactionToUndo.GetPerson());

    //Removing something that was added
    if(currentTransactionToUndo.GetType() == ADDITION)
    {
      facultyTree.DeleteNode(*currentFaculty);
    }
    //Adding something that was returned
    else
    {
      facultyTree.InsertNode(*currentFaculty);
    }
  }
}


bool SchoolDatabase :: CheckFileNameValid(string fileName)
{
  ifstream inFile;
  bool valid = false;

  inFile.open(fileName.c_str());

  //check if file exists
  if(inFile)
  {
    valid = true; //is valid
  }
  else
  {
    valid = false; //repeat loop
  }

  inFile.close();

  return valid;
}

bool SchoolDatabase :: GetYesOrNoInput(const string initialMessage)
{
  char gameChoice;
  bool invalidInput = true;

  cout << initialMessage << endl;

  do
  {
    cout << "Please enter either \'Y\' for \"Yes\" or \'N\' for \"No\": ";
    cin.get(gameChoice);
    cin.ignore(100000000, '\n');
    cout << endl;
    gameChoice = toupper(gameChoice);

    if(gameChoice == 'Y' || gameChoice == 'N')
    {
      invalidInput = false;
    }
    else
    {
      invalidInput = true;
      cout << "Sorry, \'" << gameChoice << "\' is invalid.\n";
    }
  }while(invalidInput);

  if(gameChoice == 'Y')
  {
    return true;
  }
  else
  {
    return false;
  }

}

int SchoolDatabase ::  GenerateStudentID()
{
  bool valid = false;
  int randomValue;

  srand(time(0));

  do
  {
    //genereate random 6xxxx number
    randomValue = rand() % 10000 + 60000;

    //Check if number is already in tree
    Student newStudent(randomValue);

    if(studentTree.IfSearchNode(newStudent))
    {
      valid = false;
    }
    else
    {
      valid = true;
    }

  } while(!valid);

  return randomValue;
}
int SchoolDatabase ::  GenerateFacultyID()
{
  bool valid = false;
  int randomValue;

  srand(time(0));

  do
  {
    //genereate random 7xxxx number
    randomValue = rand() % 10000 + 70000;

    //Check if number is already in tree
    Faculty newFaculty(randomValue);

    if(facultyTree.IfSearchNode(newFaculty))
    {
      valid = false;
    }
    else
    {
      valid = true;
    }

    valid = true;


  } while(!valid);

  return randomValue;
}

//Serialiization
void SchoolDatabase :: SerializeStudents()
{
  ofstream oFile;

  oFile.open("masterStudent");

  studentTree.SerializeStudentBST(oFile);

  oFile.close();
}
void SchoolDatabase :: SerializeFaculty()
{
  ofstream oFile;

  oFile.open("masterFaculty");

  facultyTree.SerializeFacultyBST(oFile);

  oFile.close();
}
void SchoolDatabase :: DeserializeStudents(string fileName)
{
  int    newID;
  string newFirstName;
  string newLastName;
  string newStudentLevel;
  string newMajor;
  float  newGPA;
  int    newAdvisorID;

  ifstream inFile;

  inFile.open(fileName);

  while(true)
  {
    inFile >> newID;
    if(inFile.eof())
    {
      break;
    }
    if(inFile.fail())
    {
      inFile.clear();
      throw "Sorry, file not formatted correctly\n";
    }
    inFile.ignore(100000000, '\n');

    getline(inFile, newFirstName);

    getline(inFile, newLastName);

    getline(inFile, newStudentLevel);

    getline(inFile, newMajor);

    inFile >> newGPA;

    inFile >> newAdvisorID;

    //clearing blank line between students
    inFile.ignore(100000000, '\n');

    Student newStudent(newID, newFirstName, newLastName, newStudentLevel,
      newMajor, newGPA, newAdvisorID);

    studentTree.InsertNode(newStudent);
  }

  inFile.close();
}
void SchoolDatabase :: DeserializeFaculty(string fileName)
{
  int    newID;
  string newFirstName;
  string newLastName;
  string newFacultyLevel;
  string newDepartment;
  string dummyString;
  int    newAdviseeID;

  ifstream inFile;

  inFile.open(fileName);

  while(true)
  {
    DoublyLinkedList<int> newAdviseesIDsList;

    inFile >> newID;
    if(inFile.eof())
    {
      break;
    }
    if(inFile.fail())
    {
      inFile.clear();
      throw "Sorry, file not formatted correctly\n";
    }
    inFile.ignore(100000000, '\n');

    getline(inFile, newFirstName);

    getline(inFile, newLastName);

    getline(inFile, newFacultyLevel);

    getline(inFile, newDepartment);


    do
    {
      getline(inFile, dummyString);

      if(dummyString.length() == 0 || inFile.eof())
      {
        break;
      }

      istringstream(dummyString) >> newAdviseeID;

      newAdviseesIDsList.InsertBack(newAdviseeID);

    } while(true);

    //clearing blank line between students
    //inFile.ignore(100000000, '\n');

    Faculty newFaculty(newID, newFirstName, newLastName, newFacultyLevel,
      newDepartment, newAdviseesIDsList);

    facultyTree.InsertNode(newFaculty);
  }

  inFile.close();
}
void SchoolDatabase :: AddStudentIDToFacultyTree(int facultyID, int newStudentID)
{
  Faculty tempFaculty(facultyID);

  TreeNode<Faculty>* designatedFaculty = facultyTree.ReturnPointerToNode(tempFaculty);

  designatedFaculty -> key.AddAdvisee(newStudentID);
}
void SchoolDatabase :: RemoveStudentIDFromFacultyTree(int facultyID, int newStudentID)
{
  Faculty tempFaculty(facultyID);

  TreeNode<Faculty>* designatedFaculty = facultyTree.ReturnPointerToNode(tempFaculty);

  designatedFaculty -> key.RemoveAdvisee(newStudentID);
}
