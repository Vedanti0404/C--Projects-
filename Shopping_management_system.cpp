#include <bits/stdc++.h>
using namespace std;

class Product {
protected:
    string brand;
    int price;
    
public:
    void dashboard();
    void account(string arr[],int n);
    void sign_up();
    void sign_in();

};

void addUser(const string& username, const string& password) {
    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();
}

bool doesUserExist(const string& username, const string& password) {
    ifstream file("users.txt");
    string line;
    string check=username+" "+password;
    
    while (getline(file, line)) {
        if(line==check){
            return true;
        }

    }

    return false; // Username not found or password doesn't match
}


//************************************SIGN-IN****************************************************
void Product::sign_in(){
    cout<<"\nYou are on the Sign-in Page"<<endl;
    cout<<"\nEnter your user name: ";
    string username;                     
    cin>>username;
    cout<<"\nEnter password: ";
    string password;
    cin>>password;
    bool ans=doesUserExist(username,password);
    if(ans==true){
cout<<"-----------------------------------------------------------------------------------------------------";
        cout<<"\nWelcome again "<<username<<"!"<<endl;
        cout<<"\nYour payment is successful!"<<endl;
        cout<<"\nThank for buying with us"<<endl;
        cout<<"\nDo you want to buy anything else? "<<endl;
        cout<<"\nEnter 'y' for Yes and 'n' for No: ";
        char ask;
        cin>>ask;
        if(ask=='y' || ask=='Y'){
                dashboard();
            }

        else if(ask=='n' || ask=='N'){
          cout << "\nThank you. Visit again!" << endl;
          exit(0);
        }
    }
    else if(ans==false){
        cout<<"User does not exist. Please Sign-up."<<endl;
        sign_up();
    }
    
}
//*************************************************************SIGN-UP***************************************************
void Product::sign_up() {
        cout << "------------------------------------------------------------------------------------------------------";
        cout << "\nYou are on the Sign-up Page" << endl;
        string newuser;
        cout << "\nEnter your user name: ";
        cin >> newuser;

        string newpassword;
        cout << "\nEnter Password: ";
        cin.ignore(); 
        getline(cin, newpassword); 

        if (doesUserExist(newuser, "")) {
            cout << "Username already exists. Please sign in if you have an account." << endl;
            return;
        }

        addUser(newuser, newpassword);
        cout << "------------------------------------------------------------------------------------------------------";
        cout << "\nWelcome " << newuser << "! You have been signed up." << endl;
        cout << "\nYour payment is successful!" << endl;
        cout << "\nThank you for buying with us." << endl;

        cout << "\nDo you want to buy anything else?" << endl;
        cout << "Enter 'y' for Yes and 'n' for No: ";
        char ask;
        cin >> ask;

        if (ask == 'y' || ask == 'Y') {
           
            dashboard();
        } else if(ask == 'n' || ask == 'N'){
            cout << "\nThank you. Visit again!" << endl;
            exit(0);
        }
    }

//***********************************************************************************************************************
void Product::account(string arr[],int n){
    cout<<"----------------------------------------CART------------------------------------------------"<<endl; 
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\nYour Total Bill is "<<arr[1]<<endl;
    int opt;
    cout<<"\nSign-in / Sign-up to buy the product\n";
    cout<<"\nEnter '1' to Sign-in and '2' to Sign-up: ";
    cin>>opt;
    switch(opt){
        case 1: sign_in();
        break;
        case 2: sign_up();
        break;
    }
}



//*******************************************************FASHION*********************************

class fashion : public Product {
private:
    int size;

public:
    void fashion_dashboard();
    void mens_wear();
    void womens_wear();
    void kids_wear();
    void further_action();
};



void fashion::fashion_dashboard() {
    cout << "---------------------------------------------FASHION DASHBOARD------------------------------------------------" << endl;
    // Add the implementation for the fashion dashboard here
    cout << "1) Men's Wear\n\n";
    cout << "2) Women's Wear\n\n";
    cout << "3) Kids Wear\n\n";
    int option;
    cout << "Please select the sub-category: ";
    cin >> option;
    switch (option) {
    case 1:
        mens_wear();
        break;
    case 2:
        womens_wear();
        break;
    case 3:
        kids_wear();
        break;
    // Add cases for other sub-categories
    }
}

