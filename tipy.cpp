#include <iostream>
#include <list>

class ToDoItem {
private: 
    int id;
    std::string description;
    bool state;
public:
    ToDoItem(): id(0), description(""), state(false) {}
    ~ToDoItem() = default;
    bool create(std::string newDescription, int newId) {
        id = newId;
        description = newDescription;
        return true;
    }

    int getId() { return id; }
    std::string getDescription() { return description; }
    bool getState() { return state; }
    void setCompleted(bool val) { state = val; }
};

int main() {
    std::string inputDescription;
    char inputOption;
    int inputId;
    std::string version = "0.1.0";
    std::list<ToDoItem> ToDoItems;
    std::list<ToDoItem>::iterator iterator;

    ToDoItems.clear();
    

    while (1) {
        system("cls");
        std::cout << "tipy - " << version << std::endl;
        std::cout << std::endl;

        for (iterator = ToDoItems.begin(); iterator != ToDoItems.end(); iterator++) {
            std::string completed = iterator->getState() ? "v" : "x";
            std::cout << iterator->getId() << " | " << iterator->getDescription() << " | " << completed << std::endl;
        }

        if (ToDoItems.empty()) {
            std::cout << "Great day, isn't it?" << std::endl;
        }

        std::cout << std::endl;

        std::cout << "[a]dd goal | [c]omplete it | [q]uit" << std::endl;
        std::cout << "What to do?: ";
        std::cin >> inputOption;

        if (inputOption == 'q') {
            std::cout << "Come again!" << std::endl;
            break;
        } else if (inputOption == 'c') {
            std::cout << "Enter id of completed goal: ";
            std::cin >> inputId;

            for (iterator = ToDoItems.begin(); iterator != ToDoItems.end(); iterator++) {
                if (inputId == iterator->getId()) {
                    iterator->setCompleted(true);
                    break;
                }
            }
        } else if (inputOption == 'a') {
            std::cout << "Enter description of goal: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, inputDescription);

            ToDoItem newItem;
            newItem.create(inputDescription, ToDoItems.size() + 1);
            ToDoItems.push_back(newItem); 
        }

    }
    std::cin>>version;
    return 0;
}