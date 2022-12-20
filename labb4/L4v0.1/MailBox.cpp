//
// Created by amari on 2022-12-10.
//

#include <algorithm>
#include "MailBox.h"
#include <utility>
MailBox::MailBox(size_t size) {
    emailContainer.reserve(size);
    //setEmailContainer(std::vector<Email>(size));
}

const std::vector<Email> &MailBox::getEmailContainer() const {
    return emailContainer;
}

void MailBox::setEmailContainer(const std::vector<Email> &emailContainer) {
    MailBox::emailContainer = emailContainer;
}

void MailBox::pushBack(const std::string &recipient, const std::string &dt, const std::string &sub) {
    //On pushBack operations, empty string objects are erased if the first object is empty
    /*if(emailContainer[0].getWho().empty() && emailContainer[0].getDate().empty()
        && emailContainer[0].getSubject().empty()) {
        emailContainer.erase(std::remove_if(emailContainer.begin(), emailContainer.end(),
                                            [](const Email &obj) {
                                                return obj.getWho().empty() && obj.getDate().empty() &&
                                                       obj.getSubject().empty();
                                            }), emailContainer.end());
    }*/

    emailContainer.push_back(Email(recipient, dt, sub));
}

/*Sort by recipient names (if names are equal, sort by date, then by subject)
 * Upper case characters come before lower case characters*/
void MailBox::SortWho() {
    std::sort(emailContainer.begin(), emailContainer.end(), CompWhoDateSubject());
}

/*Sort by date (if dates are equal, sort by recipient, then by subject)
 * Upper case characters come before lower case characters*/
void MailBox::SortDate() {
    std::sort(emailContainer.begin(), emailContainer.end(), CompDateWhoSubject());
}

/*Sort by subject (if subjects are equal, sort by recipient, then by date)
 * Upper case characters come before lower case characters*/
void MailBox::SortSubject() {
    std::sort(emailContainer.begin(), emailContainer.end(), CompSubjectWhoDate());
}




