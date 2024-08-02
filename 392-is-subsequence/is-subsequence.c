
bool isSubSequence(char *strA, char *strB, int m, int n)
{
	//strA - Big sting
	//strA - Small sting

	if(n==0) 
		return true;
	if(m==0) // nothing to compare and  n>0 ...so false
		return false;

	if(strA[m-1]==strB[n-1])
		return isSubSequence(strA, strB, m-1, n-1);
	else
		return isSubSequence(strA, strB, m-1, n);//only decrement m to see StrB is present in StrA
}
bool isSubsequence(char* s, char* t) {
    return isSubSequence(t,s, strlen(t), strlen(s));
}