use practical_2;

-- Customer Table

CREATE TABLE Customer (
CustID INT PRIMARY KEY,
Name VARCHAR(30),
City VARCHAR(20)
);

-- Account Table

CREATE TABLE Account (
AccNo INT PRIMARY KEY,
CustID INT,
Balance DECIMAL(10,2),
BranchName VARCHAR(20),
FOREIGN KEY (CustID) REFERENCES Customer(CustID)
);

-- Loan Table

CREATE TABLE Loan (
LoanNo INT PRIMARY KEY,
CustID INT,
Amount DECIMAL(10,2),
BranchName VARCHAR(20),
FOREIGN KEY (CustID) REFERENCES Customer(CustID)
);

-- Branch Table

CREATE TABLE Branch (
BranchName VARCHAR(20) PRIMARY KEY,
City VARCHAR(20)
);

-- Insert Sample Data
-- Customers

INSERT INTO Customer VALUES
(1, 'Anil', 'Nagpur'),
(2, 'Sunita', 'Mumbai'),
(3, 'Mehul', 'Delhi'),
(4, 'Priya', 'Nagpur'),
(5, 'Naren', 'Pune');

-- Branches

INSERT INTO Branch VALUES
('VRCE', 'Nagpur'),
('AJNI', 'Nagpur'),
('KAROLBAGH', 'Delhi'),
('ANDHERI', 'Mumbai'),
('MGROAD', 'Pune');

-- Accounts

INSERT INTO Account VALUES
(1001, 1, 5000, 'VRCE'),
(1002, 2, 8000, 'AJNI'),
(1003, 3, 12000, 'KAROLBAGH'),
(1004, 4, 3000, 'ANDHERI'),
(1005, 5, 15000, 'MGROAD');

-- Loans

INSERT INTO Loan VALUES
(2001, 1, 4000, 'VRCE'),
(2002, 2, 6000, 'AJNI'),
(2003, 3, 10000, 'KAROLBAGH'),
(2004, 4, 2000, 'ANDHERI'),
(2005, 5, 12000, 'MGROAD');

-- Assignment Questions (Simplified Subqueries & Nested Queries)
/* 
1.Find customers who have balance more than 8000.
2.List customers who have taken a loan amount greater than 5000.
3.Find customers who have an account in the Nagpur branches.
4.Find the customer(s) who have the maximum loan amount.
5.Find the branch where Sunita has her account.
6.Find customers who have a loan in the Delhi branch.
7.Find customers whose balance is equal to 5000.
8.Find the loan amount of Priya.
9.Find customers who belong to the same city as Naren.
10.Find the branch name where Anil has his loan.
11.Find all customers whose balance is less than Sunita’s balance.
12.Find the customer who has the minimum loan amount.
13.Find customers whose loan amount is equal to their account balance.
14.Find customers who do not have a loan.
15.Find customers who do not have an account.
*/

-- 1.Find customers who have balance more than 8000.
select * from customer where custid in (select custid from account where balance>8000);

-- 2.List customers who have taken a loan amount greater than 5000.
select * from customer where custid in (select custid from loan where amount>5000);

-- 3.Find customers who have an account in the Nagpur branches.
select name from customer where custid in
(select custid from account where branchname in 
(select branchname from branch where city='Nagpur')
);

-- 4.Find the customer(s) who have the maximum loan amount.
SELECT Name
FROM Customer
WHERE CustID IN (
    SELECT CustID
    FROM Loan
    WHERE Amount = (SELECT MAX(Amount) FROM Loan)
);

-- 5.Find the branch where Sunita has her account.
-- custid where customer.name= sunita
-- branchname where account.custid =customer.custid

SELECT BranchName
FROM Account
WHERE CustID = (
    SELECT CustID FROM Customer WHERE Name = 'Sunita'
);

-- 6.Find customers who have a loan in the Delhi branch.
SELECT Name
FROM Customer
WHERE CustID IN (
    SELECT CustID
    FROM Loan
    WHERE BranchName IN (
        SELECT BranchName
        FROM Branch
        WHERE City = 'Delhi'
    )
);

-- 7.Find customers whose balance is equal to 5000.
SELECT Name
FROM Customer
WHERE CustID IN (
    SELECT CustID
    FROM Account
    WHERE Balance = 5000
);

-- 8.Find the loan amount of Priya.
SELECT Amount
FROM Loan
WHERE CustID = (
    SELECT CustID FROM Customer WHERE Name = 'Priya'
);

-- 9.Find customers who belong to the same city as Naren.
SELECT Name
FROM Customer
WHERE City = (
    SELECT City FROM Customer WHERE Name = 'Naren'
)
AND Name <> 'Naren';

-- 10.Find the branch name where Anil has his loan.
SELECT BranchName
FROM Loan
WHERE CustID = (
    SELECT CustID FROM Customer WHERE Name = 'Anil'
);

-- 11.Find all customers whose balance is less than Sunita’s balance.
SELECT Name
FROM Customer
WHERE CustID IN (
    SELECT CustID
    FROM Account
    WHERE Balance < (
        SELECT Balance
        FROM Account
        WHERE CustID = (SELECT CustID FROM Customer WHERE Name = 'Sunita')
    )
);

-- 12.Find the customer who has the minimum loan amount.
SELECT Name
FROM Customer
WHERE CustID IN (
    SELECT CustID
    FROM Loan
    WHERE Amount = (SELECT MIN(Amount) FROM Loan)
);

-- 13.Find customers whose loan amount is equal to their account balance.
SELECT Name
FROM Customer
WHERE CustID IN (
    SELECT A.CustID
    FROM Account A
    JOIN Loan L ON A.CustID = L.CustID
    WHERE A.Balance = L.Amount
);

-- 14.Find customers who do not have a loan.
SELECT Name
FROM Customer
WHERE CustID NOT IN (SELECT CustID FROM Loan);

-- 15.Find customers who do not have an account.
SELECT Name
FROM Customer
WHERE CustID NOT IN (SELECT CustID FROM Account);



