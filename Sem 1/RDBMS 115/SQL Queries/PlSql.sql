											-- Procedures and Functions
use practice_dp;	
									
-- 1.	Write a PL/SQL block that selects the maximum department number in the department table 
-- and store it in a SQL*PLUS variable. And print the results to screen.
CREATE TABLE department (
    deptno INT PRIMARY KEY,
    deptname VARCHAR(50)
);
alter table department add location varchar(55);
INSERT INTO department VALUES
(10, 'HR'),
(20, 'Sales'),
(30, 'Finance'),
(40, 'IT');



delimiter $$
create procedure get_max_dept()
begin
select max(deptno) as Max_dept from department;
end $$
delimiter ;

call get_max_dept();


-- 2.	Create a PL/SQL block to insert a new department number into the Departments table. 
-- Use maximum dept number fetched from above and adds 10 to it.
--  Use SQL*PLUS substitution variable for department name. Leave the location AS null.

delimiter $$
create procedure insert_new_dept(In d_name varchar(55))
begin
 declare max_dept int;
 select max(deptno) into max_dept from department;
 insert into department(deptno,deptname,location) values(max_dept+10,d_name,null);
 select "New Record Inserted Successfully ! " as Message;

end $$
delimiter ;

call insert_new_dept("HR");

-- 3.	Create a PL/SQL block to update the location for an existing department.
--  Use substitution variable for dept no. and dept location.

delimiter $$
create procedure update_dept_loc(in dept_no int, in dept_loc varchar(50))
begin 
	update  department
    set location = dept_loc 
    where deptno=dept_no;
    select row_count() as row_updated;
end $$
delimiter ;

call update_dept_loc(40,"Ahmedabad");

SELECT 
    *
FROM
    department;

-- 4.	Create a PL/SQL Block to delete the department created in exercise 2.
-- 	Print to the screen the number of rows affected.

delimiter $$
create procedure delete_dept(in dept_no int)
begin 
	delete  from department
    where deptno=dept_no;
    select row_count() as row_updated;
end $$
delimiter ;

call delete_dept(50);

-- 5.	Write a PL/SQL block which accepts employee name, basic and should display Employee name, PF and net salary.
-- HRA=31% of basic salary DA=15% of basic salary
-- Net salary=basic+HRA+DA-PF

delimiter $$
create procedure calc_salary(in emp_name varchar(50), in basic decimal(10,2))
begin
	declare hra, da, pf , netsal decimal(10,2);
    set hra=basic*.31;
    set da=basic*.15;
    
    if basic < 3000 then
     set pf=basic * .05;
    elseif basic between 3000 and 5000 then
		set pf= basic *.07;
	 elseif basic between 5000 and 8000 then
		set pf= basic *.08;
	else 
		set pf= basic *.10;
	end if ;
    
	set netsal=basic+hra+da-pf;
    
	select emp_name as Employee_name , hra, da , pf , netsal;
end $$
delimiter ;

call calc_salary('darshna',100000.00);

-- 6.	Write a PL/SQL block to find the salary grade of the specified employee. If grade is 1 display ‘the employee is junior engineer’
-- If grade is 2 display ‘the employee is engineer’
-- If grade is 3 display ‘the employee is lead engineer’ If grade is 4 display ‘the employee is Manager’
-- If grade is 5 display ‘the employee is Project manager’ (Use case expression)

delimiter $$ 
create procedure grade_message(in grade int)
begin
select
   case grade	
   when 1 then  'the employee is junior engineer'
   when 2 then  'the employee is  engineer'
   when 3 then  'the employee is lead engineer'
   when 4 then  'the employee is manager'
   when 5 then  'the employee is Project Manager'
   else "Invalid grade"
   end as grade_message;
end $$
delimiter ;


call grade_message(5);



