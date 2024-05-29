# 10.16 (Account Inheritance Hierarchy) Create an inheritance hierarchy that a bank might use to represent customer
# bank accounts. All customers at this bank can deposit money into their accounts and withdraw money from their
# accounts. More specific types of accounts also exist. Savings accounts, for instance, earn interest on the money
# they hold. Checking accounts, on the other hand, don’t earn interest and charge a fee per transaction.
# Start with class Account from this chapter and create two subclasses SavingsAccount and CheckingAccount.
# A SavingsAccount should also include a data attribute indicating the interest rate.
# A SavingsAccount’s calculate_interest method  should return the Decimal result of multiplying the interest rate
# by the account balance. SavingsAccount should inherit methods deposit and withdraw without redefining them.
# A CheckingAccount should include a Decimal data attribute that represents the fee charged per transaction.
# Class CheckingAccount should override methods deposit and withdraw so that they subtract the fee from the account
# balance whenever either transaction is performed successfully. CheckingAccount’s versions of these methods should
# invoke the base-class Account versions to update the account balance. CheckingAccount’s withdraw method should
# charge a fee only if money is withdrawn (that is, the withdrawal amount does not exceed the account balance).
# Create objects of each class and tests their methods.
# Add interest to the SavingsAccount object by invoking its calculate_interest method, then passing the returned
# interest amount to the object’s deposit method.

from decimal import Decimal


class Account:
    """Account class for maintaining a bank account balance."""

    def __init__(self, name, balance):
        """Initialize an Account object."""

        # if balance is less than 0.00, raise an exception
        if balance < Decimal('0.00'):
            raise ValueError('Initial balance must be >= to 0.00.')

        self.name = name
        self.balance = Decimal(balance)

    def deposit(self, amount):
        """Deposit money to the account."""

        # if amount is less than 0.00, raise an exception
        if amount < Decimal('0.00'):
            raise ValueError('Amount must be positive.')

        self.balance += amount

    def withdraw(self, amount):
        """Withdraw money from the account."""

        # if amount is less than 0.00, raise an exception
        if amount < Decimal('0.00'):
            raise ValueError('Amount must be positive.')

        # if balance is less than amount, raise an exception
        if self.balance < amount:
            raise ValueError('Insufficient funds.')

        self.balance -= amount


class SavingsAccount(Account):
    """SavingsAccount class that inherits from Account."""

    def __init__(self, name, balance, interest_rate):
        """Initialize a SavingsAccount object."""
        super().__init__(name, balance)
        self.interest_rate = Decimal(interest_rate)

    def calculate_interest(self):
        """Calculate interest based on the current balance."""
        return self.balance * self.interest_rate


class CheckingAccount(Account):
    """CheckingAccount class that inherits from Account."""

    def __init__(self, name, balance, transaction_fee):
        """Initialize a CheckingAccount object."""
        super().__init__(name, balance)
        self.transaction_fee = Decimal(transaction_fee)

    def deposit(self, amount):
        """Deposit money to the account, deducting the transaction fee."""
        if amount < Decimal('0.00'):
            raise ValueError('Amount must be positive.')

        if amount <= self.transaction_fee:
            raise ValueError('Deposit amount must be greater than the transaction fee.')

        super().deposit(amount - self.transaction_fee)

    def withdraw(self, amount):
        """Withdraw money from the account, deducting the transaction fee."""
        if amount < Decimal('0.00'):
            raise ValueError('Amount must be positive.')

        total_withdraw = amount + self.transaction_fee
        if self.balance < total_withdraw:
            raise ValueError('Insufficient funds.')

        super().withdraw(total_withdraw)


# Create objects of each class and test their methods
# SavingsAccount example
savings = SavingsAccount(name='Alice', balance=1000, interest_rate=0.05)
print(f'Initial Savings Account Balance: {savings.balance:.2f}')
interest = savings.calculate_interest()
savings.deposit(interest)
print(f'Savings Account Balance after adding interest: {savings.balance:.2f}')

# CheckingAccount example
checking = CheckingAccount(name='Bob', balance=500, transaction_fee=2.50)
print(f'Initial Checking Account Balance: {checking.balance:.2f}')
checking.deposit(100)
print(f'Checking Account Balance after deposit: {checking.balance:.2f}')
checking.withdraw(50)
print(f'Checking Account Balance after withdrawal: {checking.balance:.2f}')
