#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

class Food{
    private:
        double distance; //in miles from the student center
        string name; //of place
        int price; //1-$ 2-$$ 3-$$
    public:
        Food(string nameInp, double distInp, int priceInp){
            name = nameInp;
            distance = distInp;
            price = priceInp;
        }
        double getDistance(){
            return distance;
        }
        void setDistance(double distInp){
            distance = distInp;
        }
        string getName(){
            return name;
        }
        void setName(string nameInp){
            name = nameInp;
        }
        int getPrice(){
            return price;
        }
        void setPrice(int priceInp){
            price = priceInp;
        }
        void print(){
            cout << name << ":\t" << distance << " miles away" << endl;
        }
};

struct Node{
    Food *place;
    Node *next;
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            head = NULL;
        }
        Node* getHead(){
            return head;
        }
        void setHead(Node* n){
            head = n;
        }
        void append(Food* obj){ 
            Node* newPtr = new Node;
            newPtr->place = obj;
            newPtr->next = NULL;

            if (head == NULL)
                head = newPtr;
            else{
                Node* temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newPtr;
            }
        }
        void printLL(){
            Node* temp = head;
            while (temp != NULL){
                cout << temp->place->getName() << " " << temp->place->getDistance()  << " " << temp->place->getPrice() << endl;
                temp = temp->next;
            }
        }
        void search(int moneyOption){
            Node* temp = head;
            while (temp != NULL){
                if (temp->place->getPrice() <= moneyOption )
                    temp->place->print();
            temp = temp->next;
            }
        }
};

int main(){  
    LinkedList italian;
    ifstream textFile;
    string restaurantName;
    string tempString;
    int price;
    double distance;

    textFile.open("italian.txt", ios::in);
    while (!textFile.eof()){
        restaurantName = "";
        textFile >> tempString;
        restaurantName = restaurantName + tempString;
        textFile >> tempString;
        while (tempString != "0"){
            restaurantName = restaurantName + " " + tempString;
            textFile >> tempString;
        }
        textFile >> tempString;
        price = stoi(tempString);
        textFile >> tempString;
        distance = stod(tempString);
        Food* obj = new Food(restaurantName, distance, price);
        italian.append(obj);
    }
    textFile.close();
    

    textFile.open("FastFood.txt", ios::in);
    LinkedList FF;
    while (!textFile.eof()){
        restaurantName = "";
        textFile >> tempString;
        restaurantName = restaurantName + tempString;
        textFile >> tempString;
        while (tempString != "0"){
            restaurantName = restaurantName + " " + tempString;
            textFile >> tempString;
        }
        textFile >> tempString;
        price = stoi(tempString);
        textFile >> tempString;
        distance = stod(tempString);
        Food* obj = new Food(restaurantName, distance, price);
        FF.append(obj);
    }
    textFile.close();
 
    textFile.open("asian.txt", ios::in);
    LinkedList asian;
    while (!textFile.eof()){
        restaurantName = "";
        textFile >> tempString;
        restaurantName = restaurantName + tempString;
        textFile >> tempString;
        while (tempString != "0"){
            restaurantName = restaurantName + " " + tempString;
            textFile >> tempString;
        }
        textFile >> tempString;
        price = stoi(tempString);
        textFile >> tempString;
        distance = stod(tempString);
        Food* obj = new Food(restaurantName, distance, price);
        asian.append(obj);
    }
    textFile.close();

    textFile.open("GeneralRestaurants.txt", ios::in);
    LinkedList GR;
    while (!textFile.eof()){
        restaurantName = "";
        textFile >> tempString;
        restaurantName = restaurantName + tempString;
        textFile >> tempString;
        while (tempString != "0"){
            restaurantName = restaurantName + " " + tempString;
            textFile >> tempString;
        }
        textFile >> tempString;
        price = stoi(tempString);
        textFile >> tempString;
        distance = stod(tempString);
        Food* obj = new Food(restaurantName, distance, price);
        GR.append(obj);
    }
    textFile.close();
       
    textFile.open("MexicanRestaurants.txt", ios::in);
    LinkedList mexicanhispanic;
    while (!textFile.eof()){
        restaurantName = "";
        textFile >> tempString;
        restaurantName = restaurantName + tempString;
        textFile >> tempString;
        while (tempString != "0"){
            restaurantName = restaurantName + " " + tempString;
            textFile >> tempString;
        }
        textFile >> tempString;
        price = stoi(tempString);
        textFile >> tempString;
        distance = stod(tempString);
        Food* obj = new Food(restaurantName, distance, price);
        mexicanhispanic.append(obj);
    }
    textFile.close();
    int decision;
    int money;
    cout << "       Welcome to our Food Decision Maker for TCNJ Students        " << endl << endl;
    cout<< "Would you like a surpise? or do you want to pick a specific cuisine? Enter 1 for a surprise. Enter 0 for a selection of categories." << endl;
    int surprise;
    cin >> surprise;
    if(surprise == 1){
        srand(time(NULL));
        decision = (rand() % 6);
        cout << "Now how expensive of a meal do you want? Enter the corresponding number:" << endl;
    } 
    else{
        cout << "What type of food are you feeling?\nEnter the corresponding number:\n1- Asian, 2- Mexican/Hispanic, 3- Italian, 4- General Resturants, 5- Fast Food\n";

        cin >>decision;

        cout << endl;
    }
    if(decision == 1){
        if(surprise != 1)
            cout << "Asian food.. nice choice!\nUp to how expensive of a meal do you want? Enter the corresponding number:";
        cout << "1- I need something on the cheaper side, I'm a college student! 2- I can spend a moderate amount. 3- I feel like spoiling myself!" <<endl;
        cin >> money;
        cout<< endl << "Your options are: " << endl;
        asian.search(money);
        
    }
    else if(decision == 2){
        if(surprise !=1)
            cout << "Good pick, you have fine tastebuds!\nUp to how expensive of a meal do you want? Enter the corresponding number:";
        cout << "1- I need something on the cheaper side, I'm a college student! 2- I can spend a moderate amount. 3- I feel like spoiling myself!" <<endl;
        cin >> money;
        cout<< endl << "Your options are: " << endl;
        mexicanhispanic.search(money);
    }  
    else if(decision == 3){
        if(surprise !=1)
            cout << "Italian food, simple but tasty!\nUp to how expensive of a meal do you want? Enter the corresponding number:";
        cout << "1- I need something on the cheaper side, I'm a college student! 2- I can spend a moderate amount. 3- I feel like spoiling myself!" <<endl;
        cin >> money;
        cout<< endl << "Your options are: " << endl;
        italian.search(money);
    }
        
    else if(decision == 4){
        if(surprise !=1)
            cout << "Keeping it basic, I like that!\nUp to how expensive of a meal do you want?\nEnter the corresponding number:";
        cout << "1- I need something on the cheaper side, I'm a college student! 2- I can spend a moderate amount. 3- I feel like spoiling myself!" <<endl;
        cin >> money;
        cout<< endl << "Your options are: " << endl;
        GR.search(money);
    }   
    else if (decision == 5){
        if(surprise !=1)
            cout << "Not the healthiest, but defintely superior!\nUp to how expensive of a meal do you want? Enter the corresponding number:" << endl;
        cout << "1- I need something on the cheaper side, I'm a college student! 2- I can spend a moderate amount. 3- I feel like spoiling myself!" <<endl;
        cin >> money;
        cout<< endl << "Your options are: " << endl;
        FF.search(money);
    }
    return 0;
}