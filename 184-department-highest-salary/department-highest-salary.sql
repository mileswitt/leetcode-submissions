# The JOIN creates a temporary result containing columns from both tables,
# so SELECT can access columns from both Employee (e) and Department (d).
SELECT
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary

# Give the Employee table the alias "e".
FROM Employee e

# Give the Department table the alias "d".
LEFT JOIN Department d

# Match each employee with their department.
# LEFT JOIN keeps every employee.
# If an employee's department doesn't exist in the Department table,
# the department columns (d.*) will be NULL.
ON e.departmentId = d.id

# Keep only employees whose salary equals the highest salary
# in their own department.
WHERE e.salary = (

    # Find the highest salary...
    SELECT MAX(salary)

    # from the Employee table.
    FROM Employee

    # Restrict the search to employees in the same department
    # as the current employee from the outer query.
    # This makes it a correlated subquery because it references
    # e.departmentId from the outer query.
    WHERE departmentId = e.departmentId
);