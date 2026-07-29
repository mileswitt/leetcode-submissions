# Write your MySQL query statement below

#window function
/*
SELECT score, 
    DENSE_RANK() OVER(ORDER BY score DESC) AS 'rank'
FROM Scores
*/

# practice with other window functions and sub query

/*
SELECT *
FROM 
(SELECT Gender, name, total,
    ROW_NUMBER() OVER(PARTITION BY gender ORDER BY total DESC) as popularity
FROM baby_names) AS pop
WHERE popularity <= 3
*/

# non window function
# we use aliases and correlated sub queries
# look at table twice once for getting current score
# second time for comparing to other scores
# remember sql runs logically not top to bottom

# table.column means "table alias.column"
# s1.score = score column from the outer copy of Scores
# s2.score = score column from the inner copy of Scores

# Outer query: iterate through every row in Scores
SELECT s1.score,

       # For the current s1 row, count the number of DISTINCT scores
       # in the second copy (s2) that are greater than or equal to
       # the current s1 score.
       #
       # The inner query runs once for EVERY row processed by the
       # outer query (similar to a nested loop).
       (
           SELECT COUNT(DISTINCT s2.score)

           # Second copy of the Scores table
           FROM Scores s2

           # Compare every score in s2 against the current score in s1
           WHERE s2.score >= s1.score

       ) AS 'rank'

# First copy of the Scores table
FROM Scores s1

ORDER BY s1.score DESC;