/*Approach:=The idea is to generate all even length and odd length palindromes and keep track of the longest palindrome seen so far.

Step to generate odd length palindrome:
Fix a centre and expand in both directions for longer palindromes.

Step to generate even length palindrome
Fix two centre ( low and high ) and expand in both directions for longer palindromes.
*/



int longestPalSubstr(char *str) 
{ 
    int maxLength = 1;  // The result (length of LPS) 
  
    int start = 0; 
    int len = strlen(str); 
  
    int low, high; 
  
    // One by one consider every character as center point of  
    // even and length palindromes 
    for (int i = 1; i < len; ++i) 
    { 
        // Find the longest even length palindrome with center points 
        // as i-1 and i.   
        low = i - 1; 
        high = i; 
        while (low >= 0 && high < len && str[low] == str[high]) 
        { 
            if (high - low + 1 > maxLength) 
            { 
                start = low; 
                maxLength = high - low + 1; 
            } 
            --low; 
            ++high; 
        } 
  
        // Find the longest odd length palindrome with center  
        // point as i 
        low = i - 1; 
        high = i + 1; 
        while (low >= 0 && high < len && str[low] == str[high]) 
        { 
            if (high - low + 1 > maxLength) 
            { 
                start = low; 
                maxLength = high - low + 1; 
            } 
            --low; 
            ++high; 
        } 
    } 
  
    printf("Longest palindrome substring is: "); 
    printSubStr(str, start, start + maxLength - 1); 
  
    return maxLength; 
} 
