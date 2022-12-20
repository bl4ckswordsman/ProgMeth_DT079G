//
// Created by amari on 2022-12-09.
//

#ifndef L4V0_1_EMAIL_H
#define L4V0_1_EMAIL_H
#include <string>
#include <ostream>


class Email {
    std::string who;
    std::string date;
    std::string subject;
public:
    Email()=default;
    Email(std::string who, std::string date, std::string subject);

    const std::string &getWho() const;
    void setWho(const std::string &who);

    const std::string &getDate() const;
    void setDate(const std::string &date);

    const std::string &getSubject() const;
    void setSubject(const std::string &subject);

    friend std::ostream &operator<<(std::ostream &os, const Email &email);

};


struct CompWhoDateSubject{
    bool operator()(Email &lhs, Email &rhs){
        if (lhs.getWho()==rhs.getWho()){
            if (lhs.getDate()==rhs.getDate()){
                return lhs.getSubject()<rhs.getSubject();
            }
            else {
                return lhs.getDate()<rhs.getDate();
            }
        }
        else {
            return lhs.getWho()<rhs.getWho();
        }
    }
};

struct CompDateWhoSubject {
    bool operator()(Email &lhs, Email &rhs) {
        if (lhs.getDate() == rhs.getDate()) {
            if (lhs.getWho() == rhs.getWho()) {
                return lhs.getSubject() < rhs.getSubject();
            } else {
                return lhs.getWho() < rhs.getWho();
            }
        } else {
            return lhs.getDate() < rhs.getDate();
        }

    //FÖRSLAG TILL FÖRBÄTTRING:
    /*
    if (lhs.getDate() == rhs.getDate()) {
        return lhs.getWho() < rhs.getWho();
    }
    if (lhs.getWho() == rhs.getWho()){
        return lhs.getSubject() < rhs.getSubject();
    }
    return lhs.getDate() < rhs.getDate();
     */
    }
};

struct CompSubjectWhoDate{
    bool operator()(Email &lhs, Email &rhs){
        if (lhs.getSubject()==rhs.getSubject()){
            if (lhs.getWho()==rhs.getWho()){
                return lhs.getDate()<rhs.getDate();
            }
            else {
                return lhs.getWho()<rhs.getWho();
            }
        }
        else {
            return lhs.getSubject()<rhs.getSubject();
        }
    }
};




#endif //L4V0_1_EMAIL_H
