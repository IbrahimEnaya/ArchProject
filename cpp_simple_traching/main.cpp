#include <iostream>
#include<map>
using namespace std ;
// Operations

// 1 Ceaser 
void caesar( char text [], char key , int txt_p ,map <int,char> l, map<char , int> n  )
{
  for(int i = txt_p ; i<txt_p+16  ; i++)
    {
      int c = (n[text[i]] + n[key] )% 52; 
      text[i] = l[c];
      }
}

// 2 XOR with 2 
void xxor(char text [],int txt_p , map<int,char> l , map <char,int> n)
{
  for(int i = txt_p ; i<txt_p +16  ;i++)
    {
      int x = n[text[i]] xor 2 ;
      text [i]= l[x];
    }
}

//3  Swapping
void Swapping(char text[] , int txt_p )
{ 
  //first bit with the size'th bit
  //second with the size-1 'th bit ... 
  for(int i = txt_p , j=txt_p+15 ; i<((2*txt_p +15) /2) ; i++ , j-- )
    {
      char temp = text[i];
      text[i]=text[j];
      text[j]= temp ;
    }
}

//4 Circular shift 
void circular_shift(char text[] , int txt_p)
{
  //to right 
  char last = text[txt_p+15];
  for(int i = txt_p +15 ; i> txt_p ; i--)
    {
      text[i] =text[i-1];
    }
  text[txt_p]= last ; 
}



using namespace std ; 
int main() {


         /////////////////////////////
         /////////////MAPS///////////
         ///////////////////////////

   // 1) initializing the map (i give it a number it gives a letter that this number represents)
  map <int  , char  > letters ;
  
  char a = 'A';
  for(int i = 0 ; i<26 ; i++)
    {
      letters[i]= a;
      a++;
    }
  a = 'a';
  for(int i = 26 ; i<52 ; i++)
    {
      letters[i]= a;
      a++;
    }
   // 2) initializing the map (i give it a letter it gives a number that this letter represents)
  map<char , int> num ;

  int A = 0;
  for(char i = 'A' ; i<='Z' ; i++)
    {
      num[i]= A;
      A++;
    }
  a = 26;
  for(char i ='a'  ; i<='z'; i++)
    {
      num[i]= a;
      a++;
    }




         /////////////////////////////
         ///////////TRACING//////////
         ///////////////////////////       


  char plaintxt[112] = {'T','a','l','a','R','a','e','d','H','a','s','h','e','m','m','m','T','a','l','a','E','m','a','d','I','b','r','a','h','e','e','m','J','o','u','d','B','a','n','i','I','s','m','a','e','i','i','l','D','a','n','a','S','a','m','e','e','r','h','a','d','d','a','d','R','u','n','d','H','a','n','i','i','R','a','s','h','e','e','d','B','a','n','a','S','a','m','e','r','E','l','a','y','y','a','n','L','u','n','a','r','J','a','m','a','l','S','a','l','a','m','e'};


string key ="StudentsOfComputerEngineeringMajorr"; 


    /// SHOW TEXT & KEY 
  cout<<"The user-input TEXT  :  \n";
   cout<<plaintxt <<endl<<endl<<endl; 

  cout<<"The user-input KEY  :  \n";
   cout<<key <<endl<<endl <<endl;   
  cout<<"Start Encryption .... \n\n\n";
  
 
  /// Encryption 
  int txt_p= 0 ; // points to text 
  for(int i = 1 ; i<= 7; i++)
    {
       
      cout<<"TEXT"<< i <<": "<<endl<<endl ;

      // printing the plain text 
      cout<<"    Plain TEXT : "<<endl;
      cout<<"  ";
      for(int j= txt_p ; j< txt_p + 16 ; j++)
      cout <<plaintxt[j];  
      cout<<endl <<endl ;
        

     // printing the key of the text 
      cout<<"    Key for  text "<<i<<" : "<<endl;
      cout<<"  ";
      for(int j= (i-1) * 5  ; j< ((i-1) * 5 ) +5  ; j++)
      cout <<key [j];  
      cout<<endl <<endl ;

      //start calling operations (5 times each )

      //1 ceaser 
      for(int k = 0 ; k<=4 ; k++)
        {
      caesar(plaintxt,key[(i-1) * 5 + k  ],txt_p,letters,num);
      //2 xor 
      xxor(plaintxt,txt_p,letters,num);
      //3 circular shift  
      circular_shift(plaintxt,txt_p);
      //4 Swapping 
      Swapping(plaintxt,txt_p);
          }



      // printing the cipher text 
      cout<<"    cipher TEXT : "<<endl;
      cout<<"  ";
      for(int j= txt_p ; j< txt_p + 16 ; j++)
      cout <<plaintxt[j];  
      cout<<endl <<endl ;
      cout<<"_____________________________________";
      cout<<endl <<endl ; 
    txt_p +=16 ;   
    }
}