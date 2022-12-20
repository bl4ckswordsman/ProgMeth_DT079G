#include <iostream>
#include "Email.h"
#include "MailBox.h"

template<typename T>
void Show(const std::vector<T> &v) {
    for (const auto& e: v){
        std::cout << e << "\n";
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    MailBox mb(3);
    //Show(mb.getEmailContainer());
    mb.pushBack("John Kennedy", "2022-12-11", "Hello");
    mb.pushBack("Walter White", "2022-12-11", "Hello");
    mb.pushBack("John Kennedy", "2022-12-12", "Hello");
    mb.pushBack("John Kennedy", "2022-12-11", "What's up");
    mb.pushBack("Abraham Lincoln", "2022-12-11", "Hello");

    mb.SortWho();
    std::cout << " Sorted by who, date, subject:" << std::endl;
    /*for (auto& e: mb.getEmailContainer()){
        std::cout << e.getWho() << ", " << e.getDate() << ", " << e.getSubject() << "----\n";
    }*/
    Show(mb.getEmailContainer());

    mb.SortDate();
    std::cout << " Sorted by date, who, subject:" << std::endl;
    Show(mb.getEmailContainer());

    mb.SortSubject();
    std::cout << " Sorted by subject, who, date:" << std::endl;
    Show(mb.getEmailContainer());

    return 0;

}
