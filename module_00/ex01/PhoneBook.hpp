#include "Contact.hpp"

class PhoneBook{
private:
    Contact contacts[8];
public:
    PhoneBook();
    ~PhoneBook();
    void    printContacts();
    void	addContact(std::string contactInfo[5]);
    void    shiftContact();
    std::string    menuSelector();
    void    fillFields();
};
