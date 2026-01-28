create schema a4;
use a4;

-- Concept 1 — Cursors (8 Questions)

-- Q1. Create a table `students(id, name, marks)` and write a cursor to display all student names one by one.
create table students(
id int primary key auto_increment,
name varchar(50),
marks int );

INSERT INTO students(name, marks) VALUES
('Amit', 85),
('Bhavin', 72),
('Chirag', 60),
('Disha', 45),
('Ekta', 90);
select * from students;

-- display student names

DELIMITER $$

CREATE PROCEDURE show_student_names()
BEGIN
  DECLARE done INT DEFAULT 0;
  DECLARE v_name VARCHAR(50);

  DECLARE cur CURSOR FOR
    SELECT name FROM students;

  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

  OPEN cur;

  read_loop: LOOP
    FETCH cur INTO v_name;
    IF done = 1 THEN
      LEAVE read_loop;
    END IF;

    -- print one name
    SELECT v_name AS student_name;
  END LOOP;

  CLOSE cur;
END $$

DELIMITER ;

CALL show_student_names();

-- Q2. Write a cursor that fetches both the name and marks of students and prints them.

DELIMITER $$

CREATE PROCEDURE show_student_name_marks()
BEGIN
  DECLARE done INT DEFAULT 0;
  DECLARE v_name  VARCHAR(50);
  DECLARE v_marks INT;

  DECLARE cur CURSOR FOR
    SELECT name, marks FROM students;

  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

  OPEN cur;

  read_loop: LOOP
    FETCH cur INTO v_name, v_marks;
    IF done = 1 THEN
      LEAVE read_loop;
    END IF;

    SELECT v_name AS name, v_marks AS marks;
  END LOOP;

  CLOSE cur;
END $$

DELIMITER ;

CALL show_student_name_marks();


-- Q3. Write a cursor to classify each student into grade A, B, or C based on marks.


DELIMITER $$

CREATE PROCEDURE show_student_grades()
BEGIN
  DECLARE done INT DEFAULT 0;
  DECLARE v_name  VARCHAR(50);
  DECLARE v_marks INT;
  DECLARE v_grade CHAR(1);

  DECLARE cur CURSOR FOR
    SELECT name, marks FROM students;

  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

  OPEN cur;

  read_loop: LOOP
    FETCH cur INTO v_name, v_marks;
    IF done = 1 THEN
      LEAVE read_loop;
    END IF;

    IF v_marks >= 80 THEN
      SET v_grade = 'A';
    ELSEIF v_marks >= 60 THEN
      SET v_grade = 'B';
    ELSE
      SET v_grade = 'C';
    END IF;

    SELECT v_name AS name, v_marks AS marks, v_grade AS grade;
  END LOOP;

  CLOSE cur;
END $$

DELIMITER ;

CALL show_student_grades();


-- Q4. Write a cursor that increases each student’s marks by 5 and updates the table.
DELIMITER $$

CREATE PROCEDURE increase_marks_by_5()
BEGIN
  DECLARE done INT DEFAULT 0;
  DECLARE v_id    INT;
  DECLARE v_marks INT;

  DECLARE cur CURSOR FOR
    SELECT id, marks FROM students;

  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

  OPEN cur;

  read_loop: LOOP
    FETCH cur INTO v_id, v_marks;
    IF done = 1 THEN
      LEAVE read_loop;
    END IF;

    UPDATE students
    SET marks = v_marks + 5
    WHERE id = v_id;
  END LOOP;

  CLOSE cur;
END $$

DELIMITER ;

CALL increase_marks_by_5();

SELECT * FROM students;   


-- Q5. Write a cursor to copy all students with marks ≥ 70 into `passed_students`.

DROP TABLE IF EXISTS passed_students;

CREATE TABLE passed_students (
  id    INT PRIMARY KEY,
  name  VARCHAR(50),
  marks INT
);

DELIMITER $$

DROP PROCEDURE IF EXISTS copy_passed_students $$

