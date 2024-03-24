Buses 3

group: 202

members: Gayane Abgaryan, Inna Hayrapetyan

goal of the task: The ultimate goal of the program is to maintain optimal routes for buses in a new city. The city is represented as an ordered graph with N vertices as crossroads and M edges as the streets, where each street has an assigned number to it - the time it takes to drive through that street in minutes. The program should support the following operations:

1. Find and Construct the shortest pathing for a new bus starting at crossroad A and with potential destinations at crossroads B1, B2, …, Bk. The operation should have O(k) complexity.
2. Add a new crossroad A with corresponding streets. The operation should have O(N^2) complexity.
3. Common streets between I-th and J-th bus paths. The operation should have O(N^2 + M) complexity.
   
Input:

The first line containing N and M, the number of intersections and streets respectively.
The following M lines contain u, v, and k, where u and v denote the street from intersection u to intersection v, and k is the duration in minutes required to travel along the street.
