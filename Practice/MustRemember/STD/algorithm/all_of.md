# Test condition on all elements in range

Returns true if pred returns true for all the elements in the range [first,last) or if the range is empty, 
and false otherwise.

## Example 
all_of(exp.begin(), exp.end(), ::isdigit) - To check the exp string is number