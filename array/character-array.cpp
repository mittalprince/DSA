#include <iostream>
#include <cstring>
using namespace std;

// string mystrtok(string str, char delim)
// {   
//     static string input;
//     if (!str.empty())
//     {
//         input = str;
//     }

//     if(input.empty()){
//         return "";
//     }
//     cout<<input<<endl;
//     string output;
//     int i;
//     for(i=0; input[i] != '\0'; i++){
//         if(input[i] != delim){
//             output[i] = input[i];
//             cout<<output[i]<<" ";
//         }
//         else{
//             cout<<output;
//             output[i] = '\0';
//             input += i+1;
//             cout<<"Output "<<output;
//             return output;
//         }
//     }

//     output[i] = '\0';
//     input = "";
//     return output;
// }

char *mystrtok(char *str, char delim)
{
    static char* input;
    if (str != NULL)
    {
        input = str;
    }

    if (input == NULL)
    {
        return NULL;
    }

    char *output = new char[strlen(input) + 1];
    int i;
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != delim)
        {
            output[i] = input[i];
        }
        else
        {
            output[i] = '\0';
            input += i + 1;
            return output;
        }
    }

    output[i] = '\0';
    input = NULL;
    return output;
}

void helper(char *s)
{

    char *temp;
    temp = strtok(s, " ");
    while (temp != NULL)
    {
        cout << temp << "\n";
        temp = strtok(NULL, " ");
    }
}

int main()
{

    char a[100];
    char b[] = {'a', 'b', 'c', '\0'};
    char c[] = "Hello world this gonna be best new year eve";
    char d[] = "hello world this gonna be best new year eve";

    // cin>>a;
    /*
    Syntax 
    cin.getline(arr, sizeof array, deliminator)
    */
    // cin.getline(a, 100, '.');
    // cout<<a<<"\n"<<b<<"\n"<<c<<"\n";

    string s1("Hello World");
    string s2 = "Another way !";
    string s3;
    getline(cin, s3);

    cout << s1 << "\n"
         << s2 << "\n"
         << s3 << "\n";

    // helper(c);
    // cout<<endl;
    char *temp = mystrtok(d, ' ');
    while(temp != NULL){
        cout<<temp<<"\n";
        temp = mystrtok(NULL, ' ');
    }
}