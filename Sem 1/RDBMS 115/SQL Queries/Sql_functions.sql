use practice_dp;


-- SQL FUNCTIONS
-- 1 Print the absolute value of –15.35
SELECT ABS(- 15.35)

-- 2 Calculate 3.25 raised to 2.25
SELECT POWER(3.25, 2.25)

-- 3 Display the rounded value of 3.1417 upto 3 decimal places.
SELECT ROUND(3.1417, 3)

-- 4 Display the truncated value of 3.1417 upto 3 decimal places.
SELECT TRUNCATE(3.1417, 3)

-- 5 Find the square root of 17 and –13 if possible.
select sqrt(17),sqrt(-13);

-- 6 Print the value of e to the 5th power
select exp(5);


-- 7 Print the ceil value and floor value of 15.72
select ceil(15.72) , floor(15.72);

-- 8 Find the value of 13 mod 5
select mod(13,5);

-- 9 Add 275 months to your date of birth and display it.
select date_add('2003-07-20' , interval 275 month) as Result;

-- 10 Find the value sin of 100, and log 100 to the base 10
select sin(100),log(10,100);

-- Create a database of books :- (no, title, author, publication, price, edition)
-- 1) create the database and switch to it
CREATE DATABASE IF NOT EXISTS books_db;
USE books_db;

-- 2) create the table
CREATE TABLE IF NOT EXISTS books (
  `no` INT UNSIGNED NOT NULL AUTO_INCREMENT,   -- book number (primary key)
  title VARCHAR(255) NOT NULL,
  author VARCHAR(200) NOT NULL,
  publication VARCHAR(200),                    -- publisher name
  price DECIMAL(10,2) DEFAULT 0.00,           -- price with 2 decimals
  edition VARCHAR(50),                        -- e.g. '1st', 'Revised 2nd', '2021'
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`no`),
  INDEX idx_title (title),
  INDEX idx_author (author)
);

-- 3) sample inserts
INSERT INTO books (title, author, publication, price, edition) VALUES
('Introduction to Algorithms', 'Thomas H. Cormen', 'MIT Press', 799.00, '3rd'),
('Clean Code', 'Robert C. Martin', 'Prentice Hall', 499.00, '1st'),
('You Don''t Know JS: Scope & Closures', 'Kyle Simpson', 'O''Reilly', 299.00, '2nd'),
('Database System Concepts', 'Abraham Silberschatz', 'McGraw-Hill', 650.00, '6th'),
('Design Patterns', 'Erich Gamma', 'Addison-Wesley', 599.00, '1st');

-- 4) basic select queries
-- all books
SELECT 
    *
FROM
    books;

select * from books;	

-- 11 List the names of author starting with capital letter.
-- select author from books where author=initcap(author);
select author from books where left(author,1) between 'A' and 'Z';

-- 12 Display the name of book in both lower and upper case using a single query.
select lower(title) as Lower,upper(title)as Upper from books;

-- 13 Display the output : ‘BAD’ using CHR function.
SELECT CONCAT(CHAR(66), CHAR(65), CHAR(68)) AS result;

-- 14 Display the price of books in the following format : ****450
select concat("****",format(price,0)) as Formatted_Price from books;
-- 15 Display the price of books in the following format : 450*/*/
SELECT CONCAT(FORMAT(price, 0), '*/*/') AS Formatted_Price
FROM books;

-- 16 Display the publication of PHI as Pearson (Use replace…)
select replace(publication,'PHI','Pearson') from books;

-- 17 Display the title of books and trim the ending part if it ends with prog.

-- 18 Display the titles of books which contains ‘++’ in it.
select title from books where title like "%++%";

-- 19 Modify the column size of author.
alter table books modify author varchar(80);

-- 20 Add a new column author2 to the table.
alter table books add author2 varchar(80);
select * from books;


-- STUDENT MARKS TABLE QUERIES 
-- 1 Create a table stud_marks which contains (no, fname, lname, m1, m2, m3, dob) 
-- m1,m2,m3 :- marks of 3 subjects, Enter atleast 10 values in this table
--  Create table
CREATE TABLE stud_marks(
no INT,
fname VARCHAR(30),
lname VARCHAR(30),
m1 INT,
m2 INT,
m3 INT,
dob DATE
);

INSERT INTO stud_marks (no, fname, lname, m1, m2, m3, dob) VALUES
(1, 'Amit', 'Shah', 78, 82, 69, '2002-05-10'),
(2, 'Priya', 'Patel', 88, 91, 85, '2001-11-22'),
(3, 'Rahul', 'Mehta', 67, 73, 70, '2002-02-14'),
(4, 'Sneha', 'Rao', 92, 89, 95, '2003-01-08'),
(5, 'Karan', 'Desai', 54, 60, 58, '2001-07-30'),
(6, 'Neha', 'Joshi', 81, 77, 84, '2002-09-19'),
(7, 'Vivek', 'Trivedi', 69, 72, 75, '2003-04-05'),
(8, 'Riya', 'Kapoor', 90, 94, 89, '2001-12-12'),
(9, 'Dhruv', 'Panchal', 73, 68, 80, '2002-03-03'),
(10, 'Jiya', 'Sharma', 85, 79, 83, '2003-06-25');

