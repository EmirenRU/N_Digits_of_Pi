// The program to find numbers of pi in range of limits
// The user need to enter only how many numbers you want to see
// algorithm was taken from there http://pi314.net/eng/goutte.php and how I understand it is Spigot's algorithm.

#include <iostream>
#include <string>

using namespace std;

class PI_Finder{
    int limits;
    string pi;

    void finder(){
        int carriedOver, replaced,quotient, sum, q, heldDigits = 0;

        int len = (this->limits * 10) / 3;
        int *arr = new int [len];

        for (int i = 0; i < len; i++){
            arr[i] = 2;
        }


        for (int i = 0; i < this->limits; i++){
            carriedOver = 0;
            sum = 0;

            for (int j = len - 1; j >= 0; j--){
                arr[j] *= 10;
                sum = arr[j] + carriedOver;
                quotient = sum / (j * 2 + 1);
                arr[j] = sum % (j * 2 + 1);
                carriedOver = quotient * j;
            }
            arr[0] = sum % 10;
            q = sum / 10;

            if (q == 9){
                heldDigits++;
            }
            else if (q == 10){
                q = 0;
                for (int k = 1; k <= heldDigits; k++){
                    replaced = atoi(pi.substr(i-k,i-k+1));
                    if (replaced == 9) replaced = 0;
                    else replaced++;
                    this->pi.erase(i-k);
                    this->pi.insert(i-k, to_string(replaced));
                }
                heldDigits = 1;
            }
            else heldDigits = 1;
            this->pi.append(to_string(q));
        }
    }

public:
    PI_Finder(int limit){
        this->limits = limit;
    }

    void Printer(){
        this->finder();
        cout << pi;
    }
};


int main(int argc, char* argv[]){
    int limits;

    cout << "Enter the limit of number PI: ";
    cin >> limits;

    PI_Finder pi = PI_Finder(limits);
    pi.Printer();
}
