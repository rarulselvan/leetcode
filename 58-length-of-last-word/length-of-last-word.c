int lengthOfLastWord(char* s) 
{
    if(s==NULL)
        return 0;
    
    int len=0;
    int lastLen=0;
    while(*s)
    {
        if(*s==' ')
        {
            if(len)
                lastLen=len;
            len=0;
        }
        else
            len++;
        s++;
    }
    if(len==0)
        return lastLen;
    else
        return len;

}