#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void decodedMessage(int);

int main() {
    int e = 0;
    int n = 0;
    int m = 0;
    int num = 0;
    int p = 0;
    int q = 0;
    int phi = 0;
    int d = 0;
    bool prime = true;
    vector <int> message;

    cin >> e >> n;
    cin >> m;

    //Reads in numbers from message and stores in vector
    for (int i = 0; i < m; i++) {
        cin >> num;                 
        message.push_back(num);
    }
    
    //Find p and q through brute force
    for (int i = 2; i < n - 1; i++) {
        if (n % i == 0) {
            p = i;
            q = n / i;
        }
    }

    //If they are prime, they should not be divisible by numbers other than 1 and itself
    for (int i = 2; i < p; i++) {
        if (p % i == 0) {
            prime = false;
            break;
        }
    }

    for (int i = 2; i < q; i++) {
        if (q % i == 0) {
            prime = false;
            break;
        }
    }      

    //if p greater than q, we swap since we want p < q
    if (p > q) {
        int temp = p;
        p = q;
        q = temp;
    }

    phi = (p-1) * (q-1);

    if (p == q || (__gcd(e, phi) != 1)|| prime == false) {
        cout << "Public key is not valid!";
        return 0;
    }
    else {
    int e2 = e;
    int phi2 = phi;
    int count = 1;

    //We find d through listing multiples
    while(e2 != phi2 + 1) {
        if (e2 > phi2) {
            phi2 += phi;
        }
        e2 += e;
        count++;
    }

    d = count;

    cout << p << " " << q << " " << phi << " " << d << endl;

    int M = 1;
    int exponent = d;
    int base = 0;

    //We decode the message to an int using exponentiation by squaring
    for (int i = 0; i < m; i++) {
        M = 1;
        exponent = d;
        base = message.at(i);
        while (exponent > 0) {
            if (exponent % 2 == 1) {        
                M = (M * base) % n;         
            }
            base = (base * base) % n;
            exponent = exponent / 2;        
        }
        message.at(i) = M;
        cout << M;
        if (i < m) {
            cout << " ";
        }
    }    

    cout << endl;
    

    //Calls functions that would output letter depending on decoded integer
    for (int i = 0; i < m; i++) {
        M = message.at(i);
        decodedMessage(M);
       
}
    }
    return 0;
}

void decodedMessage(int integerMessage) {
    // Map the decoded integer to the corresponding ASCII value
    char decodedChar;

    if (integerMessage == 7) {
        decodedChar = 'A';
    } else if (integerMessage == 8) {
        decodedChar = 'B';
    } else if (integerMessage == 9) {
        decodedChar = 'C';
    } else if (integerMessage == 10) {
        decodedChar = 'D';
    } else if (integerMessage == 11) {
        decodedChar = 'E';
    } else if (integerMessage == 12) {
        decodedChar = 'F';
    } else if (integerMessage == 13) {
        decodedChar = 'G';
    } else if (integerMessage == 14) {
        decodedChar = 'H';
    } else if (integerMessage == 15) {
        decodedChar = 'I';
    } else if (integerMessage == 16) {
        decodedChar = 'J';
    } else if (integerMessage == 17) {
        decodedChar = 'K';
    } else if (integerMessage == 18) {
        decodedChar = 'L';
    } else if (integerMessage == 19) {
        decodedChar = 'M';
    } else if (integerMessage == 20) {
        decodedChar = 'N';
    } else if (integerMessage == 21) {
        decodedChar = 'O';
    } else if (integerMessage == 22) {
        decodedChar = 'P';
    } else if (integerMessage == 23) {
        decodedChar = 'Q';
    } else if (integerMessage == 24) {
        decodedChar = 'R';
    } else if (integerMessage == 25) {
        decodedChar = 'S';
    } else if (integerMessage == 26) {
        decodedChar = 'T';
    } else if (integerMessage == 27) {
        decodedChar = 'U';
    } else if (integerMessage == 28) {
        decodedChar = 'V';
    } else if (integerMessage == 29) {
        decodedChar = 'W';
    } else if (integerMessage == 30) {
        decodedChar = 'X';
    } else if (integerMessage == 31) {
        decodedChar = 'Y';
    } else if (integerMessage == 32) {
        decodedChar = 'Z';
    } else if (integerMessage == 33) {
        decodedChar = ' ';
    } else if (integerMessage == 34) {
        decodedChar = '"';
    } else if (integerMessage == 35) {
        decodedChar = ',';
    } else if (integerMessage == 36) {
        decodedChar = '.';
    } else if (integerMessage == 37) {
        decodedChar = '\'';
    } 

    cout << decodedChar;
}
