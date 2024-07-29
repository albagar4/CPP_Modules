#include "Contact.hpp"

class PhoneBook{
private:
    Contact contacts[8];
public:
    PhoneBook();
    ~PhoneBook();
    void	       	addContact(std::string contactInfo[5]);
    void           	shiftContact();
    void			fillFields();
    void    		menuSelector();
    bool            isAllDigit(std::string data);
    void            searchContact();
    void            displayAgenda();
    void            displayContact(std::string input);
};