-- 7.	Wrtie a PL/SQL block to award an employee with the bonus. Bonus is 15% of commission drawn by the employee.
-- If the employee does not earn any commission then display a message that ‘employee does not earn any commission’.
--  Otherwise add bonus to the salary of the employee. The block should accept an input for the employee number.

CREATE TABLE employee (
    empno INT PRIMARY KEY,
    ename VARCHAR(50),
    salary DECIMAL(10,2),
    commission DECIMAL(10,2)
);
INSERT INTO employee VALUES
(101, 'Amit', 20000, 2000),
(102, 'Riya', 25000, NULL),
(103, 'John', 18000, 0),
(104, 'Mira', 30000, 5000);

select * from employee;
DELIMITER $$

CREATE PROCEDURE award_bonus(IN p_empno INT)
BEGIN
    DECLARE v_salary DECIMAL(10,2);
    DECLARE v_comm DECIMAL(10,2);
    DECLARE v_bonus DECIMAL(10,2);

    -- Fetch salary and commission
    SELECT salary, commission
    INTO v_salary, v_comm
    FROM employee
    WHERE empno = p_empno;

    -- Check if commission is NULL or zero
    IF v_comm IS NULL OR v_comm = 0 THEN
        SELECT 'Employee does not earn any commission' AS Message;
    ELSE
        -- Calculate bonus (15% of commission)
        SET v_bonus = v_comm * 0.15;

        -- Update salary by adding bonus
        UPDATE employee
        SET salary = salary + v_bonus
        WHERE empno = p_empno;

        SELECT CONCAT('Bonus added: ', v_bonus,
                      ', Updated salary: ', v_salary + v_bonus) AS Message;
    END IF;

END $$

DELIMITER ;


call award_bonus(102);

-- 8.	Write a PL/SQL block which displays the department name, 
-- total no of employees in the department, avg salary of the employees in the department
--  for all the departments from department 10 to department 40 in the Dept table.
-- If no employees are working in the department ,then display a message that no employees are working in that department.

drop table if exists department ;
select * from department;
CREATE TABLE department (
    deptno INT PRIMARY KEY,
    dname VARCHAR(50),
    location VARCHAR(50)
);

CREATE TABLE emp (
    empno INT PRIMARY KEY,
    ename VARCHAR(50),
    job VARCHAR(50),
    salary DECIMAL(10,2),
    deptno INT,
    FOREIGN KEY (deptno) REFERENCES department(deptno)
);

INSERT INTO department VALUES
(10, 'ACCOUNTING', 'NEW YORK'),
(20, 'RESEARCH', 'DALLAS'),
(30, 'SALES', 'CHICAGO'),
(40, 'OPERATIONS', 'BOSTON');

INSERT INTO emp VALUES
(101, 'Amit', 'Manager', 30000, 10),
(102, 'Riya', 'Clerk', 15000, 10),
(106, 'John', 'Analyst', 28000, 20),
(107, 'Mira', 'Salesman', 18000, 30),
(108, 'Sam', 'Clerk', 12000, 30);

delimiter $$
create procedure info()
begin 
	select d.deptno,d.dname , count(e.empno) as Total_employees, avg(e.salary) as Avg_Salary
    from department d left join emp e on d.deptno=e.deptno
    where d.deptno between 10 and 40
    group by d.deptno,d.dname; 
end $$
delimiter ;

call info();
select * from department;

-- 9.	Write a PL/SQL block which accepts employee number and
-- finds the average salary of the employees working in the department 
-- where that employee works.
-- If his salary is more than the average salary of his department, 
-- then display message that ‘employee’s salary is more than average salary’ 
-- else display ‘employee’s salary is less than average salary’
select avg(salary) as Avg_salary from emp where deptno=(select deptno from emp where empno=101);
select salary from emp where empno=101;