void fashion::mens_wear() {
    cout << "----------------------------------------------MEN'S WEAR-----------------------------------------------------" << endl;
    // Add the implementation for men's wear here
    string arr[5][3] = {{"Formal Shirt", "Rs 1000", "Small/Medium/Large"},
                        {"T-shirt", "Rs 850", "Small/Medium/Large"},
                        {"Jeans", "Rs 1500", "34"},
                        {"Trouser", "Rs 700", "38"},
                        {"Jacket", "Rs 2000", "Small/Medium/Large"}};

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << "Categories" << setw(15) << "|" << setw(15) << "Price" << setw(15) << "|" << setw(20) << "Size" << setw(15) << "|" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(15) << arr[i][0] << setw(15) << "|" << setw(15) << arr[i][1] << setw(15) << "|" << setw(20) << arr[i][2] << setw(15) << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;
    
    cout<<"\nDo you want to buy product from this category?\n\nEnter 'y' for Yes and 'n' for No: ";
    char ask;
    cin>>ask;
    if(ask=='y' || ask=='Y'){
      cout<<"\nWhich product you wih to buy ?"<<endl;
      cout<<"\n1) Formal Shirt\n"<<endl;
      cout<<"2) T-shirt\n"<<endl;
      cout<<"3) Jeans\n"<<endl;
      cout<<"4) Trouser\n"<<endl;
      cout<<"5) Jacket\n"<<endl;
      cout<<"Enter the product number you want to buy: ";

      int option;
      cin>>option;
      
      account(arr[option-1],3);
      

    }
    else if(ask=='n' || ask=='N'){
        further_action();
    }

    
}

void fashion::womens_wear() {
    cout << "----------------------------------------------WOMEN'S WEAR-----------------------------------------------------" << endl;
    // Add the implementation for women's wear here
    string arr[5][3] = {{"Top", "Rs 800", "Small/Medium/Large"},
                        {"Kurti", "Rs 950", "Small/Medium/Large"},
                        {"Jeans", "Rs 2500", "28"},
                        {"Saree", "Rs 3700", "6 yards"},
                        {"Jacket", "Rs 3000", "Small/Medium/Large"}};

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << "Categories" << setw(15) << "|" << setw(15) << "Price" << setw(15) << "|" << setw(20) << "Size" << setw(15) << "|" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(15) << arr[i][0] << setw(15) << "|" << setw(15) << arr[i][1] << setw(15) << "|" << setw(20) << arr[i][2] << setw(15) << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout<<"\nDo you want to buy product from this category?\n\nEnter 'y' for Yes and 'n' for No: ";
    char ask;
    cin>>ask;
    if(ask=='y' || ask=='Y'){
      cout<<"\nWhich product you wih to buy ?"<<endl;
      cout<<"\n1) Top\n"<<endl;
      cout<<"2) Kurti\n"<<endl;
      cout<<"3) Jeans\n"<<endl;
      cout<<"4) Saree\n"<<endl;
      cout<<"5) Jacket\n"<<endl;
      cout<<"Enter the product number you want to buy: ";

      int option;
      cin>>option;
      
      account(arr[option-1],3);
      

    }
    else if(ask=='n' || ask=='N'){
        further_action();
    }
    
}

void fashion::kids_wear() {
    cout << "----------------------------------------------------KIDS WEAR-----------------------------------------------" << endl;
    // Add the implementation for kids wear here
   string arr[5][3] = {{"T-shirt", "Rs 400", "Small/Medium/Large"},
                        {"Jeans", "Rs 550", "Small/Medium/Large"},
                        {"Frock", "Rs 600", "Small/Medium/Large"},
                        {"Skirt", "Rs 480", "Small/Medium/Large"},
                        {"Jacket", "Rs 800", "Small/Medium/Large"}};

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << "Categories" << setw(15) << "|" << setw(15) << "Price" << setw(15) << "|" << setw(20) << "Size" << setw(15) << "|" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(15) << arr[i][0] << setw(15) << "|" << setw(15) << arr[i][1] << setw(15) << "|" << setw(20) << arr[i][2] << setw(15) << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;
   
   cout<<"\nDo you want to buy product from this category?\n\nEnter 'y' for Yes and 'n' for No: ";
    char ask;
    cin>>ask;
    if(ask=='y' || ask=='Y'){
      cout<<"\nWhich product you wih to buy ?"<<endl;
      cout<<"\n1) T-shirt\n"<<endl;
      cout<<"2) Jeans\n"<<endl;
      cout<<"3) Frock\n"<<endl;
      cout<<"4) Skirt\n"<<endl;
      cout<<"5) Jacket\n"<<endl;
      cout<<"Enter the product number you want to buy: ";

      int option;
      cin>>option;
      
      account(arr[option-1],3);
      

    }
    else if(ask=='n' || ask=='N'){
        further_action();
    }

}

