#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

const int MAX_VEHICLE_TYPES = 2;

class VehicleType {
public:
    VehicleType(const string* types, int numTypes) {
        for (int i = 0; i < numTypes; i++) {
            this->types[i] = types[i];
        }
        this->numTypes = numTypes;
    }

    void availableVehicles() {
        cout << "Available vehicle types: ";
        for (int i = 0; i < numTypes; i++) {
            cout << types[i] << " ";
        }
        cout << endl;
    }
	bool chooseVehicle(const string& vehicle) {
	    bool found = false;
	    for (int i = 0; i < numTypes; i++) {
	        if (vehicle == types[i]) {
	            cout << "Selected vehicle type: " << vehicle << endl;
	            found = true;
	            break;
	        }
	    }
	    if (!found) {
	        cout << "This vehicle is not available" << endl;
	    }
	    return found; // Return the value of 'found'
	}

private:
    string types[MAX_VEHICLE_TYPES];
    int numTypes;
};

class Vehicle {
public:
    Vehicle(string name, string number, string color, int model) {
        this->name = name;
        this->number = number;
        this->color = color;
        this->model = model;
    }

    void Display() {
        cout<<"\t\t\t" << "Name: " << name << endl;
        cout<<"\t\t\t" << "Number: " << number << endl;
        cout<<"\t\t\t" << "Color: " << color << endl;
        cout<<"\t\t\t" << "Model: " << model << endl;
    }

private:
    string name;
    string number;
    string color;
    int model;
};

class Captain {
public:
    Captain(string captainName, int Id, long mobileNumber, double rating) {
        this->captainName = captainName;
        this->Id = Id;
        this->mobileNumber = mobileNumber;
        this->rating = rating;
    }

    void Display() {
        cout<<"\t\t\t" << "Captain Name: " << captainName << endl;
        cout<<"\t\t\t" << "Captain ID: " << Id << endl;
        cout<<"\t\t\t" << "Captain Mobile Number: " << mobileNumber << endl;
        cout<<"\t\t\t" << "Captain Rating: " << rating << endl;
    }

private:
    string captainName;
    int Id;
    long mobileNumber;
    double rating;
};

class Car : public Vehicle, public Captain {
public:
    Car(string name, string number, string color, int model, string captainName, int Id, long mobileNumber, double rating, double carRating)
        : Vehicle(name, number, color, model), Captain(captainName, Id, mobileNumber, rating) {
        this->carRating = carRating;
    }

    void Display() {
        cout << "The vehicle type is Car" << endl;
        Vehicle::Display();
        Captain::Display();
        cout <<"\t\t\t"<< "Car Rating: " << carRating << endl;
    }

private:
    double carRating;
};

class Bike : public Vehicle, public Captain {
public:
    Bike(string name, string number, string color, int model, string captainName, int Id, long mobileNumber, double rating, double bikeRating)
        : Vehicle(name, number, color, model), Captain(captainName, Id, mobileNumber, rating) {
        this->bikeRating = bikeRating;
    }

    void Display() {
        cout << "The vehicle type is Bike" << endl;
        Vehicle::Display();
        Captain::Display();
        cout <<"\t\t\t"<< "Bike Rating: " << bikeRating << endl;
    }

private:
    double bikeRating;
};


class User {
public:
    User(string userName, long userMobnum, string userAddress, string userCity) {
        this->userName = userName;
        this->userMobnum = userMobnum;
        this->userAddress = userAddress;
        this->userCity = userCity;
    } // Default constructor

    void Display() {
        cout << "User Name: " << userName << endl;
        cout << "User Mobile Number: " << userMobnum << endl;
        cout << "User Address: " << userAddress << endl;
        cout << "User City: " << userCity << endl;
    }

private:
    string userName;
    long userMobnum;
    string userAddress;
    string userCity;
};


class RideRequest {
public:
    RideRequest(string f1, string f2, string f3, string f4, string f5, string f6, string f7, int fare1, int fare2, int fare3, int fare4, int fare5, int fare6, int fare7,
        string captainName, int Id, long mobileNumber, double rating, string userName, long userMobnum, string userAddress, string userCity)
        : captain(captainName, Id, mobileNumber, rating), user(userName, userMobnum, userAddress, userCity) {
        this->f1 = f1;
        this->f2 = f2;
        this->f3 = f3;
        this->f4 = f4;
        this->f5 = f5;
        this->f6 = f6;
        this->f7 = f7;
        this->fare1 = fare1;
        this->fare2 = fare2;
        this->fare3 = fare3;
        this->fare4 = fare4;
        this->fare5 = fare5;
        this->fare6 = fare6;
        this->fare7 = fare7;
    }

