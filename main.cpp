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
    char c,h,ch,ch1,input;
    char word[25];
    char word2[25];

    int l,i,ng,n,k,x;

    do{
        do{
            c='\0';
            cout<<"\n\t\t ****** A Simple Hangman ******\n\n";

            cout<<"(E) Enter a word\n\n(C) Computer chooses word\n\n(A)";
            cout<<"Add new word to list\n\n(Q) Quit\n\n\nEnter your choice (E - C - Q): ";
            cin>>input;
        }while (input!='C' && input!='c' && input!='E' && input!= 'e' &&
                input!='Q' && input!= 'q'&& input!='A' && input!= 'a');

        if (input == 'Q' || input=='q') {
            cout<<"Bye bye my Friend o.O";
            exit (0);
        }

        if(input == 'C' || input=='c') {
            ifstream fin("hangman_words.txt");
            if (!fin) {
                cout << "File 'hangman_words.txt' ist missing. \n Place is next to the program file.\n ";
                system("pause");
                return 0;
            }
            for (i = 0; fin.eof(); i++) {
            fin.getline(word, 25);
            }fin.close();

            do{
                x=rand();
            }while (x>1 || x<0);

            ifstream finn("hangman_words.txt");
            for(i=0; !finn.eof();i++){
                finn>>c;
                finn.getline(word,25);
                if(x==1){
                    break;
                }finn.close();
            }
        }

        if (input == 'A' || input=='a'){
            ofstream fout("hangword.txt",ios::app);
            if(!fout) {//clrscr();
                cout<<"File missing, aborting.\n\nYou are missing a file of name"
                      " **hangword.txt**\n\nLocate it, then place it next to the program"
                      " file.\n\n"; system("pause"); return 0;}
            cin.get();
            cout<<"Choose the topic of your word\n\n(M) Movie\n\n(A) Animal\n\n(P)"
                  " Sport\n\n(S) Song\n\nEnter your choice (A-P-S-M) : ";
            cin>>h;
            cin.get();
            //clrscr();
            cout<<"\n\nThe word should not exceed 25 letters\n\nEnter the word : ";
            cin.getline(word,25);
            fout<<h<<word<<endl;
            fout.close();

        }

        if (input == 'E' || input == 'e'){
            cin.get();
            cout<<"\t\t\t Type the word:  ";
            cin.getline(word, 25);
        }
        if (input == 'E' || input=='e' || input == 'C' || input=='c'){
            l=strlen(word);
            char choosen[25]="\0";
            n=0;k=0;

            for(i=0;i<=24;i++){
                if (word[i]=='\0') {word2[i]='\0';break;}
                if (word[i]==' ')  {word2[i]=' ';  n++;}
                if (word[i]!=' ')  word2[i]='-';
            }


            ng = l+2-n;
            do{
                there: type_of_word(c);
                if(k!=0) cout <<"\n\n\t\t\tChoosen letters: "<<choosen<<"\n";
                cout<<"\n\n\n\t\t\t      "<<word2<<"\n\n\nYou have "<<ng<< " guesses left, choose a letter : ";
                cin>>ch;
                cin.get();
                for(i=0;i<25;i++){
                    if(choosen[i]==ch){
                        cout<<"\a\t\t     !!You have choosen "<<ch<<" already!!\n";goto there;
                    }
                    ng--;
                    choosen[k]=ch;
                    choosen[k+1]=',';
                    k+=2;

                    for(i=0;i<=24;i++){
                        if(word[i]==ch || word[i]==ch+32 || word[i]==ch-32) word2[i]=ch;
                        if(!strcmpi (word2,word)){
                            cout<<"\n\t\t\t      "<<strupr(word)
                               <<"\n\n\t\t\tCongratulations  :-()\n"; break;
                        }
                    }
                }
            }while(ng>0 || !strcmpi (word2,word));

            if (strcmpi (word2,word))  cout<<"\nSorry, maybe next time.\n\nThe word was : "
                                           <<strupr(word)<<endl;
        }

        cout<<"\nWould you like to play again??? (Y - N) : ";
        cin>>ch1;  cin.get();

        }while (ch1=='y' || ch1=='Y');
    system("PAUSE");
    return 0;


    }

inline void type_of_word(char f)

{    if (f=='m') cout<<"\t\t\t\tMOVIE";
    if (f=='a') cout<<"\t\t\t\tANIMAL";
    if (f=='p') cout<<"\t\t\t\tSPORT";
    if (f=='s') cout<<"\t\t\t\tSONG";
}


