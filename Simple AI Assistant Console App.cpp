#include <iostream>
#include <string>
#include <algorithm>	
#include <ctime>
#include <vector>
#include <sstream> 

using namespace std;

string toLower(string s) {
	transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) { return tolower(c); });
	return s;
}

vector<string> split(const string& s) {
    vector<string> tokens;
    stringstream ss(s);
    string word;
    while (ss >> word) {
        tokens.push_back(word);
    }
    return tokens;
}

int main() {
	vector<string> helloReplies = {
		"hı,how ı can help you ?",
		"hello there! what can ı do for you?",
		"hey! need some help?"
	};
	vector<string> howAreYouReplies = {
		"I'm good, thanks for asking!",
		"Doing well, how about you?",
		"Fine, thank you!"
	};
	vector<string> thanksReplies = {
		"You're welcome!",
		"No problem!",
		"Anytime!"
	};
	vector<string> jokes = {
    	"Why don't scientists trust atoms? Because they make up everything!",
    	"I told my computer I needed a break, and it said 'No problem, I'll go to sleep.'",
    	"Why did the scarecrow win an award? Because he was outstanding in his field!",
    	"I told my wife she was drawing her eyebrows too high. She looked surprised.",
    	"Parallel lines have so much in common. It’s a shame they’ll never meet.",
    	"Why don’t skeletons fight each other? They don’t have the guts.",
    	"I'm reading a book about anti-gravity. It's impossible to put down!",
    	"What do you call fake spaghetti? An impasta!"
	};

	cout << "Welcome to AI asistant. You can type quit to exit from me :" << endl;
	cout << "Available commands:\n";
	cout << " - hello\n - how are you\n - thanks\n - time\n - joke\n - quit\n";
	cout << " - add num1 num2\n - subtract num1 num2\n - multiply num1 num2\n - divide num1 num2\n";
	cout << "Type your command:" << endl;

	srand(time(0));

	string input;

	while (true) {
		cout << "> ";
		getline(cin, input);
		string loweredInput = toLower(input);

		if (loweredInput == "quit") {
			cout << "SEE YOUU NEXT TIME" << endl;
			break;
		}

		cout << "You said: " << input << endl;

		vector<string> parts = split(loweredInput);

		if (parts.size() == 3) {
		    string op = parts[0];
		    int num1, num2;
		    try {
		        num1 = stoi(parts[1]);
		        num2 = stoi(parts[2]);
		    } catch (...) {
		        cout << "I can't understand the numbers." << endl;
		        continue;
		    }

		    if (op == "add") {
		        cout << "Result: " << (num1 + num2) << endl;
		    }
		    else if (op == "subtract") {
		        cout << "Result: " << (num1 - num2) << endl;
		    }
		    else if (op == "multiply") {
		        cout << "Result: " << (num1 * num2) << endl;
		    }
		    else if (op == "divide") {
		        if (num2 == 0) cout << "Cannot divide by zero!" << endl;
		        else cout << "Result: " << (num1 / num2) << endl;
		    }
		    else {
		        cout << "Brooo its too much ,I can't do that." << endl;
		    }
		    continue;
		}

		if (loweredInput.find("hello") != string::npos) {
			int idx = rand() % helloReplies.size();
			cout << helloReplies[idx] << endl;
		}
		else if (loweredInput.find("how are you") != string::npos) {
			int idx = rand() % howAreYouReplies.size();
			cout << howAreYouReplies[idx] << endl;
		}
		else if (loweredInput.find("thanks") != string::npos) {
			int idx = rand() % thanksReplies.size();
			cout << thanksReplies[idx] << endl;
		}
		else if (loweredInput.find("time") != string::npos) {
			time_t now = time(0);
			tm* ltm = localtime(&now);
			cout << "Now time is: " << ltm->tm_hour << ":";
			if (ltm->tm_min < 10) cout << "0";
			cout << ltm->tm_min << endl;
		}
		else if (loweredInput.find("joke") != string::npos) {
   			 vector<string> jokes = {
    			  "Why don't scientists trust atoms? Because they make up everything!",
    			  "I told my computer I needed a break, and it said 'No problem, I'll go to sleep.'",
    			  "Why did the scarecrow win an award? Because he was outstanding in his field!",
    			  "I told my wife she was drawing her eyebrows too high. She looked surprised.",
    			  "Parallel lines have so much in common. It’s a shame they’ll never meet.",
    			  "Why don’t skeletons fight each other? They don’t have the guts.",
    			  "I'm reading a book about anti-gravity. It's impossible to put down!",
    			  "What do you call fake spaghetti? An impasta!"
			 };
   			 int idx = rand() % jokes.size();
    			cout << jokes[idx] << endl;
		}
		else {
			cout << "ı didnt understand that.Please try again" << endl;
		}
	}

	return 0;
}