    void availableRoutes() {
        ifstream file("routes.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        }
    }

    void book(string select) {
        if (select == f1) {
            cout << "You have chosen the route from DHA to FCCU. The fare is " << fare1 << " rupees" << endl;
        }
        else if (select == f2) {
            cout << "You have chosen the route from Model Town to Johar Town. The fare is " << fare2 << " rupees" << endl;
        }
        else if (select == f3) {
            cout << "You have chosen the route from Shahi Qila to Gulberg. The fare is " << fare3 << " rupees" << endl;
        }
        else if (select == f4) {
            cout << "You have chosen the route from MughalPura to Bahria Town. The fare is " << fare4 << " rupees" << endl;
        }
        else if (select == f5) {
            cout << "You have chosen the route from Shahdra to Gulshan Ravi. The fare is " << fare5 << " rupees" << endl;
        }
        else if (select == f6) {
            cout << "Your have chosen the route from Wapda Town to Gulberg. The fare is " << fare6 << " rupees" << endl;
        }
        else if (select == f7) {
            cout << "You have chosen the route from Chubarji to Lohari Gate. The fare is " << fare7 << " rupees" << endl;
        }
        else {
            cout << "Sorry, you have not selected the right route" << endl;
        }
    }

    void fareReceipt(string select) {
        if (select == f1) {
            user.Display();
            cout << "Destination: DHA to FCCU" << endl;
            cout << "Fare: 500 rupees" << endl;
        }
        else if (select == f2) {
            user.Display();
            cout << "Destination: Model Town to Johar Town" << endl;
            cout << "Fare: 350 rupees" << endl;
        }
        else if (select == f3) {
        	
            user.Display();
            cout << "Destination: Shahi Qila to Gulberg" << endl;
            cout << "Fare: 700 rupees" << endl;
        }
        else if (select == f4) {
            user.Display();
            cout << "Destination: MughalPura to Bahria Town" << endl;
            cout << "Fare: 1200 rupees" << endl;
        }
        else if (select == f5) {
            user.Display();
            cout << "Destination: Shahdra to Gulshan Ravi" << endl;
            cout << "Fare: 400 rupees" << endl;
        }
        else if (select == f6) {
            user.Display();
            cout << "Destination: Wapda Town to Gulberg" << endl;
            cout << "Fare: 630 rupees" << endl;
        }
        else if (select == f7) {
            user.Display();
            cout << "Destination: Chubarji to Lohari Gate" << endl;
            cout << "Fare: 950 rupees" << endl;
        }
        else {
            cout << "No receipt available as you have selected the wrong route" << endl;
        }
    }

private:
    string f1;
    string f2;
    string f3;
    string f4;
    string f5;
    string f6;
    string f7;
    int fare1;
    int fare2;
    int fare3;
    int fare4;
    int fare5;
    int fare6;
    int fare7;
    Captain captain;
    User user;
};

class FeedBack {
public:
    FeedBack(string comments, int starRating) {
        this->comments = comments;
        this->starRating = starRating;
    }

