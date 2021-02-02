#include <cs50.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

//modules in program
int oLetters_count(string s);
int oWord_count(string s);
int oScentence_count(string s);
int oColeman_index(int letters, int words, int scentences);

//global variables
int string_length;


int main(void)
{
    //main variables
    int letters_sum;
    int words_sum;
    int scentence_sum;
    int coleman_int;
    
    //get a passage of text from the user to check
    string user_string = get_string("Text: "); 
    
    //set string length
    string_length = strlen(user_string);
    
    // call and prin number of letters in string
    letters_sum = oLetters_count(user_string);
    
    //get number of words in string
    words_sum = oWord_count(user_string);
    
    //get number of words in string
    scentence_sum = oScentence_count(user_string);
    
    //calculate coleman index using words, letters and scentences
    coleman_int = oColeman_index(letters_sum, words_sum, scentence_sum);
    
    
    // print grade with if checking
    if (coleman_int < 1)
    {
        printf("Before Grade 1\n");
    }
    
    else if (coleman_int > 16)
    {
        printf("Grade 16+\n");
    }
    
    else
    {
        printf("Grade %i\n", coleman_int);
    }
    
    //end program
    return 0;
}



//function to return number of chars in string 
int oLetters_count(string s)
{   
    //local variables
    int letter_total = 0;
    
    //loop string array and print letters
    for (int i = 0; i < string_length; i++)
    {
        // if letter add 1 to letter count
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            letter_total++;
        }
    }
    //return number of letters
    return letter_total;
}



int oWord_count(string s)
{   
    //local variables
    int spaces_Count = 1;
    
    //cycle string to get spaces for word count
    for (int i = 0; i < string_length; i++)
    {   
        //if theres a space add 1 to space_count
        if (s[i] == ' ')
        {
            spaces_Count++;
        }
    }
    
    //return spaces count
    return spaces_Count;
}


int oScentence_count(string s)
{
    //local variables
    int scentence_count = 0;
    
    for (int i = 0; i < string_length; i++)
    {   
        // . ? !
        if ((s[i] == '.') || (s[i] == '!') || (s[i] == '?'))
        {
            scentence_count++;
        }
    }
    
    //return scentence_count
    return scentence_count;
}


int oColeman_index(int letters, int words, int sentences)
{
    float L = (((float) letters / words) * 100);
    float S = (((float) sentences / words) * 100);
    
    
    float index  = round((0.0588 * L - 0.296 * S) - 15.8);

    return (int) index;
    
}
