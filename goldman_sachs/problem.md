## Problem Statement

Organize Encyclopedias

Cole needs to remove all encyclopedias from an n x m shelf in a library. When selecting an encyclopedia, all other encyclopedias in the same row and column by the same author are also removed. Determine the minimum number of encyclopedias Cole needs to select to remove all encyclopedias.

The shelf contains encyclopedias by k authors, each represented by an integer from 1 to k.

Example

Let there be k = 3 authors. Let the following matrix represent the encyclopedias shelf:

2 2 1  
1 1 1  
2 3 3

Cole can choose the encyclopedia at position (2,3) in the first operation and remove it (1-based rows and columns). Then, the matrix looks like this:

2 2 x  
x x x  
2 3 3

Cole can choose the encyclopedia at position (1,1) in the second operation and remove it. Then, the matrix looks like this:

x x x  
x x x  
x 3 3

Cole can choose the encyclopedia at position (3,3) in the third operation and remove it. Then, the matrix looks like this:

x x x  
x x x  
x x x

Therefore, the minimum number of encyclopedias to select from the shelf is 3.

## Constraints

1<=n,m<=100  
1<=k<=50

## Language: c++

## Testcases

### Sample Case 0

Sample Input For Custom Testing:
3
3
1 1 2
2 2 2
1 2 2
2

bookshelf has 3 rows
bookshelf has 3 columns
bookshelf = [[1, 1, 2], [2, 2, 2], [1,2,2]]
k = 2

Sample Output:
3

Explanation:
Cole chooses the encyclopedia book at position (1,1) in the first operation and removes it.
Cole chooses the encyclopedia book at position (2,2) in the second operation.
Cole chooses the encyclopedia book at position (1,3) in the third operation and removes the remaining books.
Therefore, the answer is 3.

### Sample Case 1:

Sample Input For Custom Testing:
2
3
1 2 3
4 5 6
6

bookshelf has 2 rows
bookshelf has 3 columns
bookshelf = [[1, 2, 3], [4, 5, 6]]
k = 6

Sample Output:
6

Explanation:
Cole has to remove each encyclopedia in a separate operation. Therefore, it takes exactly 6 operations to remove all books from the shelf.

## Template
```
/*  
Complete the 'findMinimumOperations' function below.  
  
The function is expected to return an INTEGER.  
  
The function accepts following parameters:  
  
1. 2D-INTEGER_ARRAY bookshelf   
2. INTEGER K  
*/  
  
int findMinimumOperations(vector<vector<int>> bookshelf, int k) {  
  
}
```