    void Display() {
        cout <<"Your feedback: "<< comments <<endl<< "Rating:" << starRating << endl;
    }

private:
    string comments;
    int starRating;
    
};

void saveFeedbackToFile(const string& username, const string& feedback, float rating) {
    ofstream feedbackFile("feedback.txt", ios::app); // Open file in append mode
    if (feedbackFile.is_open()) {
        feedbackFile << "Username: " << username << endl; // Write username to file
        feedbackFile << "Feedback: " << feedback << endl; // Write feedback to file
        feedbackFile << "Rating: " << rating << endl; // Write rating to file
        feedbackFile << "------------------------" << endl; // Separator for multiple feedbacks
        feedbackFile.close(); // Close the file
    } else {
        cout << "Error opening 'feedback.txt' file for writing." << endl;
    }
}

void menu() {
    cout << "******Welcome to TAXI Service*****" << endl;
    cout << endl;
    cout << "1  View Vehicles" << endl;
    cout << "2  Choose Vehicle" << endl;
    cout << "3  Add booking" << endl;
    cout << "4  Confirm booking" << endl;
    cout << "5  Shows captain details" << endl;
    cout << "6  Give feedback" << endl;
    cout << "7  Exit" << endl;
}

int main() {
    menu();
    
    string vehicleTypes[MAX_VEHICLE_TYPES] = { "car", "bike" };
    VehicleType vehicaltypeobj(vehicleTypes, MAX_VEHICLE_TYPES);
    Car carobj("Honda City", "LE-000", "White", 2018, "Ali", 546, 3245825425, 4.5, 4.0);
    Bike bikeobj("Honda CG-125", "LE-001", "Red", 2020, "Ahmed", 689, 5465824562, 4.2, 3.5);
    RideRequest rideobj("f1","f2","f3","f4","f5","f6","f7", 500, 350, 700, 1200, 400, 630, 950, "Ali", 546, 3245825425, 4.5, "Ali", 546, "123, Street ABC", "Lahore");
    FeedBack feedbackobj("", 0.0);

    int choice;
    string vehicle;
    bool isVehicleSelected = false;
    bool isVehicleValid ;
    string route;
    string booking;
    string feedback;
    string userName;
    long userMobnum;
    string userAddress;
    string userCity;
    string input;
    string x;
    float rating;
    bool add_booking = false;
    User user("", 0, "", ""); // Declare the 'User user' variable outside the switch statement
    
    while (true) {
        cout << endl;
        cout << "Enter option number: ";
        cin >> choice;
		if (cin.fail() || choice < 1 || choice > 7) {
		    cout << "Error! Please enter a valid option number." << endl;
		    cin.clear(); // Clear the error state of cin
		    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining characters in the input buffer
		    continue; // Continue with the next iteration of the main loop
		}

        switch (choice) {
            case 1:
                vehicaltypeobj.availableVehicles();
                break;
            case 2:
            
                cout << "Enter the vehicle type Car or Bike: ";
                cin >> vehicle;
                for (size_t i = 0; i < vehicle.length(); i++) {
			        vehicle[i] = tolower(vehicle[i]);
			    }
                isVehicleValid = vehicaltypeobj.chooseVehicle(vehicle);
			    if (isVehicleValid) {
			        isVehicleSelected = true; // Set the flag indicating valid vehicle selection
			        cout << "Press 3 to add booking"<<endl;
			    }
                break;
            case 3:
            	if (isVehicleSelected) {
	                cout << "Enter your name: ";
	                cin.ignore(); // Ignore the newline character in the input buffer
	                getline(cin, userName);
	                cout << "Enter your mobile number: ";
					while (!(cin >> userMobnum)) {
					    cout << "Invalid input. Please enter a valid mobile number: ";
					    cin.clear();  // Clear the error state
					    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore remaining characters in the input buffer
					}
					cin.ignore();  // Ignore the newline character in the input buffer// Ignore the newline character in the input buffer
	            
	                cout << "Enter your address: ";
	                cin.ignore(); // Ignore the newline character in the input buffer
	                getline(cin, userAddress);
	            
	                cout << "Enter your city: ";
	                getline(cin, userCity);
	                
	                user = User(userName, userMobnum, userAddress, userCity); // Initialize the 'User user' variable with user input
	                user.Display();
	                rideobj.availableRoutes();
	                
	                while (true) {
		                cout << "(f1), (f2), (f3), (f4), (f5), (f6), (f7) Choose from the available route numbers: ";
					    cin >> input;
					    if (input == "f1" || input == "f2" || input == "f3" || input == "f4" || input == "f5" || input == "f6" || input == "f7") {
					        // Input is valid, break out of the loop
					        break;
					    } else {
					        cout << "Invalid input. Please choose a valid route number:"<<endl;
						    }
					}
					add_booking = true;
	                rideobj.book(input);
	                cout<<"Press 4 to comfirm booking"<<endl;
	            } else {
			        cout << "Error! You have not made a vehicle selection. Please choose a vehicle before proceeding." << endl;
			    }
                break;
            case 4:
            	if (add_booking) {
	                cout << "If you want the ride press(yes/no): ";
				    cin.ignore(); // Ignore the newline character in the input buffer
    				getline(cin, x);
					for (size_t z = 0; z < x.length(); z++) {
				        x[z] = tolower(x[z]);
				    }
				    if (x == "yes") {
				        cout << "Your booking has been confirmed" << endl;
				        cout << "Press 5 to see captain details" << endl;
				    }
				    else if (x == "no") {
				        cout << "Thank you for your interest" << endl;
				        main();
				    }
				} else {
			        cout << "Error! Please confirm the booking first before proceeding.." << endl;
			    }
                break;
            case 5:
			    
			    if (vehicle == "car") {
			    	cout << "Details are as follows:" << endl;
			        carobj.Display();
			    }
			    else if (vehicle == "bike") {
			    	cout << "Details are as follows:" << endl;
			        bikeobj.Display();
			    }
			    else {
			        cout << "Error! You have not made a vehicle selection. Please choose a vehicle before proceeding." << endl;
			        continue;
			    }
			    break;
            case 6:
            	if (add_booking) {
	                cin.ignore(); // Ignore the newline character in the input buffer
				    cout << "Enter your feedback: ";
				    getline(cin, feedback);
				    cout << "Enter your rating between (1-5): ";
				    cin >> rating;
				    feedbackobj= FeedBack(feedback,rating);
				    feedbackobj.Display();
				    saveFeedbackToFile(userName, feedback, rating); // Call the function to save feedback to file
				} else {
			        cout << "Error! Please confirm the booking first before proceeding." << endl;
			    }
                break;
            case 7:
                cout << "Thank you for using the TAXI Service!" << endl;
	            while (true) {
				    cout << "Do you want to ride again? (yes/no): ";
				    string rideAgain;
				    cin >> rideAgain;
				    // Convert the input to lowercase
				    for (size_t j = 0; j < rideAgain.length(); j++) {
					        rideAgain[j] = tolower(rideAgain[j]);
					    }
				    if (rideAgain == "no") {
				        cout << "Thank you for using the TAXI Service!" << endl;
				        return 0; // Exit the loop and end the program
				    } else if (rideAgain == "yes") {
				        // Continue with the next iteration of the main loop
				        main();
				        break;
				    } else {
				        cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
				    }
				}

        }
       
    
    }

    return 0;
}

