delimiter $$

create function cal_tax(salary decimal(10,2))

returns decimal(10,2)

deterministic
begin

return salary * 0.18;

end $$ 
delimiter ;

select cal_tax(100000) as Total_tax;

create table emp(
emp_id int primary key auto_increment,
name varchar(50),
salary decimal(10,2));

insert into emp(name, salary) values
("dp", 188000), ("kp",23343),("hp", 23000);

select * from emp;

-- --------------------------- hello ------------
delimiter $$

create function yearly_salary(monthly decimal(10,2))
returns  decimal(10,2)

deterministic

begin 

return monthly * 12;


end $$
delimiter ;

select emp_id , name , salary , yearly_salary(salary) as Annual_Salary
from emp;

show triggers;

-- trigger
delimiter $$
create trigger before_student_insert
before insert on students
for each row 

begin 
	set new.name = upper(new.name) ; 

end $$

delimiter ;


insert into students(name, marks ) 
values('hp', 85);
select * from students;


create table student_log(
id int auto_increment primary key,
student_name  varchar(50),
action varchar(20),
action_time datetime
);

delimiter $$
create trigger after_student_insert
after insert on students
for each row

begin 
  insert into student_log(student_name, action, action_time) 
  values(new.name, 'insert', now());
end$$
delimiter ;



select * from student_log;