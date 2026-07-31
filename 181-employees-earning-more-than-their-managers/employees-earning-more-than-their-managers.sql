# Write your MySQL query statement below
# READ THE PROBLEM FULLY
# create output column named Employee
# select the name of the person making more then thier manager
SELECT e2.name as Employee
# create a duplicate of the table called e1
FROM employee e1
# create a duplicate of the table called e2
# we need to compare internal values using a inner join
INNER JOIN employee e2
# grab the columns where employees ID is the same as the managers ID 
-- e1 is the manager because its id matches e2's managerId
ON e1.id = e2.managerID
# the select grabs e2.name when this where is true so when the manager 
-- Keep pairs where the employee earns more than the manager
WHERE e1.salary < e2.salary