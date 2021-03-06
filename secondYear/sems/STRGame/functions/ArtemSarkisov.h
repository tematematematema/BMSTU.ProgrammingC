// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Sarkisov(char *string, const char *delim)
{
    static char *stc;
    static int len;
    register int num_s = 0, num_d = 0, len_str = 0, count = 0, ind;
    
    if (string != NULL)
    {
        stc = string;
        while (string[len_str] != '\0')
            len_str++;
        len = len_str;
    }
    
    else if (len > 0)
    {
        stc++;
        len--;
        string = stc;
    }
    
    else
    {
        string = NULL;
    }
    
    while (*stc)
    {
        while (delim[num_d] != '\0')
        {
            if (stc[num_s] == delim[num_d])
            {
                num_s++;
                num_d = 0;
            }
            else
                num_d++;
        }
        
        ind = num_s;
        
        if (ind > 0 && count == 0)
        {
            while (ind > 1)
            {
                stc++;
                string++;
                len--;
                ind--;
            }
            
            if (ind == 1)
            {
                if (len > 1)
                {
                    stc--;
                    len++;
                }
            }
            stc++;
            string++;
            len--;
            ind--;
        }
        
        count++;
        num_s = 0;
        num_d = 0;
        
        while (ind > 1)
        {
            *stc = '\0';
            stc++;
            len--;
            ind--;
        }
        
        if (ind == 1)
        {
            *stc = '\0';
            if (len > 1)
            {
                stc--;
                len++;
            }
        }
        
        stc++;
        len--;
    }
    
    return string;
}

int split_Sarkisov(const char *string, char matrix[][N], const char symbol)
{
    register int row = 0, col = 0;
    
    while (*string)
    {
        if (*string != symbol)
        {
            matrix[row][col++] = *string;
        }
        
        else
        {
            matrix[row++][col] = '\0';
            col = 0;
        }

        string++;
    }

    matrix[row][col] = '\0';
    row++;
    
    return row;
}