insert into stud_marks values(11, 'Dhruvi', 'Panchal', 33, 68, 80, '2002-04-03'),
(12, 'Jinal', 'Sharma', 85, 23, 83, '2004-06-25'),
(13 ,'Dhruvika', 'Rathod', 33, 34 ,80, '2002-04-03'),
(14, 'Jeel', 'Sharma', 85, 23, 22, '2003-06-25');


-- 2 Display the details in following order :- RollNo.	Lname,	Fname
select no as Rollno, Lname, Fname from stud_marks;

-- 3 Find the current age of each student.
select no,lname,fname,timestampdiff(year,dob,curdate()) as age from stud_marks;

-- 4 Display the total marks of each student along with the rollno
select no,m1+m2+m3 as Total_marks from stud_marks;

-- 5 Display the percentage of each student
select no,(m1+m2+m3)/3 as Percentage from stud_marks;

-- 6 Display the students scoring highest marks in each subject.
select * from stud_marks where m1=(select max(m1) as Subject1 from stud_marks);
select * from stud_marks where m2=(select max(m2) as Subject1 from stud_marks);
select * from stud_marks where m3=(select max(m3) as Subject1 from stud_marks);

-- 7 Display the students scoring highest total marks
select * from stud_marks where (m1+m2+m3)=(select max(m1+m2+m3) as Subject1 from stud_marks);

-- 8 Display the students whose name starts with ‘S’.
select * from stud_marks where fname like "S%";

-- 9 Display the students whose surname ends with ‘kar’
select * from stud_marks where lname like "%ah";

-- 10 List all the students who fails in any one of the subjects.
select * from stud_marks where m1<35 or m2<35 or m3<35;

-- 11 List all the students who are passing in all subjects but the percentage < 60
SELECT * FROM stud_marks WHERE m1>35 AND m2>=35 AND m3>=35 AND
((m1+m2+m3)/3)<60;

-- 12 List the students whose total marks are between 50 and 60
select * from stud_marks where (m1+m2+m3) between 50 and 60;

-- 13 List all the students whose name does not start with ‘S’
select * from stud_marks where fname not like "S%";

-- 14 Update the table, set marks m1=40 for those students 
-- who scored a total of atleast 100 marks in m2 and m3
update stud_marks
set m1=40 where (m2+m3)>=100;

-- 15 Display the students whose marks are either 50, 60 or 70.
select * from stud_marks where m1 in (50,60,70) or 	m2 in (50,60,70) or m3 in (50,60,70);

-- 16 List all the students born in the month of January.
select * from stud_marks WHERE EXTRACT(MONTH FROM dob)=1;
select * from stud_marks where month(dob)=1;

-- 17 List all the students whose date of birth is even no.
select * from stud_marks where extract(day from dob)%2=0 ;
SELECT * FROM stud_marks WHERE day(dob)%2=0;

-- 18 Find the age of students in terms of months passed
select no,timestampdiff(month,dob,curdate()) as Age_inMonths from stud_marks;

-- 19 Display the students whose date of birth falls in the first quarter of the year
select * from stud_marks where month(dob) between 1 and 3;
select * from stud_marks where extract(month from dob) between 1 and 3;

-- 20 Find the date, 15 days after today’s date.
SELECT DATE_ADD(CURDATE(), INTERVAL 15 DAY) AS date_after_15_days;

-- 21 List the students whose name contains vowels (small)
SELECT * FROM stud_marks WHERE fname  REGEXP'[aeiou]';

-- 22 List the students whose name does not contain vowels
SELECT * FROM stud_marks WHERE fname NOT REGEXP'[aeiou]';

-- 23 Count the no. of students whose name starts with ‘S’
select count(*) from stud_marks where fname like "S%";

-- 24 Count the no. of students whose name ends with ‘kar’
select count(*) from stud_marks where lname like "%kar";

-- 25 Display the names of student in following format 
-- Eg. If name is ‘hardik’ & surname is ‘joshi’ then display ‘harshi’
SELECT CONCAT(SUBSTR(fname, 1, 3), RIGHT(lname, 3)) AS result
FROM stud_marks;

-- 26 Display the rows which contains null values in m1, m2 or m3
select * from stud_marks where m1 is NULL or m2 is null or m3 is null;

-- 27 Display the rows which does not contain null values in name
select * from stud_marks where fname is not null;

-- 28 Display the rows where name sounds like ‘sachin’ (use soundex function)
select * from stud_marks where soundex(fname) = soundex("sachin");

-- 29 Generate a random no. using date
SELECT MOD(unix_timestamp(),1000) as Random_no ;
-- select floor(rand() * 1000) as Random_no; 
SELECT MOD(TO_DAYS(CURDATE()), 1000) AS random_no;

-- 30 Display the output in following form :- <Name was born on Day> Eg. Hardik was born on Thursday.
SELECT CONCAT(fname, ' was born on ', DAYNAME(dob), '.') AS result FROM stud_marks;

