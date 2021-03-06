#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
#define int long long

int Calculate_Y(int w , int s0 , int s1)
{
    return s0 + s1 * w;
}

int32_t main()
{
    int testcases;
    cin >> testcases; // Test Cases
    while(testcases--)
    {
        string input;
    	cin>>input;

    	vector<vector<pair<int,int>>>v(4,vector<pair<int,int>>(input.size()));

    	for(int i=0;i<input.size();i++)
    	{
    		cout << "Choose Any Random Integer between 1 to 100 " << endl;
        	int r1 = rand()%100;
        	cout << r1 << endl;
        	cout << endl;
        	cout << "Extracting the " << i+1 << " Byte " << endl;
        	int h = input[i];
        	cout << h - '0' << endl;
        	cout << endl;

        	cout << "Generating 4 Shares for Each Byte " << endl;;
        	for(int j=0;j<4;j++)
        		{
            		int x=rand()%100;
            		int y = Calculate_Y(x,h,r1);
            		v[j][i] = {x,y};
            		cout << x << " " << y << endl;
        		}
            cout << endl;
    	}

    	string output;
    	cout << "Now we will Apply Lagranges Polynomial for Decrypting " << endl;
    	cout << "Generating the Original Byte Array By 1st and 2nd Share " << endl;
    	cout << endl;
    	for(int i=0;i<input.size();i++)
    		{
    			cout << "Restoring " << i+1 << " digit by 1st and 2nd Share" << endl;
        		int xi0 = v[1][i].first;
        		int xi1 = v[2][i].first;
        		int yi0 = v[1][i].second;
        		int yi1 = v[2][i].second;
        		cout << xi0 << " " << xi1 << " " << yi0 << " " << yi1 << endl;
        		char apnd = char(((yi1*xi0)-(yi0*xi1))/(xi0-xi1));
        		cout << "Restored " << i+1 << " Byte " << apnd << endl;
        		output+=apnd;
        		cout << endl;
    		}
    	cout << endl;
    	cout << "Original Byte Array Restored Completely By SSS Algorithm => ";
    	cout << output;
    }

 }
