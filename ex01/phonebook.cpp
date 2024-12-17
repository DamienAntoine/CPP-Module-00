#include <iostream>
#include <iomanip>

std::string    truncate(const std::string &str)
{
    if (str.length() > 8)
        return (str.substr(0, 8) + ".");
    else
        return (str);
}

class Contact
{
private :
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

	void setContact(
		const std::string &first_name,
		const std::string &last_name,
		const std::string &nickname,
		const std::string &phone_number,
		const std::string &darkest_secret
	) {
		this->first_name = first_name;
		this->last_name = last_name;
		this->nickname = nickname;
		this->phone_number = phone_number;
		this->darkest_secret = darkest_secret;
	}

    std::string getFirstName() const { return first_name; }
    std::string getLastName() const { return last_name; }
    std::string getNickname() const { return nickname; }
    std::string getPhoneNumber() const { return phone_number; }
    std::string getDarkestSecret() const { return darkest_secret; }

	void displayContact(int i) const
	{
		std::cout << std::right
        << "Contact: " << std::setw(10) << i + 1 << " |"
        << " First Name: " << std::setw(10) << truncate(first_name) << " |"
		<< " Last Name: " << std::setw(10) << truncate(last_name) << " |"
		<< " Nickname: " << std::setw(10) << truncate(nickname) << " |"
		<< " Phone Number: " << std::setw(10) << truncate(phone_number)
        << std::endl;
	}
};

class PhoneBook
{
private:
	static const int	max_contacts = 8;
	Contact				contacts[max_contacts];
	int					contact_count;
	int					next_index;

public:
	PhoneBook() : contact_count(0), next_index(0) {}

	void	add_contact (
	const std::string &first_name,
	const std::string &last_name,
	const std::string &nickname,
	const std::string &phone_number,
	const std::string &darkest_secret)
	{
		contacts[next_index].setContact(first_name, last_name, nickname, phone_number, darkest_secret);
		next_index = (next_index + 1) % max_contacts;
		if (contact_count < max_contacts)
			contact_count++;
		std::cout << "Contact added successfully." << std::endl;
	}

	void search_contacts() const
	{
		static int i;
		if (contact_count == 0)
			std::cout << "No contacts." << std::endl;
		else
		{
			i = 0;
			while (i < contact_count)
			{
				//std::cout << "Contact " << i + 1 << ": ";
				contacts[i].displayContact(i);
				i++;
			}
		}
	}
};

void	getInput(const std::string &prompt, std::string &input)
{
	while (input.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Input cannot be empty." << std::endl;
	}
}

int	main()
{
	PhoneBook phonebook;
	std::string command;

	while (1)
	{
		std::cout << "Enter command." << std::endl;
		std::cout << "(Available commands : ADD ; SEARCH ; EXIT)" << std::endl;
		std::getline(std::cin, command);

		if (command == "ADD" || command == "add")
		{
			std::string first_name, last_name, nickname, phone_number, darkest_secret;
			getInput("Enter first name: ", first_name);
            getInput("Enter last name: ", last_name);
            getInput("Enter nickname: ", nickname);
            getInput("Enter phone number: ", phone_number);
            getInput("Enter darkest secret: ", darkest_secret);
            phonebook.add_contact(first_name, last_name, nickname, phone_number, darkest_secret);
            std::cout << std::endl;
		}
		else if (command == "SEARCH" || command == "search")
		{
			phonebook.search_contacts();
			std::cout << std::endl;
		}
		else if (command == "EXIT" || command == "exit")
			break ;
		else
		{
			std::cout << "Invalid command." << std::endl;
			std::cout << std::endl;
		}
	}
}
