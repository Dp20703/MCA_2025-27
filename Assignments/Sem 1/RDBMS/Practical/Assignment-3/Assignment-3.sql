use a3;

/* create tables */
create table customer(
CustID int primary key,
Name varchar(30),
City Varchar(20)
);

create table Account(
AccNo Int Primary key,
CustID int,
Balance decimal(10,2),
BranchName varchar(20),
Foreign key(CustID) references Customer(CustID));

create table Loan(
LoanNo int primary key,
CustId int,
Amount Decimal(10,2),
BranchName varchar(20),
foreign key (CustId) references Customer(CustId));

create table Branch(
BranchName varchar(20),
City Varchar(20));

/* insert values */
INSERT INTO Customer VALUES
(1, 'Anil', 'Nagpur'),
(2, 'Sunita', 'Mumbai'),
(3, 'Mehul', 'Delhi'),
(4, 'Priya', 'Nagpur'),
(5, 'Naren', 'Pune');

INSERT INTO Branch VALUES
('VRCE', 'Nagpur'),
('AJNI', 'Nagpur'),
('KAROLBAGH', 'Delhi'),

('ANDHERI', 'Mumbai'),
('MGROAD', 'Pune');

INSERT INTO Account VALUES
(1001, 1, 5000, 'VRCE'),
(1002, 2, 8000, 'AJNI'),
(1003, 3, 12000, 'KAROLBAGH'),
(1004, 4, 3000, 'ANDHERI'),
(1005, 5, 15000, 'MGROAD');

INSERT INTO Loan VALUES
(2001, 1, 4000, 'VRCE'),
(2002, 2, 6000, 'AJNI'),
(2003, 3, 10000, 'KAROLBAGH'),
(2004, 4, 2000, 'ANDHERI'),
(2005, 5, 12000, 'MGROAD');

-- Simple Inner Query Practice
-- 1. Display all balances from the Account table.
SELECT Balance FROM Account;

-- 2. Display all loan amounts from the Loan table.
SELECT Amount FROM Loan;

-- 3. Find the maximum loan amount.
SELECT MAX(Amount) AS Maximum_Loan FROM Loan;

-- 4. Find the minimum account balance.
SELECT MIN(Balance) AS Minimum_Balance FROM Account;

-- 5. Find the average account balance.
SELECT AVG(Balance) AS Avg_Balance FROM Account;

-- 6. Display all branch names located in ‘Nagpur’.
SELECT BranchName FROM Branch WHERE City = 'Nagpur';

-- Subqueries using ANY
-- 7. Display customers whose account balance is greater than ANY loan amount.
SELECT Name 
FROM Customer
WHERE CustID IN (
  SELECT CustID 
  FROM Account 
  WHERE Balance > ANY (SELECT Amount FROM Loan)
);

-- 8. Display customers whose account balance is less than ANY loan amount.
SELECT Name 
FROM Customer
WHERE CustID IN (
  SELECT CustID 
  FROM Account 
  WHERE Balance < ANY (SELECT Amount FROM Loan)
);

-- 9. Find customers whose loan amount is greater than ANY account balance.
SELECT Name 
FROM Customer
WHERE CustID IN (
  SELECT CustID 
  FROM Loan 
  WHERE Amount > ANY (SELECT Balance FROM Account)
);

-- 10. Display customers whose loan amount is greater than ANY loan amount taken in ‘AJNI’ branch.
SELECT Name 
FROM Customer
WHERE CustID IN (
  SELECT CustID 
  FROM Loan 
  WHERE Amount > ANY (
    SELECT Amount 
    FROM Loan 
    WHERE BranchName = 'AJNI'
  )
);

-- 11. Display customers whose account balance is greater than ANY account balance in ‘Nagpur’ branches.
SELECT Name 
FROM Customer
WHERE CustID IN (
  SELECT CustID 
  FROM Account 
  WHERE Balance > ANY (
    SELECT Balance 
    FROM Account 
    WHERE BranchName IN (
      SELECT BranchName FROM Branch WHERE City = 'Nagpur'
    )
  )
);

-- 12. Display customers whose loan amount is greater than ANY balance of customers in the ‘Pune’ branches.
SELECT Name 
FROM Customer
WHERE CustID IN (
  SELECT CustID 
  FROM Loan 
  WHERE Amount > ANY (
    SELECT Balance 
    FROM Account 
    WHERE BranchName IN (
      SELECT BranchName FROM Branch WHERE City = 'Pune'
    )
  )
);

-- Subqueries using ALL
-- 13. Display customers whose account balance is greater than ALL loan amounts.
SELECT Name 
FROM Customer
WHERE CustID IN (
  SELECT CustID 
  FROM Account 
  WHERE Balance > ALL (SELECT Amount FROM Loan)
);

-- 14. Display customers whose loan amount is greater than ALL account balances.
SELECT Name 
FROM Customer
WHERE CustID IN (
  SELECT CustID 
  FROM Loan 
  WHERE Amount > ALL (SELECT Balance FROM Account)
);

-- 15. Find customers whose account balance is less than ALL loan amounts.
SELECT Name 
FROM Customer
WHERE CustID IN (
  SELECT CustID 
  FROM Account 
  WHERE Balance < ALL (SELECT Amount FROM Loan)
);

-- 16. Display customers whose loan amount is greater than ALL loan amounts taken in ‘KAROLBAGH’ branch.
SELECT Name 
FROM Customer
WHERE CustID IN (
  SELECT CustID 
  FROM Loan 
  WHERE Amount > ALL (
    SELECT Amount 
    FROM Loan 
    WHERE BranchName = 'KAROLBAGH'
  )
);

-- 17. Find customers whose account balance is greater than ALL account balances in ‘ANDHERI’ branch.
SELECT Name 
FROM Customer
WHERE CustID IN (
  SELECT CustID 
  FROM Account 
  WHERE Balance > ALL (
    SELECT Balance 
    FROM Account 
    WHERE BranchName = 'ANDHERI'
  )
);

-- 18. Display customers whose loan amount is greater than ALL loan amounts of ‘Nagpur’ branches.
SELECT Name 
FROM Customer
WHERE CustID IN (
  SELECT CustID 
  FROM Loan 
  WHERE Amount > ALL (
    SELECT Amount 
    FROM Loan 
    WHERE BranchName IN (
      SELECT BranchName FROM Branch WHERE City = 'Nagpur'
    )
  )
);