CREATE PROCEDURE copy_passed_students()
BEGIN
  DECLARE done   INT DEFAULT 0;
  DECLARE v_id    INT;
  DECLARE v_name  VARCHAR(50);
  DECLARE v_marks INT;

  DECLARE cur CURSOR FOR
    SELECT id, name, marks FROM students WHERE marks >= 70;

  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

  OPEN cur;

  read_loop: LOOP
    FETCH cur INTO v_id, v_name, v_marks;
    IF done = 1 THEN
      LEAVE read_loop;
    END IF;

    INSERT IGNORE INTO passed_students(id, name, marks)
    VALUES (v_id, v_name, v_marks);
  END LOOP;

  CLOSE cur;
END $$

DELIMITER ;

CALL copy_passed_students();

SELECT * FROM passed_students;

-- Q6. Write a cursor to count the total number of students and display the count.
DELIMITER $$

CREATE PROCEDURE count_students()
BEGIN
  DECLARE done INT DEFAULT 0;
  DECLARE v_id INT;
  DECLARE v_count INT DEFAULT 0;

  DECLARE cur CURSOR FOR
    SELECT id FROM students;

  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

  OPEN cur;

  read_loop: LOOP
    FETCH cur INTO v_id;
    IF done = 1 THEN
      LEAVE read_loop;
    END IF;

    SET v_count = v_count + 1;
  END LOOP;

  CLOSE cur;

  SELECT v_count AS total_students;
END $$

DELIMITER ;

CALL count_students();

-- Q7. Write a parameterized cursor simulation to fetch students in a marks range.
DELIMITER $$

CREATE PROCEDURE students_in_marks_range(IN p_min INT, IN p_max INT)
BEGIN
  DECLARE done INT DEFAULT 0;
  DECLARE v_name  VARCHAR(50);
  DECLARE v_marks INT;

  DECLARE cur CURSOR FOR
    SELECT name, marks
    FROM students
    WHERE marks BETWEEN p_min AND p_max;

  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

  OPEN cur;

  read_loop: LOOP
    FETCH cur INTO v_name, v_marks;
    IF done = 1 THEN
      LEAVE read_loop;
    END IF;

    SELECT v_name AS name, v_marks AS marks;
  END LOOP;

  CLOSE cur;
END $$

DELIMITER ;

CALL students_in_marks_range(60, 90);


-- Q8. Write a cursor that prints running maximum marks while scanning rows.

DELIMITER $$

CREATE PROCEDURE running_max_marks()
BEGIN
  DECLARE done INT DEFAULT 0;
  DECLARE v_name       VARCHAR(50);
  DECLARE v_marks      INT;
  DECLARE v_running_max INT DEFAULT 0;

  DECLARE cur CURSOR FOR
    SELECT name, marks
    FROM students
    ORDER BY id;   -- or ORDER BY marks, up to you

  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

  OPEN cur;

  read_loop: LOOP
    FETCH cur INTO v_name, v_marks;
    IF done = 1 THEN
      LEAVE read_loop;
    END IF;

    IF v_marks > v_running_max THEN
      SET v_running_max = v_marks;
    END IF;

    SELECT v_name AS name,
           v_marks AS marks,
           v_running_max AS running_max_marks;
  END LOOP;

  CLOSE cur;
END $$

DELIMITER ;

CALL running_max_marks();

-- Concept 2 — Stored Procedures (8 Questions)

-- Q1. Create a procedure `show_students()` to display all students.
DELIMITER $$

CREATE PROCEDURE show_students()
BEGIN
  SELECT * FROM students;
END $$

DELIMITER ;

CALL show_students();


-- Q2. Write a procedure `add_student(name, marks)` to insert a student.
DELIMITER $$

CREATE PROCEDURE add_student(IN p_name VARCHAR(50), IN p_marks INT)
BEGIN
  INSERT INTO students(name, marks)
  VALUES (p_name, p_marks);
END $$

DELIMITER ;

CALL add_student('Khushi', 78);
CALL show_students();


-- Q3. Write a procedure `update_marks(id, new_marks)` to update marks.
DELIMITER $$

CREATE PROCEDURE update_marks(IN p_id INT, IN p_new_marks INT)
BEGIN
  UPDATE students
  SET marks = p_new_marks
  WHERE id = p_id;
END $$

DELIMITER ;

