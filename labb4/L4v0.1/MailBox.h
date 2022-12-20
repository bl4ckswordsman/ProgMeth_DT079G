//
// Created by amari on 2022-12-10.
//

#ifndef L4V0_1_MAILBOX_H
#define L4V0_1_MAILBOX_H

#include <vector>
#include "Email.h"

class MailBox {
    std::vector<Email> emailContainer;
public:
    MailBox(size_t size);

    const std::vector<Email> &getEmailContainer() const;
    void setEmailContainer(const std::vector<Email> &emailContainer);

    void pushBack(const std::string &recipient, const std::string &dt, const std::string &sub);

    void SortWho();
    void SortDate();
    void SortSubject();

};



#endif //L4V0_1_MAILBOX_H
