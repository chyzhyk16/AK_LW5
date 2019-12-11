#include <iostream>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct globalArgs_t {
    int cycles;
    int target[4];
    int alp;
} globalArgs;

static const char *optString = "c:t:l:h?";

static const struct option longOpts[] = {
        { "cycles", required_argument, nullptr, 'c'},
        { "help", no_argument, nullptr, 'h'},
        { "target", optional_argument, nullptr, 't'},
        { "learning-rate", optional_argument, nullptr, 'l'},
        {nullptr, no_argument, nullptr, 0}
};

void display_usage()
{
    puts("Perceptron implemented in cpp."
            "\nArguments:"
            "\n    -c, --cycles - amount of training epoches, available only integers 2,3,4. "
            "\n    -t, --target - list of target values, 4 elements of 0`s and 1`s, delimeter comma."
            "\n    -l, --learning-rate - learning rate of perceptron, positive integer."
            "\n    -h, --help - display help");
    exit ( EXIT_FAILURE );
}

void display_args()
{
    cout << "globalArgs.cycles = " << globalArgs.cycles << endl;
    cout << "globalArgs.target = " << globalArgs.target[0] << ", " <<
                                      globalArgs.target[1] << ", " <<
                                      globalArgs.target[2] << ", " <<
                                      globalArgs.target[3] << "." << endl;
    cout << "globalArgs.learning-rate = " << globalArgs.alp << endl;
}

int train_perceptron()
{
    int steps = 0;
    //Array for binary input
    int arr[4][2] = {{0, 0},
                     {0, 1},
                     {1, 0},
                     {1, 1}};
    //Target array for Binary Input
    //int t[4] = {0, 1, 1, 1};
    int t[4];
    for ( int i=0; i < 4; i++ )
        t[i] = globalArgs.target[i];
    //Considering learning rate = 1
    int alp = globalArgs.alp;
    //yi = input
    //yo = output
    int w1 = 0, w2 = 0, b = 0, count = 0, i, yi, yo;
    int dw1, dw2, db;

    while (true)
    {
        steps++;
        cout <<"x1"<<" "<<"x2"<<" "<<"b"<<" "<<"yi"<<" "<<
             "yo"<<" "<<"t"<<" "<<"dw1"<<" "<<"dw2"<<" "<<"db"<<
             " "<<"w1"<<" "<<"w2"<<" "<<"b"<<endl;
        for( i = 0; i < 4; i++)
        {
            //Calculating Input
            yi = arr[i][0] * w1 + arr[i][1] * w2 + b;
            if (yi >= 0)
            {
                yo = 1;
            }
            else
            {
                yo = 0;
            }
            if (t[i] == yo)
            {
                count++;
                dw1 = 0;
                dw2 = 0;
                db = 0;
            }
                //Calculating Change in Weight
            else
            {
                dw1 = alp*(t[i] - yo) * arr[i][0];
                dw2 = alp*(t[i] - yo) * arr[i][1];
                db  = alp*(t[i] - yo);
            }
            w1 = w1 + dw1;
            w2 = w2 + dw2;
            b = b + db;
            cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<1<<" "<<yi<<" "<<yo
                <<"     "<<t[i]<<" "<<dw1<<" "<<dw2<<" "<<db<<" "<<w1<<" "<<w2
                <<" "<<b<<endl;
        }
        cout << endl;
        cout << "Count = " << count << endl;
        cout << "Steps = " << steps << endl;
        if(count == globalArgs.cycles)
        {
            return 0;
        }
        else
        {
            display_args();
            count = 0;
        }
    }
}

int main( int argc, char *argv[] )
{
    int opt = 0;
    int longIndex = 0;

    globalArgs.cycles = 2;
    globalArgs.target[0] = 0;
    globalArgs.target[1] = 1;
    globalArgs.target[2] = 1;
    globalArgs.target[3] = 1;
    globalArgs.alp = 1;
    int counter = 0;

    opt = getopt_long( argc, argv, optString, longOpts, &longIndex );
    while( opt != -1 ) {
        switch( opt ) {
            case 'c':
                globalArgs.cycles = atoi(optarg);
                break;

            case 'l':
                globalArgs.alp = atoi(optarg);
                cout << "Here is optarg for alp " << optarg << endl;
                break;

            case 't':
                /*while ((pos = target_.find(delimeter_)) != std::string::npos)
                {
                    globalArgs.target[index_] = target_.substr(0, pos);
                    index_++;
                    target_.erase(0, pos + delimeter_.length());
                }
                cout << "target token real one = " << optarg << endl;*/
                globalArgs.target[0] = optarg[0] - '0';
                globalArgs.target[1] = optarg[2] - '0';
                globalArgs.target[2] = optarg[4] - '0';
                globalArgs.target[3] = optarg[6] - '0';
                break;

            case 'h':
                display_usage();
                break;

            case '?':
                /*if ( optopt )
                    cout << "Unknown short option: " << (char)optopt << endl;
                else
                    cout << "Unknown long option: " << optopt << endl;
                */
                break;

            default:
                break;
        }

        opt = getopt_long( argc, argv, optString, longOpts, &longIndex );
    }

    if ( globalArgs.cycles <= 1 or globalArgs.cycles >= 5 ){
        cout << "cycles out of range" << endl;
        return EXIT_FAILURE;
    }
    train_perceptron();
    display_args();

    return EXIT_SUCCESS;
}