CALL update_marks(1, 95);
CALL show_students();


-- Q4. Write a procedure `delete_student(id)` and print rows deleted.
DELIMITER $$

CREATE PROCEDURE delete_student(IN p_id INT)
BEGIN
  DECLARE v_rows_deleted INT;

  DELETE FROM students
  WHERE id = p_id;

  SET v_rows_deleted = ROW_COUNT();

  SELECT v_rows_deleted AS rows_deleted;
END $$

DELIMITER ;

CALL delete_student(2);
CALL show_students();


-- Q5. Write a procedure `check_even_odd(num)`.
DELIMITER $$

CREATE PROCEDURE check_even_odd(IN p_num INT)
BEGIN
  IF (p_num % 2 = 0) THEN
    SELECT CONCAT(p_num, ' is EVEN') AS result;
  ELSE
    SELECT CONCAT(p_num, ' is ODD') AS result;
  END IF;
END $$

DELIMITER ;

CALL check_even_odd(10);
CALL check_even_odd(7);



-- Q6. Write a procedure to calculate Net Salary (HRA 20%, DA 10%, PF 5%).
DELIMITER $$

CREATE PROCEDURE calc_net_salary(
    IN  p_basic   DECIMAL(10,2),
    OUT p_hra     DECIMAL(10,2),
    OUT p_da      DECIMAL(10,2),
    OUT p_pf      DECIMAL(10,2),
    OUT p_netpay  DECIMAL(10,2)
)
BEGIN
  SET p_hra    = p_basic * 0.20;
  SET p_da     = p_basic * 0.10;
  SET p_pf     = p_basic * 0.05;
  SET p_netpay = p_basic + p_hra + p_da - p_pf;
END $$

DELIMITER ;

CALL calc_net_salary(30000, @hra, @da, @pf, @net);
SELECT @hra AS HRA, @da AS DA, @pf AS PF, @net AS Net_Salary;

-- Q7. Write a transaction-based procedure `transfer_amount(from_acc, to_acc, amount)`.
CREATE TABLE accounts (
  acc_no   INT PRIMARY KEY,
  holder   VARCHAR(50),
  balance  DECIMAL(10,2)
);

INSERT INTO accounts VALUES
(101, 'Amit', 10000),
(102, 'Bhavin', 8000);

SELECT * FROM accounts;

DELIMITER $$

CREATE PROCEDURE transfer_amount(
    IN p_from_acc INT,
    IN p_to_acc   INT,
    IN p_amount   DECIMAL(10,2)
)
BEGIN
  DECLARE v_from_balance DECIMAL(10,2);

  -- Error handler: if anything fails, rollback
  DECLARE EXIT HANDLER FOR SQLEXCEPTION
  BEGIN
    ROLLBACK;
    SELECT 'Error occurred. Transaction rolled back.' AS message;
  END;

  START TRANSACTION;

  -- Check balance of source account
  SELECT balance INTO v_from_balance
  FROM accounts
  WHERE acc_no = p_from_acc
  FOR UPDATE;

  IF v_from_balance < p_amount THEN
    ROLLBACK;
    SELECT 'Insufficient balance. Transaction cancelled.' AS message;
  ELSE
    -- Debit from source
    UPDATE accounts
    SET balance = balance - p_amount
    WHERE acc_no = p_from_acc;

    -- Credit to destination
    UPDATE accounts
    SET balance = balance + p_amount
    WHERE acc_no = p_to_acc;

    COMMIT;
    SELECT 'Amount transferred successfully.' AS message;
  END IF;
END $$

DELIMITER ;

CALL transfer_amount(101, 102, 2000);
SELECT * FROM accounts;


-- Q8. Write a procedure using CONTINUE HANDLER for duplicate entry error.
DELIMITER $$

CREATE PROCEDURE add_student_safe(IN p_name VARCHAR(50), IN p_marks INT)
BEGIN
  DECLARE v_msg VARCHAR(100) DEFAULT 'Inserted successfully.';

  DECLARE CONTINUE HANDLER FOR 1062
  BEGIN
    SET v_msg = 'Duplicate entry. Student not inserted.';
  END;

  INSERT INTO students(name, marks)
  VALUES (p_name, p_marks);

  SELECT v_msg AS message;
