# Write your MySQL query statement below

select pe.firstName,
        pe.lastName,
        ad.city,
        ad.state
from
    Person  pe
left join
    Address  ad
ON pe.personId  = ad.personId ;


