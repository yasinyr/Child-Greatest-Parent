#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <cstdlib>
#include <algorithm>

using namespace std;
uint64_t loop;


int main()
{

	loop = 0; //loop for input
	string line; //this will contain the data read from the file
	ifstream myfile("data_parent.txt"); //opening the file.
	vector<string> list; // string array[500]; // creates array to hold names
	vector<string> listp;
	string q;
	string p;
	
	if (myfile.is_open()) //if the file is open
	{
		while (!myfile.eof()) //while the end of file is NOT reached
		{
			getline(myfile, line); //get one line from the file
					
			if (line.length() > 25)
				//if (line.length() == 37)
			{
				for (int i = 0; i < line.length() - 2; i++) { //ignore the occational BOM character

					char a, b, c;
					a = line[i];
					b = line[i + 1];
					c = line[i + 2];
					if ((a == (char)0xEF) && (b == (char)0xBB) && (c == (char)0xBF)) {
						//	cout << "\n\nSTUPID DUMBASS CHARACTER DETECTED!!\n\n";
						line.erase(i, 3);
					}
					
					
				}

				p = line;
				string temp = p.substr(0, 18);
				//cout << temp<< endl<<temp.length()<<"=========="<<endl;
				list.push_back(temp);

				string temp2 = p.substr(19, 39);
				//cout << temp2 << endl << temp2.length() << "==========" << endl;
				listp.push_back(temp2);

				//cout << temp2;
				
				//list.push_back(line);
				//p = list[loop];

				//cout << list[loop] << endl; //and output it
				loop++;
			}
		}
		
			
		myfile.close(); //closing the file
		cout << "\n\n\n DONE!!\n\n"; // the file is read and the data of it has been loaded to vectors.

		
		for (int i = 0; i < listp.size(); i++) {

			vector<string>::iterator itr = find(list.begin(), list.end(), listp[i]);

			int index = distance(list.begin(), itr);

			if (itr != list.cend()){
		
				list[index] = list[i];
				listp[i].erase();
				list[i].erase();
							
				//int index = distance(list.begin(), itr);
				//list[index] = list[i];
				//listp[i].erase();
				//list[i].erase(); 

				cout << list[index] << "  " << listp[index] << endl;
					//list[index] = list[i];
					//listp[i].erase();
					//list[i].erase();
				

			}
			else {
				//std::cout << "Element doesnt present at index ";
				 cout << list[i]<<"  "<< listp[i]<<endl;
			}
		}

		
	}
	else cout << "Unable to open file"; //if the file is not open output
	system("PAUSE");
	return 0;
}