END $$

DELIMITER ;

CALL add_student_safe('Kiran', 88);
CALL add_student_safe('Kiran', 90);

-- Concept 3 — Stored Functions (8 Questions)

-- Q1. Write a function `square(n)`.
DELIMITER $$

CREATE FUNCTION square(n INT)
RETURNS INT
DETERMINISTIC
BEGIN
  RETURN n * n;
END $$

DELIMITER ;

SELECT square(5);


-- Q2. Write a function `add_two(a, b)`.
DELIMITER $$

CREATE FUNCTION add_two(a INT, b INT)
RETURNS INT
DETERMINISTIC
BEGIN
  RETURN a + b;
END $$

DELIMITER ;

SELECT add_two(11, 22);


-- Q3. Write a function `get_grade(marks)`.
DELIMITER $$

CREATE FUNCTION get_grade(marks INT)
RETURNS CHAR(1)
DETERMINISTIC
BEGIN
  IF marks >= 80 THEN
    RETURN 'A';
  ELSEIF marks >= 60 THEN
    RETURN 'B';
  ELSE
    RETURN 'C';
  END IF;
END $$

DELIMITER ;

SELECT get_grade(78);

-- Q4. Write a function `calc_tax(salary)` (18% tax).
DELIMITER $$

CREATE FUNCTION calc_tax(salary DECIMAL(10,2))
RETURNS DECIMAL(10,2)
DETERMINISTIC
BEGIN
  RETURN salary * 0.18;
END $$

DELIMITER ;

SELECT calc_tax(50000);

-- Q5. Write a function `yearly_salary(monthly_salary)`.
DELIMITER $$

CREATE FUNCTION yearly_salary(monthly_salary DECIMAL(10,2))
RETURNS DECIMAL(10,2)
DETERMINISTIC
BEGIN
  RETURN monthly_salary * 12;
END $$

DELIMITER ;

SELECT yearly_salary(35000);



-- Q6. Write a function `get_marks(id)`.
DELIMITER $$

CREATE FUNCTION get_marks(stud_id INT)
RETURNS INT
DETERMINISTIC
BEGIN
  DECLARE m INT;

  SELECT marks INTO m
  FROM students
  WHERE id = stud_id;

  RETURN m;
END $$

DELIMITER ;

SELECT get_marks(11);

-- Q7. Write a function `is_pass(marks)` returning PASS/FAIL.
DELIMITER $$

CREATE FUNCTION is_pass(marks INT)
RETURNS VARCHAR(10)
DETERMINISTIC
BEGIN
  IF marks >= 40 THEN
    RETURN 'PASS';
  ELSE
    RETURN 'FAIL';
  END IF;
END $$

DELIMITER ;

SELECT is_pass(72);
SELECT is_pass(22);

-- Q8. Write a function that returns number of students scoring above 80.
DELIMITER $$

CREATE FUNCTION count_above_80()
RETURNS INT
DETERMINISTIC
BEGIN
  DECLARE c INT;

  SELECT COUNT(*) INTO c
  FROM students
  WHERE marks > 80;

  RETURN c;
END $$

DELIMITER ;

SELECT count_above_80();


-- Concept 4 — Database Triggers (8 Questions)

-- Q1. Write BEFORE INSERT trigger to uppercase name.
DELIMITER $$

CREATE TRIGGER before_student_insert_upper
BEFORE INSERT ON students
FOR EACH ROW
BEGIN
  SET NEW.name = UPPER(NEW.name);
END $$

DELIMITER ;

-- Test
INSERT INTO students(name, marks) VALUES ('hp', 83);
SELECT * FROM students;



-- Q2. Write AFTER INSERT trigger to log student entry in `student_log`.
CREATE TABLE student_log (
  log_id      INT PRIMARY KEY AUTO_INCREMENT,
  student_id  INT,
  student_name VARCHAR(50),
  action      VARCHAR(20),
  log_time    DATETIME
);

DELIMITER $$

CREATE TRIGGER after_student_insert_log
AFTER INSERT ON students
FOR EACH ROW
BEGIN
  INSERT INTO student_log(student_id, student_name, action, log_time)
  VALUES (NEW.id, NEW.name, 'INSERT', NOW());
