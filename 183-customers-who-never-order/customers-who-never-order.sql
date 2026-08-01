# Write your MySQL query statement below
SELECT name AS Customers
FROM Customers
LEFT JOIN Orders
ON Customers.id = Orders.customerId
WHERE Orders.customerId IS NULL

# return the names of the customers where their order id is null because they never places an order
