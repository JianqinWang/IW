#This is the debugging section of the take home exam

List of bugs noticed (line numbers used are from original_code.c)
- Line 35: (Correcting code in C) The 'new' call doesn't exist in C. Also, when
       	   function is complete, the memory is not freed.
- line 40: For the first iteration, p_temp[num_vectors] will be
       	   trying to access an index that is out of range.
- Line 45: Trying to set variable 'limit' to be num_vectors, but num_vectors is
       	   already -1. The loop to find the biggest dot product will never be
	   entered.1
- Line 50: Variable biggest_dot_product is never initialized.
- Line 59: Incorrect function used for string comparison. strstr() is used to
       	   find the first occurence of a substring. Should use strcmp().

Optimizations:
- Line 4: unused variable float m_w in struct
- The array p_temp has memory allocated and stores all results of the two vector
  dot products, but at the end of the function we only need the largest value
  'biggest_dot_product'.
- Possibly speed up dot product calculations using SSE (not implemented)
- Compare hash values of strings instead of strcmp (not implemented)