END $$

DELIMITER ;

-- Test
INSERT INTO students(name, marks) VALUES ('Rahul', 75);
SELECT * FROM student_log;


-- Q3. Write BEFORE UPDATE trigger preventing marks > 100.
DELIMITER $$

CREATE TRIGGER before_student_update_limit_marks
BEFORE UPDATE ON students
FOR EACH ROW
BEGIN
  IF NEW.marks > 100 THEN
    SIGNAL SQLSTATE '45000'
      SET MESSAGE_TEXT = 'Marks cannot be greater than 100';
  END IF;
END $$

DELIMITER ;

-- Test
UPDATE students
SET marks = 120
WHERE id = 11;

-- Q4. Write BEFORE DELETE trigger preventing delete of ‘Admin’.
DELIMITER $$

CREATE TRIGGER before_student_delete_protect_admin
BEFORE DELETE ON students
FOR EACH ROW
BEGIN
  IF OLD.name = 'Admin' THEN
    SIGNAL SQLSTATE '45000'
      SET MESSAGE_TEXT = 'Admin record cannot be deleted';
  END IF;
END $$

DELIMITER ;

-- Test
DELETE FROM students
WHERE name = 'Admin';

-- insert into students(name, marks) values('admin', 22);


-- Q5. Write AFTER UPDATE trigger logging old and new marks.
CREATE TABLE marks_log (
  log_id      INT PRIMARY KEY AUTO_INCREMENT,
  student_id  INT,
  old_marks   INT,
  new_marks   INT,
  changed_at  DATETIME
);

DELIMITER $$

CREATE TRIGGER after_student_update_log_marks
AFTER UPDATE ON students
FOR EACH ROW
BEGIN
 IF OLD.marks <> NEW.marks THEN
    INSERT INTO marks_log(student_id, old_marks, new_marks, changed_at)
    VALUES (OLD.id, OLD.marks, NEW.marks, NOW());
  END IF;
END $$

DELIMITER ;

-- Test
UPDATE students
SET marks = 99
WHERE id = 11;

SELECT * FROM marks_log;

-- Q6. Write BEFORE INSERT trigger to auto-calc grade.
DELIMITER $$

CREATE TRIGGER before_student_insert_set_grade
BEFORE INSERT ON students
FOR EACH ROW
BEGIN
  IF NEW.marks >= 80 THEN
    SET NEW.grade = 'A';
  ELSEIF NEW.marks >= 60 THEN
    SET NEW.grade = 'B';
  ELSE
    SET NEW.grade = 'C';
  END IF;
END $$

DELIMITER ;

-- Test
INSERT INTO students(name, marks) VALUES ('Disha', 65);
SELECT * FROM students;

-- Q7. Write BEFORE UPDATE trigger preventing marks decrease.
DELIMITER $$

CREATE TRIGGER before_student_update_no_decrease
BEFORE UPDATE ON students
FOR EACH ROW
BEGIN
  IF NEW.marks < OLD.marks THEN
    SIGNAL SQLSTATE '45000'
      SET MESSAGE_TEXT = 'Marks cannot be decreased';
  END IF;
END $$

DELIMITER ;

-- Test
UPDATE students
SET marks = 40
WHERE id = 11;

-- Q8. Write trigger to reduce product stock after order insert.

CREATE TABLE products (
  product_id   INT PRIMARY KEY,
  product_name VARCHAR(50),
  stock        INT
);

CREATE TABLE orders (
  order_id    INT PRIMARY KEY AUTO_INCREMENT,
  product_id  INT,
  qty         INT
);

DELIMITER $$

CREATE TRIGGER after_order_insert_reduce_stock
AFTER INSERT ON orders
FOR EACH ROW
BEGIN
  UPDATE products
  SET stock = stock - NEW.qty
  WHERE product_id = NEW.product_id;
END $$

DELIMITER ;

-- Test
INSERT INTO products VALUES (2, 'Pen', 100);

INSERT INTO orders(product_id, qty) VALUES (1, 5);
SELECT * FROM products;  

