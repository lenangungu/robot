using namespace std;
#include<iostream>
#include <string>
#include <vector>
#include <sstream>

class Robot_part
{
protected:
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
    Head(){}
    Head(string name, int model_number, string description, string image_filename, double power)
    {
    name = name;
    model_number = model_number;
    description = description;
    image_filename = image_filename;
    power = power;
    }

    string get_name()
    {
   stringstream name_out;
   name_out << name;
   return name_out.str();
    }

};

class Arm : public Robot_part
{
private:
    double max_power;

public:
Arm(){}
    Arm(string name, int model_number, string description, string image_filename, double max_power)
    {
    name = name;
    model_number = model_number;
    description = description;
    image_filename = image_filename;
    max_power = max_power;
    }
string get_name()
    {
    stringstream name_out;
   name_out << name;
   return name_out.str();
    }

};
class Battery : public Robot_part
{
private:
    double power_available;
    double max_energy;

public:
Battery(){}
    Battery(string name, int model_number, string description, string image_filename, double power_available, double max_energy)
    {
    name = name;
    model_number = model_number;
    description = description;
    image_filename = image_filename;
    power_available = power_available;
    max_energy = max_energy;
    }
string get_name()
    {
     stringstream name_out;
   name_out << name;
   return name_out.str();
    }
};
class Torso : public Robot_part
{
private:
    int battery_components;
    int max_arms;

public:
    Torso(){}
    Torso(string name, int model_number, string description, string image_filename, int battery_components, int max_arms)
    {
    name = name;
    model_number = model_number;
    description = description;
    image_filename = image_filename;
    battery_components = battery_components;
    max_arms = max_arms;
    }
string get_name()
    {
    stringstream name_out;
   name_out << name;
   return name_out.str();
    }
};

class Locomotor : public Robot_part
{
private:
    double max_power;

public:
Locomotor(){}
    Locomotor(string name, int model_number, string description, string image_filename, double max_power){
    name = name;
    model_number = model_number;
    description = description;
    image_filename = image_filename;
    max_power = max_power;
    }

 string get_name()
    {
     stringstream name_out;
   name_out << name;
   return name_out.str();
    }
};


class Robot_model
{
protected:
    string name;
    int model_number;
    Torso torso;
    Head head;
    Locomotor locomotor;
    Arm arm;
    Battery battery;

public:
    Robot_model(string name, int model_number, Head head, Torso torso, Arm arm, Locomotor locomotor, Battery battery)
    {
    name = name;

    model_number = model_number;
    torso = torso;
    head = head;
    locomotor = locomotor;
    arm = arm;
    battery = battery;
    }

    string get_model()
    {
      stringstream model_out;
   model_out << "Model " << name << " " << "Number " << model_number << "With: " << torso.get_name() << "," << head.get_name() <<"," << arm.get_name() <<","<<battery.get_name()<<","<<locomotor.get_name()<<endl;
   return model_out.str();
    }
    double cost();
    double max_speed();
    double max_battery_life();


};

int main ()

{
vector <Robot_model> models;
vector<Head> heads;
vector<Torso> torsos;
vector<Arm> arms;
vector<Battery> batteries;
vector<Locomotor> locomotors;

string model_name;
int model_number;
string yes = "n";
int option;
do
{

cout << "1) Create a Model" << endl << "2) Create parts" << endl << "3) List models" << endl << "9 to exit" << endl;
cin >> option;
cin.ignore();

switch(option)
{
case 1:
{
cout << "Enter the Model's name" << endl;
getline(cin,model_name);

cout << "Enter the model's number" << endl;
cin >> model_number;
cin.ignore();

// HEADS
int head_i;
cout << "Enter number of the head to add to your model" << endl;
cout << "Heads: " << endl;

for (int i = 0; i < heads.size(); i++)
{
cout << i+1 << ")" << heads[i].get_name() << endl;

}
cin >> head_i;
cin.ignore();

//TORSOS
int torso_i;
cout << "Enter number of the torso to add to your model" << endl;
cout << "Torsos: " << endl;

for (int i = 0; i < torsos.size(); i++)
{
cout << i+1 << ")" << torsos[i].get_name() << endl;

}
cin >> torso_i;
cin.ignore();

//ARMS
int arm_i;
cout << "Enter number of the arm to add to your model" << endl;
cout << "Arms: " << endl;

for (int i = 0; i < arms.size(); i++)
{
cout << i+1 << ")" << arms[i].get_name() << endl;

}
cin >> arm_i;
cin.ignore();

//Battery
int battery_i;
cout << "Enter number of the battery to add to your model" << endl;
cout << "Batteries: " << endl;

for (int i = 0; i < batteries.size(); i++)
{
cout << i+1 << ")" << batteries[i].get_name() << endl;

}
cin >> battery_i;
cin.ignore();

//LOCOMOTORS
int locomotor_i;
cout << "Enter number of the locomotor to add to your model" << endl;
cout << "Locomotors: " << endl;

for (int i = 0; i < locomotors.size(); i++)
{
cout << i+1 << ")" << locomotors[i].get_name() << endl;

}
cin >> locomotor_i;
cin.ignore();


Robot_model model(model_name, model_number,heads[head_i-1],torsos[torso_i -1],arms[arm_i -1],locomotors[locomotor_i -1],batteries[battery_i -1]);
models.push_back(model);

break;

}

case 2:
{
int part;

cout << endl;
cout << "1) Head" << endl << "2) Arm " << endl << "3) Battery" << endl << "4) Torso" << endl << "5) Locomotor" << endl;
cout << endl;
cout << "What part do you want to create and add to the model? 0 to exit or to create another model" << endl;
cin >> part;
cin.ignore();

switch (part)
{
do
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

           //Head
       Head my_head =  Head(name, model_number, description, image_filename, power);
        heads.push_back(my_head);
           cout << endl;
           cout << "***Head " << name << " was created and added to " << model_name<< "****" << endl;
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

           //Arm
          Arm my_arm =  Arm(name, model_number, description, image_filename,max_power);
           arms.push_back(my_arm);
            cout << endl;
            cout << "***Arm " << " was created and added to " << model_name<< "****" << endl;
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

           //Battery
         Battery my_battery = Battery(name, model_number, description, image_filename,power_available,max_energy);
           batteries.push_back(my_battery);
            cout << endl;
            cout << "***Baterry " << name << " was created and added to " << model_name<< "****" << endl;
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

           //Torso
          Torso my_torso = Torso(name, model_number, description, image_filename,battery_compartments,max_arms);
           torsos.push_back(my_torso);
            cout << endl;
            cout << "***Torso " << name << " was created and added to " << model_name<< "****" << endl;
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

           //Locomotor
          Locomotor my_locomotor =  Locomotor(name, model_number, description, image_filename,max_power);
           locomotors.push_back(my_locomotor);
            cout << endl;
            cout << "***Locomotor " << name << " was created and added to " << model_name<< "****" << endl;
            break;
}


}while (part != 0);
//create a model with all the given parts
}

break;
}


case 3:
{
cout << "List of models: " << endl;
for(int i =0; i<models.size();i++)
{
models[i].get_model();
}
cout << endl;
break;
}


}

}while(option != 9);



return 0;
}

//g++ -o robot_parts robot_parts.cpp ./robot_parts
// create Robot part class
//implement the robot part class
// create arm, head, locomotor, torso and battery classes
// make each class inherit from robot part
// provide additonal attribute to each class
