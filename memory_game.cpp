//Khayotbek Azimov

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main(){
    // PRINT STARTING PROMPT
    cout << "---------------------------------------" << endl;
    cout << "Hello, welcome to my adaptive memory game" << endl
         << endl;
    cout << "You will be presented with a few words." << endl;
    cout << "You have a second to memorize those." << endl;
    cout << "Then you will be prompted to enter the words..." << endl
         << endl;
    cout << "For every word you enter correctly, you'll get 1 point." << endl;
    cout << "Otherwise, you'll be deducted 1 point." << endl;
    cout << "If the number of words you enter doesn't match" << endl;
    cout << "the number of challenged words, you will be deducted 1 point." << endl;
    cout << "---------------------------------------" << endl
         << endl
         << endl;
    cout << "Ready to begin (Y/N)? ";

    // RECEIVE USER INPUT
    char input;
    cin >> input;
    while (input != 'Y' && input != 'N')
    {
        // CHECK FOR VALIDITY
        cout << "Invalid option, Ready to begin (Y/N)? ";
        cin >> input;
    }

    // CREATE ARRAY OF WORDS
    string list[] = {"apple", "avocado", "apricot", "banana", "blackberry", "blueberry", "boysenberry", 
                    "cherry", "cantaloupe", "cranberry", "coconut", "cucumber", "currant", "date", "durian",
                    "dragonfruit", "elderberry", "fig", "grapefruit", "guava", "grape", "honeydew", "honeyberry", 
                    "jackfruit", "kiwi"};
    int size = 25;

    // INITIALIZE LEVEL TO 2
    int level = 2;

    // INITIALIZE SCORE
    int score = 0;
    do
    {   
        // CLEAR THE SCREEN
        cout << "\033[2J\033[1;1H";
        cout << "***************************************************" << endl;
        cout << endl
             << endl
             << endl;

        string *expected_words = new string[level];
        // PRINT OUT RANDOMLY SELECTED WORDS BASED ON THE LEVEL
        for (int i = 0; i < level; i++)
        {
            int pos = rand() % size;
            cout << list[pos] << " ";
            expected_words[i] = list[pos];
        }

        cout << endl
             << endl
             << endl;
        cout << "***************************************************" << endl;

        // SLEEP 1 SECOND AND FLUSH THE SCREEN
        sleep(1);
        cout << "\033[2J\033[1;1H";

        // GET THE OUTPUT FROM USER
        string *user_input = new string[level];
        cout << "Please input a string (type q to quit): ";
        for(int j=0;j<level;j++){
            cin>>user_input[j]; 
            if(user_input[j]=="q")break;
        }

        // SORT USER_INPUT AND EXPECTED_WORDS
        sort(user_input, user_input+level);
        sort(expected_words, expected_words+level);

        // COMPARE BOTH OF THEM
        bool correct = true;
        for(int j=0;j<level;j++){
            if(user_input[j]!=expected_words[j]){
                correct=false;
                break;
            }
        }

        // CALCULATE THE NEW POINTS AND LEVELS
        if(correct){
            score+=level;
            level = (score/5)+2;
        }else{
            score--;
        }

        cout<<endl;
        sleep(1);
        cout<<"Checking your input ....."<<endl;
        // PLAYER WINS IF THE POINTS ARE GREATER THAN 20
        if(score>20){
            cout<<"-----------------------------------------"<<endl;
            cout<<"Excellent: YOU WIN"<<endl;
            break;
        }
        sleep(1);
        cout<<"Your current score: "<<score<<endl;
        sleep(1);
        cout<<"Here comes the next....."<<endl;
        sleep(1);
        cout<<"Ready ...."<<endl;
        sleep(1);
    } while (true);

    // PRINT THE FINAL SCORE
    cout<<endl<<"Thanks for playing.........."<<endl;
    cout<<"Your final score is.........."<<score<<endl;
    cout<<"Bye..."<<endl<<endl;
}