#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    Contact(std::string fiName, std::string laName, std::string niName, std::string phNumber, std::string daSecret);
    void    setFirstName(std::string firstName);
    void    setLastName(std::string lastName);
    void    setNickName(std::string nickName);
    void    setPhoneNumber(std::string phoneNumber);
    void    setDarkestSecret(std::string darkestSecret);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

};


#endif