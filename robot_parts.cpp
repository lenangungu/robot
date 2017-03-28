using namespace std;
#include<iostream>
#include <string>

class Robot_part
{
private:
    string name;
    int model_number;
    string description;
    string image_filename;
};

class Head : public Robot_part
{
private:
    double power;
public:
    Head(string name, int model_number, string description, string image_filename, double power)
    {
    name = name;
    model_number = model_number;
    description = description;
    image_filename = image_filename;
    power = power;
    }
};

class Arm : public Robot_part
{
private:
    double max_power;

public:
    Arm(string name, int model_number, string description, string image_filename, double max_power)
    {
    name = name;
    model_number = model_number;
    description = description;
    image_filename = image_filename;
    max_power = max_power;
    }


};
class Battery : public Robot_part
{
private:
    double power_available;
    double max_energy;

public:
    Battery(string name, int model_number, string description, string image_filename, double power_available, double max_energy)
    {
    name = name;
    model_number = model_number;
    description = description;
    image_filename = image_filename;
    power_available = power_available;
    max_energy = max_energy;
    }

};
class Torso : public Robot_part
{
private:
    int battery_components;
    int max_arms;

public:
    Torso(string name, int model_number, string description, string image_filename, int battery_components, int max_arms)
    {
    name = name;
    model_number = model_number;
    description = description;
    image_filename = image_filename;
    battery_components = battery_components;
    max_arms = max_arms;
    }
};

class Locomotor : public Robot_part
{
private:
    double max_power;

public:
    Locomotor(string name, int model_number, string description, string image_filename, double max_power)
    {
    name = name;
    model_number = model_number;
    description = description;
    image_filename = image_filename;
    max_power = max_power;
    }
};


int main ()

{
int part;
do
{
for(int i = 0; i < 5; i++){cout << endl;}

cout << "1) Head" << endl << "2) Arm " << endl << "3) Battery" << endl << "4) Torso" << endl << "5) Locomotor" << endl;
cout << endl;
cout << "What part do you want to create? 0 to exit" << endl;
cin >> part;
cin.ignore();

switch (part)
{
case 1:
{
            int model_number;
            string name;
            string description;
            string image_filename;
            int power;
            cout << "Name the head" << endl;
            getline(cin,name);
            cout << "Model number?" << endl;
            cin >> model_number;
            cin.ignore();
            cout << "Description?" << endl;
            getline(cin,description);
            cout << "Power? (in Watt)" << endl;
            cin >> power;
            cin.ignore();

           Head my_head = Head(name, model_number, description, image_filename, power);
           cout << endl;
           cout << "***Head " << name << " was created***" << endl;
            break;
}

case 2:
{
            int model_number;
            string name;
            string description;
            string image_filename;
            int max_power;
            cout << "Name the arm" << endl;
            getline(cin,name);
            cout << "Model number?" << endl;
            cin >> model_number;
            cin.ignore();
            cout << "Description?" << endl;
            getline(cin,description);
            cout << "Max Power? (in Watt)" << endl;
            cin >> max_power;
            cin.ignore();

           Arm my_arm = Arm(name, model_number, description, image_filename,max_power);

            cout << endl;
            cout << "**8Arm " << " was created***" << endl;
            break;
}

case 3:
{
            int model_number;
            string name;
            string description;
            string image_filename;
            int power_available;
            int max_energy;
            cout << "Name the battery" << endl;
            getline(cin,name);
            cout << "Model number?" << endl;
            cin >> model_number;
            cin.ignore();
            cout << "Description?" << endl;
            getline(cin,description);
            cout << "Power available? (in Watt)" << endl;
            cin >> power_available;
            cin.ignore();
            cout << "Max energy? "<< endl;
            cin >> max_energy;
            cin.ignore();

           Battery my_battery = Battery(name, model_number, description, image_filename,power_available,max_energy);
            cout << endl;
            cout << "***Baterry " << name << " was created***" << endl;
            break;
}
case 4:
{
            int model_number;
            string name;
            string description;
            string image_filename;
            int battery_compartments;
            int max_arms;
            cout << "Name the torso" << endl;
            getline(cin,name);
            cout << "Model number?" << endl;
            cin >> model_number;
            cin.ignore();
            cout << "Description?" << endl;
            getline(cin,description);
            cout << "How many battery compartment?" << endl;
            cin >> battery_compartments;
            cin.ignore();
            cout << "Max arms "<< endl;
            cin >> max_arms;
            cin.ignore();

           Torso my_torso = Torso(name, model_number, description, image_filename,battery_compartments,max_arms);
            cout << endl;
            cout << "***Torso " << name << " was created***" << endl;
            break;
}
case 5:
{
            int model_number;
            string name;
            string description;
            string image_filename;
            double max_power;
            cout << "Name the locomotor" << endl;
            getline(cin,name);
            cout << "Model number?" << endl;
            cin >> model_number;
            cin.ignore();
            cout << "Description?" << endl;
            getline(cin,description);
            cout << "Max power? "<< endl;
            cin >> max_power;
            cin.ignore();

           Locomotor my_locomotor = Locomotor(name, model_number, description, image_filename,max_power);
            cout << endl;
            cout << "***Locomotor " << name << " was created***" << endl;
            break;
}


}

}while (part != 0);
return 0;
}

//g++ -o robot_parts robot_parts.cpp ./robot_parts
// create Robot part class
//implement the robot part class
// create arm, head, locomotor, torso and battery classes
// make each class inherit from robot part
// provide additonal attribute to each class
