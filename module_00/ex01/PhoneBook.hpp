#include "Contact.hpp"

class PhoneBook{
private:
    Contact contacts[8];
public:
    PhoneBook();
    ~PhoneBook();
    void           	printContacts();
    void	       	addContact(std::string contactInfo[5]);
    void           	shiftContact();
    void			fillFields();
    std::string		menuSelector();
    bool            isAllDigit(std::string data);
    void            searchContact();
    void            displayAgenda();
    void            displayContact(std::string input);
};
