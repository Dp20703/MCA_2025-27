use practical_1;

# create tables:
create table Deposit(
ACTNO VARCHAR(5),
CNAME VARCHAR(18),
BNAME VARCHAR(18),
AMOUNT DECIMAL(8,2),
ADATE DATE
);

create table BORROW(
LOANNO VARCHAR(5),
CNAME VARCHAR(18),
BNAME VARCHAR(18),
AMOUNT DECIMAL(8,2)
);

CREATE TABLE CUSTOMER(
CNAME VARCHAR(18),
CITY VARCHAR(18));

CREATE TABLE BRANCH(
BNAME VARCHAR(18),
CITY VARCHAR(18));


# Insert values into talbes 
INSERT INTO deposit VALUES
(100, 'ANIL', 'VRCE', 1000, '1995-03-01'),
(101, 'SUNIL', 'AJNI', 5000, '1998-01-04'),
(102, 'MEHUL', 'KAROLBAGH', 3500, '1995-11-17'),
(104, 'MADHURI', 'CHANDNI', 1200, '1995-12-17'),
(105, 'PRAMOD', 'MGROAD', 3000, '1996-03-27'),
(106, 'SANDIP', 'ANDHERI', 2000, '1996-03-31'),
(107, 'SHIVANI', 'VIRAR', 1000, '1995-09-05'),
(108, 'KRANTI', 'NEHRUPLACE', 5000, '1995-07-02'),
(109, 'NAREN', 'POWAI', 7000, '1995-10-10');

SELECT * FROM DEPOSIT;

INSERT INTO customer VALUES
('ANIL', 'CALCUTTA'),
('SUNIL', 'DELHI'),
('MEHUL', 'BARODA'),
('MANDAR', 'PATNA'),
('MADHURI', 'NAGPUR'),
('PRAMOD', 'NAGPUR'),
('SANDIP', 'SURAT'),
('SHIVANI', 'BOMBAY'),
('KRANTI', 'BOMBAY'),
('NAREN', 'BOMBAY');

select * from customer;

INSERT INTO branch VALUES
('VRCE', 'NAGPUR'),
('AJNI', 'NAGPUR'),
('KAROLBAGH', 'DELHI'),
('CHANDNI', 'DELHI'),
('DHARAMPETH', 'NAGPUR'),
('MGROAD', 'BANGALORE'),
('ANDHERI', 'BOMBAY'),
('VIRAR', 'BOMBAY'),
('NEHRUPLACE', 'DELHI'),
('POWAI', 'BOMBAY');

select * from branch;

INSERT INTO borrow VALUES
(201, 'ANIL', 'VRCE', 1000),
(206, 'MEHUL', 'AJNI', 5000),
(311, 'SUNIL', 'DHARAMPETH', 3000),
(321, 'MADHURI', 'ANDHERI', 2000),
(375, 'PRAMOD', 'VIRAR', 8000),
(481, 'KRANTI', 'NEHRUPLACE', 3000);

select * from borrow;


# Questions: 
/*
1. Display all the deposit details of customer Anil. 
2. List all customers who are living in Bombay. 
3. Show depositors who have deposited more than 3000. 
4. Display borrowers who have taken a loan of less than 5000. 
5. Find all depositors from Nagpur branch. 
6. Show the total deposit amount in the bank.
7. Find the maximum deposit amount and the customer who made it.
8. Display the average loan amount of all borrowers.
9. Show the number of customers living in each city. 
10. Find the total deposit amount branch–wise. 
11. List depositors who deposited between 2000 and 6000. 
12. Display borrowers who belong to the branch Andheri. 
13. Find the minimum loan amount and the customer who took it.
14. Show the total number of depositors.
 15. List all customers whose account date is after 01-JAN-1996.
*/
# 1. Display all the deposit details of customer Anil. 
select * from deposit where cname='anil';

# 2. List all customers who are living in Bombay. 
select * from customer where city='bombay';

# 3. Show depositors who have deposited more than 3000. 
select cname,amount from deposit where amount>3000; 

# 4. Display borrowers who have taken a loan of less than 5000.
select cname, amount from borrow where amount<5000;

# 5. Find all depositors from Nagpur branch. 
select cname from deposit where bname in (select bname from branch where city='nagpur') ;

# 6. Show the total deposit amount in the bank.
select sum(amount) as Total_deposit from deposit ;

# 7. Find the maximum deposit amount and the customer who made it.
select amount , cname from deposit where amount=(select max(amount) from deposit);

# 8. Display the average loan amount of all borrowers.
select avg(amount) as Avg_loan_amount from borrow;

# 9. Show the number of customers living in each city.
select city, count(cname) as number_of_customers from customer group by city;

# 10. Find the total deposit amount branch–wise. 
select bname,sum(amount) from deposit group by bname order by bname;

# 11. List depositors who deposited between 2000 and 6000. 
select cname, amount from deposit where amount between 2000 and 6000;

# 12. Display borrowers who belong to the branch Andheri.
select cname from borrow where bname='andheri';

# 13. Find the minimum loan amount and the customer who took it.
select amount, cname from borrow where amount=(select min(amount) from borrow ) ;

# 14. Show the total number of depositors.
select count(distinct cname) as Number_of_depositors from deposit; 

# 15. List all customers whose account date is after 01-JAN-1996.
select cname , adate  from deposit where adate > '1996-01-01' ;



