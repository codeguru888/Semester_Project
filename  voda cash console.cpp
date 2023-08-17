#include <iostream>
#include <unordered_map>
#include <string>

class VodafoneCash {
private:
    std::unordered_map<std::string, double> accountBalances;
    std::unordered_map<std::string, std::string> accountPins;

public:
    void createUser(const std::string& phoneNumber, const std::string& pin) {
        accountBalances[phoneNumber] = 0.0;
        accountPins[phoneNumber] = pin;
    }

    bool authenticateUser(const std::string& phoneNumber, const std::string& pin) {
        if (accountPins.find(phoneNumber) != accountPins.end() && accountPins[phoneNumber] == pin) {
            return true;
        }
        return false;
    }

    double checkBalance(const std::string& phoneNumber) {
        return accountBalances[phoneNumber];
    }

    void sendMoney(const std::string& sender, const std::string& receiver, double amount) {
        if (accountBalances[sender] >= amount) {
            accountBalances[sender] -= amount;
            accountBalances[receiver] += amount;
            std::cout << "Transaction successful!\n";
        } else {
            std::cout << "Insufficient balance.\n";
        }
    }

    void buyAirtime(const std::string& phoneNumber, double amount) {
        if (accountBalances[phoneNumber] >= amount) {
            accountBalances[phoneNumber] -= amount;
            std::cout << "Airtime purchased successfully!\n";
        } else {
            std::cout << "Insufficient balance.\n";
        }
    }

    void changePin(const std::string& phoneNumber, const std::string& newPin) {
        accountPins[phoneNumber] = newPin;
        std::cout << "PIN changed successfully!\n";
    }
};

int main() {
    VodafoneCash vodafoneCash;

    std::string phoneNumber;
    std::string pin;

    // Sample user registration
    std::cout << "Welcome to Vodafone Cash!\n";
    std::cout << "Please register your account:\n";
    std::cout << "Enter your phone number: ";
    std::cin >> phoneNumber;
    std::cout << "Set your PIN: ";
    std::cin >> pin;

    vodafoneCash.createUser(phoneNumber, pin);

    // Main menu
    int choice;
    do {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Check Balance\n";
        std::cout << "2. Send Money\n";
        std::cout << "3. Buy Airtime\n";
        std::cout << "4. Change PIN\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (vodafoneCash.authenticateUser(phoneNumber, pin)) {
                    double balance = vodafoneCash.checkBalance(phoneNumber);
                    std::cout << "Account balance: ";
                    std::cin>>balance;
                    std::cout<<"enter pin";
                    std::cin>>pin;
                } else {
                    std::cout << "your balance is....";
                }
                break;
            case 2:
                if (vodafoneCash.authenticateUser(phoneNumber, pin)) {
                    std::string receiver;
                    double amount;
                    std::cout << "Enter receiver's phone number: ";
                    std::cin >> receiver;
                    std::cout << "Enter amount: ";
                    std::cin >> amount;
                    vodafoneCash.sendMoney(phoneNumber, receiver, amount);
                } else {
                    std::cout << "Authentication failed.\n";
                }
                break;
            case 3:
                if (vodafoneCash.authenticateUser(phoneNumber, pin)) {
                    double amount;
                    std::cout << "Enter airtime amount: ";
                    std::cin >> amount;
                    vodafoneCash.buyAirtime(phoneNumber, amount);
                } else {
                    std::cout << "Authentication failed.\n";
                }
                break;
            case 4:
                if (vodafoneCash.authenticateUser(phoneNumber, pin)) {
                    std::string newPin;
                    std::cout << "Enter new PIN: ";
                    std::cin >> newPin;
                    vodafoneCash.changePin(phoneNumber, newPin);
                } else {
                    std::cout << "Authentication failed.\n";
                }
                break;
            case 0:
                std::cout << "Exiting. Thank you!\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}
