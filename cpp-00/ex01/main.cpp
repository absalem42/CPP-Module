# include "PhoneBook.hpp"

void	printMenu()
{
	std::cout << "Please Enter a command [ADD, SEARCH, EXIT]: " << std::endl;
}

void    haddContact(PhoneBook &phobeBook)
{
    Contact newContact;

    newContact = phobeBook.createContact();
	phobeBook.addContact(newContact);
	printMenu();
}

void	contackHeader()
{
	std::cout << "     index|first name| last name|  nickname\n";
	std::cout << "----------|----------|----------|----------\n";
}
void	contackHeaderFooter()
{
	std::cout << "-------------------------------------------\n";
}

int	takeIndex(PhoneBook &phoneBook)
{
	int		index;
	while (true)
	{
		std::cout << "Enter the index of the contact you want to view: ";
		std::cin >> index;
		if (std::cin.fail() || index < 0 || index >= phoneBook.getNumOfContacts())
		{
			std::cin.clear();
			std::cin.ignore(100000000000, '\n');
			// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid index, please try again\n";
		}
		else
			break ;
	}
	return index;
}
void	hSearchContact(PhoneBook &phoneBook)
{
	int		numOfContacts;
	int	index;

	numOfContacts = phoneBook.getNumOfContacts();
	if (numOfContacts == 0)
	{
		std::cout << "No contacts available ❌" << std::endl;
		printMenu();
		return ;
	}
	contackHeader();
	phoneBook.displayContacts();
	contackHeaderFooter();
	index = takeIndex(phoneBook);
	phoneBook.chooseContact(index);
	printMenu();
}

int main()
{
	PhoneBook	phoneBook;
	std::string	input;

	printMenu();

	while (true)
	{
		if(!(getline(std::cin, input)))
			break ;
		if (input == "ADD" )
			haddContact(phoneBook);
		else if (input == "SEARCH")
			hSearchContact(phoneBook);
		else if (input == "EXIT")
			break ;
	}
}