delimiter $$
create procedure compare__salary(in emp_no int)
begin
   declare emp_sal ,avg_sal decimal(10,2);
   declare emp_dept int;
   
   select salary,deptno into emp_sal,emp_dept from emp where empno=emp_no;
   
   select avg(salary) into avg_sal from emp where deptno=emp_dept;
   
   if emp_sal > avg_sal then
		select "employee’s salary is more than average salary" as message;
   else 
		select "employee’s salary is less than average salary" as message;
   end if ;
end $$
delimiter ;

call compare__salary(102);


-- 10.	Create a procedure that deletes rows from the emp table. It should accept 1 parameter, job; 
-- only delete the employee’s with that job. Display how many employees were deleted.

delimiter $$
create procedure delete_emp(in emp_job varchar(25))
begin 
	delete from emp 
    where job=emp_job;
    select row_count() as Deleted;
end $$
delimiter ;

call delete_emp("Clerk");
select * from emp;

-- 11.	Change the above procedure so that it returns the number of employees removed via an OUT parameter.
delimiter $$
create procedure deleteEmp(in emp_job varchar(25),out deleted int)
begin 
	delete from emp 
    where job=emp_job;
    set deleted= row_count() ;
end $$
delimiter ;

call  deleteEmp("Salesman",@deleted) ;
select @deleted as Deleted_row ;
select * from emp;

-- 12.	Convert the above program to a function. Instead of using an OUT parameter for the number of employees deleted,
--  use the functions return value and display how many employees were deleted.

delimiter $$
create function delete_job_fn(p_job varchar(25))
returns int
deterministic
begin

delete from emp where job=p_job;
return row_count();

end $$
delimiter ;

select delete_job_fn("Manager") as Deleted_emp;
select * from emp;

-- 13. Banking Operations 
-- Create a table having the following structure
-- Accounts(Account_id, branch_name, amount_balance)
create table accounts(
ac_id int primary key,
branch_name varchar(255),
balance decimal(10,2));

drop table accounts;
insert into accounts values(1,"Bareja",10000),(2,"Jetalpur",20000),(3,"Nayka",30000),(4,"Kanera",44444),(5,"Kheda",550000);

select * from accounts;


-- a. Write a PL/SQL procedure to perform withdraw operation that only permits a withdrawal
-- if there sufficient funds in the account. The procedure should take Account_id and
-- withdrawal amount as input.


delimiter $$

 create procedure withdrawal(in p_ac_id int, in p_bal decimal(10,2))
begin
	declare bal decimal(10,2);
    select balance into bal from  accounts where ac_id =p_ac_id;
    if bal >= p_bal then
		update accounts
        set balance=balance -p_bal
        where ac_id =  p_ac_id;
        select p_bal,"Money withdraw successfully  " as message;
        select bal-p_bal+ "Updated balance" as message;
	else 
		select "Insufficent Amount !" as message;
	end if ;
end $$
delimiter ;

call withdrawal(1,2000);
select * from accounts;
-- b. Write a procedure to deposit money into someone's account. The procedure should
-- accept account_id and deposit amount.


delimiter $$
create procedure deposit_money(
in sender int,
 in amount decimal(10,2))
 
begin
		update accounts set balance=balance + amount where ac_id = sender;
        select concat(amount ," Deposited money Successfully ") as Message;
	
end $$
delimiter ;

call deposit_money(3,20000);
select * from accounts;




-- c. Write a procedure to transfer money from one person&#39;s account to another. The
-- procedure should table two account_id’s one for giver and one for receiver and the amount
-- to be transferred.

delimiter $$
create procedure transter_money(
in sender int,
in receiver int,
 in amount decimal(10,2))
 
begin
	declare bal decimal(10,2);
    select balance into bal from accounts where ac_id=sender; -- get the sender's balance
    if bal < amount then
		select "Insufficent Balance " as Message;
	else 
		update accounts set balance=balance - amount where ac_id = sender;
        update accounts set balance=balance + amount where ac_id = receiver;
        select amount + " Transfered Successfully " as Message;
	
    end if ;
    
		
end $$
delimiter ;

