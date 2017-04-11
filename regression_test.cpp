#include <iostream>
#include <fstream>
#include <sstream>
#include "robot_part.h"
#include "utility.h"
using namespace std;

int main() {

  Head *head;
  Arm *arm;
  Torso *torso;
  Locomotor *locomotor;
  Battery *battery;
  Robot_model *model;
  Customer *customer;
  Sale_associate *sale_associate;
  Order *order;

  ifstream ist{"robot.txt"};
  int object = 0;  // count test objects for error msgs

  while(!ist.eof()) {
    ++object;
    string expected;
    ostringstream oss;
    switch (get_int(ist)) {
      case 9: // Exit
        exit(0);

      case 1:
        {

        string name = get_string(ist);
int model_number = get_int(ist);
head = new Head{
get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist)};
torso = new Torso{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_int(ist),get_int(ist)};
arm = new Arm{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist)};
locomotor = new Locomotor{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist)};
battery = new Battery{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist),get_double(ist)};

model = new Robot_model{name,model_number,*head,*torso,*arm,*locomotor,*battery};
expected = get_string(ist) + '\n' + get_string(ist);
oss << *model;

        break;}


      case 2:
      {
      switch (get_int(ist))
      {
      case 1: // Head
        head = new Head{
          get_string(ist),
          get_int(ist),
          get_double(ist),
          get_string(ist),
          get_double(ist)
        };
        expected = get_string(ist) + '\n' + get_string(ist);
        oss << *head;
        if (oss.str() != expected) {
          cerr << "FAIL: (Head) Object " << object << endl;
          cerr << "Expected:" << endl << expected << endl;
          cerr << "Created:" << endl << oss.str() << endl;
        }
        break;
      case 2:
        arm = new Arm{
          get_string(ist),
          get_int(ist),
          get_double(ist),
          get_string(ist),
          get_double(ist)
        };
        expected = get_string(ist) + '\n' + get_string(ist);
        oss << *arm;
        if (oss.str() != expected) {
          cerr << "FAIL: (Arm) Object " << object << endl;
          cerr << "Expected:" << endl << expected << endl;
          cerr << "Created:" << endl << oss.str() << endl;
        }
        break;
      case 3:
        torso = new Torso{
          get_string(ist),
          get_int(ist),
          get_double(ist),
          get_string(ist),
          get_int(ist),
          get_int(ist)
        };
        expected = get_string(ist) + '\n' + get_string(ist);
        oss << *torso;
        if (oss.str() != expected) {
          cerr << "FAIL: (Torso) Object " << object << endl;
          cerr << "Expected:" << endl << expected << endl;
          cerr << "Created:" << endl << oss.str() << endl;
        }
        break;
      case 4:
        locomotor = new Locomotor{
          get_string(ist),
          get_int(ist),
          get_double(ist),
          get_string(ist),
          get_double(ist),
        };
        expected = get_string(ist) + '\n' + get_string(ist);
        oss << *locomotor;
        if (oss.str() != expected) {
          cerr << "FAIL: (Locomotor) Object " << object << endl;
          cerr << "Expected:" << endl << expected << endl;
          cerr << "Created:" << endl << oss.str() << endl;
        }
        break;
      case 5:
        battery = new Battery{
          get_string(ist),
          get_int(ist),
          get_double(ist),
          get_string(ist),
          get_double(ist),
          get_double(ist),
        };
        expected = get_string(ist) + '\n' + get_string(ist);
        oss << *battery;
        if (oss.str() != expected) {
          cerr << "FAIL: (Battery) Object " << object << endl;
          cerr << "Expected:" << endl << expected << endl;
          cerr << "Created:" << endl << oss.str() << endl;
        }
        break;
      default:

        cerr << "Impossible menu selection ===" << endl << endl;
        }
   break;
    }
    case 4:
    {
    customer = new Customer{get_string(ist),get_int(ist),get_string(ist),get_string(ist)};
    expected = get_string(ist) + '\n' + get_string(ist);
    oss << *customer;


    break;}

    case 5:
    {
    sale_associate = new Sale_associate{get_string(ist),get_int(ist)};
    expected = get_string(ist) + '\n' + get_string(ist);
    oss << *sale_associate;

    break;}

    case 6:
    {
int order_number = get_int(ist);
string date = get_string(ist);
customer = new Customer{get_string(ist),get_int(ist),get_string(ist),get_string(ist)};
sale_associate = new Sale_associate{get_string(ist),get_int(ist)};
string name = get_string(ist);
int model_number = get_int(ist);
head = new Head{
get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist)};
torso = new Torso{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_int(ist),get_int(ist)};
arm = new Arm{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist)};
locomotor = new Locomotor{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist)};
battery = new Battery{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist),get_double(ist)};

model = new Robot_model{name,model_number,*head,*torso,*arm,*locomotor,*battery};

expected =  get_string(ist) + '\n' + get_string(ist);
oss << *model;

    break;}

    }
  }
}
