#include <iostream>
#include <string>

class Contact{
private:
	std::string	_title[5];
	std::string	_info[5];
public:
	Contact();
	~Contact();
	std::string	getTitle(int i) const;
	std::string	getInfo(int i) const;
	void		setInfo(std::string data[5]);
	bool		empty();
};