void fashion::further_action(){
     cout<<"\n\n";
    cout<<"Do you want to select other options\n"<<endl;
   cout << "1) Men's Wear\n\n";
    cout << "2) Women's Wear\n\n";
    cout << "3) Kids Wear\n\n";
    cout << "4) Main Dashboard\n\n";
    cout << "5) Fashion Dashboard\n\n";
    
    int option;
    cin>>option;
    switch (option)
    {
   case 1:
        mens_wear();
        break;
    case 2:
        womens_wear();
        break;
    case 3:
        kids_wear();
        break;
    case 4:
        dashboard();
        break;
    case 5:
        fashion_dashboard();
        break;
    }
}
/****************************************************ELECTRONICS**********************************************************/

class electronics: public Product {
private:
    int warranty;

public:
    void electronics_dashboard();
    void TV();
    void mobile();
    void fridge();
    void further_action();
};

void electronics::electronics_dashboard() {
    cout << "----------------------------------------------ELECTRONICS DASHBOARD--------------------------------------------" << endl;
    // Add the implementation for the electronic dashboard here
    cout << "1) TV\n\n";
    cout << "2) Mobile\n\n";
    cout << "3) Fridge\n\n";
    int option;
    cout << "Please select the sub-category: ";
    cin >> option;
    switch (option) {
        case 1:
            TV();
            break;
        case 2:
            mobile();
            break;
        case 3:
            fridge();
            break;
        // Add cases for other sub-categories
    }
}

void electronics::TV() {
    cout << "------------------------------------------------TV------------------------------------------------" << endl;
    // Add the implementation for TV here
    string arr[3][3] = {{"Sony", "Rs 1,20,000", "5 years warranty"},
                        {"LG", "Rs 85,000", "2 years warranty"},
                        {"Samsung", "Rs 96,000", "2 years warranty"}};

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << "Brand" << setw(15) << "|" << setw(15) << "Price" << setw(15) << "|" << setw(20) << "Warranty" << setw(15) << "|" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(15) << arr[i][0] << setw(15) << "|" << setw(15) << arr[i][1] << setw(15) << "|" << setw(20) << arr[i][2] << setw(15) << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;

    
    cout<<"\nDo you want to buy product from this category?\n\nEnter 'y' for Yes and 'n' for No: ";
    char ask;
    cin>>ask;
    if(ask=='y' || ask=='Y'){
      cout<<"\nWhich product you wih to buy ?"<<endl;
      cout<<"\n1) Sony\n"<<endl;
      cout<<"2) LG\n"<<endl;
      cout<<"3) Samsung\n"<<endl;
      cout<<"Enter the product number you want to buy: ";

      int option;
      cin>>option;
      
      account(arr[option-1],3);
      

    }
    else if(ask=='n' || ask=='N'){
        further_action();
    }

}

