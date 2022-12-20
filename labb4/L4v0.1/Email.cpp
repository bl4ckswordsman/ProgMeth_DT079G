//
// Created by amari on 2022-12-09.
//

#include "Email.h"

#include <utility>

Email::Email(std::string who, std::string date, std::string subject):
        who(std::move(who)), date(std::move(date)), subject(std::move(subject)) {
}

std::ostream &operator<<(std::ostream &os, const Email &email) {
    os << "Recipient: " << email.getWho() << ", Date: " << email.getDate() << ", Subject: " << email.getSubject();
    return os;
}


const std::string &Email::getWho() const {
    return who;
}

void Email::setWho(const std::string &who) {
    Email::who = who;
}

const std::string &Email::getDate() const {
    return date;
}

void Email::setDate(const std::string &date) {
    Email::date = date;
}

const std::string &Email::getSubject() const {
    return subject;
}

void Email::setSubject(const std::string &subject) {
    Email::subject = subject;
}



