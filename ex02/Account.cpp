#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"

class Account {

public:

	static int	getNbAccounts( void )
    {

    }

	static int	getTotalAmount( void )
    {

    }

	static int	getNbDeposits( void )
    {

    }

	static int	getNbWithdrawals( void )
    {

    }

	static void	displayAccountsInfos( void )
    {

    }

	Account( int initial_deposit )
    {

    }

	~Account( void );

	void	makeDeposit( int deposit )
    {

    }

	bool	makeWithdrawal( int withdrawal )
    {
        if (withdrawal > _amount)
            return (0);
        else
        {
            _amount = _amount - withdrawal;
            _nbWithdrawals++;
        }
    }

	int		checkAmount( void ) const
    {

    }

	void	displayStatus( void ) const
    {

    }


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void )
    {
        
    }

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

    Account( void )
    {

    }

};

int main()
{
    
}