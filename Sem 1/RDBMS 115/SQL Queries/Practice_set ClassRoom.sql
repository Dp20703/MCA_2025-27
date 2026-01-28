/*1. Write a query to display all customers who have placed an order, along with their order
IDs and the dates of those orders.*/

select c.name, o.order_id,o.order_date
 from customers c
 join orders o on c.customer_id=o.customer_id;
 
 /* 2. Write a query to show all customers and their corresponding orders. If a customer has
not placed any order, still display their name with NULL for order details.*/

SELECT c.name, o.order_id, o.order_date
FROM Customers c
LEFT JOIN Orders o ON c.customer_id = o.customer_id;

/* 3. Write a query to display all products along with the category name to which each product
belongs. */

SELECT p.product_name, cat.category_name
FROM Products p
JOIN Categories cat ON p.category_id = cat.category_id;

/* 4. Write a query to display all categories along with the products in each category. If a
category has no products, display the category name with NULL for product name. */

SELECT cat.category_name, p.product_name
FROM Categories cat
LEFT JOIN Products p ON cat.category_id = p.category_id;

/* 5. Write a query to display each order along with the product names and quantities
purchased in that order. */

SELECT o.order_id, p.product_name, od.quantity
FROM Orders o
JOIN OrderDetails od ON o.order_id = od.order_id
JOIN Products p ON od.product_id = p.product_id;

/* 6. Write a query to display customer names along with the products they purchased and the
quantity of each product.
*/
SELECT c.name, p.product_name, od.quantity
FROM Customers c
JOIN Orders o ON c.customer_id = o.customer_id
JOIN OrderDetails od ON o.order_id = od.order_id
JOIN Products p ON od.product_id = p.product_id;

/* 7. Write a query to display the names of customers who have not placed any order. */
SELECT c.name
FROM Customers c
LEFT JOIN Orders o ON c.customer_id = o.customer_id
WHERE o.order_id IS NULL;

/* 8. Write a query to display the distinct category names of products that customers have
purchased. */
SELECT DISTINCT cat.category_name
FROM Categories cat
JOIN Products p ON cat.category_id = p.category_id
JOIN OrderDetails od ON p.product_id = od.product_id;

/* 9. Write a query to display each order ID and the total amount spent in that order (total =
price * quantity). */

# order -> order_id 
# orderDetails-> quantity
# product -> price

SELECT o.order_id, SUM(p.price * od.quantity) AS total_amount
FROM Orders o
JOIN OrderDetails od ON o.order_id = od.order_id
JOIN Products p ON od.product_id = p.product_id
GROUP BY o.order_id;

/* 10. Write a query to find customers who live in the same city and display their names
together (self join). */

SELECT c1.name AS customer1, c2.name AS customer2, c1.city
FROM Customers c1
JOIN Customers c2 ON c1.city = c2.city AND c1.customer_id < c2.customer_id;

/* 11. Write a query to display the names of customers who have purchased the product
'Headphones'. */

/* Customers => name
 order -> orderDetails 
 [ customer_id joins customer and order table,
 order_id joins orders and  orderDetails table, 
 product_id joins orderDetails and product table ]
product => product_name  */

SELECT DISTINCT c.name
FROM Customers c
JOIN Orders o ON c.customer_id = o.customer_id
JOIN OrderDetails od ON o.order_id = od.order_id
JOIN Products p ON od.product_id = p.product_id
WHERE p.product_name = 'Headphones';

/* 12. Write a query to display customer names along with the product category they
purchased. */
select distinct c.name, cat.category_name 
from customers c 
join orders o on o.customer_id = c.customer_id
 join orderdetails od on od.order_id  = o.order_id 
join products p on p.product_id = od.product_id
join categories cat on cat.category_id = p.category_id;

/* 13. Write a query to display the names of customers who purchased more than one product
in a single order. */

select c.name , o.order_id from customers c join orders o on c.customer_id = o.customer_id 
join  orderdetails od on o.order_id = od.order_id group by c.name, o.order_id
having count(distinct od.product_id ) >1;

/* 14. Write a query to generate all possible combinations of customers and products (cross
join). */

SELECT c.name, p.product_name
FROM Customers c
CROSS JOIN Products p;

/* 15. Write a query to display the names of categories in which no product has ever been
ordered by any customer. */

SELECT DISTINCT cat.category_name
FROM Categories cat
LEFT JOIN Products p ON cat.category_id = p.category_id
LEFT JOIN OrderDetails od ON p.product_id = od.product_id
WHERE od.order_id IS NULL;

/* 16. Write a query to display the names of customers whose total purchase value across all
orders is greater than 50,000. */

SELECT c.name, SUM(p.price * od.quantity) AS total_spent
FROM Customers c
JOIN Orders o ON c.customer_id = o.customer_id
JOIN OrderDetails od ON o.order_id = od.order_id
JOIN Products p ON od.product_id = p.product_id
GROUP BY c.name
HAVING SUM(p.price * od.quantity) > 50000;

/* 17. Write a query to display the number of orders placed by each customer. */
SELECT c.name, COUNT(o.order_id) AS total_orders
FROM Customers c
LEFT JOIN Orders o ON c.customer_id = o.customer_id
GROUP BY c.name;

/* 18. Write a query to display the products purchased by customers who live in 'Delhi'.*/

SELECT DISTINCT p.product_name
FROM Customers c
JOIN Orders o ON c.customer_id = o.customer_id
JOIN OrderDetails od ON o.order_id = od.order_id
JOIN Products p ON od.product_id = p.product_id
WHERE c.city = 'Delhi';

/* 19. Write a query to find the maximum quantity of a single product purchased in one order. */
SELECT MAX(od.quantity) AS max_quantity
FROM OrderDetails od;

/* 20. Write a query to display the names of customers who have purchased at least one
product from the 'Electronics' category. */
SELECT distinct c.name
FROM Customers c
JOIN Orders o ON c.customer_id = o.customer_id
JOIN OrderDetails od ON o.order_id = od.order_id
JOIN Products p ON od.product_id = p.product_id
JOIN Categories cat ON p.category_id = cat.category_id
where cat.category_name="Electronics";

/* 21. Write a query to display the names of categories where more than one product has been
sold. */
SELECT cat.category_name
FROM Categories cat
JOIN Products p ON cat.category_id = p.category_id
JOIN OrderDetails od ON p.product_id = od.product_id
GROUP BY cat.category_name
HAVING COUNT(DISTINCT p.product_id) > 1;

 /* 22. Write a query to display the order IDs of all orders that contain more than two different
products. */
SELECT o.order_id
FROM Orders o
JOIN OrderDetails od ON o.order_id = od.order_id
GROUP BY o.order_id
HAVING COUNT(DISTINCT od.product_id) > 2;

/* 23. Write a query to display the total revenue generated from each product category. */
SELECT cat.category_name, SUM(p.price * od.quantity) AS total_revenue
FROM Categories cat
JOIN Products p ON cat.category_id = p.category_id
JOIN OrderDetails od ON p.product_id = od.product_id
GROUP BY cat.category_name;














































