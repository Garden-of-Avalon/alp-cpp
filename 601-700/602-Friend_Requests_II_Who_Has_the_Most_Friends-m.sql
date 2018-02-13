-- In social network like Facebook or Twitter, people send friend requests and accept others' requests as well.

-- Table request_accepted holds the data of friend acceptance, while requester_id and accepter_id both are the id of a person.

-- | requester_id | accepter_id | accept_date|
-- |--------------|-------------|------------|
-- | 1            | 2           | 2016_06-03 |
-- | 1            | 3           | 2016-06-08 |
-- | 2            | 3           | 2016-06-08 |
-- | 3            | 4           | 2016-06-09 |

-- Write a query to find the the people who has most friends and the most friends number. For the sample data above, the result is:

-- | id | num |
-- |----|-----|
-- | 3  | 3   |

-- Note:
-- It is guaranteed there is only 1 people having the most friends.
-- The friend request could only been accepted once, which mean there is no multiple records with the same requester_id and accepter_id value.

-- Explanation:
-- The person with id '3' is a friend of people '1', '2' and '4', so he has 3 friends in total, which is the most number than any others.

-- Follow-up:
-- In the real world, multiple people could have the same most number of friends, can you find all these people in this case? 

-- # Write your MySQL query statement below
-- # SELECT id, SUM(nums) num
-- # FROM
-- #     ((SELECT ra1.requester_id id, COUNT(*) nums
-- #     FROM request_accepted ra1
-- #     GROUP BY id)
-- #     UNION ALL
-- #     (SELECT ra2.accepter_id id, COUNT(*) nums
-- #     FROM request_accepted ra2
-- #     GROUP BY id)) t1
-- # GROUP BY id
-- # ORDER BY num DESC
-- # LIMIT 1;

SELECT id, COUNT(*) num
FROM
    (SELECT ra1.requester_id id FROM request_accepted ra1
    UNION ALL
    SELECT ra2.accepter_id id FROM request_accepted ra2)
    t1
GROUP BY id
ORDER BY num DESC
LIMIT 1;