void electronics::mobile() {
    cout << "---------------------------------------------MOBILE----------------------------------------------" << endl;
    // Add the implementation for MOBILE here
    string arr[4][3] = {{"Iphone", "Rs 90,000", "1 years warranty"},
                        {"Oppo", "Rs 25,000", "2 years warranty"},
                        {"Samsung", "Rs 36,000", "2 years warranty"},
                        {"Realme", "Rs 15,000", "1 years warranty"}};

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << "Brand" << setw(15) << "|" << setw(15) << "Price" << setw(15) << "|" << setw(20) << "Warranty" << setw(15) << "|" << endl;

    for (int i = 0; i < 4; i++) {
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(15) << arr[i][0] << setw(15) << "|" << setw(15) << arr[i][1] << setw(15) << "|" << setw(20) << arr[i][2] << setw(15) << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;
    
    cout<<"\nDo you want to buy product from this category?\n\nEnter 'y' for Yes and 'n' for No: ";
    char ask;
    cin>>ask;
    if(ask=='y' || ask=='Y'){
      cout<<"\nWhich product you wih to buy ?"<<endl;
      cout<<"\n1) Iphone\n"<<endl;
      cout<<"2) Oppo\n"<<endl;
      cout<<"3) Samsung\n"<<endl;
      cout<<"4) Realme\n"<<endl;
      cout<<"Enter the product number you want to buy: ";
      

      int option;
      cin>>option;
      
      account(arr[option-1],3);
      

    }
    else if(ask=='n' || ask=='N'){
        further_action();
    }

}

void electronics::fridge() {
    cout << "-------------------------------------------FRIDGE-----------------------------------------------" << endl;
    // Add the implementation for FRIDGE here
    string arr[3][3] = {{"Whirlpool", "Rs 25,000", "3 years warranty"},
                        {"LG", "Rs 35,000", "5 years warranty"},
                        {"Samsung", "Rs 31,000", "4 years warranty"}};

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << "Brand" << setw(15) << "|" << setw(15) << "Price" << setw(15) << "|" << setw(20) << "Warranty" << setw(15) << "|" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(15) << arr[i][0] << setw(15) << "|" << setw(15) << arr[i][1] << setw(15) << "|" << setw(20) << arr[i][2] << setw(15) << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;
    
   cout<<"\nDo you want to buy product from this category?\n\nEnter 'y' for Yes and 'n' for No: ";
    char ask;
    cin>>ask;
    if(ask=='y' || ask=='Y'){
      cout<<"\nWhich product you wih to buy ?"<<endl;
      cout<<"\n1) Whirlpool\n"<<endl;
      cout<<"2) LG\n"<<endl;
      cout<<"3) Samsung\n"<<endl;
      cout<<"Enter the product number you want to buy: ";
    

      int option;
      cin>>option;
      
      account(arr[option-1],3);
      

    }
    else if(ask=='n' || ask=='N'){
        further_action();
    }

}

void electronics::further_action() {
    cout << "\n\n";
    cout << "Do you want to select other options\n" << endl;
    cout << "1) TV\n\n";
    cout << "2) Mobile\n\n";
    cout << "3) Fridge\n\n";
    cout << "4) Main Dashboard\n\n";
    cout << "5) Electronics Dashboard\n\n";
  
    int option;
    cin >> option;
    switch (option) {
        case 1:
            TV(); 
            break;
        case 2:
            mobile(); 
            break;
        case 3:
            fridge(); 
            break;
        case 4:
            dashboard(); 
            break;
        case 5:
            electronics_dashboard(); 
            break;
    }
}




//********************************************************ACCESSORIES****************************************************

class accessories: public Product {
private:
    int brand;

public:
    void accessories_dashboard();
    void shoes();
    void cosmetics();
    void jewellery();
    void bags();
    void further_action();
};

void accessories::shoes() {
    cout << "------------------------------------------------SHOES--------------------------------------------" << endl;
    // Add the implementation for shoes here
     string arr[3][3] = {{"Nike", "Rs 3,000", "1 year warranty"},
                        {"Adidas", "Rs 2,500", "6 months warranty"},
                        {"Puma", "Rs 2,200", "1 year warranty"}};

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << "Brand" << setw(15) << "|" << setw(15) << "Price" << setw(15) << "|" << setw(20) << "Warranty" << setw(15) << "|" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(15) << arr[i][0] << setw(15) << "|" << setw(15) << arr[i][1] << setw(15) << "|" << setw(20) << arr[i][2] << setw(15) << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;

    cout<<"\nDo you want to buy product from this category?\n\nEnter 'y' for Yes and 'n' for No: ";
    char ask;
    cin>>ask;
    if(ask=='y' || ask=='Y'){
      cout<<"\nWhich product you wih to buy ?"<<endl;
      cout<<"\n1) Nike\n"<<endl;
      cout<<"2) Adidas\n"<<endl;
      cout<<"3) Puma\n"<<endl;
      cout<<"Enter the product number you want to buy: ";
     

      int option;
      cin>>option;
      
      account(arr[option-1],3);
      

    }
    else if(ask=='n' || ask=='N'){
        further_action();
    }

}


void accessories::cosmetics() {
    cout << "----------------------------------------------COSMETICS-----------------------------------------" << endl;
    // Add the implementation for cosmetics here
     string arr[3][3] = {{"Maybelline", "Rs 500", "No warranty"},
                        {"L'Oreal", "Rs 700", "No warranty"},
                        {"MAC", "Rs 1,000", "No warranty"}};

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << "Brand" << setw(15) << "|" << setw(15) << "Price" << setw(15) << "|" << setw(20) << "Warranty" << setw(15) << "|" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(15) << arr[i][0] << setw(15) << "|" << setw(15) << arr[i][1] << setw(15) << "|" << setw(20) << arr[i][2] << setw(15) << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;

    cout<<"\nDo you want to buy product from this category?\n\nEnter 'y' for Yes and 'n' for No: ";
    char ask;
    cin>>ask;
    if(ask=='y' || ask=='Y'){
      cout<<"\nWhich product you wih to buy ?"<<endl;
      cout<<"\n1) Maybelline\n"<<endl;
      cout<<"2) L'Oreal\n"<<endl;
      cout<<"3) MAC\n"<<endl;
      cout<<"Enter the product number you want to buy: ";
      

      int option;
      cin>>option;
      
      account(arr[option-1],3);
      

    }
    else if(ask=='n' || ask=='N'){
        further_action();
    }

}

void accessories::jewellery() {
    cout << "------------------------------------------------JEWELLERY---------------------------------------" << endl;
    // Add the implementation for jewellery here
    string arr[3][3] = {{"Gold Necklace", "Rs 50,000", "5 years warranty"},
                        {"Silver Earrings", "Rs 2,000", "2 years warranty"},
                        {"Diamond Ring", "Rs 1,20,000", "10 years warranty"}};

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << "Brand" << setw(15) << "|" << setw(15) << "Price" << setw(15) << "|" << setw(20) << "Warranty" << setw(15) << "|" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(15) << arr[i][0] << setw(15) << "|" << setw(15) << arr[i][1] << setw(15) << "|" << setw(20) << arr[i][2] << setw(15) << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;

    cout<<"\nDo you want to buy product from this category?\n\nEnter 'y' for Yes and 'n' for No: ";
    char ask;
    cin>>ask;
    if(ask=='y' || ask=='Y'){
      cout<<"\nWhich product you wih to buy ?"<<endl;
      cout<<"\n1) Gold Necklace\n"<<endl;
      cout<<"2) Silver Earrings\n"<<endl;
      cout<<"3) Diamond Ring\n"<<endl;
      cout<<"Enter the product number you want to buy: ";
      

      int option;
      cin>>option;
      
      account(arr[option-1],3);
      

    }
    else if(ask=='n' || ask=='N'){
        further_action();
    }

}

void accessories::bags() {
    cout << "---------------------------------------------BAGS--------------------------------------------" << endl;
    // Add the implementation for bags here
     string arr[3][3] = {{"Backpack", "Rs 1,500", "1 year warranty"},
                        {"Handbag", "Rs 2,000", "6 months warranty"},
                        {"Travel Luggage", "Rs 3,500", "2 years warranty"}};

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << "Brand" << setw(15) << "|" << setw(15) << "Price" << setw(15) << "|" << setw(20) << "Warranty" << setw(15) << "|" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(15) << arr[i][0] << setw(15) << "|" << setw(15) << arr[i][1] << setw(15) << "|" << setw(20) << arr[i][2] << setw(15) << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;

    cout<<"\nDo you want to buy product from this category?\n\nEnter 'y' for Yes and 'n' for No: ";
    char ask;
    cin>>ask;
    if(ask=='y' || ask=='Y'){
      cout<<"\nWhich product you wih to buy ?"<<endl;
      cout<<"\n1) Backpack\n"<<endl;
      cout<<"2) Handbag\n"<<endl;
      cout<<"3) Travel Luggage\n"<<endl;
      cout<<"Enter the product number you want to buy: ";
     

      int option;
      cin>>option;
      
      account(arr[option-1],3);
      

    }
    else if(ask=='n' || ask=='N'){
        further_action();
    }

}

void accessories::accessories_dashboard(){
    cout << "--------------------------------------------ACCESSORIES DASHBOARD----------------------------------------------" << endl;
    // Add the implementation for the accessories dashboard here
    cout << "1) Shoes\n\n";
    cout << "2) Cosmetics\n\n";
    cout << "3) Jewellery\n\n";
    cout << "4) Bags\n\n";
    int option;
    cout << "Please select the sub-category: ";
    cin >> option;
    switch (option) {
        case 1:
            shoes();
            break;
        case 2:
            cosmetics();
            break;
        case 3:
            jewellery();
            break;
        case 4:
            bags();
            break;
        // Add cases for other sub-categories
    }
}

void accessories::further_action(){
    cout << "\n\n";
    cout << "Do you want to select other options\n" << endl;
    cout << "1) Shoes\n\n";
    cout << "2) Cosmetics\n\n";
    cout << "3) Jewellery\n\n";
    cout << "4) Bags\n\n";
    cout << "5) Main Dashboard\n\n";
    cout << "6) Accessories Dashboard\n\n";
    
    int option;
    cin >> option;
    switch (option) {
        case 1:
            shoes(); 
            break;
        case 2:
            cosmetics(); 
            break;
        case 3:
            jewellery(); 
            break;
        case 4:
            bags(); 
            break;
        case 5:
            dashboard(); 
            break;
        case 6:
            accessories_dashboard(); 
            break;
      
    }
}







//********************************************************HOME DECOR*************************************************************************

class home_decor: public Product {
private:
    int warranty;

public:
    void home_decor_dashboard();
    void mattress();
    void chair();
    void table();
    void further_action();
};

void home_decor::mattress() {
    cout << "---------------------------------------------MATTRESS------------------------------------------" << endl;
    // Add the implementation for mattress here
     string arr[3][3] = {{"Memory Foam", "Rs 15,000", "5 years warranty"},
                        {"Orthopedic", "Rs 20,000", "7 years warranty"},
                        {"Spring Mattress", "Rs 25,000", "10 years warranty"}};

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << "Type" << setw(15) << "|" << setw(15) << "Price" << setw(15) << "|" << setw(20) << "Warranty" << setw(15) << "|" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(15) << arr[i][0] << setw(15) << "|" << setw(15) << arr[i][1] << setw(15) << "|" << setw(20) << arr[i][2] << setw(15) << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;
   
   cout<<"\nDo you want to buy product from this category?\n\nEnter 'y' for Yes and 'n' for No: ";
    char ask;
    cin>>ask;
    if(ask=='y' || ask=='Y'){
      cout<<"\nWhich product you wih to buy ?"<<endl;
      cout<<"\n1) Memory Foam\n"<<endl;
      cout<<"2) Orthopedic\n"<<endl;
      cout<<"3) Spring Mattress\n"<<endl;
      cout<<"Enter the product number you want to buy: ";
      

      int option;
      cin>>option;
      
      account(arr[option-1],3);
      

    }
    else if(ask=='n' || ask=='N'){
        further_action();
    }

}

void home_decor::chair() {
    cout << "---------------------------------------------CHAIR--------------------------------------------" << endl;
    // Add the implementation for chair here
     string arr[3][3] = {{"Wooden Chair", "Rs 5,000", "3 years warranty"},
                        {"Office Chair", "Rs 8,000", "5 years warranty"},
                        {"Recliner Chair", "Rs 15,000", "7 years warranty"}};

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << "Type" << setw(15) << "|" << setw(15) << "Price" << setw(15) << "|" << setw(20) << "Warranty" << setw(15) << "|" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(15) << arr[i][0] << setw(15) << "|" << setw(15) << arr[i][1] << setw(15) << "|" << setw(20) << arr[i][2] << setw(15) << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;

    cout<<"\nDo you want to buy product from this category?\n\nEnter 'y' for Yes and 'n' for No: ";
    char ask;
    cin>>ask;
    if(ask=='y' || ask=='Y'){
      cout<<"\nWhich product you wih to buy ?"<<endl;
      cout<<"1) Wooden Chair\n"<<endl;
      cout<<"2) Office Chair\n"<<endl;
      cout<<"3) Recliner Chair\n"<<endl;
      cout<<"Enter the product number you want to buy: ";
      

      int option;
      cin>>option;
      
      account(arr[option-1],3);
      

    }
    else if(ask=='n' || ask=='N'){
        further_action();
    }

}

void home_decor::table() {
    cout << "----------------------------------------------TABLE------------------------------------------" << endl;
    // Add the implementation for table here
    string arr[3][3] = {{"Wooden Table", "Rs 10,000", "3 years warranty"},
                        {"Glass Table", "Rs 15,000", "5 years warranty"},
                        {"Dining Table Set", "Rs 25,000", "7 years warranty"}};

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(15) << "Type" << setw(15) << "|" << setw(15) << "Price" << setw(15) << "|" << setw(20) << "Warranty" << setw(15) << "|" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(15) << arr[i][0] << setw(15) << "|" << setw(15) << arr[i][1] << setw(15) << "|" << setw(20) << arr[i][2] << setw(15) << "|" << endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;

    cout<<"\nDo you want to buy product from this category?\nEnter 'y' for Yes and 'n' for No: ";
    char ask;
    cin>>ask;
    if(ask=='y' || ask=='Y'){
      cout<<"\nWhich product you wih to buy ?"<<endl;
      cout<<"\n1) Wooden Table\n"<<endl;
      cout<<"2) Glass Table\n"<<endl;
      cout<<"3) Dining Table Set\n"<<endl;
     cout<<"Enter the product number you want to buy: ";

      int option;
      cin>>option;
      
      account(arr[option-1],3);
      

    }
    else if(ask=='n' || ask=='N'){
        further_action();
    }

}

void home_decor::home_decor_dashboard(){
    cout << "-----------------------------------------HOME-DECOR DASHBOARD----------------------------------------------" << endl;
    // Add the implementation for the home decor dashboard here
    cout << "1) Mattress\n\n";
    cout << "2) Chair\n\n";
    cout << "3) Table\n\n";
    int option;
    cout << "Please select the sub-category: ";
    cin >> option;
    switch (option) {
        case 1:
            mattress();
            break;
        case 2:
            chair();
            break;
        case 3:
            table();
            break;
        // Add cases for other sub-categories
    }
}

void home_decor::further_action(){
    cout << "\n\n";
    cout << "Do you want to select other options\n" << endl;
    cout << "1) Mattress\n\n";
    cout << "2) Chair\n\n";
    cout << "3) Table\n\n";
    cout << "4) Main Dashboard\n\n";
    cout << "5) Home Decor Dashboard\n\n";
    int option;
    cin >> option;
    switch (option) {
        case 1:
            mattress(); 
            break;
        case 2:
            chair(); 
            break;
        case 3:
            table(); 
            break;
        case 4:
            dashboard(); 
            break;
        case 5:
            home_decor_dashboard(); 
            break;
   
    }
}




//**********************************************PRODUCT DASHBOARD*******************************************************
void Product::dashboard() {
    cout << "--------------------------------------------WELCOME TO SHOPPING CART--------------------------------------------" << endl;

    cout << "\nCategories\n" << endl;
    cout << "\n1) Fashion\n" << endl;
    cout << "\n2) Electronics\n" << endl;
    cout << "\n3) Accessories\n" << endl;
    cout << "\n4) Home Decor\n" << endl;
    int option;
    cout << "Please select the category: ";
    cin >> option;
    switch (option) {
    case 1:
        // Assuming you want to create an instance of the fashion class and call its dashboard method
        {
            fashion fashionObj;
            fashionObj.fashion_dashboard();
        }
        break;
        // Add cases for other categories here
    
     case 2:
        // Assuming you want to create an instance of the electronics class and call its dashboard method
        {
            electronics electronics;
            electronics.electronics_dashboard();
        }
        break;
        // Add cases for other categories here

    case 3:
        // Assuming you want to create an instance of the accessories class and call its dashboard method
        {
            accessories accessories;
            accessories.accessories_dashboard();
        }
        break;
    
     case 4:
        // Assuming you want to create an instance of the home_decor class and call its dashboard method
        {
            home_decor home_decor;
            home_decor.home_decor_dashboard();
        }
        break;
        // Add cases for other categories here
    }

    

}
//*****************************************************************f******************************************************



int main() {
    Product user;
    user.dashboard();
    return 0;
}