call transter_money(3,1,20000);
select * from accounts;

										-- Cursors and Data Types as in 3GL
-- 14. Write a PL/SQL block to accept an employee number. and use a record variable to store the
-- record of that employee. and insert it into retired_employee table.
-- Retired_employee table has the following structure
-- Retired_employee (empno, ename, hiredate, leaveDate, salary, mgr_id, deptno).
-- Set the leavedate to the current date.

CREATE TABLE retired_emp (
    empno     INT PRIMARY KEY,
    ename     VARCHAR(50),
    hiredate  DATE,
    leaveDate DATE,
    salary    DECIMAL(10,2),
    mgr_id    INT,
    deptno    INT
);

CREATE TABLE emp_old (
    empno    INT PRIMARY KEY,
    ename    VARCHAR(50),
    hiredate DATE,
    salary   DECIMAL(10,2),
    mgr_id   INT,
    deptno   INT
);

INSERT INTO emp_old (empno, ename, hiredate, salary, mgr_id, deptno) VALUES
(101, 'Amit',   '2015-06-12', 45000, 201, 10),
(102, 'Neha',   '2016-08-25', 52000, 201, 20),
(103, 'Rahul',  '2017-01-10', 48000, 202, 10),
(104, 'Priya',  '2018-03-18', 60000, 202, 30),
(105, 'Karan',  '2019-11-05', 55000, 201, 20);

select * from emp_old;

delimiter $$ 
create procedure retire_employee(in p_no int)
begin 
	insert into retired_emp(empno,ename,hiredate,leaveDate,salary,mgr_id,deptno) 
    select         empno,
        ename,
        hiredate,
        curdate(),   -- leaveDate set to current date
        salary,
        mgr_id,
        deptno
        from emp_old where empno=p_no;
        select "Added to retired emp table " as message;
end $$
delimiter ;
select * from  retired_emp;

call retire_employee(101);


-- 15. Write a PL/SQL Block to create a PL/SQL table which can store grade and on of employees
-- with that grade. Get the information about the grade and number of employees with that
-- grade and store it in the PL/SQL table. Then retrieve the information from the PL/SQL table
-- and display it on the screen in the following way.
-- No of employees with the grade 1 are 3
-- No of employees with the grade 2 are 2
-- No of employees with the grade 3 are 1
-- No of employees with the grade 4 are 2
-- No of employees with the grade 5 are 5
select * from emp;
alter table emp add grade char; 
drop table emp;
CREATE TABLE emp (
    emp_id  int PRIMARY KEY,
    name    VARCHAR(50),
    salary  decimal	(10,2),
    grade   int
);

INSERT INTO emp VALUES (1,  'Amit',   25000, 1);
INSERT INTO emp VALUES (2,  'Neha',   27000, 1);
INSERT INTO emp VALUES (3,  'Rahul',  26000, 1);
INSERT INTO emp VALUES (4,  'Priya',  30000, 2);
INSERT INTO emp VALUES (5,  'Karan',  32000, 2);
INSERT INTO emp VALUES (6,  'Rohit',  35000, 3);
INSERT INTO emp VALUES (7,  'Sneha',  40000, 4);
INSERT INTO emp VALUES (8,  'Ankit',  42000, 4);
INSERT INTO emp VALUES (9,  'Pooja',  45000, 5);
INSERT INTO emp VALUES (10, 'Vikas',  47000, 5);
INSERT INTO emp VALUES (11, 'Nisha',  46000, 5);
INSERT INTO emp VALUES (12, 'Arjun',  48000, 5);

create temporary table grade_summary as select grade ,count(*) as employee_count from emp group by grade;

select concat("No emp with grade " , grade,' are ',employee_count) as result from grade_summary;
select * from grade_summary;


-- 16. Write a program that gives all employees in department 10 a 15% pay increase. Display a
-- message displaying how many Employees were awarded the increase.   

