//
// Created by BukkitGerman on 16.05.2019.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

inline void type_of_word(char f);

int main(){
    char c,h,ch,ch1,ch2;
    char word[25];
    char word2[25];

    int l,i,ng,n,k,x;

    do{
        do{
            c='\0';
            cout<<"\n\t\t ****** A Simple Hangman ******\n\n";

            cout<<"(E) Enter a word\n\n(C) Computer chooses word\n\n(A)";
            cout<<"Add new word to list\n\n(Q) Quit\n\n\nEnter your choice (E - C - Q): ";
            cin>>ch2;
        }while (ch2!='C' && ch2!='c' && ch2!='E' && ch2!= 'e' &&
                ch2!='Q' && ch2!= 'q'&& ch2!='A' && ch2!= 'a');

        if (ch2 == 'Q' || ch2=='q') {
            cout<<"Bye bye my Friend o.O";
            exit (0);
        }


    }while(true);
}