delimiter $$
create procedure hike_salary()
begin
	update emp set salary = salary * 1.15 where deptno=10;
    select row_count() as employees_hiked;
end $$
delimiter ;

select * from emp;
alter table emp add deptno int;
insert into emp values(108,"rahul",10000,2,10);
		call hike_salary();
        
        
        -- Cursors
-- 17. Write a PL/SQL block and use cursor to retrieve the details of the employees with grade 5.
-- and then display employee no,job_id ,max_sal and min_sal and grade for all these
-- employees.                                                         
                                                            
                                                          CREATE TABLE employee_grade (
    emp_no   INT,
    job_id   VARCHAR(20),
    max_sal  DECIMAL(10,2),
    min_sal  DECIMAL(10,2),
    grade    INT
);
INSERT INTO employee_grade VALUES (101, 'DEV', 60000, 30000, 3);
INSERT INTO employee_grade VALUES (102, 'HR',  50000, 25000, 2);
INSERT INTO employee_grade VALUES (103, 'MGR', 90000, 50000, 5);
  INSERT INTO employee_grade VALUES (104, 'DEV', 60000, 30000, 5);
INSERT INTO employee_grade VALUES (105, 'HR',  50000, 25000, 5);
INSERT INTO employee_grade VALUES (106, 'MGR', 90000, 50000, 5);

SELECT * FROM EMPLOYEE_GRADE;

drop procedure emp_grade_5;
--  --------------------------------------------- 
delimiter $$
create procedure emp_grade_5()
begin
	declare done int default 0;
    declare v_empno int;
    declare v_job varchar(50);
    declare v_sal decimal(10,2);
    declare v_grade int;
    declare cur cursor for
		select emp_no,job_id,max_sal,grade from EMPLOYEE_GRADE where grade=5;
        
	declare continue handler for not found set done =1;

    open cur;
		read_loop:loop
			fetch cur into v_empno,v_job,v_sal,v_grade;
			if done = 1 then leave read_loop; end if ;
			select v_empno as Emp_no, v_job as Job, v_sal  as Salary, v_grade as Grade;
		end loop;
    close cur;
end $$
delimiter ;

call emp_grade_5();

-- 18. Write a PL/SQL block that copies all departments to a table called old_dept. Do not use a
-- cursor FOR loop. Display how many rows were copied.

delimiter $$
create procedure copy_dept()
begin
	insert into old_dept select * from department;
    select row_count() as Copied_row;
end $$
delimiter ;


call copy_dept();

use practice_dp;
select * from old_dept;
create table old_dept(
 deptno int,
 dname varchar(50),
 location varchar(50));


-- 19. Display the names of employees who are working for Department 30 
select ename from emp where deptno=30;

-- 20. Write a PL/SQL Block that mimics selecting all columns and rows from the dept table. There
-- is no need to format the output, just select all columns and all rows. Use a cursor FOR loop.

select * from department;

-- 21. Write a PL/SQL block to display the top 6 employees with respect to salaries using cursors.
select * from emp order by salary desc limit 6;

-- 22. Use a cursor to retrieve the department number and the department name from the dept
-- table. Pass the department number to another cursor to retrieve from the emp table the
-- details of employee name, job, hiredate and salary of all the employees who work in that
-- department.

delimiter $$
create procedure read_emp()
begin
	select d.deptno,d.dname,e.ename,e.job,e.salary from department d left join emp e on d.deptno =e.deptno;
end $$
delimiter ;
call read_emp();
-- 23. Write a procedure Raise_salary which gives a specified hike to all the employees working in
-- a specified department.The procedure should take department number and percemtage of
-- hike as input.(Use for update and where current of)
delimiter $$
create procedure raise_salary(
in dept_no int,in per int
)
begin
	update emp 
    set salary = salary +(salary * (per)/100 )where deptno=dept_no;
    select row_count() as Employee_updated;
end $$
delimiter ;
call raise_salary(30,10);
select * from emp;